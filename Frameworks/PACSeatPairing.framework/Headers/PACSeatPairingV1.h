/** @module PACSeatPairing.framework *///
//  PACSeatPairingV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015-2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

#pragma mark - Seat Pairing Result

@class PACSeatRemoteControlV1;
@class PACSeatPreferencesV1;
@class PACSeatRemoteMediaQueueV1;
@class PACSeatFavoritesTransferV1;
@class PACSeatPropertyTransferV1;
@class PACSeatBookmarksV1;
@class PACSeatLoginV1;

/**
 * The return code of the pairing API calls.
 * @owner PACSeatPairingV1
 */
typedef enum{
    /** Request queued successfully. */
    PACSeatPairingResultQueued = 0,
    /** Request failed and device is not paired. */
    PACSeatPairingResultNotPaired,
    /** Request failed due to the device being currently paired. */
    PACSeatPairingResultAlreadyPaired,
    /** Request failed due to invalid or missing parameters. */
    PACSeatPairingResultInvalidParams,
}PACSeatPairingResult;

#pragma mark - Seat Pairing Pair Status

/**
 * Device pairing status
 * @owner PACSeatPairingV1
 */
typedef enum{
    /** Status is unknown. */
    PACSeatPairingPairStatusUnknown = 0,
    /** Device is unpaired. */
    PACSeatPairingPairStatusUnpaired,
    /** Device is paired. */
    PACSeatPairingPairStatusPaired,
    /** Device is blocked. */
    PACSeatPairingPairStatusBlocked,
    /** Pairing is disabled. */
    PACSeatPairingPairStatusDisabled
}PACSeatPairingPairStatus;

#pragma mark - Error Codes

/**
 * The error codes for the Seat Pairing API call.
 * @owner PACSeatPairingV1
 */
typedef enum {
    /** Request has failed due to an unknown error. */
    PACSeatPairingPairErrorUnknown                         = 1200,
    /** Request has failed due to missing or incorrect parameters. */
    PACSeatPairingPairErrorBadRequest                      = 1201,
    /** Request has failed due to an invalid passcode. */
    PACSeatPairingPairErrorInvalidPasscode                 = 1202,
    /** Request has failed due to the device being paired with another seatback monitor. */
    PACSeatPairingPairErrorDeviceAlreadyPaired             = 1203,
    /** Request has failed due to the seatback monitor timing out.*/
    PACSeatPairingPairErrorSeatTimedout                    = 1204,
    /** Request has failed due to the seatback monitor not responding. */
    PACSeatPairingPairErrorSeatNotResponding               = 1205,
    /** Request has failed due to the seatback monitor rejecting the pairing request. */
    PACSeatPairingPairErrorSeatRejectedPairingRequest      = 1206,
    /** Request has failed due to the seatback monitor returning an unexpected response. */
    PACSeatPairingPairErrorSeatBadResponse                 = 1207,
    /** Request has failed due to a connection error. */
    PACSeatPairingPairErrorConnectionError                 = 1208,
    /** Request has failed due to the server returning an incorrect response. */
    PACSeatPairingPairErrorBadResponse                     = 1209,
    /** Request has failed due to the service being unavailable. */
    PACSeatPairingPairErrorServiceNotFound                 = 1210,
    /** Request has failed due to the seatback monitor being in the process of pairing with another device. */
    PACSeatPairingPairErrorSeatInUse                       = 1211,
    /** Request has failed due to the device being temporarily blocked by too many pairing attempts. */
    PACSeatPairingPairErrorTemporarilyBlocked              = 1212,
    /** Request has failed due to a passenger announcement in progress */
    PACSeatPairingPairErrorSeatPAInProgress                = 1213,
    /** Request has failed due to the pairing service being disabled */
    PACSeatPairingPairErrorPairingServiceDisabled          = 1214
}PACSeatPairingPairErrorCode;

/**
 * The error codes for the seat unpairing API call.
 * @owner PACSeatPairingV1
 */
typedef enum {
    /** Request has failed due to an unknown error. */
    PACSeatPairingUnPairErrorUnknown                       = 1300,
    /** Request has missing or incorrect parameters. */
    PACSeatPairingUnPairErrorBadRequest                    = 1301,
    /** Request failed due to an internal error. Please contact manufacturer. */
    PACSeatPairingUnPairErrorInternalError                 = 1302,
    /** Request has failed. Please try again later. */
    PACSeatPairingUnPairErrorUnpairFailed                  = 1303,
    /**   */
    PACSeatPairingUnPairErrorConnectionError               = 1304,
    /** Request has failed due to the server returning an unexpected response. */
    PACSeatPairingUnPairErrorBadResponse                   = 1305,
    /** Request has failed due to the service not found. */
    PACSeatPairingUnPairErrorServiceNotFound               = 1306,
    /** Request has failed due to a passenger announcement being in progress */
    PACSeatPairingUnPairErrorSeatPAInProgress              = 1307,
    /** Request has failed because pairing service is disabled */
    PACSeatPairingUnPairErrorPairingServiceDisabled        = 1308
}PACSeatPairingUnPairErrorCode;

/**
 * The error codes for the initiate seat pairing API call.
 * @owner PACSeatPairingV1
 */
typedef enum {
    /** Request has failed due to an unknown error. */
    PACSeatPairingInitiatePairErrorUnknown                 = 1400,
    /** Request has failed due to missing or incorrect parameters. */
    PACSeatPairingInitiatePairErrorBadRequest              = 1401,
    /** Request has failed due to the device currently being paired with another seatback monitor. */
    PACSeatPairingInitiatePairErrorDeviceAlreadyPaired     = 1402,
    /** Request has failed due to the device currently paired with the seatback monitor. */
    PACSeatPairingInitiatePairErrorPairSessionExists       = 1403,
    /** Request has failed due to the seatback monitor not being available. */
    PACSeatPairingInitiatePairErrorSeatNotFound            = 1404,
    /** Request has failed due to the seatback monitor currently paired with another device. */
    PACSeatPairingInitiatePairErrorSeatInUse               = 1405,
    /** Request has failed due to the seatback monitor timing out. */
    PACSeatPairingInitiatePairErrorSeatTimedout            = 1406,
    /** Request has failed due to the seatback monitor not responding. */
    PACSeatPairingInitiatePairErrorSeatNotResponding       = 1407,
    /** Request has failed due to the seatback monitor returning an unexpected response. */
    PACSeatPairingInitiatePairErrorSeatBadResponse         = 1408,
    /** Request has failed due to a connection error. */
    PACSeatPairingInitiatePairErrorConnectionError         = 1409,
    /** Request has failed due to an unexpected response from the server. */
    PACSeatPairingInitiatePairErrorBadResponse             = 1410,
    /** Request has failed due to the unavailability of the service. */
    PACSeatPairingInitiatePairErrorServiceNotFound         = 1411,
    /** Request has failed due to the device being temporarily blocked by too many attempts. */
    PACSeatPairingInitiatePairErrorTemporarilyBlocked      = 1412,
    /** Request has failed due to the passenger announcement being in progress */
    PACSeatPairingInitiatePairErrorSeatPAInProgress        = 1413,
    /** Request has failed due to pairing service being disabled */
    PACSeatPairingInitiatePairErrorPairingServiceDisabled  = 1414
}PACSeatPairingInitiatePairErrorCode;


#pragma mark - Interface

/**
 This class is responsible for starting a pairing session between a passenger's personal electronic device (PED) and the interactive seatback monitor. The two pairing modes are: Passcode and NFC. Passcode allows the passenger to manually enter a passcode on the seatback monitor. NFC allows a passenger to pair by tapping their device on the seatback monitor.
 
 Pairing a personal device with a seatback monitor allows passengers to use their devices to control and view media content and other information, such as a favorites list, on the seatback monitor and video handset. Information is shared only during pairing.
 
 // Class vairables and properties
 PACSeatPairingV1 seatPairing;
 
 // Initialize PACSeatPairingV1 service
 - (void) initializeSeatPairing{
 self.seatPairing = [PACSeatPairingV1 initService:nil];
 }
 */
@interface PACSeatPairingV1 : InFlightService

/**
 * Returns the seat pairing status, such as paired, unpaired or unknown, for this device.
 *
 * Refer to PACSeatPairingPairStatus. Pairing status is known only after PACSeatPairingPairStatusDidChangeNotification is dispatched.
 */
@property (nonatomic,assign,readonly) PACSeatPairingPairStatus pairStatus;

/**
 * Returns the seat number that this device is paired with.
 *
 * Seat number is populated only if pairStatus is PACSeatPairingPairStatusPaired. Seat number is nil if pairStatus is PACSeatPairingPairStatusUnknown or PACSeatPairingPairStatusUnpaired
 */
@property (nonatomic,strong,readonly) NSString * _Nullable seatNumber;

/**
 * Returns the seat class of the seat that this device is paired with.
 *
 * Seat class is populated only if pairStatus is PACSeatPairingPairStatusPaired. Seat class is nil if pairStatus is PACSeatPairingPairStatusUnknown or PACSeatPairingPairStatusUnpaired
 */
@property (nonatomic,strong,readonly) NSString * _Nullable seatClass;

/**
 * Returns true if device is already paired. Returns false if device is unpaired or pairing status not yet known.
 *
 * Pairing status is known only after a successful execution of the [PACSeatPairingV1 initiatePairingSessionWithSeatNumber:deviceName:deviceMessage:completionHandler:],
 * [PACSeatPairingV1 pairWithPasscode:seatNumber:deviceName:deviceMessage:completionHandler:], or [PACSeatPairingV1 unpairWithCompletionHandler:]
 * API requests.
 * @deprecated This property is deprecated starting from framework version 03.00.00.00. Please use pairStatus instead.
 */
@property (nonatomic,assign,readonly) BOOL isPaired
__attribute__((deprecated("This property is deprecated starting from framework version 03.00.00.00. Please use pairStatus instead.")));


/**
 * Returns the remote media queue service that will handle mirroring and controlling
 *
 * the seatback monitor media queue. The media queue allows a passenger to control and view video or audio media in either the seatback monitor or PED.
 * @return The PACSeatRemoteMediaQueueV1 instance associated with the seat pairing session.
 */
- (PACSeatRemoteMediaQueueV1 * _Nonnull)remoteMediaQueueService;

/**
 * Returns the remote control service that will handle the playback controls for
 * the media player on the seatback monitor.
 *
 * @return The PACSeatRemoteControlV1 instance associated with the seat pairing session.
 */
- (PACSeatRemoteControlV1 * _Nonnull)remoteControlService;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
/**
 * Returns the seatback monitor preferences service that will handle updating the seatback monitor
 * preference values. This provides the ability to customize properties, such as display messages that contain the passenger's name, frequent flyer information and upcoming flights.
 *
 * @return The PACSeatPreferencesV1 instance associated to the seat pairing session.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 03.03.00.04. Please use the class [PACSeatPairingV1 seatPropertyTransferService] instead.
 */
- (PACSeatPreferencesV1 * _Nonnull)seatPreferencesService __attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 03.03.00.04. Please use the class [PACSeatPairingV1 seatPropertyTransferService] instead.")));
#pragma clang diagnostic pop

/**
 * Returns the seatback monitor property transfer service that will handle setting the seatback monitor property values. This provides the ability to customize properties, such as display messages that contain the passenger's name, frequent flyer information and upcoming flights.
 *
 * @return The PACSeatPropertyTransferV1 instance associated to the seat pairing session.
 */
- (PACSeatPropertyTransferV1 * _Nonnull)seatPropertyTransferService;

/**
 * Returns the 'seat <-> ped' favorites bridge service that will handle bridging commands from the seatback monitor to the PED and vice versa.
 *
 * @return The PACSeatFavoritesBridgeV1 instance associated to the seat pairing session.
 */
- (PACSeatFavoritesTransferV1 * _Nonnull)seatFavoritesTransferService;

/**
 * Returns bookmarks service that will handle retrieving and setting bookmarks in the seatback monitor.
 *
 * @return The PACSeatBookmarksV1 instance associated to the seat pairing session.
 */
- (PACSeatBookmarksV1 * _Nonnull)seatBookmarksService;

/**
 * Returns login service that will handle logging in the seat with user credentials.
 *
 * @return The PACSeatLoginV1 instance associated to the seat pairing session.
 */
- (PACSeatLoginV1 * _Nonnull)seatLoginService;

/**
 * Initiate a pairing session request with the seatback monitor. This will allow the seatback monitor
 * to know that the PED requested to pair with it.
 *
 * If the seat is already paired with the device when the request was made, you will
 * get a PACSeatPairingInitiatePairErrorPairSessionExists error code in the completion handler.
 * At that point you can skip the pairWithPasscode api call.
 * @param seatNumber The seat number. This field is required.
 * @param deviceName The name of the device. This field is optional.
 * @param deviceMessage The message from the device to be dispayed on the seatback monitor. This field is optional.
 * @param completed The completion handler.
 *
 *   - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatPairingInitiatePairErrorCode for error codes.
 * @return The result status of the request.
 */
- (PACSeatPairingResult)initiatePairingSessionWithSeatNumber:(NSString * _Nonnull)seatNumber
                                                  deviceName:(NSString * _Nullable)deviceName
                                               deviceMessage:(NSString * _Nullable)deviceMessage
                                           completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completed;


/**
 * Pair a device with a seatback monitor.
 *
 * @param passcode Passcode that displays on the seatback monitor. This field is required.
 * @param seatNumber Seat number. This field is optional.
 * @param deviceName Name of the device used for personalizing messages. This field is optional.
 * @param deviceMessage The message from the device to be dispayed on the seatback monitor. This field is optional.
 * @param completed The completion handler.
 *
 *   - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatPairingPairErrorCode for error codes.
 * @return The result status of the request.
 */
- (PACSeatPairingResult)pairWithPasscode:(NSString * _Nonnull)passcode
                              seatNumber:(NSString * _Nullable)seatNumber
                              deviceName:(NSString * _Nullable)deviceName
                           deviceMessage:(NSString * _Nullable)deviceMessage
                       completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completed;

/**
 * Pair a device with a seatback monitor by NFC.
 *
 * @param alertMessage The message to display when the NFC popup has been presented. This field is optional.
 * @param deviceName The name of the device. This field is optional.
 * @param deviceMessage The message from the device to be dispayed on the seatback monitor. This field is optional.
 */
- (void)startNfcPairSessionWithAlertMessage:(NSString * _Nullable)alertMessage
                                 deviceName:(NSString * _Nullable)deviceName
                              deviceMessage:(NSString * _Nullable)deviceMessage;


/**
 * Unpair a device from a seatback monitor.
 *
 * @param completed The completion handler.
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatPairingUnPairErrorCode for error codes.
 * @return The result status of the request.
 */
- (PACSeatPairingResult)unpairWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completed;

/**
 * Show passcode on seatback for pairing.
 *
 * This function can only be called after pair initiation and has requested passcode.
 * @param completed The completion handler.
 * - *error* If error is nil, no error has occurred.
 */
- (void)showPasscodeOnSeatWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completed;


#pragma mark - Notifications


/**
 * Event dispatched when a device pair status has changed.
 *
 * This notification will be dispatched after a user-initiated pair or unpair, on network connect or disconnect, or at service initialization. Check pairStatus for updated status after receiving this event.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingPairStatusDidChangeNotification;


/**
 * Event dispatched when a user rejects a pair request on a seatback monitor.
 *
 * *userinfo* The userinfo includes a payload information describing which seat rejected the pair.
 *
 *  - *seat* - The seat number. This object is of type NSString.
 *
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingDidRejectInitiatePairNotification;

/**
 * Event dispatched when a user changes pairing mode to pair to a seatback monitor.
 *
 * *userinfo* The userinfo includes a "PairMode" string field describing the new pairing mode.
 *
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingDidPairModeChangeNotification;

/**
 * Event dispatched when a device pairing to a seatback monitor by NFC.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingPairNfcNotification;

/**
 * Event dispatched when a device fails to pair to a seatback monitor using NFC.
 *
 * *userinfo* The user info field "error" describing the error.
 *
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingPairNfcErrorNotification;

/**
 * Event dispatched when a device pairing has occurred.
 *
 * @deprecated This event is deprecated starting from framework version 03.00.00.00. Please use PACSeatPairingPairStatusDidChangeNotification instead.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingDidPairNotification __attribute__ ((deprecated("This event is deprecated starting from framework version 03.00.00.00. Please use PACSeatPairingPairStatusDidChangeNotification instead.")));

/**
 * Event dispatched when a device has unpaired.
 *
 * @deprecated This event is deprecated starting from framework version 03.00.00.00. Please use PACSeatPairingPairStatusDidChangeNotification instead.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatPairingDidUnPairNotification __attribute__ ((deprecated("This event is deprecated starting from framework version 03.00.00.00. Please use PACSeatPairingPairStatusDidChangeNotification instead.")));



@end

