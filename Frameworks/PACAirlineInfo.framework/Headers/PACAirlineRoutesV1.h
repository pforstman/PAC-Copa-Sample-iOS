/** @module PACAirlineInfo.framework *///
//  PACAirlineRoutesV1.h
//  SampleAirlineRoutesApplication
//
//  Created by Rawad Hilal on 5/11/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 * A model class representing an airport.
 */
@interface PACAirlineRouteAirport : NSObject

/**
 * The three letter IATA code for the airport. 
 */
@property (nonatomic, copy, readonly) NSString * _Nonnull IATA;


/**
 * The airport name.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable airportName;

@end

/**
 * The airline route item model class.
 */
@interface PACAirlineRouteItem : NSObject

/**
 * The flight number for a specific airline route.
 */
@property (nonatomic, copy, readonly) NSString * _Nonnull flightNumber;

/**
 * The arrival airport for the flight.
 */
@property (nonatomic, strong, readonly) PACAirlineRouteAirport * _Nonnull arrivalAirport;

/**
 * The departure airport for the flight.
 */
@property (nonatomic, strong, readonly) PACAirlineRouteAirport * _Nonnull departureAirport;
@end

/**
 * This class provides information, such as flight number, arrival airport and departure airport, on the routes for an airline. 
 *
 * @available Ground 03.03.00.05 1
 */
@interface PACAirlineRoutesV1 : InFlightService

/**
 * @constantgroup PACAirlineRoutesErrorDomains
 * The error domains associated to the PACAirlineRoutesV1 class.
 */

/**
 * The generic error associated with the PACAirlineRoutesV1 class.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACAirlineRoutesErrorDomain;

/**
 * The request error codes.
 *
 * @owner PACAirlineRoutesV1
 */
typedef enum {
    /** The request has failed due to an unknown error. */
    PACAirlineRoutesErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACAirlineRoutesErrorBadRequest = 1001,
    /** The request has failed due to the unavailability of the service. */
    PACAirlineRoutesErrorServiceNotFound = 1002,
    /** The request has failed due to an unexpected internal error. */
    PACAirlineRoutesErrorInternalError = 1003,
    /** The request has failed due to an unexpected response from the server. */
    PACAirlineRoutesErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACAirlineRoutesErrorConnectionError = 1005,
    /** The request has failed due to insufficient privilege. */
    PACAirlineRoutesErrorAuthenticationError = 1006
}PACAirlineRoutesErrorCode;

/**
 * The completion block that is called by retreiveRoutesWithAttributes:completion: function.
 * @param items The items that include the route informations.
 * @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACAirlineRoutesV1RetrieveRoutesCompletionHanlder)(NSArray <PACAirlineRouteItem *> * _Nullable items, NSError * _Nullable error);

/**
 * Retrieve route information for the airline flight.
 * @param attributes Attributes associated to the request. Please refer to PACAirlineRoutesRetrieveRoutesAttributes for more details.
 * @param completion The completion block that will be called when the request ends.
 */
- (void)retrieveRoutesWithFilterAttributes:(NSDictionary * _Nullable)attributes
                                completion:(PACAirlineRoutesV1RetrieveRoutesCompletionHanlder _Nonnull)completion;

/**
 * @constantgroup PACAirlineRoutesRetrieveRoutesAttributes
 * The attributes for retrieving route requests.
 */

/**
 * Retrieve routes by flight number. If not provided, all routes for the airline would be returned.
 *
 * The value for this key is of type NSString.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACAirlineRoutesRetrieveRoutesFlightNumberAttribute;

/**
 * Retrieve route information in a specific language.
 *
 * The value for this key is a NSString object holding the ISO 639-2 language code. If the language attribute is not provided,
 * the language for the current locale of the device will be used. If the language value is not supported, the default
 * language set by the airline will be used.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACAirlineRoutesRetrieveRoutesLanguageAttribute;

@end

