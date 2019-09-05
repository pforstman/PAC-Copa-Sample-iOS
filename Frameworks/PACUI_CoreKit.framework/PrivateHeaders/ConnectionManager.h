//
//  ConnectionManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 11/20/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Reachability.h"

typedef enum : NSInteger {
    ConnectionStatus_NotConnected = 0,
    ConnectionStatus_WiFiConnected,
    ConnectionStatus_PlaneWiFiConnected,
    ConnectionStatus_PairingWithSeatback,
    ConnectionStatus_SeatbackPaired
} ConnectionStatus;

typedef enum : NSInteger {
    ConnectionMode_InFlight = 0,
    ConnectionMode_OnGround
} ConnectionMode;

@interface ConnectionManager : NSObject

@property (nonatomic, assign, readonly) ConnectionStatus connectionStatus;
@property (nonatomic, assign) BOOL isUplink;
@property (nonatomic, assign) int timeUntilCoverageChange;
@property (nonatomic, assign) int totalCoverageRemaining;
@property (nonatomic) Reachability *connectionReachability;

+ (ConnectionManager *)sharedConnectionManager;
- (ConnectionStatus)connectionStatus;
- (BOOL)isSSIDInWhitelist;
- (void)initiatePairingWithSeatNumber:(NSString *)seatNumber completion:(void (^)(BOOL, NSError *))completion;
- (void)pairWithSeatbackUsingPairingCode:(NSString *)pairingCode  withCompletion:(void(^)(BOOL result, NSError *error))completion;
- (void)unpairWithCompletion:(void (^)(BOOL result, NSError *error))completion;
- (void)checkConnectionWithCompletion:(void(^)(BOOL result, NSError *error))completion;
- (NSString *)fetchSSID;
- (void)enterForegroundCheck;
- (void)enterBackgroundCheck;
- (void)noConnectionAlertShow:(BOOL)showHide;
- (void)handleSdkError:(NSError *)error;
- (BOOL)isMiniAppModeAndModulesLoaded;
- (BOOL)connectionToNetwork;

@end
