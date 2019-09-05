//
//  SystemServiceManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 06/03/15.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@class PSMedia;

@interface SystemServiceManager : NSObject

@property (nonatomic, assign) BOOL disablePairingServiceCheck;

+ (SystemServiceManager *)sharedSystemServiceManager;
- (BOOL)isServiceAvailable:(NSString *)serviceCode;
- (BOOL)isServiceMissing:(NSString *)serviceCode;
- (BOOL)isLocationAvailable:(NSString *)location;
- (BOOL)isServerReachable;
- (BOOL)isInGroundMode;
- (BOOL)isMediaAvailable:(PSMedia *)media;
- (BOOL)isMediaServiceAvailable:(NSString *)mediaTemplateID;
- (BOOL)isPairingServiceAvailable;

@end
