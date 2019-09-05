/** @module PACCoreKit.framework *///
//  PACTemperature.h
//  PACCoreKit
//
//  Created by Jeff Chen (MLS Technologies) on 9/22/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * The class provides values for temperature.
 
 Example
 
        PACTemperature* temp1  = [[PACTemperature alloc] initWithCelsius:100];
 
        float tmpC = [temp1 celsius];
        NSLog(@"tmpC:%f", tmpC);
 
        float tmpF = [temp1 fahrenheit];
        NSLog(@"tmpF:%f", tmpF);
 */
@interface PACTemperature : NSObject

/**
 * Initialize temperature object in Fahrenheit
 * @return The temperature object
 */
- (id)initWithFahrenheit:(float)fahrenheit;

/**
 * Initialize temperature object in Celsius
 * @return The temperature object
 */
- (id)initWithCelsius:(float)celsius;

/**
 * The Celsius.
 * @return The temperature value in celsius
 */
-(float)celsius;

/**
 * The Fahrenheit.
 * @return The temperature value in Fahrenheit
 */
-(float)fahrenheit;

@end
