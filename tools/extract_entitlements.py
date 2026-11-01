#!/usr/bin/env python3
"""Extract entitlements XML from a Mach-O binary's embedded CMS signature"""
import sys

def main():
    if len(sys.argv) < 2:
        print('usage: extract_entitlements.py <macho-binary>')
        return 1
    path = sys.argv[1]
    data = open(path, 'rb').read()
    idx = data.find(b'<?xml version="1.0"')
    if idx == -1:
        print('No entitlements found in binary (not signed?)')
        return 1
    end = data.find(b'</plist>', idx)
    if end == -1:
        print('Malformed entitlements plist')
        return 1
    blob = data[idx:end + len(b'</plist>')]
    out = sys.argv[2] if len(sys.argv) > 2 else 'entitlements.xml'
    open(out, 'wb').write(blob)
    print(blob.decode('utf-8', 'ignore'))
    return 0

if __name__ == '__main__':
    sys.exit(main())
