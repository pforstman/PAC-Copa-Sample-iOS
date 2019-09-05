/** @module PACCoreKit.framework *///
//  PACSpeed.h
//  PACCoreKit
//
//  Created by Rawad Hilal on 9/21/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * The class provides values for speed.
 
 Example
 
        PACSpeed* speed = [[PACSpeed alloc] initWithKilometersPerHour:100.0];
 
        float kph = [speed kilometersPerHour];
        NSLog(@"kph: %f", kph);
         
        float mph = [speed milesPerHour];
        NSLog(@"mph: %f", mph);
         
        float knot = [speed knots];
        NSLog(@"knot: %f", knot);
         
        float mach = [speed machs];
        NSLog(@"mach: %f", mach);
 */
@interface PACSpeed : NSObject

/**
 * Initialize the speed object in kilometers per hour
 * @return The speed object
 */
- (instancetype)initWithKilometersPerHour:(float)kmph;

/**
 * Initialize the speed object in miles per hour
 * @return The speed object
 */
- (instancetype)initWithMilesPerHour:(float)mph;

/**
 * Initialize the speed object in knots
 * @return The speed object
 */
- (instancetype)initWithKnot:(float)knot;

/**
 * Initialize the speed object in meters per hour
 * @return The speed object
 */
- (instancetype)initWithMetersPerHour:(float)meterPerHour;

/**
 * Initialize the speed object in Mach
 * @return The speed object
 */
- (instancetype)initWithMach:(float)mach;

/**
 * The kilometersPerHour
 * @return The value in kilometers per hour
 */
-(float)kilometersPerHour;

/**
 * The milesPerHour
 * @return The value in miles per hour
 */
-(float)milesPerHour;

/**
 * The metersPerHour
 * @return The value in meters per hour
 */
-(float)metersPerHour;

/**
 * The knots
 * @return The value in knots
 */
-(float)knots;

/**
 * The Mach
 * @return The value in Mach
 */
-(float)machs;
@end
