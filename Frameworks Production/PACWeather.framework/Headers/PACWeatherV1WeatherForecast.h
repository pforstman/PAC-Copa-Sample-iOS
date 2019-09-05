/** @module PACWeather.framework *///
//  PACWeatherV1WeatherForecast.h
//  Weather
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACWeather/PACWeatherV1WeatherForecastItem.h>

/**
 * This class is a model structure for weather forecasts.
 */
@interface PACWeatherV1WeatherForecast : NSObject

/**
 * The current weather.
 *
 * Please refer to WeatherV1WeatherForecastItem for information refgarding the current weather.
 */
@property (nonatomic, strong) PACWeatherV1WeatherForecastItem * _Nonnull currentWeather;

/**
 * The weather forecast.
 *
 * Please refer to WeatherV1WeatherForecastItem for information refgarding the objects of the array.
 */
@property (nonatomic, strong) NSArray<PACWeatherV1WeatherForecastItem *> * _Nullable forecast;

@end
