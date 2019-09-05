/** @module PACCoreKit.framework *///
//  InFlightService.h
//  CoreKit
//
//  Created by Rawad Hilal on 11/23/15.
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MIN_SYSTEM_VERSION      8.0

/**
 * This is a parent class for all InFlight services.
 */
@interface InFlightService : NSObject

/**
 * InFlight error codes.
 * @owner InFlight
 */
typedef enum {
    /** Unknown error. */
    InFlightServiceErrorUnknown                    = 700,
    /** Device system OS version is not supported. */
    InFlightServiceErrorSystemVersionNotSupported  = 701,
    /** The service that is linked is not compatible. Please make sure that all InFlight libraries that are linked come from the same package. */
    InFlightServiceErrorIncompatibleServiceVersion = 702,
}InFlightServiceErrorCodes;

/**
 * Initializes a service.
 *
 * This function is a synchronous call.
 * @param error The pointer to an error object that is set when an error occurs.
 */
+ (instancetype) initService:(NSError **)error;

/**
 * Initializes a service asynchronously.
 *
 * This function is an asynchronous call.
 * @param completion The completion block that is executed when the service has finished initializing.
 *
 *  - *object* The service object.
 *  - *error* The pointer to an error object that is set when an error occurs.
 */
+ (void) initServiceWithCompletionBlock: (void (^)(id object, NSError * error))completion;

/**
 * Returns the version of a particular service.
 */
+ (NSString *) serviceVersion;

/**
 * Sets the services preferred locale IDs using the format specified by RFC 5646 (e.g., zh-Hant for Traditional Chinese).  If nil, the iOS frameworks default options are used.  If non-nil, this overrides the array provided by -[NSBundle preferredLocalizations] or +[NSLocale preferredLanguages].
 */
+(void)setServicesPreferredLocaleIDsWithArrayOfRFC5646Strings:(NSArray* )preferredLocaleIDsAsRFC5646;

/**
 * Returns an array of the services preferred locale IDs using the format specified by RFC 5646 (e.g., zh-Hant for Traditional Chinese).  If no overridden value has been provided, the iOS frameworks default options are returned (-[NSBundle preferredLocalizations] or +[NSLocale preferredLanguages]).
 */
+(NSArray* )arrayOfServicesPreferredLocaleIDsAsRFC5646Strings;

/**
 * Returns a string that can be used as the value for an Accept-Language header for HTTP calls.
 */
+(NSString* )servicesPreferredLocaleIDsAsAcceptLanguageHeaderValue;

@end
