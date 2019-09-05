/** @module PACCoreKit.framework *///
//  PACCoordinate.h
//  PACCoreKit
//
//  Created by Jeff Chen on 9/22/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * The class provides values for coordinate.
 */
@interface PACCoordinate : NSObject


/**
 * The latitude value in a flight coordinate.
 * Default value is nil.
 */
@property (nonatomic,readonly) NSNumber *latitude;

/**
 * The longitude value in a flight coordinate.
 * Default value is nil.
 */
@property (nonatomic,readonly) NSNumber *longitude;

/**
 * Initialize the coordinate object with default longitude and latitude
 * @return The coordinate object
 */
- (id)initWithLongitude:(NSNumber *)longitude latitude:(NSNumber *)latitude;

@end
