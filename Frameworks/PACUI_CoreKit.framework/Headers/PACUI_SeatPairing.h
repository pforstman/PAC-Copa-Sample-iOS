/*!
 @module PACUI_CoreKit.framework
 */
//
//  PACUI_SeatPairing.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 5/1/17.
//  Copyright © 2017 Panasonic Avionics Corporation. All rights reserved.
//


/*!
 * @typedef PACUISeatPairingPairStatus
 * @brief The device pair status.
 * @owner PACUI_SeatPairing
 */
typedef enum {
    /// Pairing status is unknown.
    PACUISeatPairingPairStatusUnknown = 0,
    /// Pairing status is unpaired.
    PACUISeatPairingPairStatusUnpaired,
    /// Pairing status is paired.
    PACUISeatPairingPairStatusPaired
} PACUISeatPairingPairStatus;


/*!
 * @discussion
 * This class is responsible for starting a pairing session between
 * a passenger's personal electronic device (PED) and the interactive 
 * seatback monitor.
 */
@interface PACUI_SeatPairing : NSObject


/*!
 * Returns the seat pairing status, such as paired, unpaired
 * or unknown, for this device.
 *
 * Refer to PACUISeatPairingPairStatus. Pairing status is known
 * only after PACUISeatPairingPairStatusDidChangeNotification
 * is dispatched.
 */
@property (nonatomic, assign, readonly) PACUISeatPairingPairStatus pairStatus;


/*!
 * Returns the seat number that this device is paired with.
 *
 * Seat number is populated only if pairStatus is
 * PACUISeatPairingPairStatusPaired. Seat number is nil if
 * pairStatus is PACUISeatPairingPairStatusUnknown or 
 * PACUISeatPairingPairStatusUnpaired.
 */
@property (nonatomic, copy, readonly) NSString  * _Nullable seatNumber;


/*!
 * @discussion
 * Asks the Mini-App to begin the seat pairing process.
 * This will have the effect of opening the seat pairing
 * overlay allowing the user to input a seat pairing code
 * provided by the interactive seatback monitor.
 * If the pairing is ultimately successful, the Mini-App
 * will dispatch PACUISeatPairingPairStatusDidChangeNotification.
 */
- (void)pairWithSeatback;


/*!
 * @discussion
 * Asks the Mini-App to close a seat pairing session.
 * If the unpairing is successful, the Mini-App will dispatch
 * PACUISeatPairingPairStatusDidChangeNotification.
 */
- (void)unpairWithSeatback;


@end


#pragma mark - Notifications


/*!
 * @brief Event dispatched when the mini plalyer's seat pairing status changes.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACUISeatPairingPairStatusDidChangeNotification;

