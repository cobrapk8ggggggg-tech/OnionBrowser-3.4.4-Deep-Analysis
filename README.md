# 🔬 Onion Browser 3.4.4 — التحليل الهندسي العميق الشامل

> **Repository**: تحليل عكسي (Reverse Engineering) كامل لتطبيق [Onion Browser](https://github.com/OnionBrowser/OnionBrowser) الإصدار **3.4.4** لنظام iOS
> **الملف المصدر**: `com.miketigas.OnionBrowser-3.4.4-eeveedecrypter.ipa` (مفكوك التشفير — decrypted)
> **الحزمة**: `com.miketigas.OnionBrowser` | **الفريق**: `68QUP6KP2C` | **iOS الأدنى**: 15.0

---

## 📋 نظرة سريعة

| البند | القيمة |
|---|---|
| الثنائي الرئيسي | `OnionBrowser` — Mach-O ARM64 واحد (26,015,008 بايت) |
| الفئات المستخرجة | **130 فئة** ObjC/Swift + **551 محدد (selector)** |
| الأطر المضمنة | 9 أطر (Tor, IPtProxy, OrbotKit, SwiftSoup...) |
| حزمة Tor | Tor 409.14.1 + GeoIP (geoip + geoip6 ~26MB) |
| نظام التشغيل بُني عليه | Xcode 27.1 SDK / iOS 27.1 (حديث جداً) |
| الصلاحيات الخاصة | `web-browser` + `siri` + `NSFileProtectionComplete` |
| المتتبعات | **صفر** — لا توجد أي مكتبات تتبع خارجية ✅ |

## 🗂️ محتويات المستودع

```
├── REPORT.ar.md                ← التقرير الكامل بالعربية (اقرأ هذا!)
├── class-dump/                 ← تفريغ الفئات (class dump) من الثنائي
│   ├── OnionBrowser_dumped.h   ← واجهات بأسلوب class-dump لكل الفئات والخصائص والدوال
│   ├── classnames.txt          ← الفئات مع التسلسل الوراثي
│   ├── selectors.txt           ← 551 محدد
│   ├── objc_classes.json       ← بيانات خام JSON
│   └── Tor.framework/          ← تفريغ Tor.framework (TORController, TORConfiguration...)
├── analysis/
│   ├── binary_report.json      ← بنية Mach-O الكاملة (segments/sections/dylibs)
│   ├── strings_analysis.json   ← سلاسل نصية مصنفة (روابط، تكوين Tor، تشفير...)
│   ├── entitlements.xml        ← الصلاحيات المستخرجة من التوقيع
│   ├── info_plist.json         ← Info.plist كامل
│   ├── structure.txt           ← شجرة الحزمة الكاملة
│   └── hashes.json             ← بصمات SHA-256 لكل الثنائيات
├── tools/                      ← أدوات التحليل (Python — بدون اعتماديات macOS!)
│   ├── objc_dump.py            ← مفكك فئات ObjC مخصص يدعم chained fixups و iOS 18+ selref-relative
│   ├── analyze_binary.py       ← محلل Mach-O عبر LIEF
│   ├── strings_analysis.py     ← ماسح سلاسل مصنف أمنياً
│   └── map_hierarchies.py      ← دمج الثنائي مع الكود المصدري الرسمي
└── .github/workflows/          ← أتمتة CI/CD قوية
    ├── deep-analysis.yml       ← تحليل ثنائي كامل تلقائي (أي IPA عبر رابط)
    ├── security-audit.yml      ← فحص أمني دوري أسبوعي (أسرار، روابط، خدمات onion)
    └── verify-source.yml       ← مقارنة الثنائي مقابل الكود المصدري للكشف عن التعديلات
```

## 🚀 GitHub Actions — أتمتة التحليل

1. **`deep-analysis.yml`** — قم بتشغيله يدوياً مع رابط أي ملف IPA → يقوم بـ:
   - استخراج الحزمة وتحليل ثنائي Mach-O (LIEF)
   - تفريغ كل فئات ObjC/Swift بأداة `objc_dump.py` المخصصة
   - فحص أمني للسلاسل (روابط، خدمات onion، مفاتيح)
   - رفع النتائج كـ artifacts + commit تلقائي في `analysis/ci-runs/`

2. **`security-audit.yml`** — فحص أسبوعي مجدول: أسرار مسربة، مخزون شبكي، بصمات جسور Tor

3. **`verify-source.yml`** — يستنسخ الكود المصدري الرسمي v3.4.4 ويقارنه بتفريغ الثنائي
   للكشف عن **أي فئة موجودة في الثنائي غير موجودة في المصدر** (مؤشر على تعديل خفي)

## 🔧 الأداة المميزة: `objc_dump.py`

مفكك فئات Objective-C/Swift مكتوب من الصفر بلغة Python يعمل على **Linux بدون macOS**:

- ✅ فك **dyld chained fixups** (تنسيقات `PTR_64_OFFSET` والـ binds عبر جدول imports)
- ✅ دعم **relative method lists** (iOS 14+)
- ✅ دعم **selref-relative method lists** (iOS 18+ — جديد!): فك السلسلة `method → selref slot → selector string`
- ✅ فك الخصائص `@property` بكامل معاملاتها (`T@"UITableView",N,&,V...`)
- ✅ دمج التسلسل الوراثي مع الكود المصدري الرسمي للتحقق

## ⚖️ ملاحظة قانونية

Onion Browser **مفتوح المصدر** رخصة [MIT](https://github.com/OnionBrowser/OnionBrowser/blob/main/LICENSE).
هذا المستودع لأغراض تعليمية/أمنية بحتة — التطبيق المرفق كان مفكوك التشفير أصلاً ولا نوزع أي ثنائيات هنا.
