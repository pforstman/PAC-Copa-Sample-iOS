/** @module PACCoreKit.framework *///
//  PACDistance.h
//  PACCoreKit
//
//  Created by Rawad Hilal on 9/21/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * The class provides values for distance.
 
 Example
        PACDistance* distance = [[PACDistance alloc] initWithMeter:1000];
        float feet = [distance feet];
        NSLog(@"feet:%f", feet);
 
        float mile = [distance miles];
        NSLog(@"mile:%f", mile);
 
        float meter = [distance meters];
        NSLog(@"meter:%f", meter);
 
        float km = [distance kilometers];
        NSLog(@"km:%f", km);
 */
@interface PACDistance : NSObject

/**
 * Initialize the distance object in meters
 * @return The distance object
 */
- (instancetype)initWithMeter:(float)meter;

/**
 * Initialize the distance object in miles
 * @return The distance object
 */
- (instancetype)initWithMile:(float)mile;

/**
 * Initialize the distance object in feet
 * @return The distance object
 */
- (instancetype)initWithFeet:(float)feet;

/**
 * Initialize the distance object in kilometers
 * @return The distance object
 */
- (instancetype)initWithKilometer:(float)kilometer;

/**
 * initialize the distance object in nautical mile
 * @return The distance object
 */
- (instancetype)initWithNauticalMile:(float)nauticalMile;

/**
 * initialize the distance object in yard
 * @return The distance object
 */
- (instancetype)initWithYard:(float)yard;

/**
 * The miles
 * @return The value in miles
 */
-(float)miles;

/**
 * The feet
 * @return The value in feet
 */
-(float)feet;

/**
 * The meters
 * @return The value in meters
 */
-(float)meters;

/**
 * The kilometers
 * @return The value in kilometers
 */
-(float)kilometers;

/**
 * The nauticalMiles
 * @return The value in nauticalMiles
 */
-(float)nauticalMiles;

/**
 * The yards
 * @return The value in yards
 */
-(float)yards;
@end
