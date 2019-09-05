/** @module PACWeather.framework *///
//  PACWeatherV1WeatherForecastItem.h
//  Weather
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class is a model structure for a weather forecast item.
 */
@interface PACWeatherV1WeatherForecastItem : NSObject

/**
 * The weather condition, such as sunny or cloudy.
 *
 * Please refer to PACWeatherV1WeatherConditions for weather conditions.
 */
@property (nonatomic, copy) NSString * _Nonnull condition;

/**
 * The weather condition code. For example, the code for sunny is 1001 and for cloudy is 3009.
 *
 * Please refer to PACWeatherV1WeatherConditionCode for weather conditions.
 */
@property (nonatomic, copy) NSNumber * _Nonnull conditionCode;

/**
 * The current temperature.
 *
 * Temperatures are in degrees Celsius.
 */
@property (nonatomic, copy) NSNumber * _Nullable currentTemperature;

/**
 * The high temperature.
 *
 * Temperatures are in degrees Celsius.
 */
@property (nonatomic, copy) NSNumber * _Nullable highTemperature;

/**
 * The low temperature.
 *
 * Temperatures are in degrees Celsius.
 */
@property (nonatomic, copy) NSNumber * _Nullable lowTemperature;

/**
 * The date and time that the forecast data was retrieved on.
 */
@property (nonatomic, copy) NSDate * _Nonnull timestamp;

/**
 * The local time.
 *
 * The local time is in RFC2822 format.
 */
@property (nonatomic, copy) NSString * _Nonnull localTime;

/**
 * The WeatherIcon class provides only distinct weather condition names which can be used to distinguish the icons in your icon set.
 *
 * The WeatherIcon class provides only distinct weather condition names which can be used to distinguish the icons in your icon set. The image files for each icon grouping are not provided by the API and must be included in your application. The application developer must provide their own image assets.
 * Please refer to WeatherV1WeatherIcons for a selection of icons.
 */
@property (nonatomic, copy) NSString * _Nonnull iconName;

@end
