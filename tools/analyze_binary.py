#!/usr/bin/env python3
"""Deep Mach-O binary analyzer for OnionBrowser using LIEF"""
import lief
import sys, json, re
from collections import Counter

path = sys.argv[1]
binary = lief.MachO.parse(path).at(0)

report = {}

# Header info
hdr = binary.header
report['header'] = {
    'cpu_type': str(hdr.cpu_type),
    'file_type': str(hdr.file_type),
    'flags': [str(f) for f in hdr.flags_list],
    'n_cmds': len(list(binary.commands)),
}

# Architectures (fat binary slices)
fat = lief.MachO.parse(path)
report['architectures'] = [str(b.header.cpu_type) for b in fat]

# Load commands summary
cmds = Counter()
for cmd in binary.commands:
    cmds[type(cmd).__name__] += 1
report['load_commands'] = dict(cmds)

# Dylibs
report['linked_libraries'] = []
for lib in binary.libraries:
    report['linked_libraries'].append({
        'name': lib.install_name,
        'current_version': hex(lib.current_version),
        'compat_version': hex(lib.compatibility_version),
        'timestamp': lib.timestamp,
    })

# Segments & sections
report['segments'] = []
for seg in binary.segments:
    s = {
        'name': seg.name.strip('\x00'),
        'vm_address': hex(seg.virtual_address),
        'vm_size': seg.virtual_size,
        'file_size': seg.file_size,
        'sections': []
    }
    for sec in seg.sections:
        s['sections'].append({
            'name': sec.section_name.strip('\x00'),
            'size': sec.size,
            'type': str(sec.type),
        })
    report['segments'].append(s)

# Entitlements / code signature
for cmd in binary.code_signature.commands if binary.has_code_signature else []:
    pass
report['has_code_signature'] = binary.has_code_signature
report['has_uuid'] = binary.has_uuid

# Exported symbols count
exports = list(binary.exported_symbols)
imports = list(binary.imported_symbols)
report['exported_symbols_count'] = len(exports)
report['imported_symbols_count'] = len(imports)

# ObjC classes
try:
    report['objc_classes_count'] = len(binary.objc_classes)
except Exception as e:
    report['objc_classes_count'] = -1
    report['objc_err'] = str(e)

# Main binary class names
try:
    def demang(x):
        try: return x.demangled_name
        except Exception: return None
    classes = sorted(set((c.demangled_name or c.name) for c in binary.objc_classes))
    report['objc_classes'] = classes
except Exception as e:
    report['objc_classes'] = []
    report['objc_err2'] = str(e)

# Categories
try:
    cats = set()
    for c in binary.objc_categories:
        cats.add(c.demangled_name if c.demangled_name else c.name)
    report['objc_categories'] = sorted(cats)
except Exception:
    report['objc_categories'] = []

# Protocols
try:
    protos = sorted(set(p.demangled_name if p.demangled_name else p.name for p in binary.objc_protocols))
    report['objc_protocols_count'] = len(protos)
except Exception:
    report['objc_protocols_count'] = 0

# Swift metadata
report['has_swift'] = any('__TEXT' in seg.name for seg in () ) or cmds.get('LCSegment', 0) > 0

with open(sys.argv[2], 'w') as f:
    json.dump(report, f, indent=1, default=str)

print(f"CPU: {report['header']['cpu_type']}")
print(f"Arch slices: {report['architectures']}")
print(f"ObjC classes: {report['objc_classes_count']}")
print(f"Categories: {len(report['objc_categories'])}")
print(f"Exports: {report['exported_symbols_count']} | Imports: {report['imported_symbols_count']}")
print(f"Linked libs: {len(report['linked_libraries'])}")
for lib in report['linked_libraries']:
    print(f"  - {lib['name']}")
