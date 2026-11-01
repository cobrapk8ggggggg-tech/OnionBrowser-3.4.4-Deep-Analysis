#!/usr/bin/env python3
"""
Pure-Python ObjC metadata dumper for iOS Mach-O binaries (ARM64).
Handles dyld chained fixups (iOS 15+) and classic rebase info.
Outputs class-dump style headers: classes, methods, ivars, properties, protocols, categories.
"""
import struct, sys, json, os

class MachO:
    def __init__(self, path):
        self.path = path
        self.data = open(path, 'rb').read()
        self.parse_header()
        self.segments = {}   # segname -> (vmaddr, fileoff, filesize, vmsize, sections{name: (vmaddr, size, offset)})
        self.seglist = []
        self.dylibs = []
        self.chained_fixups = None
        self.classlist_addr = None
        self.catlist_addr = None
        self.protolist_addr = None
        self.swift_sections = []
        self.parse_load_commands()

    def u32(self, off): return struct.unpack_from('<I', self.data, off)[0]
    def u64(self, off): return struct.unpack_from('<Q', self.data, off)[0]
    def i64(self, off): return struct.unpack_from('<q', self.data, off)[0]

    def parse_header(self):
        magic = self.u32(0)
        if magic == 0xFEEDFACF:
            self.off = 0
        elif magic == 0xBEBAFECA:  # fat
            n = self.u32(4)
            for i in range(n):
                cputype, cpusub, offset = struct.unpack_from('<II I', self.data, 8 + i*20)[0:3]
                sub = self.data[offset:offset+struct.unpack_from('<I', self.data, offset+56)[0]]  # not exact; handle single slice below
            # simple: find arm64 slice
            for i in range(n):
                base = 8 + i*20
                cputype = self.u32(base)
                offset = self.u32(base+8)
                if cputype == 0x0100000C:  # arm64
                    self.off = offset
                    break
        else:
            raise Exception('not a macho: %x' % magic)
        self.ncmds = self.u32(self.off + 16)
        self.cmdsize_total = self.u32(self.off + 20)

    def parse_load_commands(self):
        off = self.off + 32
        for _ in range(self.ncmds):
            cmd, size = self.u32(off), self.u32(off+4)
            if cmd == 0x19:  # LC_SEGMENT_64
                segname = self.data[off+8:off+24].split(b'\x00')[0].decode()
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from('<QQQQ', self.data, off+24)
                nsects = self.u32(off+64)
                sections = {}
                for i in range(nsects):
                    so = off + 72 + i*80
                    sect = self.data[so:so+16].split(b'\x00')[0].decode()
                    seg2 = self.data[so+16:so+32].split(b'\x00')[0].decode()
                    addr, sz = struct.unpack_from('<QQ', self.data, so+32)
                    fo = self.u32(so+48)
                    sections[sect] = (addr, sz, fo)
                    if seg2 == '__TEXT' and sect.startswith('__swift'):
                        self.swift_sections.append(sect)
                self.segments[segname] = (vmaddr, fileoff, filesize, vmsize)
                self.seglist.append((segname, vmaddr, fileoff, filesize, vmsize, sections))
                if segname == '__DATA' or segname == '__DATA_CONST' or segname == '__DATA_DIRTY':
                    if '__objc_classlist' in sections: self.classlist_addr = sections['__objc_classlist'][0]
                    if '__objc_catlist' in sections: self.catlist_addr = sections['__objc_catlist'][0]
                    if '__objc_protolist' in sections: self.protolist_addr = sections['__objc_protolist'][0]
            elif cmd == 0xC:  # LC_LOAD_DYLIB
                nameoff = self.u32(off+8)
                name = self.data[off+nameoff:off+size].split(b'\x00')[0].decode()
                self.dylibs.append(name)
            elif cmd == 0x80000034:  # LC_DYLD_CHAINED_FIXUPS
                dataoff, datasize = self.u32(off+8), self.u32(off+12)
                self.chained_fixups = (dataoff, datasize)
            off += size

    # ---------- address translation ----------
    def vm2file(self, addr):
        for (name, vmaddr, fileoff, filesize, vmsize, sections) in self.seglist:
            if vmaddr <= addr < vmaddr + vmsize:
                return fileoff + (addr - vmaddr)
        return None

    def in_section(self, addr):
        for (name, vmaddr, fileoff, filesize, vmsize, sections) in self.seglist:
            for sect, (sa, sz, so) in sections.items():
                if sa <= addr < sa + sz and sz > 0:
                    return (name, sect)
        return None

    def read_str(self, addr, maxlen=256):
        fo = self.vm2file(addr)
        if fo is None: return None
        end = self.data.find(b'\x00', fo, fo+maxlen)
        if end == -1: return None
        try: return self.data[fo:end].decode('utf-8')
        except: return None

    def read_u64(self, addr):
        fo = self.vm2file(addr)
        if fo is None: return None
        return self.u64(fo)

    def read_u32(self, addr):
        fo = self.vm2file(addr)
        if fo is None: return None
        return self.u32(fo)

    # ---------- chained fixup decoding ----------
    def decode_ptr(self, fileoff, ptr_format):
        """Decode a fixup pointer at file offset. Returns vmaddr (rebase) or ('bind', ordinal)."""
        v = self.u64(fileoff)
        if v == 0: return None
        if self.chained_fixups is None:
            return v
        fmt = ptr_format
        if fmt in (2, 7):  # ARM64E
            auth = (v >> 63) & 1
            if auth: return None
            target = v & 0x7FFFFFFFFFF
            high8 = (v >> 43) & 0xFF
            if high8: return None
            return self.image_base + target
        else:  # format 4: dyld_chained_ptr_64_rebase/bind
            bind = (v >> 63) & 1
            if bind:
                ordinal = v & 0xFFFFFF
                return ('bind', ordinal)
            target = v & 0xFFFFFFFFF
            high8 = (v >> 36) & 0xFF
            if high8: return None
            return self.image_base + target

    @property
    def image_base(self):
        for (name, vmaddr, fileoff, filesize, vmsize, sections) in self.seglist:
            if name == '__TEXT':
                return vmaddr
        return 0x100000000

    def fixup_ptr_format(self):
        if not self.chained_fixups: return None
        off, size = self.chained_fixups
        fo = off  # dataoff is file offset
        try:
            version = self.u32(fo)
            if version != 0: return None
            starts_off = self.u32(fo+4)
            img = fo + starts_off
            seg_count = self.u32(img)
            if seg_count == 0: return None
            seg_info_off0 = self.u32(img+4)
            seg = img + seg_info_off0
            # dyld_chained_starts_in_segment: u32 size, u16 page_size, u16 pointer_format
            return self.u32(seg+4) & 0xFFFF
        except Exception:
            return None

    def load_imports(self):
        """Parse dyld chained fixups imports table -> list of symbol names"""
        if hasattr(self, '_imports'): return self._imports
        self._imports = []
        if not self.chained_fixups: return self._imports
        fo = self.chained_fixups[0]
        try:
            imports_off = self.u32(fo+8)
            symbols_off = self.u32(fo+12)
            imports_count = self.u32(fo+16)
            imports_format = self.u32(fo+20)
            base = fo + imports_off
            strbase = fo + symbols_off
            for i in range(imports_count):
                if imports_format == 1:  # dyld_chained_import_addend (12 bytes)
                    o = base + i*12
                    hdr = self.u32(o)
                    sym_off = self.u32(o+4)
                else:  # format 0: dyld_chained_import (8 bytes)
                    o = base + i*8
                    hdr = self.u32(o)
                    sym_off = self.u32(o+4)
                lib = hdr & 0xFF
                name = self.read_str(strbase + sym_off, 512) or '?'
                self._imports.append(name)
        except Exception:
            pass
        return self._imports

    # ---------- ObjC dumping ----------
    def fixup_target(self, addr):
        """Read pointer at vmaddr and decode chained fixup -> target vmaddr"""
        v = self.read_u64(addr)
        if v is None or v == 0: return None
        bind = (v >> 63) & 1
        if bind: return None
        target = v & 0xFFFFFFFFF   # 36-bit target, format 4
        high8 = (v >> 36) & 0xFF
        if high8: return None
        return self.image_base + target

    def method_list(self, addr):
        """method_list_t -> [(name, types)] — classic ptr, relative, and selref-relative (iOS 18+)"""
        out = []
        if not addr: return out
        fo = self.vm2file(addr)
        if fo is None: return out
        entsize_u32 = self.u32(fo)
        count = self.u32(fo+4)
        rel = (entsize_u32 & 0x80000000) != 0
        if rel:
            entry = 12
            for i in range(count):
                entry_vmaddr = addr + 8 + i*entry
                io = fo + 8 + i*entry
                name_delta, types_delta, imp_delta = struct.unpack_from('<iii', self.data, io)
                # name: self-relative delta -> selref slot -> chained pointer -> string
                selref_vm = entry_vmaddr + name_delta
                name_addr = self.fixup_target(selref_vm)
                name = self.read_str(name_addr) if name_addr else '?'
                types_addr = entry_vmaddr + 4 + types_delta
                types = self.read_str(types_addr) or '?'
                out.append((name, types))
        else:
            entry = 16
            for i in range(count):
                eo = fo + 8 + i*entry
                name_ptr = self.decode_ptr(eo, self.ptr_format)
                types_ptr = self.decode_ptr(eo+8, self.ptr_format)
                name = self.read_str(name_ptr) if name_ptr else '?'
                types = self.read_str(types_ptr) if types_ptr else '?'
                out.append((name, types))
        return out

    def ivar_list(self, addr):
        out = []
        if not addr: return out
        fo = self.vm2file(addr)
        if fo is None: return out
        entsize_u32 = self.u32(fo)
        count = self.u32(fo+4)
        rel = (entsize_u32 & 0x80000000) != 0
        entry = entsize_u32 & 0xFFFF
        if entry not in (16, 24): entry = 24
        for i in range(count):
            entry_vmaddr = addr + 8 + i*entry
            io = fo + 8 + i*entry
            if rel:
                name_delta, types_delta = struct.unpack_from('<ii', self.data, io)
                name = self.read_str(entry_vmaddr + name_delta) or '?'
                types = self.read_str(entry_vmaddr + 4 + types_delta) or '?'
            else:
                name_ptr = self.decode_ptr(io+8, self.ptr_format)
                types_ptr = self.decode_ptr(io+16, self.ptr_format)
                name = self.read_str(name_ptr) if name_ptr else '?'
                types = self.read_str(types_ptr) if types_ptr else '?'
            out.append((name, types))
        return out

    def prop_list(self, addr):
        out = []
        if not addr: return out
        fo = self.vm2file(addr)
        if fo is None: return out
        entsize_u32 = self.u32(fo)
        count = self.u32(fo+4)
        entry = entsize_u32 & 0xFFFF
        if entry != 16: entry = 16
        rel = (entsize_u32 & 0x80000000) != 0
        for i in range(count):
            entry_vmaddr = addr + 8 + i*entry
            po = fo + 8 + i*entry
            if rel:
                name_delta, attr_delta = struct.unpack_from('<ii', self.data, po)
                name = self.read_str(entry_vmaddr + name_delta) or '?'
                attrs = self.read_str(entry_vmaddr + 4 + attr_delta) or '?'
            else:
                name_ptr = self.decode_ptr(po, self.ptr_format)
                attr_ptr = self.decode_ptr(po+8, self.ptr_format)
                name = self.read_str(name_ptr) if name_ptr else '?'
                attrs = self.read_str(attr_ptr) if attr_ptr else '?'
            out.append((name, attrs))
        return out

    def parse_class(self, class_vmaddr):
        """class object -> dict"""
        fo = self.vm2file(class_vmaddr)
        if fo is None: return None
        isa = self.decode_ptr(fo, self.ptr_format)
        superclass = self.decode_ptr(fo+8, self.ptr_format)
        if superclass is None:
            superclass = self.fixup_target(class_vmaddr + 8)
        data_ptr = self.decode_ptr(fo+32, self.ptr_format)
        if data_ptr is None: return None
        ro = data_ptr & ~0x7  # remove FAST_DATA mask
        rfo = self.vm2file(ro)
        if rfo is None: return None
        flags = self.u32(rfo)
        name_addr = self.decode_ptr(rfo+24, self.ptr_format)
        name = self.read_str(name_addr) if name_addr else '?'
        methods = self.method_list(self.decode_ptr(rfo+32, self.ptr_format))
        ivars = self.ivar_list(self.decode_ptr(rfo+56, self.ptr_format))
        props = self.prop_list(self.decode_ptr(rfo+64, self.ptr_format))
        super_name = '?'
        if superclass:
            if isinstance(superclass, tuple) and superclass[0] == 'bind':
                super_name = f'BIND:{superclass[1]}'
            else:
                sfo = self.vm2file(superclass)
                if sfo:
                    sdata = self.decode_ptr(sfo+32, self.ptr_format)
                    if sdata and not isinstance(sdata, tuple):
                        sro = sdata & ~0x7
                        srfo = self.vm2file(sro)
                        if srfo:
                            sname_addr = self.decode_ptr(srfo+24, self.ptr_format)
                            if sname_addr and not isinstance(sname_addr, tuple):
                                super_name = self.read_str(sname_addr) or '?'
        return {
            'name': name, 'super': super_name,
            'methods': methods, 'ivars': ivars, 'props': props,
            'is_meta': False,
        }

    @property
    def ptr_format(self):
        if not hasattr(self, '_ptrfmt'):
            self._ptrfmt = self.fixup_ptr_format() or 4
        return self._ptrfmt

    def dump_all(self):
        classes = []
        if self.classlist_addr:
            fo = self.vm2file(self.classlist_addr)
            n = 0
            # classlist size unknown; scan until pointer decode fails / section end
            (segname, sect) = self.in_section(self.classlist_addr)
            for (name, vmaddr, fileoff, filesize, vmsize, sections) in self.seglist:
                if sect in sections:
                    sa, sz, so = sections[sect]
                    end = sa + sz
            addr = self.classlist_addr
            while addr < end:
                ptr = self.decode_ptr(self.vm2file(addr), self.ptr_format)
                if ptr is None:
                    addr += 8
                    continue
                c = self.parse_class(ptr)
                if c and c['name'] and c['name'] != '?':
                    classes.append(c)
                addr += 8
        cats = []
        if self.catlist_addr:
            (segname, sect) = self.in_section(self.catlist_addr)
            for (name, vmaddr, fileoff, filesize, vmsize, sections) in self.seglist:
                if sect in sections:
                    sa, sz, so = sections[sect]
                    end = sa + sz
            addr = self.catlist_addr
            while addr < end:
                fo = self.vm2file(addr)
                if fo is None: break
                cat_name_ptr = self.decode_ptr(fo, self.ptr_format)
                cls_ptr = self.decode_ptr(fo+8, self.ptr_format)
                cat_name = self.read_str(cat_name_ptr) if cat_name_ptr else None
                cls = self.parse_class(cls_ptr) if cls_ptr else None
                if cat_name and cls:
                    cats.append({'category': cat_name, 'class': cls['name'], 'methods': cls['methods'], 'props': cls['props']})
                addr += 8
        return classes, cats

    def section_strings(self, seg, sect):
        for (name, vmaddr, fileoff, filesize, vmsize, sections) in self.seglist:
            if seg in sections and sect in sections[seg]:
                sa, sz, so = sections[seg][sect]
                blob = self.data[so:so+sz]
                return [s.decode('utf-8', 'ignore') for s in blob.split(b'\x00') if len(s) > 2]
        return []


if __name__ == '__main__':
    path = sys.argv[1]
    outdir = sys.argv[2]
    os.makedirs(outdir, exist_ok=True)
    m = MachO(path)
    print(f"image base: {hex(m.image_base)}, chained fixups: {m.chained_fixups}, ptr format: {m.ptr_format}")
    classes, cats = m.dump_all()
    print(f"classes: {len(classes)}, categories: {len(cats)}")

    # Write class-dump style headers
    with open(os.path.join(outdir, 'objc_classes.json'), 'w') as f:
        json.dump({'classes': classes, 'categories': cats}, f, indent=1)

    # Human readable header file
    with open(os.path.join(outdir, 'OnionBrowser_dumped.h'), 'w') as f:
        for c in sorted(classes, key=lambda x: x['name']):
            f.write(f"@interface {c['name']} : {c['super']}\n")
            for n, t in c['ivars']:
                f.write(f"    {t} {n};\n")
            if c['ivars']: f.write('\n')
            for n, t in c['props']:
                f.write(f"    @property {t} {n};\n")
            if c['props']: f.write('\n')
            for n, t in c['methods']:
                f.write(f"    {t} {n};\n")
            f.write("@end\n\n")
        for cat in sorted(cats, key=lambda x: (x['class'], x['category'])):
            f.write(f"@interface {cat['class']} ({cat['category']})\n")
            for n, t in cat['methods']:
                f.write(f"    {t} {n};\n")
            f.write("@end\n\n")

    # Class name list
    with open(os.path.join(outdir, 'classnames.txt'), 'w') as f:
        for c in sorted(classes, key=lambda x: x['name']):
            f.write(f"{c['name']} -> {c['super']} ({len(c['methods'])} methods)\n")

    # Method name inventory (ObjC selectors)
    sel = set()
    for c in classes:
        for n, t in c['methods']: sel.add(n)
    for cat in cats:
        for n, t in cat['methods']: sel.add(n)
    with open(os.path.join(outdir, 'selectors.txt'), 'w') as f:
        f.write('\n'.join(sorted(sel)))
    print(f"selectors: {len(sel)}")
