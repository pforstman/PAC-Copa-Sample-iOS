/** @module PACEXConnect.framework *///
//  PACEXConnectV1GroundConnectivityStatus.h
//  eXConnect
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The PACEXConnectV1GroundConnectivityStatus is a class that provides status on the ground connectivity.
 */
@interface PACEXConnectV1GroundConnectivityStatus : NSObject


/**
 *  True, if the link to ground is up. False, if link is down.
 */
@property (nonatomic, readonly, assign, getter=isGroundLinkUp) BOOL  groundLinkUp;

/**
 * The number of minutes until the connection will flip state from online to offline or offline to online.
 */
@property (nonatomic, readonly, assign) NSInteger  timeUntilCoverageChange;

/**
 * The number of minutes of predicted coverage remaining for the duration of flight.
 */
@property (nonatomic, readonly, assign) NSInteger     totalCoverageRemaining;

@end
