/** @module PACSeatPairing.framework *///
//  PACSeatBookmarksV1.h
//  SeatPairing
//
//  Created by Rawad Hilal on 11/7/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>

@class PACMediaBookmark;

/**
 * Seat pairing service that allows retrieving and setting bookmarks on the seat.
 */
@interface PACSeatBookmarksV1 : InFlightService

/**
 * @constantgroup PACSeatBookmarksErrorDomains
 * The list of error domains for PACSeatBookmarksV1.
 * @owner PACSeatBookmarksV1
 */

/**
 * This key defines the general error domain for PACSeatBookmarksV1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatBookmarksErrorDomain;

/**
 * The error codes returned the remote control requests.
 */
typedef enum{
    /** The request has failed due to an unknown error. */
    PACSeatBookmarksErrorUnknown                          = 1500,
    /** The request has failed due to invalid or missing parameters in the request.
     */
    PACSeatBookmarksErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatBookmarksErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatBookmarksErrorConnectionError                  = 1503,
    /** The request has failed due to the server returning an unexpected response. */
    PACSeatBookmarksErrorBadResponse                      = 1504,
    /** The request has failed due to the service being unavailable. */
    PACSeatBookmarksErrorServiceNotFound                  = 1505,
    /** The request has failed due to a passenger announcement on the seatback monitor is in progress */
    PACSeatBookmarksErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to the device not being paired to the seatback monitor. */
    PACSeatBookmarksErrorNotPaired                        = 1600,
    /** The request has failed due to an invalid or missing parameter in the request. */
    PACSeatBookmarksErrorInvalidParameters                = 1601,
    /** The request has failed because the seat rejected the command. */
    PACSeatBookmarksErrorRejected                         = 1701
}PACSeatBookmarksErrorCode;

/**
 * The completion block that is called when sendRequestToRetrieveBookmarksFromSeatWithExtras:completionHandler: finished executing the request.
 * @param mediaBoomarks The array of media bookmarks on the seat. Nil on error.
 * @param error The error object that defined the reason why the request has failed. Please refer to PACSeatBookmarksErrorCode for possible error codes.
 * @see PACSeatBookmarksErrorCode
 * @see PACMediaBookmark
 */
typedef void (^PACSeatBookmarksV1RetrieveBookmarksCompletionBlock)(NSArray <PACMediaBookmark *> * _Nullable mediaBoomarks, NSError * _Nullable error);

/**
 * The completion block that is called when sendRequestToPushBookmarksToSeat:withExtras:completionHandler: finished executing the request.
 * @param error The error object that defined the reason why the request has failed. Please refer to PACSeatBookmarksErrorCode for possible error codes.
 * @see PACSeatBookmarksErrorCode
 */
typedef void (^PACSeatBookmarksV1PushBookmarksCompletionBlock)(NSError * _Nullable error);

/**
 * Request to retrieve all bookmarks from the seat.
 *
 * @param extras The extras parameters to be passed to the seat.
 * @param completion The completion handler that will be called when an error occurs or when the request ends.
 *
 */
- (void)sendRequestToRetrieveBookmarksFromSeatWithExtras:(NSDictionary * _Nullable)extras
                                       completionHandler:(PACSeatBookmarksV1RetrieveBookmarksCompletionBlock _Nonnull)completion;


/**
 * Request to append or update bookmarks on the seat.
 *
 * @param mediaBoomarks The media bookmarks to push to the seat.
 * @param extras The extras parameters to be passed to the seat.
 * @param completion The completion handler that will be called when an error occurs or when the request ends.
 *
 */
- (void)sendRequestToPushBookmarksToSeat:(NSArray <PACMediaBookmark *> * _Nonnull)mediaBoomarks
                              withExtras:(NSDictionary * _Nullable)extras
                       completionHandler:(PACSeatBookmarksV1PushBookmarksCompletionBlock _Nonnull)completion;


/**
 * @constantgroup PACSeatBookmarksExtras
 * The list of predefined extras for PACSeatBookmarksV1 apis.
 * @owner PACSeatBookmarksV1
 */

/**
 * Specifies whether bookmarks should be appended to the queue or clearer.
 *
 * The value should be of type [NSNumber boolValue].
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatBookmarksExtraAppendBookmarks;

@end
