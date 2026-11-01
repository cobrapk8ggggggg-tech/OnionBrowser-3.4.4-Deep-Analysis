#!/usr/bin/env python3
"""Merge binary ObjC dump with Swift source ground truth"""
import re, os, json

# 1. Parse Swift source: class -> superclass
src_root = 'source/OnionBrowser'
class_map = {}
for root, dirs, files in os.walk(src_root):
    for f in files:
        if f.endswith('.swift'):
            content = open(os.path.join(root, f), encoding='utf-8', errors='ignore').read()
            for m in re.finditer(r'(?:public |open |final |)\bclass (\w+)\s*:\s*([^{]+)', content):
                name, supers = m.group(1), m.group(2).split(',')[0].strip()
                class_map[name] = supers
# Objective-C sources too
for root, dirs, files in os.walk(src_root):
    for f in files:
        if f.endswith(('.h', '.m')):
            content = open(os.path.join(root, f), encoding='utf-8', errors='ignore').read()
            for m in re.finditer(r'@interface\s+(\w+)\s*:\s*(\w+)', content):
                class_map[m.group(1)] = m.group(2)

# Pod classes (from Podfile)
pods = {}
if os.path.exists('source/Podfile'):
    for line in open('source/Podfile'):
        m = re.match(r"\s*pod '(\w+)'", line)
        if m: pods[m.group(1)] = True

# 2. Load binary dump
dump = json.load(open('dump/objc_classes.json'))
demangle = lambda n: n
bind_map = {}   # ordinal -> supername (derived)
mismatches = []

for c in dump['classes']:
    raw = c['name']
    # demangle _TtC12OnionBrowser23BookmarksViewController
    m = re.match(r'_TtC\d+(\w+?)(\d+)(\w+)$', raw)
    if m:
        mod, ln, cls = m.group(1), int(m.group(2)), m.group(3)
        short = cls
    else:
        short = raw
    c['short_name'] = short
    sup = c['super']
    if isinstance(sup, str) and sup.startswith('BIND:'):
        ordinal = int(sup[5:])
        if short in class_map:
            s = class_map[short]
            if ordinal in bind_map and bind_map[ordinal] != s:
                mismatches.append((ordinal, bind_map[ordinal], s))
            bind_map[ordinal] = s
            c['super_resolved'] = s
        else:
            c['super_resolved'] = f'?external(ordinal {ordinal})'
    elif sup and sup != '?':
        c['super_resolved'] = sup
    else:
        c['super_resolved'] = class_map.get(short, '?')

print('bind ordinal map:', {hex(k): v for k, v in sorted(bind_map.items())})
print('mismatches:', mismatches)

# 3. Fix dump supers and re-save
for c in dump['classes']:
    if c.get('super_resolved'):
        c['super'] = c['super_resolved']
json.dump(dump, open('dump/objc_classes.json', 'w'), indent=1)

# 4. Regenerate readable header + classnames
with open('dump/OnionBrowser_dumped.h', 'w') as f:
    f.write('// OnionBrowser 3.4.4 — class dump (binary-extracted, source-verified)\n')
    f.write('// 130 ObjC/Swift classes from the main executable\n\n')
    for c in sorted(dump['classes'], key=lambda x: x['name']):
        f.write(f"@interface {c['short_name']} : {c['super']}\n")
        for n, t in c['ivars']:
            if '?' not in (n, t): f.write(f"    {t} {n};\n")
        if any('?' not in (n, t) for n, t in c['ivars']): f.write('\n')
        for n, t in c['props']:
            if '?' not in (n, t): f.write(f"    @property {t} {n};\n")
        if any('?' not in (n, t) for n, t in c['props']): f.write('\n')
        for n, t in c['methods']:
            f.write(f"    {t} {n};\n")
        f.write('@end\n\n')
with open('dump/classnames.txt', 'w') as f:
    for c in sorted(dump['classes'], key=lambda x: x['name']):
        f.write(f"{c['short_name']} : {c['super']} ({len(c['methods'])} methods)\n")
print('done')
