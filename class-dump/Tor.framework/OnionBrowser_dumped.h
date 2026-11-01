@interface PodsDummy_Tor : BIND:344
@end

@interface TORAuthKey : BIND:344
    @property T@"NSURL",R,N,V_file file;
    @property TB,R isPrivate;
    @property T@"NSURL",R,N,V_onionAddress onionAddress;
    @property T@"NSString",R,N,V_authType authType;
    @property T@"NSString",R,N,V_keyType keyType;
    @property T@"NSString",R,N,V_key key;

    @24@0:8@16 initFromUrl:;
    @24@0:8@16 initFromFile:;
    @32@0:8@16@24 initPrivate:forDomain:;
    @32@0:8@16@24 initPublic:withName:;
    B16@0:8 isPrivate;
    v24@0:8@16 setDirectory:;
    B16@0:8 persist;
    @16@0:8 description;
    @16@0:8 debugDescription;
    B24@0:8@16 isEqualToAuthKey:;
    B24@0:8@16 isEqual:;
    Q16@0:8 hash;
    @16@0:8 file;
    @16@0:8 onionAddress;
    @16@0:8 authType;
    @16@0:8 keyType;
    @16@0:8 key;
    v16@0:8 .cxx_destruct;
@end

@interface TORCircuit : BIND:344
    @property T@"NSString",R,V_raw raw;
    @property T@"NSString",R,V_circuitId circuitId;
    @property T@"NSString",R,V_status status;
    @property T@"NSArray",R,V_nodes nodes;
    @property T@"NSArray",R,V_buildFlags buildFlags;
    @property T@"NSString",R,V_purpose purpose;
    @property T@"NSString",R,V_hsState hsState;
    @property T@"NSString",R,V_rendQuery rendQuery;
    @property T@"NSDate",R,V_timeCreated timeCreated;
    @property T@"NSString",R,V_reason reason;
    @property T@"NSString",R,V_remoteReason remoteReason;
    @property T@"NSString",R,V_socksUsername socksUsername;
    @property T@"NSString",R,V_socksPassword socksPassword;

    @24@0:8@16 initFromString:;
    @24@0:8@16 initWithCoder:;
    v24@0:8@16 encodeWithCoder:;
    @16@0:8 description;
    @16@0:8 raw;
    @16@0:8 circuitId;
    @16@0:8 status;
    @16@0:8 nodes;
    @16@0:8 buildFlags;
    @16@0:8 purpose;
    @16@0:8 hsState;
    @16@0:8 rendQuery;
    @16@0:8 timeCreated;
    @16@0:8 reason;
    @16@0:8 remoteReason;
    @16@0:8 socksUsername;
    @16@0:8 socksPassword;
    v16@0:8 .cxx_destruct;
@end

@interface TORConfiguration : BIND:344
    @property T@"NSURL",C,N,V_dataDirectory dataDirectory;
    @property T@"NSURL",C,N,V_cacheDirectory cacheDirectory;
    @property T@"NSURL",R,C,N controlPortFile;
    @property T@"NSURL",C,N,V_controlSocket controlSocket;
    @property T@"NSURL",C,N,V_socksURL socksURL;
    @property TQ,N,V_socksPort socksPort;
    @property TQ,N,V_dnsPort dnsPort;
    @property T@"NSURL",C,N,V_clientAuthDirectory clientAuthDirectory;
    @property T@"NSURL",C,N,V_hiddenServiceDirectory hiddenServiceDirectory;
    @property T@"NSURL",R,C,N serviceAuthDirectory;
    @property T@"NSURL",C,N,V_geoipFile geoipFile;
    @property T@"NSURL",C,N,V_geoip6File geoip6File;
    @property T@"NSURL",C,N,V_logfile logfile;
    @property TB,N,V_ignoreMissingTorrc ignoreMissingTorrc;
    @property TB,N,V_cookieAuthentication cookieAuthentication;
    @property TB,N,V_autoControlPort autoControlPort;
    @property TB,N,V_avoidDiskWrites avoidDiskWrites;
    @property TB,N,V_clientOnly clientOnly;
    @property TB,R,N isLocked;
    @property T@"NSData",R,C,N cookie;
    @property T@"NSMutableDictionary",C,N,V_options options;
    @property T@"NSMutableArray",C,N,V_arguments arguments;

    @16@0:8 options;
    @16@0:8 arguments;
    @16@0:8 controlPortFile;
    @16@0:8 serviceAuthDirectory;
    B16@0:8 isLocked;
    @16@0:8 cookie;
    @24@0:8@16 valueOf:;
    @16@0:8 compile;
    @16@0:8 dataDirectory;
    v24@0:8@16 setDataDirectory:;
    @16@0:8 cacheDirectory;
    v24@0:8@16 setCacheDirectory:;
    @16@0:8 controlSocket;
    v24@0:8@16 setControlSocket:;
    @16@0:8 socksURL;
    v24@0:8@16 setSocksURL:;
    Q16@0:8 socksPort;
    v24@0:8Q16 setSocksPort:;
    Q16@0:8 dnsPort;
    v24@0:8Q16 setDnsPort:;
    @16@0:8 clientAuthDirectory;
    v24@0:8@16 setClientAuthDirectory:;
    @16@0:8 hiddenServiceDirectory;
    v24@0:8@16 setHiddenServiceDirectory:;
    @16@0:8 geoipFile;
    v24@0:8@16 setGeoipFile:;
    @16@0:8 geoip6File;
    v24@0:8@16 setGeoip6File:;
    @16@0:8 logfile;
    v24@0:8@16 setLogfile:;
    B16@0:8 ignoreMissingTorrc;
    v20@0:8B16 setIgnoreMissingTorrc:;
    B16@0:8 cookieAuthentication;
    v20@0:8B16 setCookieAuthentication:;
    B16@0:8 autoControlPort;
    v20@0:8B16 setAutoControlPort:;
    B16@0:8 avoidDiskWrites;
    v20@0:8B16 setAvoidDiskWrites:;
    B16@0:8 clientOnly;
    v20@0:8B16 setClientOnly:;
    v24@0:8@16 setOptions:;
    v24@0:8@16 setArguments:;
    v16@0:8 .cxx_destruct;
@end

@interface TORController : BIND:344
    @property T@"NSOrderedSet",R,C,N,V_events events;
    @property TB,R,N,GisConnected connected;

    @24@0:8@16 initWithSocketURL:;
    @28@0:8@16S24 initWithSocketHost:port:;
    @24@0:8@16 initWithControlPortFile:;
    v16@0:8 dealloc;
    B16@0:8 isConnected;
    B24@0:8o^@16 connect:;
    v16@0:8 disconnect;
    @24@0:8@?16 addObserverForCircuitEstablished:;
    @24@0:8@?16 addObserverForStatusEvents:;
    @24@0:8@?16 addObserver:;
    v24@0:8@16 removeObserver:;
    v32@0:8@16@?24 authenticateWithData:completion:;
    v32@0:8@16@?24 resetConfForKey:completion:;
    v40@0:8@16@24@?32 setConfForKey:withValue:completion:;
    v32@0:8@16@?24 setConfs:completion:;
    v32@0:8@16@?24 listenForEvents:completion:;
    v32@0:8@16@?24 getInfoForKeys:completion:;
    v24@0:8@?16 getSessionConfiguration:;
    v48@0:8@16@24@32@?40 sendCommand:arguments:data:observer:;
    v24@0:8@?16 getCircuits:;
    v24@0:8@?16 resetConnection:;
    v32@0:8@16@?24 closeCircuitsByIds:completion:;
    v32@0:8@16@?24 closeCircuits:completion:;
    v36@0:8@16B24@?28 resolveCountriesOfNodes:testCapabilities:completion:;
    @16@0:8 events;
    v16@0:8 .cxx_destruct;
@end

@interface TORNode : BIND:344
    @property T@"NSString",&,N,V_fingerprint fingerprint;
    @property T@"NSString",&,N,V_nickName nickName;
    @property T@"NSString",&,N,V_ipv4Address ipv4Address;
    @property T@"NSString",&,N,V_ipv6Address ipv6Address;
    @property T@"NSString",&,N,V_countryCode countryCode;
    @property T@"NSString",R,N localizedCountryName;
    @property TB,V_isExit isExit;

    @24@0:8@16 initFromString:;
    @24@0:8@16 initFromNsString:;
    v24@0:8@16 acquireIpAddressesFromNsResponse:;
    @16@0:8 localizedCountryName;
    @24@0:8@16 initWithCoder:;
    v24@0:8@16 encodeWithCoder:;
    @16@0:8 description;
    B24@0:8@16 isEqual:;
    Q16@0:8 hash;
    @16@0:8 fingerprint;
    v24@0:8@16 setFingerprint:;
    @16@0:8 nickName;
    v24@0:8@16 setNickName:;
    @16@0:8 ipv4Address;
    v24@0:8@16 setIpv4Address:;
    @16@0:8 ipv6Address;
    v24@0:8@16 setIpv6Address:;
    @16@0:8 countryCode;
    v24@0:8@16 setCountryCode:;
    B16@0:8 isExit;
    v20@0:8B16 setIsExit:;
    v16@0:8 .cxx_destruct;
@end

@interface TOROnionAuth : BIND:344
    @property T@"NSURL",R,N,V_privateUrl privateUrl;
    @property T@"NSURL",R,N,V_publicUrl publicUrl;
    @property T@"NSArray",R,N,V_keys keys;

    @32@0:8@16@24 initWithPrivateDirUrl:andPublicDirUrl:;
    @32@0:8@16@24 initWithPrivateDir:andPublicDir:;
    B24@0:8@16 set:;
    B24@0:8q16 removeKeyAtIndex:;
    @16@0:8 privateUrl;
    @16@0:8 publicUrl;
    @16@0:8 keys;
    v16@0:8 .cxx_destruct;
@end

@interface TORThread : BIND:345
    @property T@"NSArray",R,C,N,V_arguments arguments;

    @16@0:8 init;
    @24@0:8@16 initWithConfiguration:;
    @24@0:8@16 initWithArguments:;
    v16@0:8 main;
    @16@0:8 arguments;
    v16@0:8 .cxx_destruct;
@end

@interface TORX25519KeyPair : BIND:344
    @property T@"NSString",R,N,V_privateKey privateKey;
    @property T@"NSString",R,N,V_publicKey publicKey;

    @16@0:8 init;
    @32@0:8@16@24 initWithBase32PrivateKey:andPublicKey:;
    @32@0:8@16@24 initWithPrivateKey:andPublicKey:;
    @24@0:8@16 getPrivateAuthKeyForDomain:;
    @24@0:8@16 getPrivateAuthKeyForUrl:;
    @24@0:8@16 getPublicAuthKeyWithName:;
    @16@0:8 privateKey;
    @16@0:8 publicKey;
    v16@0:8 .cxx_destruct;
@end

