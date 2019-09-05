/** @module PACSeatPairing.framework *///
//  PACSeatFavoritesTransferV1.h
//  SeatPairing
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class acts as a bridge to manage sharing and retrieving of the Favorites List between the personal electronic device (PED) and seatback monitor.
 */
@interface PACSeatFavoritesTransferV1 : NSObject

/**
 * @constantgroup PACSeatFavoritesTransferErrorDomains
 * The list of error domains for PACSeatFavoritesTransferV1.
 * @owner PACSeatFavoritesTransferV1
 */

/**
 * This key defines the general error domain for PACSeatFavoritesTransferV1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatFavoritesTransferErrorDomain;

/**
 * The error codes returned the remote control requests.
 */
typedef enum{
    /** The request has failed due to an unknown error. */
    PACSeatFavoritesTransferErrorUnknown                          = 1500,
    /** The request has failed due to invalid or missing parameters in the request.
     */
    PACSeatFavoritesTransferErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatFavoritesTransferErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatFavoritesTransferErrorConnectionError                  = 1503,
    /** The request has failed due to the server returning an unexpected response. */
    PACSeatFavoritesTransferErrorBadResponse                      = 1504,
    /** The request has failed due to the service being unavailable. */
    PACSeatFavoritesTransferErrorServiceNotFound                  = 1505,
    /** The request has failed due to a passenger announcement on the seatback monitor is in progress */
    PACSeatFavoritesTransferErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to the device not being paired to the seatback monitor. */
    PACSeatFavoritesTransferErrorNotPaired                        = 1600,
    /** The request has failed due to an invalid or missing parameter in the request. */
    PACSeatFavoritesTransferErrorInvalidParameters                = 1601,
    /** The request has failed because the seat rejected the command. */
    PACSeatFavoritesTransferErrorRejected                         = 1701
}PACSeatFavoritesTransferErrorCode;

/**
 * Request to load favorites items to the seatback monitor. On receipt of the PACSeatFavoritesTransferRequestFromSeatToFetchFavoriteListNotification event,
 * the app developer can prompt the user to share the Favorites List with the seatback monitor. In order for the user to share the favorites list,
 * this function must be called by the app developer.
 *
 * @param items The serialized array of dictionaries as exported by [PACFavoritesListV1 serializedData].
 * @param extras The extras parameters to be passed to the seatback monitor.
 * @param completion The completion handler that will be called when an error occurs or when the request ends.
 *
 */
- (void)sendRequestToLoadFavoritesItemsToSeat:(NSArray <NSDictionary *> * _Nonnull)items
                                       extras:(NSDictionary * _Nullable)extras
                        withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Request to add Favorites items to the seatback monitor. On receipt of the PACSeatFavoritesTransferRequestFromSeatToFetchFavoriteListNotification event,
 * the app developer can prompt the user to share the Favorites List to the seatback monitor. In order for the user to share the Favorites List,
 * this function must be called by the app developer.
 *
 * @param items The serialized array of dictionaries as exported by [PACFavoritesListV1 serializedData].
 * @param extras The extras parameters to be passed to the seatback monitor.
 * @param completion The completion handler that will be called when an error occurs or when the request ends.
 */
- (void)sendRequestToAddFavoritesItemsToSeat:(NSArray <NSDictionary *> * _Nonnull)items
                                      extras:(NSDictionary * _Nullable)extras
                       withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Request to remove items from the Favorites List on the seatback monitor.
 *
 * @param items The serialized array of dictionaries as exported by [PACFavoritesListV1 serializedData].
 * @param extras The extras parameters to be passed to the seatback monitor.
 * @param completion The completion handler that will be called when the request succeeds or an error occurs.
 */
- (void)sendRequestToRemoveFavoritesItemsFromSeat:(NSArray <NSDictionary *> * _Nonnull)items
                                           extras:(NSDictionary * _Nullable)extras
                            withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Request to remove all Favorites items from the seatback monitor.
 * @param extras The extras parameters to be passed to the seat.
 * @param completion The completion handler that will be called when an error occurs or when the request succeeds.
 */
- (void)sendRequestToClearFavoritesItemsFromSeatWithExtras:(NSDictionary * _Nullable)extras
                                         completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Pulls the favorites list from the seatback monitor to the PED.
 * @param extras The extras parameters to be passed to the seatback monitor.
 * @param completion The completion handler that will be called when the request succeeds or an error occurs. The structure for items is compatible with the serialized data structure of PACFavoritesListV1.
 */
- (void)sendRequestToPullFavoritesItemsFromSeatWithExtras:(NSDictionary * _Nullable)extras
                                        completionHandler:(void (^ _Nullable)(NSArray <NSDictionary *> * _Nullable items, NSError * _Nullable error))completion;

/**
 Dispatched when the seatback monitor requests for the favorites list on the PED.
 
 The userInfo dictionary will include the pending item to be added.
 
 - *extras* An NSDictionary object containing extra information passed from seat.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatFavoritesTransferRequestFromSeatToFetchFavoriteListNotification;

/**
 Dispatched when the seatback monitor requests to add a favorite item to the favorites list on the PED.
 
 The userInfo dictionary will include the pending item to be added.
 
 - *items* The pending items. The type is NSArray of NSDictionary items. This structure is compatible with the serialized data structure of PACFavoritesListV1.
 
 */

FOUNDATION_EXPORT NSString * _Nonnull const PACSeatFavoritesTransferRequestFromSeatToAddItemsNotification;

/**
 Dispatched when the seatback monitor requests to remove a favorite item from the favorites list on the PED.
 
 The userInfo dictionary will include the to-be-removed item.
 
 - *items* The pending items. The type is NSArray of NSDictionary items. This structure is compatible with the serialized data structure of PACFavoritesListV1.
 
 */

FOUNDATION_EXPORT NSString * _Nonnull const PACSeatFavoritesTransferRequestFromSeatToRemoveItemsNotification;

@end
