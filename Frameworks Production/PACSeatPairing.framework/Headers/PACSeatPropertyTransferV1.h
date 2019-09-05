/** @module PACSeatPairing.framework *///
//  PACSeatPropertyTransferV1.h
//  SeatPairing
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class handles the updating of the properties on the seatback monitor.
 */
@interface PACSeatPropertyTransferV1 : NSObject


/**
 * @constantgroup PACSeatPropertyTransferErrorDomains
 * The list of error domains for PACSeatPropertyTransferV1.
 * @owner PACSeatPropertyTransferV1
 */

/**
 * This key defines the general error domain for PACSeatPropertyTransferV1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPropertyTransferErrorDomain;

/**
 * Error codes returned for the remote control requests.
 */
typedef enum{
    /** The request has failed due to an unknown error. */
    PACSeatPropertyTransferErrorUnknown                          = 1500,
    /** The request has missing or incorrect parameters. */
    PACSeatPropertyTransferErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatPropertyTransferErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatPropertyTransferErrorConnectionError                  = 1503,
    /** The request has failed due to an unexpected response from the server. */
    PACSeatPropertyTransferErrorBadResponse                      = 1504,
    /** The request has failed due to the service being unavailable. */
    PACSeatPropertyTransferErrorServiceNotFound                  = 1505,
    /** The request has failed due to a seat passenger announcement being in progress */
    PACSeatPropertyTransferErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to device not being paired to seat. */
    PACSeatPropertyTransferErrorNotPaired                        = 1600,
    /** The request has failed due to an invalied parameter. */
    PACSeatPropertyTransferErrorInvalidParameters                = 1601,
    /** One or more properties provided are invalid. */
    PACSeatPropertyTransferErrorInvalidProperties                = 1901
}PACSeatPropertyTransferErrorCode;

/**
 This method is used to set or update a property on the seatback monitor.
 
 This method is used to update the display message on the seatback monitor.
         [self.seatPropertyTransfer sendRequestToSetSeatProperties: @{PACSeatPropertyPersonalizedDisplayMessageKey: @"Welcome aboard!"}
                                         withCompletionHandler:^(NSError *error){
            if (!error) {
                NSLog(@"Request sent successfully.";
            }
            else{
                NSLog(@"Error in sending request: %@", error);
            }
         }];

 @param seatProperties A key-value pair which maps seat properties to the corresponding value. Please refer to PACSeatPropertyKeys for options.
 @param completion The completion handler.
 
 - *error* If error is nil, no error has occurred. Please refer to PACSeatPropertyTransferErrorCode for error codes.
 
 */
- (void)sendRequestToSetSeatProperties:(NSDictionary * _Nonnull)seatProperties
                 withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 This method is used to get one or more properties from the seatback monitor.
 
 This method is used to get the display message on the seatback monitor.
         [self.seatPropertyTransfer sendRequestToGetSeatProperties: @[PACSeatPropertyPersonalizedDisplayMessageKey]
                                         withCompletionHandler:^(NSDictionary *propertyValue, NSError *error){
            if (!error) {
                NSString* displayMessage = propertyValue[PACSeatPropertyPersonalizedDisplayMessageKey];
            }
            else{
                NSLog(@"Error in sending request: %@", error);
            }
         }];

 @param seatProperties An array of seat properties. Please refer to PACSeatPropertyKeys for possible options.
 @param completion The completion handler.
 
 - *propertyValue* The property to value mapping.
 - *error* If error is nil, no error has occurred. Please refer to PACSeatPropertyTransferErrorCode for error codes.
 
 */
- (void)sendRequestToGetSeatProperties:(NSArray<NSString*>* _Nonnull)seatProperties
                 withCompletionHandler:(void (^ _Nullable)(NSDictionary * _Nullable propertyValue, NSError * _Nullable error))completion;

/**
 * @constantgroup PACSeatPropertyKeys
 * List of seatback monitor properties.
 * @owner PACSeatPropertyTransferV1
 */

/**
 * This key defines the preferred personalized display message on the seatback monitor.
 * The value should be a NSString object.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPropertyPersonalizedDisplayMessageKey;

/**
 * This key defines the seat preference key to be used to update the user preferences on the seatback monitor.
 * The value should be a NSDictionary object as returned by [PACUserPreferencesV1 serializedData].
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPropertyUserPreferencesKey;

/**
 * This key defines the seat preference key to be used to update the user profile on the seatback monitor.
 * The value should be a NSDictionary object as returned by [PACUserProfileV1 serializedData].
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPropertyUserProfileKey;


@end
