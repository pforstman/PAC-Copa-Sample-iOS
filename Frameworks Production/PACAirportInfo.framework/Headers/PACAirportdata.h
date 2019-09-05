/** @module PACAirportInfo.framework *///
//  Airportdata.h
//  InFlight iOS SDK
//
//  Copyright (c) 2016 Panasonic Avionics Corporation. All rights reserved.
//

@class PACAirportdataCoordinate;

#import <Foundation/Foundation.h>

@class PACLocalizedItem;

/**
 * This class represents a data structure for the airport city information.
 * @see PACAirportInfoV1
 */
@interface PACAirportdata : NSObject

/**
 * ICAO code for the airport.
 *
 */
@property (nonatomic,strong,readonly) NSString *ICAO;

/**
 * IATA code for the airport.
 *
 */
@property (nonatomic,strong,readonly) NSString *IATA;

/**
 Key value pairs the languages to city names.
 
 <h4>Example</h4>
 
 NSString *name = cityName[@"en"];
 
 */
@property (nonatomic,strong,readonly) NSDictionary *cityName;

/**
 * Name of the airport.
 */
@property (nonatomic,strong,readonly) NSString *airportName;

/**
 * The localized name of the airport.
 */
@property (nonatomic,strong,readonly) PACLocalizedItem* localizedAirportName;

/**
 * Country where the airport is located.
 */
@property (nonatomic,strong,readonly) NSString *country;

/**
 * Region or state where the airport is located.
 */
@property (nonatomic,strong,readonly) NSString *state;

/**
 * Longitude and latitude of the airport.
 * @see PACAirportdataCoordinate
 */
@property (nonatomic,strong,readonly) PACAirportdataCoordinate *coordinate;

@end


/**
 * PACAirportdataCoordinate is a class used to represent the airport coordinate by longitude and latitude.
 */
@interface PACAirportdataCoordinate : NSObject

/**
 * Latitude value in flight coordinate.
 * Default value is nil.
 */
@property (nonatomic,readonly) NSNumber *latitude;

/**
 * Longitude value in flight coordinate.
 * Default value is nil.
 */
@property (nonatomic,readonly) NSNumber *longitude;

@end

