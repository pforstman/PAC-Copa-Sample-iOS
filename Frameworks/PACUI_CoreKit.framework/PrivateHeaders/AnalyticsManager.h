//
//  AnalyticsManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 07/22/16.
//  Copyright (c) 2016 Mercury. All rights reserved.
//

@class PSMedia;

@interface AnalyticsManager : NSObject

+ (AnalyticsManager *)sharedAnalyticsManager;

- (void)applicationHasStarted;
- (void)applicationHasStopped;
- (void)transitionToDestination:(NSString *)destinationIdentifier;
- (void)transitionToDestination:(NSString *)destinationIdentifier withAutoTrackingDisabled:(BOOL)autoTrackingDisabled;
- (void)transitionBack;
- (void)queueTransitionToDestination:(NSString *)destinationIdentifier;
- (void)queueTransitionToDestination:(NSString *)destinationIdentifier withAutoTrackingDisabled:(BOOL)autoTrackingDisabled;
- (void)flushTransitionQueueWithDetail:(NSString *)detail;
- (void)miniPlayerTransitionToDestination:(NSString *)destinationIdentifier;
- (void)miniPlayerTransitionToDestination:(NSString *)destinationIdentifier withAutoTrackingDisabled:(BOOL)autoTrackingDisabled;

@end
