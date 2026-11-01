#!/usr/bin/env python3
"""Categorized strings extraction: URLs, endpoints, keys, Tor config, security findings"""
import re, json, sys
from collections import defaultdict

def extract(path, minlen=6):
    data = open(path, 'rb').read()
    strs = set()
    for m in re.finditer(rb'[\x20-\x7e]{%d,}' % minlen, data):
        strs.add(m.group().decode())
    return strs

app = extract('ipa/Payload/OnionBrowser.app/OnionBrowser')
out = defaultdict(list)

patterns = {
    'urls': re.compile(r'https?://[^\s"\'<>]{4,}'),
    'onion_services': re.compile(r'[a-z2-7]{16,56}\.onion'),
    'tor_config_keys': re.compile(r'\b(SocksPort|ControlPort|UseBridges|ClientTransportPlugin|Bridge|DataDirectory|CookieAuthentication|HashedControlPassword|NumEntryGuards|EnforceDistinctSubnets|UseEntryGuards|StrictNodes|AllowSingleHopCircuits|ConnectionPadding|ReducedConnectionPadding|MaxCircuitDirtiness|GeoIPFile|ClientDNSRejectInternalAddresses|AutomapHostsOnResolve|NumDirectoryGuards|GuardLifetime|DormantClientTimeout|UseMicrodescriptors|PathBias|Vanguards)\b'),
    'transport_plugins': re.compile(r'\b(obfs4|snowflake|meek_lite|webtunnel|conjure|lyrebird|DTLS|STUN)\b'),
    'api_endpoints': re.compile(r'(/api/[a-zA-Z0-9_/\-\.]+)'),
    'prefs_keys': re.compile(r'(com\.miketigas[a-zA-Z0-9_\.]*|[Oo]nionBrowser[a-zA-Z0-9_\.]*)'),
    'blocklist_refs': re.compile(r'(stevenblack|hagezi|oisd|light-onlydomains|universityofbbb|UT1)[a-zA-Z0-9_\-\./]*', re.I),
    'crypto_refs': re.compile(r'\b(ed25519|x25519|curve25519|aes|sha256|sha1|hmac|pbkdf2|scrypt|ntruprime|kyber|cbc|ctr)\b', re.I),
    'keychain': re.compile(r'\b(kSecClass|kSecAttrService|kSecAttrAccessible|SecItem[A-Za-z]+)\b'),
    'trackers': re.compile(r'\b(google-analytics|doubleclick|facebook|graph\.facebook|appsflyer|adjust\.com|branch\.io|mixpanel|crashlytics|firebase)[a-zA-Z0-9\.\-_]*', re.I),
}

for s in app:
    for cat, rx in patterns.items():
        for m in rx.finditer(s):
            val = m.group() if isinstance(m.group(), str) else m.group(0)
            if val not in out[cat]:
                out[cat].append(val)

for cat in out:
    out[cat] = sorted(out[cat])[:200]

json.dump(out, open('strings_analysis.json', 'w'), indent=1)
for cat, vals in out.items():
    print(f'== {cat}: {len(vals)}')
    for v in vals[:12]:
        print('   ', v[:150])
