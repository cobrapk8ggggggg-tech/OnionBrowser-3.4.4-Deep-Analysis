// OnionBrowser 3.4.4 - class dump (binary-extracted + source-verified)
// 130 ObjC/Swift classes, 551 selectors

@interface EurekaBaseCell : UITableViewCell
    @24@0:8@16 initWithCoder:;
    @32@0:8q16@24 initWithStyle:reuseIdentifier:;
    v16@0:8 .cxx_destruct;
@end

@interface EurekaFormViewController : UITableViewController
    @property T@"UITableView",N,&,VtableView tableView;

    v16@0:8 navigationDone;
    v16@0:8 navigationPrevious;
    v16@0:8 navigationNext;
    v32@0:8@16@24 pressesBegan:withEvent:;
    v24@0:8@16 keyboardWillShow:;
    v24@0:8@16 keyboardWillHide:;
    v24@0:8@16 scrollViewWillBeginDragging:;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    @32@0:8@16q24 tableView:titleForHeaderInSection:;
    @32@0:8@16q24 tableView:titleForFooterInSection:;
    @24@0:8@16 sectionIndexTitlesForTableView:;
    q40@0:8@16@24q32 tableView:sectionForSectionIndexTitle:atIndex:;
    @32@0:8@16@24 tableView:willSelectRowAtIndexPath:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    d32@0:8@16@24 tableView:heightForRowAtIndexPath:;
    d32@0:8@16@24 tableView:estimatedHeightForRowAtIndexPath:;
    @32@0:8@16q24 tableView:viewForHeaderInSection:;
    @32@0:8@16q24 tableView:viewForFooterInSection:;
    d32@0:8@16q24 tableView:heightForHeaderInSection:;
    d32@0:8@16q24 tableView:heightForFooterInSection:;
    B32@0:8@16@24 tableView:canEditRowAtIndexPath:;
    v40@0:8@16q24@32 tableView:commitEditingStyle:forRowAtIndexPath:;
    B32@0:8@16@24 tableView:canMoveRowAtIndexPath:;
    @40@0:8@16@24@32 tableView:targetIndexPathForMoveFromRowAtIndexPath:toProposedIndexPath:;
    v40@0:8@16@24@32 tableView:moveRowAtIndexPath:toIndexPath:;
    q32@0:8@16@24 tableView:editingStyleForRowAtIndexPath:;
    B32@0:8@16@24 tableView:shouldIndentWhileEditingRowAtIndexPath:;
    @32@0:8@16@24 tableView:leadingSwipeActionsConfigurationForRowAtIndexPath:;
    @32@0:8@16@24 tableView:trailingSwipeActionsConfigurationForRowAtIndexPath:;
    @32@0:8@16@24 tableView:editActionsForRowAtIndexPath:;
    @16@0:8 tableView;
    v24@0:8@16 setTableView:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v20@0:8B16 viewWillDisappear:;
    v32@0:8@16@24 prepareForSegue:sender:;
    v32@0:8@16@24 tableView:willBeginReorderingRowAtIndexPath:;
    v16@0:8 .cxx_destruct;
@end

@interface EurekaNavigationAccessoryView : UIView
    @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 initWithFrame:;
    @24@0:8@16 initWithCoder:;
    v32@0:8@16@24 touchesBegan:withEvent:;
    v16@0:8 didTapDone;
    v16@0:8 didTapNext;
    v16@0:8 didTapPrevious;
    v16@0:8 .cxx_destruct;
@end

@interface GoSeqRef : NSObject
    @property Ti,R,V_refnum refnum;
    @property T@,&,V_obj obj;

    @16@0:8 init;
    i16@0:8 incNum;
    @28@0:8i16@20 initWithRefnum:obj:;
    v16@0:8 dealloc;
    i16@0:8 refnum;
    @16@0:8 obj;
    v24@0:8@16 setObj:;
    v16@0:8 .cxx_destruct;
@end

@interface IPtProxyController : NSObject
    @property T@,R,V__ref _ref;
    @property T@"NSString",&,N snowflakeIceServers;
    @property T@"NSString",&,N snowflakeBrokerUrl;
    @property T@"NSString",&,N snowflakeFrontDomains;
    @property T@"NSString",&,N snowflakeAmpCacheUrl;
    @property T@"NSString",&,N snowflakeSqsUrl;
    @property T@"NSString",&,N snowflakeSqsCreds;
    @property Tq,N snowflakeMaxPeers;

    @24@0:8@16 initWithRef:;
    @48@0:8@16B24B28@32@40 init:enableLogging:unsafeLogging:logLevel:transportEvents:;
    @16@0:8 snowflakeIceServers;
    v24@0:8@16 setSnowflakeIceServers:;
    @16@0:8 snowflakeBrokerUrl;
    v24@0:8@16 setSnowflakeBrokerUrl:;
    @16@0:8 snowflakeFrontDomains;
    v24@0:8@16 setSnowflakeFrontDomains:;
    @16@0:8 snowflakeAmpCacheUrl;
    v24@0:8@16 setSnowflakeAmpCacheUrl:;
    @16@0:8 snowflakeSqsUrl;
    v24@0:8@16 setSnowflakeSqsUrl:;
    @16@0:8 snowflakeSqsCreds;
    v24@0:8@16 setSnowflakeSqsCreds:;
    q16@0:8 snowflakeMaxPeers;
    v24@0:8q16 setSnowflakeMaxPeers:;
    @24@0:8@16 localAddress:;
    q24@0:8@16 port:;
    B40@0:8@16@24^@32 start:proxy:error:;
    @16@0:8 stateDir;
    v24@0:8@16 stop:;
    @16@0:8 _ref;
    v16@0:8 .cxx_destruct;
@end

@interface IPtProxyOnTransportEvents : NSObject
    @property T@,R,V__ref _ref;
    @property TQ,R hash;
    @property T#,R superclass;
    @property T@"NSString",R,C description;
    @property T@"NSString",?,R,C debugDescription;

    @24@0:8@16 initWithRef:;
    v24@0:8@16 connected:;
    v32@0:8@16@24 error:error:;
    v32@0:8@16@24 stopped:error:;
    @16@0:8 _ref;
    v16@0:8 .cxx_destruct;
@end

@interface IPtProxySnowflakeClientEvents : NSObject
    @property T@,R,V__ref _ref;
    @property TQ,R hash;
    @property T#,R superclass;
    @property T@"NSString",R,C description;
    @property T@"NSString",?,R,C debugDescription;

    @24@0:8@16 initWithRef:;
    v16@0:8 connected;
    v16@0:8 connectionFailed;
    v24@0:8@16 disconnected:;
    v24@0:8@16 natTypeUpdated:;
    v72@0:8q16q24q32q40@48@56q64 stats:failedConnectionCount:inboundBytes:outboundBytes:inboundUnit:outboundUnit:summaryInterval:;
    @16@0:8 _ref;
    v16@0:8 .cxx_destruct;
@end

@interface IPtProxySnowflakeProxy : NSObject
    @property T@,R,V__ref _ref;
    @property Tq,N capacity;
    @property T@"NSString",&,N brokerUrl;
    @property T@"NSString",&,N relayUrl;
    @property Tq,N ephemeralMinPort;
    @property Tq,N ephemeralMaxPort;
    @property T@"NSString",&,N stunServer;
    @property T@"NSString",&,N natProbeUrl;
    @property Tq,N natTypeMeasurementInterval;
    @property Tq,N pollInterval;
    @property T@"<IPtProxySnowflakeClientEvents>",&,N clientEvents;
    @property T@"NSString",&,N proxyTypeIdentifier;
    @property Tq,N summaryInterval;
    @property T@"NSString",&,N covertDTLSConfig;

    @24@0:8@16 initWithRef:;
    @16@0:8 init;
    q16@0:8 capacity;
    v24@0:8q16 setCapacity:;
    @16@0:8 brokerUrl;
    v24@0:8@16 setBrokerUrl:;
    @16@0:8 relayUrl;
    v24@0:8@16 setRelayUrl:;
    q16@0:8 ephemeralMinPort;
    v24@0:8q16 setEphemeralMinPort:;
    q16@0:8 ephemeralMaxPort;
    v24@0:8q16 setEphemeralMaxPort:;
    @16@0:8 stunServer;
    v24@0:8@16 setStunServer:;
    @16@0:8 natProbeUrl;
    v24@0:8@16 setNatProbeUrl:;
    q16@0:8 natTypeMeasurementInterval;
    v24@0:8q16 setNatTypeMeasurementInterval:;
    q16@0:8 pollInterval;
    v24@0:8q16 setPollInterval:;
    @16@0:8 clientEvents;
    v24@0:8@16 setClientEvents:;
    @16@0:8 proxyTypeIdentifier;
    v24@0:8@16 setProxyTypeIdentifier:;
    q16@0:8 summaryInterval;
    v24@0:8q16 setSummaryInterval:;
    @16@0:8 covertDTLSConfig;
    v24@0:8@16 setCovertDTLSConfig:;
    B16@0:8 isRunning;
    B24@0:8^@16 start:;
    v16@0:8 stop;
    @16@0:8 _ref;
    v16@0:8 .cxx_destruct;
@end

@interface PodsDummy_Pods_OnionBrowser : NSObject
@end

@interface RefCounter : NSObject
    @property T@,R,V_obj obj;
    @property Ti,V_cnt cnt;

    @24@0:8@16 initWithObject:;
    @16@0:8 obj;
    i16@0:8 cnt;
    v20@0:8i16 setCnt:;
    v16@0:8 .cxx_destruct;
@end

@interface RefTracker : NSObject
    @16@0:8 init;
    v20@0:8i16 dec:;
    v20@0:8i16 inc:;
    @20@0:8i16 get:;
    i24@0:8@16 assignRefnumAndIncRefcount:;
    v16@0:8 .cxx_destruct;
@end

@interface TlsCertificateEntity : NSObject
    @property T@"NSDictionary",N,C data;
    @property T@"NSString",N,R commonName;
    @property T@"NSString",N,R sn;
    @property T@"NSString",N,R serialNumber;
    @property T@"NSString",N,R country;
    @property T@"NSString",N,R locality;
    @property T@"NSString",N,R state;
    @property T@"NSString",N,R address;
    @property T@"NSString",N,R organization;
    @property T@"NSString",N,R orgUnit;
    @property T@"NSString",N,R businessCategory;
    @property T@"NSString",N,R postalCode;

    @16@0:8 data;
    v24@0:8@16 setData:;
    @16@0:8 commonName;
    @16@0:8 sn;
    @16@0:8 serialNumber;
    @16@0:8 country;
    @16@0:8 locality;
    @16@0:8 state;
    @16@0:8 address;
    @16@0:8 organization;
    @16@0:8 orgUnit;
    @16@0:8 businessCategory;
    @16@0:8 postalCode;
    v32@0:8@16@24 add::;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface URLBlocker : NSObject
    @property T@"NSArray",N,C hosts;
    @property T@"NSString",N,C title;
    @property T@"NSString",N,C desc;
    @property T@"NSString",N,C modified;

    @16@0:8 hosts;
    v24@0:8@16 setHosts:;
    @16@0:8 title;
    v24@0:8@16 setTitle:;
    @16@0:8 desc;
    v24@0:8@16 setDesc:;
    @16@0:8 modified;
    v24@0:8@16 setModified:;
    @16@0:8 init;
    v16@0:8 reload;
    @32@0:8@16@24 blockRuleFor:withMain:;
    @24@0:8@16 isDisabledWithHost:;
    v32@0:8@16@24 disableWithHost:with:;
    v24@0:8@16 enableWithHost:;
    v16@0:8 .cxx_destruct;
@end

@interface Universeerror : NSObject
    @property T@,R,V__ref _ref;
    @property TQ,R hash;
    @property T#,R superclass;
    @property T@"NSString",R,C description;
    @property T@"NSString",?,R,C debugDescription;

    @24@0:8@16 initWithRef:;
    @16@0:8 error;
    @16@0:8 _ref;
    v16@0:8 .cxx_destruct;
@end

@interface ProgressHUD : UIView
    v24@0:8@16 setupPosition:;
    v16@0:8 hideBanner;
    @16@0:8 init;
    @24@0:8@16 initWithCoder:;
    @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 initWithFrame:;
    v16@0:8 .cxx_destruct;
@end

@interface ProgressView : UIView
    @24@0:8@16 initWithCoder:;
    @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 initWithFrame:;
    v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 drawRect:;
    v16@0:8 .cxx_destruct;
@end

@interface _9ABE1711070ADE038BFFDAEC45D4730612BundleFinder : NSObject
@end

@interface AltService : NSObject
    @property T@"NSString",N,R protocolId;
    @property T@"NSString",N,R host;
    @property Tq,N,R,Vport port;
    @property Tq,N,R,VmaxAge maxAge;
    @property TB,N,R,Vpersist persist;
    @property T@"NSDate",N,R maxAgeAbsolute;
    @property Tq,N,R hash;
    @property T@"NSString",N,R description;

    @16@0:8 protocolId;
    @16@0:8 host;
    q16@0:8 port;
    q16@0:8 maxAge;
    B16@0:8 persist;
    @16@0:8 maxAgeAbsolute;
    @52@0:8@16@24q32q40B48 initWithProtocolId:host:port:maxAge:persist:;
    q16@0:8 hash;
    B24@0:8@16 isEqual:;
    @16@0:8 description;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface NcBookmark : Codable
@end

@interface TorManager : NSObject
@end

@interface AlertHelper : NSObject
@end

@interface AppDelegate : NSObject
    @property T@"NSArray",N,R browsingUis;

    @16@0:8 browsingUis;
    B32@0:8@16@24 application:willFinishLaunchingWithOptions:;
    v32@0:8@16@24 application:didDiscardSceneSessions:;
    v24@0:8@16 applicationWillTerminate:;
    B32@0:8@16@24 application:shouldAllowExtensionPointIdentifier:;
    B32@0:8@16@24 application:shouldRestoreSecureApplicationState:;
    B32@0:8@16@24 application:shouldRestoreApplicationState:;
    B32@0:8@16@24 application:shouldSaveApplicationState:;
    B32@0:8@16@24 application:shouldSaveSecureApplicationState:;
    v24@0:8@16 applicationDidReceiveMemoryWarning:;
    @16@0:8 init;
@end

@interface NcBookmarks : NSObject
@end

@interface AltSvcHeader : NSObject
    @property T@"NSArray",N,C services;
    @property T@"NSString",N,R description;

    @16@0:8 services;
    v24@0:8@16 setServices:;
    @24@0:8@16 initWithToken:;
    @24@0:8@16 initWithHeaders:;
    @24@0:8@16 init:;
    @16@0:8 description;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface BookmarkCell : UITableViewCell
    @property T@"UIImageView",N,W,ViconImg iconImg;
    @property T@"NSLayoutConstraint",N,W,ViconWidth iconWidth;
    @property T@"UILabel",N,W,VnameLb nameLb;
    @property T@"NSLayoutConstraint",N,W,VnameLeading nameLeading;

    @16@0:8 iconImg;
    v24@0:8@16 setIconImg:;
    @16@0:8 iconWidth;
    v24@0:8@16 setIconWidth:;
    @16@0:8 nameLb;
    v24@0:8@16 setNameLb:;
    @16@0:8 nameLeading;
    v24@0:8@16 setNameLeading:;
    @32@0:8q16@24 initWithStyle:reuseIdentifier:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface ContentRules : NSObject
@end

@interface HostSettings : NSObject
    @property T@"NSString",N,R host;
    @property TB,N ignoreTlsErrors;
    @property TB,N whitelistCookies;
    @property TB,N blockInsecureHttp;
    @property TB,N universalLinkProtection;
    @property TB,N followOnionLocationHeader;
    @property T@"NSString",N,C userAgent;
    @property TB,N javaScript;
    @property TB,N lockdownMode;
    @property TB,N orientationAndMotion;
    @property TB,N mediaCapture;
    @property TB,N linkPreview;

    @16@0:8 host;
    B16@0:8 ignoreTlsErrors;
    v20@0:8B16 setIgnoreTlsErrors:;
    B16@0:8 whitelistCookies;
    v20@0:8B16 setWhitelistCookies:;
    B16@0:8 blockInsecureHttp;
    v20@0:8B16 setBlockInsecureHttp:;
    B16@0:8 universalLinkProtection;
    v20@0:8B16 setUniversalLinkProtection:;
    B16@0:8 followOnionLocationHeader;
    v20@0:8B16 setFollowOnionLocationHeader:;
    @16@0:8 userAgent;
    v24@0:8@16 setUserAgent:;
    B16@0:8 javaScript;
    v20@0:8B16 setJavaScript:;
    B16@0:8 lockdownMode;
    v20@0:8B16 setLockdownMode:;
    B16@0:8 orientationAndMotion;
    v20@0:8B16 setOrientationAndMotion:;
    B16@0:8 mediaCapture;
    v20@0:8B16 setMediaCapture:;
    B16@0:8 linkPreview;
    v20@0:8B16 setLinkPreview:;
    @28@0:8@16B24 initFor:withDefaults:;
    #16@0:8 save;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface OrbotManager : NSObject
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface SceneDelegate : UIResponder
    @property T@"UIWindow",N,&,Vwindow window;
    @property T@"_TtC12OnionBrowser22BrowsingViewController",N,& browsingUi;

    @16@0:8 window;
    v24@0:8@16 setWindow:;
    @16@0:8 browsingUi;
    v24@0:8@16 setBrowsingUi:;
    v40@0:8@16@24@32 scene:willConnectToSession:options:;
    v24@0:8@16 sceneDidBecomeActive:;
    v40@0:8@16@24@?32 windowScene:performActionForShortcutItem:completionHandler:;
    v32@0:8@16@24 scene:openURLContexts:;
    v24@0:8@16 sceneWillResignActive:;
    v24@0:8@16 sceneDidDisconnect:;
    @24@0:8@16 stateRestorationActivityForScene:;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface SecureEnclave : NSObject
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface DownloadHelper : NSObject
@end

@interface FileTranslator : NSObject
@end

@interface PreviewWebView : WKWebView
    @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48 initWithFrame:configuration:;
    @24@0:8@16 initWithCoder:;
    @24@0:8@16 loadRequest:;
    v48@0:8@16@24@32@?40 webView:decidePolicyForNavigationAction:preferences:decisionHandler:;
    v40@0:8@16@24@?32 webView:didReceiveAuthenticationChallenge:completionHandler:;
    v40@0:8@16@24@?32 webView:authenticationChallenge:shouldAllowDeprecatedTLS:;
    v32@0:8@16@24 webView:didFinishNavigation:;
    v40@0:8@16@24@32 webView:didFailNavigation:withError:;
    v40@0:8@16@24@32 webView:didFailProvisionalNavigation:withError:;
    v24@0:8@16 webViewWebContentProcessDidTerminate:;
@end

@interface SecurityShield : UIView
    @24@0:8@16 initWithCoder:;
    v24@0:8@16 encodeWithCoder:;
    @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 initWithFrame:;
    v16@0:8 .cxx_destruct;
@end

@interface TlsCertificate : NSObject
    @property Tq,N,Vversion version;
    @property T@"NSString",N,C serialNumber;
    @property T@"NSString",N,C signatureAlgorithm;
    @property T@"TlsCertificateEntity",N,&,Vissuer issuer;
    @property T@"NSDate",N,C validityNotBefore;
    @property T@"NSDate",N,C validityNotAfter;
    @property T@"TlsCertificateEntity",N,&,Vsubject subject;
    @property TB,N,VisEv isEv;
    @property T@"NSString",N,C evOrgName;
    @property TB,N,R hasWeakSignatureAlgorithm;
    @property TB,N,R isExpired;

    q16@0:8 version;
    v24@0:8q16 setVersion:;
    @16@0:8 serialNumber;
    v24@0:8@16 setSerialNumber:;
    @16@0:8 signatureAlgorithm;
    v24@0:8@16 setSignatureAlgorithm:;
    @16@0:8 issuer;
    v24@0:8@16 setIssuer:;
    @16@0:8 validityNotBefore;
    v24@0:8@16 setValidityNotBefore:;
    @16@0:8 validityNotAfter;
    v24@0:8@16 setValidityNotAfter:;
    @16@0:8 subject;
    v24@0:8@16 setSubject:;
    B16@0:8 isEv;
    v20@0:8B16 setIsEv:;
    @16@0:8 evOrgName;
    v24@0:8@16 setEvOrgName:;
    B16@0:8 hasWeakSignatureAlgorithm;
    B16@0:8 isExpired;
    @24@0:8@16 initWithData:;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface WebsiteStorage : NSObject
@end

@interface BlurredSnapshot : NSObject
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface CircuitNodeCell : UITableViewCell
    @property T@"UIView",N,W,VtopLink topLink;
    @property T@"UIView",N,W,VbottomLink bottomLink;
    @property T@"UILabel",N,W,VtextLb textLb;

    @16@0:8 topLink;
    v24@0:8@16 setTopLink:;
    @16@0:8 bottomLink;
    v24@0:8@16 setBottomLink:;
    @16@0:8 textLb;
    v24@0:8@16 setTextLb:;
    @32@0:8q16@24 initWithStyle:reuseIdentifier:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface ClearAltService : _TtC12OnionBrowser10AltService
    @property Tq,N,R hash;
    @property T@"NSString",N,R description;

    @16@0:8 init;
    q16@0:8 hash;
    B24@0:8@16 isEqual:;
    @16@0:8 description;
    @52@0:8@16@24q32q40B48 initWithProtocolId:host:port:maxAge:persist:;
@end

@interface DownloadActivity : UIActivity
    @property T@"NSString",N,R activityType;
    @property T@"NSString",N,R activityTitle;
    @property T@"UIImage",N,R activityImage;

    @16@0:8 activityType;
    @16@0:8 activityTitle;
    @16@0:8 activityImage;
    B24@0:8@16 canPerformWithActivityItems:;
    v24@0:8@16 prepareWithActivityItems:;
    v16@0:8 performActivity;
    v48@0:8@16@24@32@?40 URLSession:task:didReceiveChallenge:completionHandler:;
    v40@0:8@16@24@32 URLSession:task:didCompleteWithError:;
    v40@0:8@16@24@32 URLSession:downloadTask:didFinishDownloadingToURL:;
    v56@0:8@16@24q32q40q48 URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:;
    v16@0:8 cancel;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface MozillaBookmarks : NSObject
@end

@interface SecurityLevelCell : UITableViewCell
    @property T@"UIImageView",N,W,VshieldImg shieldImg;
    @property T@"UILabel",N,W,VnumberLb numberLb;
    @property T@"UILabel",N,W,VnameLb nameLb;
    @property T@"UILabel",N,W,VexplanationLb explanationLb;
    @property T@"UILabel",N,W,VradioLb radioLb;

    v16@0:8 awakeFromNib;
    @16@0:8 shieldImg;
    v24@0:8@16 setShieldImg:;
    @16@0:8 numberLb;
    v24@0:8@16 setNumberLb:;
    @16@0:8 nameLb;
    v24@0:8@16 setNameLb:;
    @16@0:8 explanationLb;
    v24@0:8@16 setExplanationLb:;
    @16@0:8 radioLb;
    v24@0:8@16 setRadioLb:;
    v24@0:8B16B20 setSelected:animated:;
    @32@0:8q16@24 initWithStyle:reuseIdentifier:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface WhyViewController : UIViewController
    @property T@"UILabel",N,W,Vtitle1Lb title1Lb;
    @property T@"UILabel",N,W,Vbody1Lb body1Lb;
    @property T@"UILabel",N,W,Vbody2Lb body2Lb;
    @property T@"UILabel",N,W,Vbody3Lb body3Lb;
    @property T@"UILabel",N,W,Vbody4Lb body4Lb;
    @property T@"UILabel",N,W,Vbody5Lb body5Lb;
    @property T@"UILabel",N,W,Vbody6Lb body6Lb;
    @property T@"UILabel",N,W,Vbody7Lb body7Lb;
    @property T@"UIButton",N,W,Vbutton1 button1;
    @property T@"UILabel",N,W,Vtitle2Lb title2Lb;
    @property T@"UILabel",N,W,Vbody8Lb body8Lb;
    @property T@"UILabel",N,W,Vbody9Lb body9Lb;
    @property T@"UILabel",N,W,Vbody10Lb body10Lb;
    @property T@"UILabel",N,W,Vbody11Lb body11Lb;
    @property T@"UILabel",N,W,Vbody12Lb body12Lb;
    @property T@"UIButton",N,W,Vbutton2 button2;

    @16@0:8 title1Lb;
    v24@0:8@16 setTitle1Lb:;
    @16@0:8 body1Lb;
    v24@0:8@16 setBody1Lb:;
    @16@0:8 body2Lb;
    v24@0:8@16 setBody2Lb:;
    @16@0:8 body3Lb;
    v24@0:8@16 setBody3Lb:;
    @16@0:8 body4Lb;
    v24@0:8@16 setBody4Lb:;
    @16@0:8 body5Lb;
    v24@0:8@16 setBody5Lb:;
    @16@0:8 body6Lb;
    v24@0:8@16 setBody6Lb:;
    @16@0:8 body7Lb;
    v24@0:8@16 setBody7Lb:;
    @16@0:8 button1;
    v24@0:8@16 setButton1:;
    @16@0:8 title2Lb;
    v24@0:8@16 setTitle2Lb:;
    @16@0:8 body8Lb;
    v24@0:8@16 setBody8Lb:;
    @16@0:8 body9Lb;
    v24@0:8@16 setBody9Lb:;
    @16@0:8 body10Lb;
    v24@0:8@16 setBody10Lb:;
    @16@0:8 body11Lb;
    v24@0:8@16 setBody11Lb:;
    @16@0:8 body12Lb;
    v24@0:8@16 setBody12Lb:;
    @16@0:8 button2;
    v24@0:8@16 setButton2:;
    v16@0:8 viewDidLoad;
    v24@0:8@16 action:;
    v16@0:8 close;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface SyncViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillDisappear:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface AddBookmarkActivity : UIActivity
    @property T@"NSString",N,R activityType;
    @property T@"NSString",N,R activityTitle;
    @property T@"UIImage",N,R activityImage;

    @16@0:8 activityType;
    @16@0:8 activityTitle;
    @16@0:8 activityImage;
    B24@0:8@16 canPerformWithActivityItems:;
    v24@0:8@16 prepareWithActivityItems:;
    v16@0:8 performActivity;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface UpdateAdvertisement : NSObject
@end

@interface FolderViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillDisappear:;
    v16@0:8 addNew;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface AddSiteViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v16@0:8 add;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface CircuitViewController : UIViewController
    @property T@"UILabel",N,W,VheaderLb headerLb;
    @property T@"UITableView",N,W,VtableView tableView;
    @property T@"UIView",N,W,VnoCircuitsView noCircuitsView;
    @property T@"UILabel",N,W,VnoCircuitsLb1 noCircuitsLb1;
    @property T@"UILabel",N,W,VnoCircuitsLb2 noCircuitsLb2;
    @property T@"UIButton",N,W,VnewCircuitsBt newCircuitsBt;
    @property T@"UIButton",N,W,VbridgeConfigBt bridgeConfigBt;
    @property T{CGSize=dd},N preferredContentSize;

    @16@0:8 headerLb;
    v24@0:8@16 setHeaderLb:;
    @16@0:8 tableView;
    v24@0:8@16 setTableView:;
    @16@0:8 noCircuitsView;
    v24@0:8@16 setNoCircuitsView:;
    @16@0:8 noCircuitsLb1;
    v24@0:8@16 setNoCircuitsLb1:;
    @16@0:8 noCircuitsLb2;
    v24@0:8@16 setNoCircuitsLb2:;
    @16@0:8 newCircuitsBt;
    v24@0:8@16 setNewCircuitsBt:;
    @16@0:8 bridgeConfigBt;
    v24@0:8@16 setBridgeConfigBt:;
    {CGSize=dd}16@0:8 preferredContentSize;
    v32@0:8{CGSize=dd}16 setPreferredContentSize:;
    v16@0:8 viewDidLoad;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    d32@0:8@16@24 tableView:heightForRowAtIndexPath:;
    q24@0:8@16 adaptivePresentationStyleForPresentationController:;
    v16@0:8 newCircuits;
    v24@0:8@16 showBridgeSelection:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface HistoryViewController : UITableViewController
    v16@0:8 viewDidLoad;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v16@0:8 _dismiss;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface InstallViewController : UIViewController
    @property T@"UIButton",N,W,VbackBt backBt;
    @property T@"UILabel",N,W,VtitleLb titleLb;
    @property T@"UILabel",N,W,VbodyLb bodyLb;
    @property T@"UIButton",N,W,VgetOrbotBt getOrbotBt;
    @property T@"UIButton",N,W,VwhyBt whyBt;

    @16@0:8 backBt;
    v24@0:8@16 setBackBt:;
    @16@0:8 titleLb;
    v24@0:8@16 setTitleLb:;
    @16@0:8 bodyLb;
    v24@0:8@16 setBodyLb:;
    @16@0:8 getOrbotBt;
    v24@0:8@16 setGetOrbotBt:;
    @16@0:8 whyBt;
    v24@0:8@16 setWhyBt:;
    v16@0:8 viewDidLoad;
    v16@0:8 back;
    v16@0:8 action;
    v16@0:8 why;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface WelcomeViewController : UIViewController
    @property T@"UILabel",N,W,VtitleLb titleLb;
    @property T@"UILabel",N,W,VbodyLb bodyLb;
    @property T@"UIButton",N,W,VnextBt nextBt;

    @16@0:8 titleLb;
    v24@0:8@16 setTitleLb:;
    @16@0:8 bodyLb;
    v24@0:8@16 setBodyLb:;
    @16@0:8 nextBt;
    v24@0:8@16 setNextBt:;
    v16@0:8 next;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface BaseNavigationDelegate : NSObject
@end

@interface BookmarkViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillDisappear:;
    v16@0:8 addNew;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface BrowsingViewController : UIViewController
    @property Tq,N,R preferredStatusBarStyle;
    @property T@"NSArray",N,R keyCommands;
    @property T@"UIView",N,W,VsearchBar searchBar;
    @property T@"NSLayoutConstraint",N,W,VsearchBarHeightConstraint searchBarHeightConstraint;
    @property T@"UIButton",N,W,VsecurityBt securityBt;
    @property T@"UITextField",N,W,VsearchFl searchFl;
    @property T@"UIButton",N,W,VtorBt torBt;
    @property T@"UIProgressView",N,W,Vprogress progress;
    @property T@"UIView",N,W,Vcontainer container;
    @property T@"NSLayoutConstraint",N,W,VcontainerBottomConstraint2Toolbar containerBottomConstraint2Toolbar;
    @property T@"UICollectionView",N,W,VtabsCollection tabsCollection;
    @property T@"UIView",N,W,Vtoolbar toolbar;
    @property T@"NSLayoutConstraint",N,W,VtoolbarHeightConstraint toolbarHeightConstraint;
    @property T@"UIStackView",N,W,VmainTools mainTools;
    @property T@"UIView",N,W,VtabsTools tabsTools;
    @property T@"UIButton",N,W,VbackBt backBt;
    @property T@"UIButton",N,W,VfrwrdBt frwrdBt;
    @property T@"UIButton",N,W,VfindBt findBt;
    @property T@"UIButton",N,W,VactionBt actionBt;
    @property T@"UIButton",N,W,VbookmarksBt bookmarksBt;
    @property T@"UIButton",N,W,VnewTabBt newTabBt;
    @property T@"UIButton",N,W,VtabsBt tabsBt;
    @property T@"UIButton",N,W,VsettingsBt settingsBt;
    @property T@"UIButton",N,W,VnewTabFromOverviewBt newTabFromOverviewBt;
    @property T@"UIButton",N,W,VhideOverviewBt hideOverviewBt;
    @property T@"NSArray",N,C tabs;
    @property T@"_TtC12OnionBrowser3Tab",N,W currentTab;

    @16@0:8 keyCommands;
    v24@0:8@16 handle:;
    q16@0:8 preferredStatusBarStyle;
    v16@0:8 showOverview;
    v16@0:8 newTabFromOverview;
    v16@0:8 hideOverview;
    q32@0:8@16q24 collectionView:numberOfItemsInSection:;
    @32@0:8@16@24 collectionView:cellForItemAtIndexPath:;
    v32@0:8@16@24 collectionView:didSelectItemAtIndexPath:;
    {CGSize=dd}40@0:8@16@24@32 collectionView:layout:sizeForItemAtIndexPath:;
    @40@0:8@16@24@32 collectionView:itemsForBeginningDragSession:atIndexPath:;
    @40@0:8@16@24@32 collectionView:dropSessionDidUpdate:withDestinationIndexPath:;
    v32@0:8@16@24 collectionView:performDropWithCoordinator:;
    v24@0:8@16 scrollViewDidScrollToTop:;
    v24@0:8@16 scrollViewDidScroll:;
    B32@0:8@16@24 gestureRecognizer:shouldRequireFailureOfGestureRecognizer:;
    v24@0:8@16 showHistory:;
    v24@0:8@16 textFieldDidBeginEditing:;
    B24@0:8@16 textFieldShouldReturn:;
    v32@0:8@16q24 textFieldDidEndEditing:reason:;
    v16@0:8 searchDidChange;
    @16@0:8 searchBar;
    v24@0:8@16 setSearchBar:;
    @16@0:8 searchBarHeightConstraint;
    v24@0:8@16 setSearchBarHeightConstraint:;
    @16@0:8 securityBt;
    v24@0:8@16 setSecurityBt:;
    @16@0:8 searchFl;
    v24@0:8@16 setSearchFl:;
    @16@0:8 torBt;
    v24@0:8@16 setTorBt:;
    @16@0:8 progress;
    v24@0:8@16 setProgress:;
    @16@0:8 container;
    v24@0:8@16 setContainer:;
    @16@0:8 containerBottomConstraint2Toolbar;
    v24@0:8@16 setContainerBottomConstraint2Toolbar:;
    @16@0:8 tabsCollection;
    v24@0:8@16 setTabsCollection:;
    @16@0:8 toolbar;
    v24@0:8@16 setToolbar:;
    @16@0:8 toolbarHeightConstraint;
    v24@0:8@16 setToolbarHeightConstraint:;
    @16@0:8 mainTools;
    v24@0:8@16 setMainTools:;
    @16@0:8 tabsTools;
    v24@0:8@16 setTabsTools:;
    @16@0:8 backBt;
    v24@0:8@16 setBackBt:;
    @16@0:8 frwrdBt;
    v24@0:8@16 setFrwrdBt:;
    @16@0:8 findBt;
    v24@0:8@16 setFindBt:;
    @16@0:8 actionBt;
    v24@0:8@16 setActionBt:;
    @16@0:8 bookmarksBt;
    v24@0:8@16 setBookmarksBt:;
    @16@0:8 newTabBt;
    v24@0:8@16 setNewTabBt:;
    @16@0:8 tabsBt;
    v24@0:8@16 setTabsBt:;
    @16@0:8 settingsBt;
    v24@0:8@16 setSettingsBt:;
    @16@0:8 newTabFromOverviewBt;
    v24@0:8@16 setNewTabFromOverviewBt:;
    @16@0:8 hideOverviewBt;
    v24@0:8@16 setHideOverviewBt:;
    @16@0:8 tabs;
    v24@0:8@16 setTabs:;
    @16@0:8 currentTab;
    v24@0:8@16 setCurrentTab:;
    @16@0:8 init;
    @24@0:8@16 initWithCoder:;
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v20@0:8B16 viewDidAppear:;
    v20@0:8B16 viewWillDisappear:;
    v24@0:8@16 encodeRestorableStateWithCoder:;
    v24@0:8@16 decodeRestorableStateWithCoder:;
    v24@0:8@16 action:;
    v16@0:8 showBookmarks;
    @16@0:8 showSettings;
    v24@0:8@16 keyboardWillShowWithNotification:;
    v24@0:8@16 keyboardWillBeHiddenWithNotification:;
    @32@0:8@16@24 addNewTab:configuration:;
    v16@0:8 becomesVisible;
    v16@0:8 addEmptyTabAndFocus;
    v24@0:8q16 switchToTab:;
    v16@0:8 removeCurrentTab;
    v16@0:8 removeAllTabs;
    v16@0:8 focusSearchField;
    @32@0:8@16@24 initWithNibName:bundle:;
    v16@0:8 .cxx_destruct;
@end

@interface DonationViewController : UITableViewController
    @16@0:8 init;
    v16@0:8 viewDidLoad;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16q24 tableView:titleForHeaderInSection:;
    @32@0:8@16q24 tableView:titleForFooterInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v32@0:8@16@24 productsRequest:didReceiveResponse:;
    v32@0:8@16@24 paymentQueue:updatedTransactions:;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface SecurityViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillDisappear:;
    v40@0:8@16@24q32 tableView:willDisplayHeaderView:forSection:;
    v16@0:8 _dismiss;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface SettingsViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v16@0:8 dismsiss_;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface StartTorViewController : UIViewController
    @property T@"UILabel",N,W,VtitleLb titleLb;
    @property T@"UIActivityIndicatorView",N,W,VactivityIndicator activityIndicator;
    @property T@"UIButton",N,W,VretryBt retryBt;
    @property T@"UIProgressView",N,W,VprogressView progressView;
    @property T@"UILabel",N,W,VstatusLb statusLb;
    @property T@"UIButton",N,W,VbridgesBt bridgesBt;

    @16@0:8 titleLb;
    v24@0:8@16 setTitleLb:;
    @16@0:8 activityIndicator;
    v24@0:8@16 setActivityIndicator:;
    @16@0:8 retryBt;
    v24@0:8@16 setRetryBt:;
    @16@0:8 progressView;
    v24@0:8@16 setProgressView:;
    @16@0:8 statusLb;
    v24@0:8@16 setStatusLb:;
    @16@0:8 bridgesBt;
    v24@0:8@16 setBridgesBt:;
    v20@0:8B16 viewDidAppear:;
    v16@0:8 retry;
    v16@0:8 configureBridges;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface Storage1ViewController : _TtC12OnionBrowser29SearchableTableViewController
    @16@0:8 init;
    @24@0:8@16 initWithCoder:;
    v16@0:8 viewDidLoad;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    d32@0:8@16q24 tableView:heightForHeaderInSection:;
    @32@0:8@16q24 tableView:viewForHeaderInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    B32@0:8@16@24 tableView:canEditRowAtIndexPath:;
    v40@0:8@16q24@32 tableView:commitEditingStyle:forRowAtIndexPath:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v24@0:8@16 updateSearchResultsForSearchController:;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    v16@0:8 .cxx_destruct;
@end

@interface Storage2ViewController : UITableViewController
    v16@0:8 viewDidLoad;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface BlocklistViewController : UIViewController
    @property T@"UILabel",N,W,VenableLb enableLb;
    @property T@"UISwitch",N,W,VenableSw enableSw;
    @property T@"UITableView",N,W,VtableView tableView;

    @16@0:8 enableLb;
    v24@0:8@16 setEnableLb:;
    @16@0:8 enableSw;
    v24@0:8@16 setEnableSw:;
    @16@0:8 tableView;
    v24@0:8@16 setTableView:;
    @16@0:8 init;
    @24@0:8@16 initWithCoder:;
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillDisappear:;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16q24 tableView:titleForHeaderInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    B32@0:8@16@24 tableView:canEditRowAtIndexPath:;
    v40@0:8@16q24@32 tableView:commitEditingStyle:forRowAtIndexPath:;
    @32@0:8@16@24 tableView:titleForDeleteConfirmationButtonForRowAtIndexPath:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v24@0:8@16 updateSearchResultsForSearchController:;
    v16@0:8 update;
    v16@0:8 toggleBlocker;
    @32@0:8@16@24 initWithNibName:bundle:;
    v16@0:8 .cxx_destruct;
@end

@interface BookmarksViewController : UIViewController
    @property T@"UITableView",N,W,VtableView tableView;
    @property T@"UIToolbar",N,W,Vtoolbar toolbar;

    @16@0:8 tableView;
    v24@0:8@16 setTableView:;
    @16@0:8 toolbar;
    v24@0:8@16 setToolbar:;
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v20@0:8B16 viewWillDisappear:;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    d32@0:8@16@24 tableView:heightForRowAtIndexPath:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    B32@0:8@16@24 tableView:canEditRowAtIndexPath:;
    B32@0:8@16@24 tableView:canMoveRowAtIndexPath:;
    @40@0:8@16@24@32 tableView:targetIndexPathForMoveFromRowAtIndexPath:toProposedIndexPath:;
    v40@0:8@16q24@32 tableView:commitEditingStyle:forRowAtIndexPath:;
    v40@0:8@16@24@32 tableView:moveRowAtIndexPath:toIndexPath:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v24@0:8@16 updateSearchResultsForSearchController:;
    v32@0:8@16@24 documentPicker:didPickDocumentsAtURLs:;
    v16@0:8 dismiss_;
    v24@0:8@16 exportBookmarksWithSender:;
    v16@0:8 importBookmarks;
    v16@0:8 add;
    v16@0:8 addFolder;
    v16@0:8 edit;
    v16@0:8 showSyncScene;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface FixedFormViewController : EurekaFormViewController
    v24@0:8@16 keyboardWillShow:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
@end

@interface LiveSearchViewController : UITableViewController
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16q24 tableView:titleForHeaderInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    v40@0:8@16@24q32 tableView:willDisplayHeaderView:forSection:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v16@0:8 hide;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface PermissionViewController : UIViewController
    @property T@"UIButton",N,W,VbacktBt backtBt;
    @property T@"UIImageView",N,W,VstatusIv statusIv;
    @property T@"UILabel",N,W,VtitleLb titleLb;
    @property T@"UILabel",N,W,Vbody1Lb body1Lb;
    @property T@"UILabel",N,W,Vbody2Lb body2Lb;
    @property T@"NSLayoutConstraint",N,W,Vbody2Top body2Top;
    @property T@"UILabel",N,W,Vbody3Lb body3Lb;
    @property T@"UILabel",N,W,Vbody4Lb body4Lb;
    @property T@"UIButton",N,W,VrequestAccessBt requestAccessBt;
    @property T@"UIButton",N,W,VwhyBt whyBt;

    @16@0:8 backtBt;
    v24@0:8@16 setBacktBt:;
    @16@0:8 statusIv;
    v24@0:8@16 setStatusIv:;
    @16@0:8 titleLb;
    v24@0:8@16 setTitleLb:;
    @16@0:8 body1Lb;
    v24@0:8@16 setBody1Lb:;
    @16@0:8 body2Lb;
    v24@0:8@16 setBody2Lb:;
    @16@0:8 body2Top;
    v24@0:8@16 setBody2Top:;
    @16@0:8 body3Lb;
    v24@0:8@16 setBody3Lb:;
    @16@0:8 body4Lb;
    v24@0:8@16 setBody4Lb:;
    @16@0:8 requestAccessBt;
    v24@0:8@16 setRequestAccessBt:;
    @16@0:8 whyBt;
    v24@0:8@16 setWhyBt:;
    v20@0:8B16 viewWillAppear:;
    v16@0:8 back;
    v16@0:8 action;
    v16@0:8 why;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface StartOrbotViewController : UIViewController
    @property T@"UILabel",N,W,VtitleLb titleLb;
    @property T@"UILabel",N,W,VbodyLb bodyLb;
    @property T@"UIButton",N,W,VstartOrbotBt startOrbotBt;
    @property T@"UIButton",N,W,VstartBuiltInTorBt startBuiltInTorBt;
    @property T@"UIButton",N,W,VwhyBt whyBt;

    @16@0:8 titleLb;
    v24@0:8@16 setTitleLb:;
    @16@0:8 bodyLb;
    v24@0:8@16 setBodyLb:;
    @16@0:8 startOrbotBt;
    v24@0:8@16 setStartOrbotBt:;
    @16@0:8 startBuiltInTorBt;
    v24@0:8@16 setStartBuiltInTorBt:;
    @16@0:8 whyBt;
    v24@0:8@16 setWhyBt:;
    v20@0:8B16 viewWillAppear:;
    v24@0:8@16 action:;
    v16@0:8 why;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface CertificateViewController : UITableViewController
    v16@0:8 viewDidLoad;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16q24 tableView:titleForHeaderInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    v16@0:8 done;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface CustomSitesViewController : _TtC12OnionBrowser29SearchableTableViewController
    @16@0:8 init;
    @24@0:8@16 initWithCoder:;
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    q24@0:8@16 numberOfSectionsInTableView:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16q24 tableView:titleForHeaderInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    B32@0:8@16@24 tableView:canEditRowAtIndexPath:;
    v40@0:8@16q24@32 tableView:commitEditingStyle:forRowAtIndexPath:;
    v40@0:8@16@24q32 tableView:willDisplayHeaderView:forSection:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    v24@0:8@16 updateSearchResultsForSearchController:;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    v16@0:8 .cxx_destruct;
@end

@interface SearchEnginesViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v20@0:8B16 viewWillDisappear:;
    v24@0:8B16B20 setEditing:animated:;
    v32@0:8@16@24 tableView:didSelectRowAtIndexPath:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface SecurityPopUpViewController : UIViewController
    @property T@"UILabel",N,W,VheaderLb headerLb;
    @property T@"UITableView",N,W,VtableView tableView;
    @property T@"UIButton",N,W,VcustomizeBt customizeBt;
    @property T@"UIButton",N,W,VlearnMoreBt learnMoreBt;
    @property T{CGSize=dd},N preferredContentSize;

    @16@0:8 headerLb;
    v24@0:8@16 setHeaderLb:;
    @16@0:8 tableView;
    v24@0:8@16 setTableView:;
    @16@0:8 customizeBt;
    v24@0:8@16 setCustomizeBt:;
    @16@0:8 learnMoreBt;
    v24@0:8@16 setLearnMoreBt:;
    {CGSize=dd}16@0:8 preferredContentSize;
    v32@0:8{CGSize=dd}16 setPreferredContentSize:;
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v20@0:8B16 viewWillDisappear:;
    q32@0:8@16q24 tableView:numberOfRowsInSection:;
    @32@0:8@16@24 tableView:cellForRowAtIndexPath:;
    d32@0:8@16@24 tableView:heightForRowAtIndexPath:;
    @32@0:8@16@24 tableView:willSelectRowAtIndexPath:;
    q24@0:8@16 adaptivePresentationStyleForPresentationController:;
    v16@0:8 customize;
    v16@0:8 learnMore;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface OrbotOrBuiltInViewController : UIViewController
    @property T@"UILabel",N,W,VtitleLb titleLb;
    @property T@"UILabel",N,W,VbodyLb bodyLb;
    @property T@"UIButton",N,W,VuseOrbotBt useOrbotBt;
    @property T@"UIButton",N,W,VuseBuiltInTor useBuiltInTor;
    @property T@"UIButton",N,W,VwhyBt whyBt;

    @16@0:8 titleLb;
    v24@0:8@16 setTitleLb:;
    @16@0:8 bodyLb;
    v24@0:8@16 setBodyLb:;
    @16@0:8 useOrbotBt;
    v24@0:8@16 setUseOrbotBt:;
    @16@0:8 useBuiltInTor;
    v24@0:8@16 setUseBuiltInTor:;
    @16@0:8 whyBt;
    v24@0:8@16 setWhyBt:;
    v16@0:8 viewDidLoad;
    v24@0:8@16 action:;
    v16@0:8 why;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface AddSearchEngineViewController : _TtC12OnionBrowser23FixedFormViewController
    v16@0:8 viewDidLoad;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface SearchableTableViewController : UITableViewController
    v16@0:8 viewDidLoad;
    v24@0:8@16 updateSearchResultsForSearchController:;
    @24@0:8q16 initWithStyle:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface Log : NSObject
@end

@interface Tab : UIView
    @property T@"NSURL",N,C url;
    @property Tq,N,R index;
    @property TB,N userInteractionEnabled;

    v16@0:8 refresherTriggered;
    @48@0:8@16@24@32@40 webView:createWebViewWithConfiguration:forNavigationAction:windowFeatures:;
    v24@0:8@16 webViewDidClose:;
    v48@0:8@16@24@32@?40 webView:runJavaScriptAlertPanelWithMessage:initiatedByFrame:completionHandler:;
    v48@0:8@16@24@32@?40 webView:runJavaScriptConfirmPanelWithMessage:initiatedByFrame:completionHandler:;
    v56@0:8@16@24@32@40@?48 webView:runJavaScriptTextInputPanelWithPrompt:defaultText:initiatedByFrame:completionHandler:;
    v40@0:8@16@24@?32 webView:contextMenuConfigurationForElement:completionHandler:;
    v48@0:8@16@24@32@?40 webView:requestDeviceOrientationAndMotionPermissionForOrigin:initiatedByFrame:decisionHandler:;
    v56@0:8@16@24@32q40@?48 webView:requestMediaCapturePermissionForOrigin:initiatedByFrame:type:decisionHandler:;
    @24@0:8@16 activityViewControllerPlaceholderItem:;
    @32@0:8@16@24 activityViewController:itemForActivityType:;
    @32@0:8@16@24 activityViewController:subjectForActivityType:;
    @32@0:8@16@24 activityViewController:dataTypeIdentifierForActivityType:;
    @48@0:8@16@24{CGSize=dd}32 activityViewController:thumbnailImageForActivityType:suggestedSize:;
    @24@0:8@16 activityViewControllerLinkMetadata:;
    v48@0:8@16@24@32@?40 download:decideDestinationUsingResponse:suggestedFilename:completionHandler:;
    v40@0:8@16@24@?32 download:didReceiveAuthenticationChallenge:completionHandler:;
    v40@0:8@16@24@32 download:didFailWithError:resumeData:;
    v24@0:8@16 downloadDidFinish:;
    @32@0:8@16q24 previewController:previewItemAtIndex:;
    q24@0:8@16 numberOfPreviewItemsInPreviewController:;
    v32@0:8@16@24 userContentController:didReceiveScriptMessage:;
    v48@0:8@16@24@32@?40 webView:decidePolicyForNavigationAction:preferences:decisionHandler:;
    v40@0:8@16@24@?32 webView:decidePolicyForNavigationResponse:decisionHandler:;
    v32@0:8@16@24 webView:didCommitNavigation:;
    v40@0:8@16@24@32 webView:navigationAction:didBecomeDownload:;
    v40@0:8@16@24@32 webView:navigationResponse:didBecomeDownload:;
    v32@0:8@16@24 webView:didFinishNavigation:;
    v40@0:8@16@24@32 webView:didFailNavigation:withError:;
    v40@0:8@16@24@32 webView:didFailProvisionalNavigation:withError:;
    v40@0:8@16@24@?32 webView:didReceiveAuthenticationChallenge:completionHandler:;
    v40@0:8@16@24@?32 webView:authenticationChallenge:shouldAllowDeprecatedTLS:;
    @16@0:8 url;
    v24@0:8@16 setUrl:;
    q16@0:8 index;
    B16@0:8 isUserInteractionEnabled;
    v20@0:8B16 setUserInteractionEnabled:;
    @24@0:8@16 initWithCoder:;
    v48@0:8@16@24@32^v40 observeValueForKeyPath:ofObject:change:context:;
    v16@0:8 refresh;
    v24@0:8@16 load:;
    v24@0:8@16 searchFor:;
    v16@0:8 goBack;
    v16@0:8 goForward;
    v24@0:8@16 hostSettingsChanged:;
    v16@0:8 dealloc;
    @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 initWithFrame:;
    v16@0:8 .cxx_destruct;
@end

@interface TabCell : UICollectionViewCell
    @property T@"UIView",N,W,Vheader header;
    @property T@"UILabel",N,W,Vtitle title;
    @property T@"UIImageView",N,W,Vpreview preview;

    @16@0:8 header;
    v24@0:8@16 setHeader:;
    @16@0:8 title;
    v24@0:8@16 setTitle:;
    @16@0:8 preview;
    v24@0:8@16 setPreview:;
    @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16 initWithFrame:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 close;
    B32@0:8@16@24 gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:;
    B32@0:8@16@24 gestureRecognizer:shouldBeRequiredToFailByGestureRecognizer:;
    v24@0:8@16 pan:;
    v16@0:8 .cxx_destruct;
@end

@interface NcFolder : Codable
@end

@interface NcServer : NSObject
@end

@interface Settings : _TtC17IPtProxyUI_Shared8Settings
@end

@interface Formatter : NSObject
    @16@0:8 init;
@end

@interface _706EA45DFF7E05B87BCD268F283213B419ResourceBundleClass : NSObject
@end

@interface BridgesConfViewController : _TtC20IPtProxyUI_iOS_AppEx23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillAppear:;
    v20@0:8B16 viewWillDisappear:;
    v36@0:8@16@24B32 navigationController:willShowViewController:animated:;
    v16@0:8 save;
    v16@0:8 resetCountryLocalization;
    v16@0:8 cancel;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface CustomBridgesViewController : _TtC20IPtProxyUI_iOS_AppEx23FixedFormViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewWillDisappear:;
    v32@0:8@16@24 imagePickerController:didFinishPickingMediaWithInfo:;
    v24@0:8@16 imagePickerControllerDidCancel:;
    v40@0:8@16q24@32 mailComposeController:didFinishWithResult:error:;
    v24@0:8@16 scannedWithBridges:;
    v24@0:8@16 scannedWithError:;
    v16@0:8 save;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface Reachability : NSObject
@end

@interface BuiltInBridges : NSObject
@end

@interface L10n : NSObject
@end

@interface Bridge : NSObject
@end

@interface Country : NSObject
@end

@interface DnsInfo : NSObject
@end

@interface Helpers : NSObject
@end

@interface MoatApi : NSObject
@end

@interface AutoConf : NSObject
@end

@interface OnDemand : NSObject
@end

@interface Settings : IPtProxyUI_Shared.Settings
@end

@interface Constants : NSObject
@end

@interface DnsServer : NSObject
@end

@interface IpSupport : NSObject
    v16@0:8 reachabilityChanged;
@end

@interface _44950D1CB2DE26CB7D19656282D50D5012BundleFinder : NSObject
@end

@interface _4A132270E622D8855CBFFCA02C34CBEA21ReachabilityWeakifier : NSObject
@end

@interface AlertHelper : NSObject
@end

@interface ScanQrViewController : _TtC20IPtProxyUI_iOS_AppEx22BaseScanViewController
    v16@0:8 viewDidLoad;
    v20@0:8B16 viewDidAppear:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
@end

@interface BaseScanViewController : UITableViewController
    v20@0:8B16 viewWillDisappear:;
    v40@0:8@16@24@32 captureOutput:didOutputMetadataObjects:fromConnection:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface FixedFormViewController : EurekaFormViewController
    v24@0:8@16 keyboardWillShow:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
@end

@interface RuleRegExp : NSObject
@end

@interface RowDefaults : NSObject
@end

@interface SwipeAction : NSObject
@end

@interface DecimalFormatter : ?external(ordinal 1632)
    @16@0:8 init;
    @24@0:8@16 initWithCoder:;
    B48@0:8^@16@24^{_NSRange=QQ}32^@40 getObjectValue:forString:range:error:;
@end

@interface BaseMultivaluedSection : _TtC6Eureka7Section
@end

@interface Form : NSObject
@end

@interface BaseRow : NSObject
@end

@interface Section : NSObject
@end

@interface RuleEmail : _TtC6Eureka10RuleRegExp
@end

@interface ImagePickerController : ?external(ordinal 1708)
    @property Tq,N,R preferredStatusBarStyle;

    q16@0:8 preferredStatusBarStyle;
    v16@0:8 viewDidLoad;
    v32@0:8@16@24 imagePickerController:didFinishPickingMediaWithInfo:;
    v24@0:8@16 imagePickerControllerDidCancel:;
    @32@0:8#16#24 initWithNavigationBarClass:toolbarClass:;
    @24@0:8@16 initWithRootViewController:;
    @32@0:8@16@24 initWithNibName:bundle:;
    @24@0:8@16 initWithCoder:;
    v16@0:8 .cxx_destruct;
@end

@interface _TtCC17IPtProxyUI_Shared6Bridge7Builder : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi12CheckRequest : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi12FetchRequest : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi13CheckResponse : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi13FetchResponse : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi15SettingsRequest : _TtCC17IPtProxyUI_Shared7MoatApi4Body
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi16SettingsResponse : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi4Body : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi6Bridge : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi6Errors : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi7Setting : NSObject
@end

@interface _TtCC17IPtProxyUI_Shared7MoatApi9MoatError : NSObject
@end

@interface _TtCC6Eureka4Form10KVOWrapper : NSObject
    @property T@"NSMutableArray",N,&,V_sections _sections;

    @16@0:8 _sections;
    v24@0:8@16 set_sections:;
    v16@0:8 dealloc;
    v48@0:8@16@24@32^v40 observeValueForKeyPath:ofObject:change:context:;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface _TtCC6Eureka7Section10KVOWrapper : NSObject
    @property T@"NSMutableArray",N,&,V_rows _rows;

    @16@0:8 _rows;
    v24@0:8@16 set_rows:;
    v16@0:8 dealloc;
    v48@0:8@16@24@32^v40 observeValueForKeyPath:ofObject:change:context:;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface _TtCO17IPtProxyUI_Shared9TransportP33_7CA1B806E7A5BDE75D41FFEEFF8AF89E15StatusCollector : NSObject
    v32@0:8@16@24 stopped:error:;
    v24@0:8@16 connected:;
    v32@0:8@16@24 error:error:;
    @16@0:8 init;
    v16@0:8 .cxx_destruct;
@end

@interface goSeqDictionary : NSObject
    @property T@"NSMutableDictionary",&,V_dict dict;

    @16@0:8 init;
    @24@0:8@16 get:;
    v32@0:8@16@24 put:withKey:;
    @16@0:8 dict;
    v24@0:8@16 setDict:;
    v16@0:8 .cxx_destruct;
@end

