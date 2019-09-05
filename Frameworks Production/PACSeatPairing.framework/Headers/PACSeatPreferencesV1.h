/** @module PACSeatPairing.framework *///
//  PACSeatPreferencesV1.h
//  SeatPairing
//
//  Created by Rawad Hilal on 3/29/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class handles the updating of the user preferences on the seatback monitor.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 03.03.00.04. Please use the class PACSeatPropertyTransferV1 instead.
 */
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 03.03.00.04. Please use the class PACSeatPropertyTransferV1 instead.")))
@interface PACSeatPreferencesV1 : NSObject

/**
 * @constantgroup PACSeatPreferenceErrorDomains
 * The list of error domains for PACSeatPreferencesV1.
 * @owner PACSeatPreferencesV1
 */

/**
 * This key defines the general error domain for PACSeatPreferencesV1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPreferencesErrorDomain;

/**
 * Error codes returned for the remote control requests.
 */
typedef enum{
    /** The request has failed due to an unknown error. */
    PACSeatPreferencesErrorUnknown                          = 1500,
    /** The request has missing or incorrect parameters. */
    PACSeatPreferencesErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatPreferencesErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatPreferencesErrorConnectionError                  = 1503,
    /** The request has failed due to an unexpected response from the server. */
    PACSeatPreferencesErrorBadResponse                      = 1504,
    /** The request has failed due to the service being unavailable. */
    PACSeatPreferencesErrorServiceNotFound                  = 1505,
    /** The request has failed due to a seat passenger announcement being in progress */
    PACSeatPreferencesErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to device not being paired to seat. */
    PACSeatPreferencesErrorNotPaired                        = 1600,
    /** The request has failed due to an invalied parameter. */
    PACSeatPreferencesErrorInvalidParameters                = 1601
}PACSeatPreferencesErrorCode;

/**
 This method is used to update the user preferences on the seatback monitor.
 
 This method is used to update the user preferences on the seatback monitor. 
         [self.seatPreferences updateSeatPreferences: @{PACSeatPreferencePersonalizedDisplayMessageKey: @"Welcome aboard!"}
                                 withCompletionHandler:^(NSError *error){
            if (!error) {
                NSLog(@"Request sent successfully.";
            }
            else{
                NSLog(@"Error in sending request: %@", error);
            }
         }];

 @param seatPreferences The seatback monitor preferences. Please refer to PACSeatPreferenceKeys for options.
 @param completion The completion handler.
 
 - *error* If error is nil, no error has occurred. Please refer to
 PACSeatPreferencesErrorCode for error codes.
 */
- (void)updateSeatPreferences:(NSDictionary * _Nonnull)seatPreferences
                                withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;


/**
 * @constantgroup PACSeatPreferenceKeys
 * List of seatback monitor preferences.
 * @owner PACSeatPreferencesV1
 */

/**
 * This key defines the preferred personalized display message on the seatback monitor.
 * The value should be a NSString object.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPreferencePersonalizedDisplayMessageKey;

/**
 * This key defines the seat preference key to be used to update the user preferences on the seatback monitor.
 * The value should be a NSDictionary object as returned by [PACUserPreferencesV1 serializedData].
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPreferenceUserPreferencesKey;

/**
 * This key defines the seat preference key to be used to update the user profile on the seatback monitor.
 * The value should be a NSDictionary object as returned by [PACUserProfileV1 serializedData].
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPreferenceUserProfileKey;


@end
