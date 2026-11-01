# 🔬 التقرير التحليلي الشامل — Onion Browser 3.4.4 لنظام iOS

> **التطبيق**: Onion Browser 3.4.4 (`com.miketigas.OnionBrowser`)
> **المنشئ**: Tigas Ventures, LLC (Mike Tigas) — بتمويل من Guardian Project
> **طريقة التحليل**: تفكيك ثنائي Mach-O عبر أدوات مخصصة (LIEF + Python) + مقارنة بالكود المصدري الرسمي (v3.4.4) + فحص الموارد والصلاحيات والتوقيع

---

## الفهرس

1. [نظرة عامة على الحزمة](#1-نظرة-عامة-على-الحزمة)
2. [الثنائي الرئيسي: بنية Mach-O](#2-الثنائي-الرئيسي-بنية-mach-o)
3. [الصلاحيات (Entitlements) والتوقيع](#3-الصلاحيات-entitlements-والتوقيع)
4. [معمارية Tor — قلب التطبيق](#4-معمارية-tor--قلب-التطبيق)
5. [تجاوز الحجب: الجسور والنواقل](#5-تجاوز-الحجب-الجسور-والنواقل)
6. [محرك التصفح: تبويبات WKWebView](#6-محرك-التصفح-تبويبات-wkwebview)
7. [الحماية ومستويات الأمان](#7-الحماية-ومستويات-الأمان)
8. [حاجب المحتوى وقوائم الحظر](#8-حاجب-المحتوى-وقوائم-الحظر)
9. [الخصوصية: البصمة ومزيف User-Agent](#9-الخصوصية-البصمة-ومزيف-user-agent)
10. [التخزين الآمن و Secure Enclave](#10-التخزين-الآمن-و-secure-enclave)
11. [التكامل مع Orbot](#11-التكامل-مع-orbot)
12. [App Intents و Siri](#12-app-intents-و-siri)
13. [الإعدادات وإعدادات المواقع الفردية](#13-الإعدادات-وإعدادات-المواقع-الفردية)
14. [العربات (Bookmarks) ومدير الدوائر](#14-العربات-bookmarks-ومدير-الدوائر)
15. [شهادات TLS ومعالجة ALT-SVC](#15-شهادات-tls-ومعالجة-alt-svc)
16. [الأطر المضمنة التسعة](#16-الأطر-المضمنة-التسعة)
17. [التدويل: 33 لغة بينها العربية](#17-التدويل-33-لغة-بينها-العربية)
18. [تدفق الإقلاع الكامل](#18-تدفق-الإقلاع-الكامل)
19. [الفئات الـ 130 كاملة](#19-الفئات-الـ-130-كاملة)
20. [نتائج الفحص الأمني](#20-نتائج-الفحص-الأمني)
21. [الخلاصة](#21-الخلاصة)

---

## 1. نظرة عامة على الحزمة

الملف `.ipa` حاوية ZIP تحتوي:

```
Payload/OnionBrowser.app/
├── OnionBrowser                  ← الثنائي الرئيسي 26MB (ARM64 فقط)
├── Info.plist                    ← بيانات الحزمة والصلاحيات الوظيفية
├── Assets.car                    ← الأيقونات والصور المجمّعة (17.4MB)
├── Frameworks/                   ← 9 أطر ديناميكية
│   ├── Tor.framework (10.8MB + GeoIP.bundle 26MB)
│   ├── IPtProxy.framework (Go runtime لجسور Tor)
│   ├── OrbotKit.framework (SDK للتكامل مع Orbot)
│   ├── SwiftSoup.framework (2MB — HTML parser)
│   └── DTFoundation, FavIcon, MBProgressHUD, SDCAlertView, TUSafariActivity
├── IPtProxyUI_IPtProxyUI-Shared.bundle ← تكوينات الجسور + DNS لكل دولة
├── *.nib                         ← 19 واجهة UI مجمّعة
├── SearchEngines.plist           ← محركات البحث (DuckDuckGo عبر onion!)
├── ua-strings.plist              ← بصمات User-Agent المزيفة
├── content-rules.json            ← قواعد حاجب المحتوى
├── light-onlydomains.txt         ← قائمة حظر 1.3MB (HaGeZi)
├── credits.html, security-levels.html, start.html
├── PrivacyInfo.xcprivacy         ← بيان الخصوصية لـ Apple
├── Metadata.appintents           ← تعريفات Siri/App Intents
└── 33 مجلد لغة (ar.lproj موجودة ✅)
```

**الإصدار**: 3.4.4 (build 168466.412098550) — بُني بـ **Xcode 27.1 SDK** (أحدث سلسلة أدوات) والحد الأدنى **iOS 15.0**، يدعم iPhone + iPad (UIDeviceFamily: 1,2) مع تعدد النوافذ (Multiple Scenes).

**بصمة SHA-256 لملف IPA الأصلي** موجودة في `analysis/hashes.json`.

---

## 2. الثنائي الرئيسي: بنية Mach-O

الثنائي `OnionBrowser` — **شريحة ARM64 واحدة** (ليس fat binary — حجم أصغر):

| Segment | العنوان الافتراضي | الحجم | المحتوى |
|---|---|---|---|
| `__PAGEZERO` | 0x0 | 4GB (محمي) | حماية مؤشرات null |
| `__TEXT` | 0x100000000 | 21MB | الكود + `__objc_methlist` + بيانات Swift 5 |
| `__DATA_CONST` | 0x10141c000 | 2.7MB | `__objc_classlist`, `__objc_protolist`, GOT |
| `__DATA` | 0x1016bc000 | 1.1MB | `__objc_data`, selrefs, classrefs |
| `__LINKEDIT` | 0x103830000 | 1MB | الرموز + التوقيع |

### اكتشاف تقني مهم: أدوات بناء حديثة جداً
- القسم `__objc_methlist` موجود في **`__TEXT`** وليس `__DATA` — هذا تنسيق "method lists كاملة النسبية" الجديد
- قوائم الدوال تستخدم **selref-relative naming** (iOS 18+): كل إدخال طريقة `{delta→selref, delta→types, delta→imp}` حيث يشير delta إلى **فجوة selref** في `__DATA` تحتاج فك مزدوج
- قسم `__objc_stubs` في `__TEXT` — استدعاءات ObjC محسّنة (Xcode 16+)
- `LC_DYLD_CHAINED_FIXUPS` بدل LC_DYLD_INFO — ربط مؤشرات بسلاسل (chained fixups) بتنسيق `DYLD_CHAINED_PTR_64_OFFSET`

### ما استخرجناه من الثنائي
- **130 فئة** ObjC/Swift (بأسماء Swift المنحلة مثل `_TtC12OnionBrowser23BookmarksViewController` → `BookmarksViewController`)
- **551 محدد** بأكواد الأنواع الكاملة (`@32@0:8@16@24` = دالة ترجع object وتستقبل objectين)
- **1782 استيراد** ديناميكي (chained fixups imports)
- **19 قائمة دوال** نسبية في `__objc_methlist`
- بيانات انعكاس Swift كاملة: `__swift5_types`, `__swift5_fieldmd`, `__swift5_reflstr` وغيرها

التفاصيل الكاملة: `analysis/binary_report.json`

---

## 3. الصلاحيات (Entitlements) والتوقيع

المستخرجة من كتلة CMS داخل التوقيع (`analysis/entitlements.xml`):

| الصلاحية | القيمة | الدلالة |
|---|---|---|
| `com.apple.developer.web-browser` | ✅ | **صلاحية المتصفح النظام** — تسمح بأن يكون المتصفح الافتراضي، وإبقاء اتصالات الشبكة حية في الخلفية (ضروري لـ Tor) |
| `com.apple.developer.siri` | ✅ | تكامل Siri و App Shortcuts |
| `com.apple.developer.default-data-protection` | `NSFileProtectionComplete` | **تشفير كامل** لكل ملفات التطبيق — لا تُفك إلا بعد أول فتح للجهاز |
| `application-identifier` | `68QUP6KP2C.com.miketigas.OnionBrowser` | فريق التطوير الرسمي |

من `Info.plist` الإضافية:
- **URL Schemes**: يُسجل نفسه كمعالج لـ `http`, `https`, `onionhttp`, `onionhttps` (متصفح نظام) + `onionbrowser` (deep links)
- **`LSApplicationQueriesSchemes: orbot`** — يفحص وجود تطبيق Orbot
- **`NSAllowsArbitraryLoads: true`** — إلزامي للوصول لخدمات onion
- **NSCameraUsageDescription**: "لازمة لقراءة عناوين الجسور من رموز QR"
- **NSFaceIDUsageDescription**: لقفل التطبيق ببصمة الوجه
- **`UIFileSharingEnabled: true`** — مشاركة ملفات عبر تطبيق الملفات
- **Quick Actions** على الشاشة الرئيسية: "New Tab" و "Clear Data" (إغلاق التبويبات ومسح البيانات)
- `ITSAppUsesNonExemptEncryption: false` (الإعفاء من تصدير التشفير)

---

## 4. معمارية Tor — قلب التطبيق

### الطبقات الثلاث:

```
┌─────────────────────────────────────────────────────┐
│  TorManager (Swift) — منسق التشغيل عالي المستوى      │
│  ├─ وضع مدمج: TORThread → tor daemon (C)           │
│  └─ وضع Orbot: OrbotKit → IPC لتطبيق Orbot         │
├─────────────────────────────────────────────────────┤
│  Tor.framework (409.14.1) — غلاف ObjC               │
│  ├─ TORController — التحكم عبر ControlPort         │
│  ├─ TORConfiguration — بناء torrc برمجياً          │
│  ├─ TORThread — daemon في خيط منفصل                │
│  ├─ TORCircuit/TORNode — عرض الدوائر               │
│  ├─ TORAuthKey/TOROnionAuth — مفاتيح v3 onion      │
│  └─ TORX25519KeyPair — توليد مفاتيح Ed25519/X25519 │
├─────────────────────────────────────────────────────┤
│  tor daemon (C/C) — 10.8MB داخل Tor.framework      │
│  + geoip/geoip6 (26MB) لعرض بلد كل عقدة             │
└─────────────────────────────────────────────────────┘
```

### تفاصيل من الثنائي (strings) والمصدر:
- **SocksPort**: يُفتح على منفذ عشوائي محلي (loopback فقط)
- **ControlPort**: يتصل عبر **cookie authentication** (مقبس Unix) — استخدمنا `TORController` بمسار كوكي
- مفتاح torrc المُولَّد: `Bridge`, `ClientTransportPlugin`, `UseBridges`, `StrictNodes`
- **Vanguards**: إعدادات حماية من هجمات ربط الدوائر (circuit linkage) عبر قيود `GuardLifetime`/`NumEntryGuards`
- `GeoIPFile` → يشير إلى GeoIP.bundle لعرض **بلد كل عقدة في الدائرة** (شاشة CircuitViewController)

### وضعا التشغيل:
1. **المدمج (Built-in Tor)**: `TORThread` يشغّل daemon tor حقيقي داخل التطبيق — الكود الكامل في `TorManager.swift` (وضع `Status: stopped → starting → started`)
2. **Orbot الخارجي**: يكتشف Orbot عبر `LSApplicationQueriesSchemes` + `onionbrowser://`، ويستخدم `OrbotKit` (SDK من Guardian Project) للتحكم — بما فيه إغلاق دوائر محددة!

---

## 5. تجاوز الحجب: الجسور والنواقل

أقوى جزء في التطبيق — 7 نواقل pluggable transports داخل IPtProxy (Go):

| الناقل | الوصف | ملاحظات من التحليل |
|---|---|---|
| `obfs4` (lyrebird) | تشويش عشوائي للحزم | جسور مدمجة بـ certs حقيقية في `builtin-bridges.json` |
| `snowflake` | WebRTC / DTLS / STUN | جسور موزعة عبر متطوعين ومشغلي CDN |
| `meek_lite` | التمويه عبر CDN | مدمج: `cdn77.org` مموّه كـ `www.phpmyadmin.net` + `utls=HelloRandomizedALPN` |
| `webtunnel` | يبدو ك HTTPS عادي | أحدث النواقل |
| `conjure` | عبور عبر registerrnal | Experimental |
| `DTLS`/`STUN` | بروتوكولات snowflake الأساسية | مذكورة في strings |

### الملفات الداعمة:
- **`builtin-bridges.json`**: جسور obfs4 مدمجة بمعرفات وشهادات كاملة، منها:
  ```
  obfs4 51.222.13.177:80 5EDAC3B810E12B01F6FD8050D2FD3E277B289A08 cert=2uplIpLQ0q9+...
  obfs4 212.83.43.74:443 39562501228A4D5E27FCA4C0C81A01EE23AE3EE4 cert=PBwr+S8JTVZo...
  meek_lite 192.0.2.20:80 url=https://1603026938.rsc.cdn77.org front=www.phpmyadmin.net
  ```
- **`dns-*.json` لـ 16 دولة** (إيران 🇮🇷 الصين 🇨🇳 روسيا 🇷🇺 تركيا 🇹🇷 سوريا 🇸🇾 وغيرها): قوائم DNS عامة موصى بها لكل دولة — ملف إيران وحده 140KB (آخر تحديث: 2026-01-25!)
- **واجهة إدخال جسور يدوية + قراءة QR بالكاميرا** (`NSCameraUsageDescription`)
- IPtProxy version: `0.0.1791540005` (بناء حديث)

---

## 6. محرك التصفح: تبويبات WKWebView

### بنية `Tab` (900+ سطر في Tab.swift):
```
Tab : UIView
├── WKWebView (المتصفح الفعلي)
├── URLBlocker delegation (حجب قبل التحميل)
├── SecureMode: insecure | mixed | secure | secureEv
├── User-Agent لكل تبويب (حسب HostSettings!)
├── favicons عبر FavIcon.framework
└── ذاكرة URL عبر RefCounter/RefTracker
```

### `BrowsingViewController` — أكبر فئة (93 دالة في الثنائي!):
- شريط عنوان URL + شريط تقدم + أزرار تنقل
- **CircuitViewController**: شاشة عرض دائرة Tor الحالية (Entry → Middle → Exit) مع أعلام الدول
- بحث داخل الصفحة (LiveSearchViewController : UITableViewController)
- إدارة تعدد التبويبات (TabCell : UITableViewCell)
- معالجة `URLSchemeHandler` لطلبات `about:` و`onionbrowser://`

### معالجة الروابط (SceneDelegate — 13 دالة):
- استقبال `http://` و `https://` من النظام (يفتح التطبيق كمتصفح افتراضي)
- استقبال `onionhttp://` و `onionhttps://` (روابط onion صريحة)
- دعم تعدد النوافذ على iPad عبر `UIApplicationSceneManifest`

---

## 7. الحماية ومستويات الأمان

### نظام الدروع (SecurityShield : UIView):
| المستوى | الاسم | اللون | الوصف (من strings) |
|---|---|---|---|
| 3 | Insecure | برونزي 🟤 | "Easy breezy. Though it could be dangerous." |
| 2 | Medium | فضي ⚪ | "Works pretty well. Your identity is mostly protected." |
| 1 | Secure | ذهبي 🟡 | أعلى حماية |
| ? | Custom | accent | إعدادات يدوية لكل موقع |

- **`security-levels.html`** صفحة تفاعلية مدمجة تشرح المستويات
- **`HostSettings`** (27 دالة في الثنائي): قاعدة بيانات إعدادات **لكل نطاق على حدة** — مستوى الأمان، User-Agent، حظر الصور/الفيديو/السكربتات، الكوكيز، WebSocket، XC — تُخزن في UserDefaults باسم `com.miketigas.OnionBrowser.HostSettings`
- شعار الدرع يظهر في شريط العناوين (SecurityPopUpViewController + SecurityLevelCell)

---

## 8. حاجب المحتوى وقوائم الحظر

### طبقتان من الحجب:

1. **WKContentRuleList** (`content-rules.json`):
   ```json
   [{"trigger": {"url-filter": ".*", "resource-type": ["ping"]},
     "action": {"type": "block"}}]
   ```
   → يمنع كل طلبات hyperlink auditing (تتبع النقرات) على مستوى WebKit

2. **URLBlocker** (حجب على مستوى الشبكة قبل الإرسال عبر Tor):
   - قائمة **HaGeZi light-onlydomains** — 1.3MB نطاقات إعلانية/تتبع (light-onlydomains.txt)
   - واجهة إدارة BlocklistViewController + تفعيل/تعطيل لكل فئة
   - حجب URL بدوال تصنيف (`isBlocked(host, url)`) قبل إنشاء أي اتصال

3. **URLBlocker + SwiftSoup**: تنظيف HTML وإزالة العناصر الخطرة (باستخدام SwiftSoup 2.11.3 — بورتر Swift لـ jsoup)

---

## 9. الخصوصية: البصمة ومزيف User-Agent

### ثلاث بصمات UA جاهزة (`ua-strings.plist`):
| الاسم | القيمة |
|---|---|
| Safari Desktop | `Mozilla/5.0 (Macintosh...) Version/15.0 Safari/605.1.15` |
| Tor Browser Desktop | `Mozilla/5.0 (Windows NT 10.0; rv:78.0) Gecko/20100101 Firefox/78.0` |
| Tor Browser Mobile Android | `Mozilla/5.0 (Android 9; Mobile; rv:78.0) ... Firefox/78.0` |

- **لكل تبويب UA مختلف** حسب HostSettings (تحايل على حجب المواقع لمتصفحات الخصوصية)
- **تحسين تلقائي**: الكود يضيف `Version/15.0 ... Safari/600.1.4` ليبدو المتصفح كـ Mobile Safari الأصلي (دالة `defaultUserAgent` في Tab.swift)
- منع الوصول لخدمات الموقع/الكاميرا عبر WebKit (`WKPreferences`)
- حجب `ping` + قوائم HaGeZi = حجب نشط للتتبع
- **لا وجود لأي SDK تتبع** — الفحص أثبت صفر: (Google Analytics, Facebook SDK, Firebase, AppsFlyer...) ✅

---

## 10. التخزين الآمن و Secure Enclave

### فئة `SecureEnclave` — حماية قفل التطبيق:
- توليد زوج مفاتيح **داخل Secure Enclave** (المعالج الآمن) بعلامة `"Onion Browser".data`
- المفتاح **لا يغادر المعالج أبداً** — يُستخدم فقط بتواقيع يتحقق منها التطبيق
- فتح بـ **Face ID / Touch ID / كلمة مرور الجهاز** عبر `LAContext`
- الإعداد: `NSFileProtectionComplete` على كل الملفات

### فئات التخزين (من الثنائي):
- `WebsiteStorage` — تخزين بيانات المواقع (localStorage/cookies) مع مسح انتقائي
- `WebsiteDataStore` custom — كل تبويب له حاوية معزولة
- زر "Clear Data" (و Quick Action) → مسح كامل: تبويبات + كوكيز + كاش + تاريخ

---

## 11. التكامل مع Orbot

### `OrbotManager : NSObject, OrbotStatusChangeListener`:
- SDK **OrbotKit 1.2.0** (Guardian Project) — `OrbotKit.shared.closeCircuit(circuit:)` لإدارة دوائر Tor من تطبيق آخر!
- فحص وجود Orbot عبر فتح `orbot://` (LSApplicationQueriesSchemes)
- شاشة اختيار (`OrbotOrBuiltInViewController`): استخدام Orbot المثبت أم Tor المدمج؟
- `StartOrbotViewController` — توجيه المستخدم لتحميل Orbot (InstallViewController)

### أسباب هذا النمط المزدوج:
- Tor المدمج = استقلالية كاملة لكن بطارية أكثر
- Orbot = VPN على مستوى النظام (يحمي كل التطبيقات) لكنه تطبيق منفصل

---

## 12. App Intents و Siri

**14 Intent** كاملة (مجلد `AppIntents/` + `Metadata.appintents`):

| Intent | الوظيفة |
|---|---|
| `CreateTabIntent` | فتح تبويب جديد عبر Siri |
| `OpenUrlInTabIntent` | فتح رابط في تبويب |
| `OpenBookmarkIntent` | فتح عربة محفوظة |
| `BookmarkTabIntent` / `BookmarkUrlIntent` | حفظ الصفحة/رابط الحالي |
| `CloseTabsIntent` | إغلاق كل التبويبات |
| `ClearHistoryIntent` | مسح التاريخ |
| `DeleteBookmarksIntent` | حذف عربات |
| `SearchIntent` | بحث في الويب |
| `FindOnPageIntent` | بحث داخل الصفحة |
| `SwitchToTabIntent` | التنقل بين التبويبات |
| `TabEntity` / `BookmarkEntity` | كيانات App Shortcuts (اختيار تبويب/عربة من Siri) |

مع `NSUserActivityTypes: com.miketigas.OnionBrowser.view` للاستمرارية.

---

## 13. الإعدادات وإعدادات المواقع الفردية

شجرة واجهات الإعدادات (كلها في الثنائي كـ NIBs):
```
Settings (يورث من IPtProxyUI_Shared.Settings!)
├── SecurityViewController — مستوى الأمان العام
├── CustomSitesViewController — قائمة المواقع المخصصة
├── AddSiteViewController — إضافة موقع
├── SearchEnginesViewController — إدارة محركات البحث
├── AddSearchEngineViewController (Eureka Form!) — محرك جديد
├── BlocklistViewController — إدارة قوائم الحظر
├── Storage1ViewController / Storage2ViewController — التخزين
├── DonationViewController — الدعم المالي
└── WhyViewController — شرح "لماذا Onion Browser؟"
```

### محركات البحث (`SearchEngines.plist`):
- **DuckDuckGo (Onion)**: `duckduckgogg42xjoc72x3sjasowoarfbgcmvfimaftt6twagswzczad.onion` — كامل + `/html` + `/lite` مع autocomplete عبر onion!
- **Google**: عبر clearnet (عندما يكون المستوى الأقل صرامة)
- **Startpage**: مع POST params

---

## 14. العربات (Bookmarks) ومدير الدوائر

- **BookmarksViewController** (29 دالة): UITableViewDataSource + UIAction يدعم السحب والحذف والمشاركة (BookmarkCell : UITableViewCell)
- **NcBookmarks / NcBookmark** — تكامل مع **NextCloud Bookmarks**! ( Codable + طبقة API)
- **CircuitViewController + CircuitNodeCell** — عرض دوائر Tor الحية مع أعلام الدول (من GeoIP)
- **FavIcon framework** — استخراج أيقونة الموقع وحفظها للعربة

---

## 15. شهادات TLS ومعالجة ALT-SVC

ميزة متقدمة نادرة:
- **TlsCertificate** (23 دالة) + **TlsCertificateEntity** (16 دالة) — عرض تفاصيل شهادة الموقع (المصدر، الصلاحية، البصمة)
- **AltService + AltSvcHeader + ClearAltService** — تحليل **HTTP ALT-SVC headers**! يكشف ما إذا كان الموقع يعرض خدمة onion مكافئة ويحوّل إليها تلقائياً (مثل NYT وBBC!)
- تحقق EV (Extended Validation) في حالة `secureEv`

---

## 16. الأطر المضمنة التسعة

| الإطار | الإصدار | الوظيفة | الحجم |
|---|---|---|---|
| **Tor** | 409.14.1 | daemon tor + غلاف ObjC + GeoIP | 10.8MB + 26MB |
| **IPtProxy** | 0.0.1791540005 | Go runtime لكل النواقل (gomobile) | 35KB غلاف + Go مدمج |
| **OrbotKit** | 1.2.0 | SDK تحكم بـ Orbot | 268KB |
| **SwiftSoup** | 2.11.3 | HTML/DOM parser (Pure Swift) | 2MB |
| **DTFoundation** | 1.7.19 | أدوات iOS مساعدة (DTZone etc.) | 172KB |
| **FavIcon** | 3.1.0 | اكتشاف وتحميل favicons | 279KB |
| **MBProgressHUD** | 1.2.0 | مؤشرات التقدم | 161KB |
| **SDCAlertView** | 12.0.5 | تنبيهات مخصصة | 489KB |
| **TUSafariActivity** | 1.0.4 | مشاركة "فتح في Safari" | 91KB |

جميعها عبر **CocoaPods** (`PodsDummy_Pods_OnionBrowser` موجودة في الثنائي، و`Podfile.lock` في المصدر).

---

## 17. التدويل: 33 لغة بينها العربية

`ar.lproj` موجودة ✅ — التطبيق مترجم بالكامل للعربية (Plus: bn, ca, cs, de, el, en, es, fa, fi, fr, ga, he, hi, hr, hu, id, is, it, ja, km, ko, mk, nb, nl, pl, ps, pt-BR, pt-PT, ro, ru, sq, th, tr, tt, uk, vi, zh-Hans, zh-Hant).
ملف `IPtProxyUI-Shared.bundle` أيضاً مترجم لـ 30+ لغة.

---

## 18. تدفق الإقلاع الكامل

```
AppDelegate (11 دالة)
    │
    ▼
SceneDelegate (13 دالة) ← تعدد النوافذ
    │
    ▼
أول تشغيل فقط:
WelcomeViewController → "مرحباً"
    ↓
WhyViewController → "لماذا نستخدم Tor؟" (تعليمي)
    ↓
OrbotOrBuiltInViewController → "Orbot أم مدمج؟"
    ↓ (إن مدمج)
StartTorViewController → تشغيل daemon tor + انتظار bootstrap
    ↓
PermissionViewController → أذونات الإشعارات/الكاميرا
    ↓
BrowsingViewController → شاشة البداية (start.html)
```

تدفق التشغيل اللاحق: `TorManager.start(transport:)` → `IpSupport.shared.start()` → `TORThread.start()` → `TORController.connect(cookie:)` → مراقبة `TORControllerProgress` → جاهز (نسبة bootstrap تظهر للمستخدم).

---

## 19. الفئات الـ 130 كاملة

القائمة الكاملة مع التسلسل الوراثي والدوال في:
- `class-dump/classnames.txt` (قائمة مختصرة)
- `class-dump/OnionBrowser_dumped.h` (كامل — واجهات + خصائص + دوال + أنواع)
- `class-dump/objc_classes.json` (بيانات خام)

أبرز العائلات:

**التصفح**: BrowsingViewController (93 دالة!), Tab, TabCell, PreviewWebView (WKWebView), LiveSearchViewController, TlsCertificate
**Tor**: TorManager, OrbotManager, IPtProxyController, TORController/TORConfiguration/TORThread/TORCircuit/TORNode (من Tor.framework)
**الأمان**: URLBlocker, ContentRules, HostSettings, SecurityShield, SecureEnclave, TlsCertificateEntity
**البيانات**: Bookmark, BookmarkCell, NcBookmark(s), WebsiteStorage, RefCounter, RefTracker
**الواجهة**: EurekaFormViewController (نماذج الإعدادات), SDCAlertView, ProgressHUD, DownloadActivity, UIActivity مخصص
**Go bridge**: GoSeqRef, Universeerror (من gomobile في IPtProxy)

---

## 20. نتائج الفحص الأمني

### ✅ النتائج الإيجابية:
1. **صفر متتبعات خارجية** — لا Google Analytics ولا Facebook SDK ولا أي SDK تحليلات
2. **NSFileProtectionComplete** — تشفير ملفات بأقوى مستوى
3. **Secure Enclave** لتخزين مفاتيح القفل
4. **Cookie auth** لمنفذ تحكم Tor (لا كلمات مرور نصية)
5. قوائم حظر محدثة (HaGeZi) + حجب ping
6. تواصل Tor عبر loopback فقط
7. مفتوح المصدر بالكامل (MIT) — الثنائي يطابق المصدر (تحقق عبر workflow)

### ⚠️ ملاحظات:
1. **NSAllowsArbitraryLoads = true** — ضروري لخدمات onion لكنه يرخي ATS للمواقع العادية
2. جسور مدمجة **ثابتة في الملف** (`builtin-bridges.json`) — يمكن تعقبها وحجبها (سلوك معروف في المشروع)
3. التطبيق المفكوك — أزيل توقيع App Store الأصلي وأعيد توقيعه بأداة فك التشفير (eeveedecrypter) — كتلة التوقيع الحالية تحمل team مختلف محتمَل، تأكد دائماً من المصدر الموثوق

### 🔑 خدمات Onion المدمجة (defaults):
| الخدمة | العنوان |
|---|---|
| DuckDuckGo | duckduckgogg42xjoc72x3sjasowoarfbgcmvfimaftt6twagswzczad.onion |
| BBC News | bbcnewsd73hkzno2ini43t4gblxvycyac5aw4gnv7t2rccijh7745uqd.onion |
| BBC (v2) | bbcnewsv2vjtpsuy.onion |
| Facebook | facebookcorewwwi.onion + facebookwkhpilnemxj7asaniu7vnjjbiltxjqhye3mhbshg7kx5tfyd.onion |
| NYT | p53lf57qovyuvwsc6xnrppyply3vtqm7l6pcobkmyqsiofyeznfu5uqd.onion |
| ProtonMail | juhanurmihxlp77nkq76byazcldy2hlmovfu2epvl5ankdibsot4csyd.onion |
| Deutsche Welle | dwnewsgngmhlplxy6o2twtfgjnrnjxbegbwqx6wnotdhkzt562tszfid.onion |
| Tor Project | 2gzyxa5ihm7nsggfxnu52rck2vv4rvmdlkiu3zzui5du4xyclen53wid.onion |
| SecureDrop | fpfjxcrmw437h6z2xl3w4czl55kvkmxpapg37bbopsafdu7q454byxid.onion |

---

## 21. الخلاصة

Onion Browser 3.4.4 هو **متصفح خصوصية بنية ناضجة ومحكمة**:

1. **Tor حقيقي مدمج** (daemon كامل 10.8MB) — ليس غلافاً لواجهة ويب
2. **7 نواقل تجاوز حجب** — تغطية شاملة للدول الممارسة للرقابة (ملفات DNS لـ 16 دولة!)
3. **حماية متعددة الطبقات**: حجب شبكي (URLBlocker) + حجب WebKit (ContentRuleList) + مزيف UA + إعدادات لكل موقع
4. **خصوصية مادية**: Secure Enclave + FileProtectionComplete + صفر متتبعات
5. **حداثة تقنية**: أحدث أدوات بناء (iOS 27.1 SDK)، selref-relative method lists، App Intents كاملة
6. **شفافية**: مفتوح المصدر بالكامل ويتطابق مع الثنائي

### منهجية التحليل المستخدمة هنا:
1. **تفكيك ثنائي مستقل** (LIEF + مفكك مخصص بلغة Python) — بدون اعتماد على المصدر
2. **استخراج كتلة entitlements من التوقيع CMS** يدوياً
3. **فك chained fixups + selref-relative lists** (تقنيات iOS 15-18+)
4. **مطابقة تسلسل وراثي bind-ordinal مع المصدر الرسمي** — تقنية جديدة للتحقق من الثنائي مقابل المصدر
5. **فحص سلاسل مصنف** (URLs/onion/config/crypto/trackers)

كل الأدوات مرفوعة في `tools/` وقابلة لإعادة التشغيل عبر GitHub Actions على أي IPA جديد.
