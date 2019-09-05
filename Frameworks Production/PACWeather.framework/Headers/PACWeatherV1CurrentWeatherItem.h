/** @module PACWeather.framework *///
//  PACWeatherV1Weather.h
//  Weather
//
//  Created by Gary L. Wade on 04/25/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class is a model structure for displaying the current weather.
 */
@interface PACWeatherV1CurrentWeatherItem : NSObject

/**
 * The weather condition, such as sunny or cloudy.
 *
 * Please refer to PACWeatherV1WeatherConditions for weather conditions.
 */
@property (nonatomic, copy) NSString * _Nonnull condition;

/**
 * The weather condition code. For example, the code for sunny is 1001 and for cloudy is 3009.
 *
 * Please refer to PACWeatherV1WeatherConditionCode for weather condition codes.
 */
@property (nonatomic, copy) NSNumber * _Nonnull conditionCode;

/**
 * The current temperature.
 *
 * Temperatures are in degrees Celsius.
 */
@property (nonatomic, copy) NSNumber * _Nonnull currentTemperature;

/**
 * Unique 4-letter ICAO airport code, such as KLAX or YBHM.
 */
@property (nonatomic, copy) NSString * _Nonnull ICAOCode;

/**
 * Weather icon string representation.
 *
 * Distinct weather condition names are provided. These names
 * can be used to distinguish icons in your icon set. Weather
 * icons are not provided by this service. The application
 * developer must provide their own icon image assets.
 * Please refer to PACWeatherV1WeatherIcons for a selection of icons.
 */
@property (nonatomic, copy) NSString * _Nonnull iconName;

/**
 * Name of the city
 */
@property (nonatomic, copy) NSString * _Nonnull cityName;

/**
 * Name of the region or location
 */
@property (nonatomic, copy) NSString * _Nonnull regionName;

/**
 * ID for the region or location
 */
@property (nonatomic, copy) NSString * _Nonnull regionId;

/**
 * Date and time.
 *
 *
 */
@property (nonatomic, copy) NSDate * _Nonnull timestamp;

@end
