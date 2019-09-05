/** @module PACCoreKit.framework *///
//  PACSystemV1.h
//  InFlight iOS SDK
//  Copyright (c) 2014 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 * The PACSystemPAState enum contains bitmaks representing the system PA states.
 * @owner PACSystemV1
 */
typedef enum {
    /** PACSystemPAStateOff PA is off */
    PACSystemPAStateOff = 0,
    /** Audio PA is on */
    PACSystemPAStateAudio = 1 << 0,
    /** Video PA is on */
    PACSystemPAStateVideo = 1 << 1,
    /** Video Announcement PA is on */
    PACSystemPAStateVideoAnnouncement = 1 << 2,
    /** Overhead Video PA is on */
    PACSystemPAStateOverheadVideo = 1 << 3,
    /** Other PA type is on */
    PACSystemPAStateOther = 1 << 7
} PACSystemPAState;


/**
 * The PACSystemWeightOnWheelsState defines the possible states of Weight on Wheels.
 * @owner PACSystemV1
 */
typedef enum {
    /** The plane is in the air. */
    PACSystemWeightOnWheelsStateAir = 0,
    /** The plane is on the ground. */
    PACSystemWeightOnWheelsStateGround = 1,
    /** The plane weight on wheel state is unknown. */
    PACSystemWeightOnWheelsStateUnknown = 2,
} PACSystemWeightOnWheelsState;

/**
 * This is the class offers services to provide information on the system updates.
 */
@interface PACSystemV1 : InFlightService

/**
 *  Returns system's Passenger Announcement state.
 *
 * @return Returns the value of the system's PA state. Refer to PACSystemPAState
 *
 * @deprecated First deprecated in InFlight iOS SDK 02.04.00.00. Use the identical function [SystemV1 passengerAnnouncementState] instead.
 */

- (PACSystemPAState) getPAState __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 02.04.00.00. Use the identical function [SystemV1 passengerAnnouncementState] instead.")));

/**
 *  Returns system's Passenger Announcement state.
 *
 * @return Returns the value of the system's PA state. Refer to PACSystemPAState.
 */

- (PACSystemPAState) passengerAnnouncementState;

/**
 *  Returns system's Decompression state.
 *
 * @return Returns TRUE if decompression is active.
 */
- (BOOL)decompressionState;

/**
 *  Returns system's weight on wheel state.
 *
 * @return Returns the state of the weight on wheels.
 */
- (PACSystemWeightOnWheelsState)weightOnWheelsState;


/**
 *  Subscribes for system events.
 *
 * @param systemEvents An array of strings representing the system events. See PACSystemV1 Notifications for possible values.
 */

- (void) subscribe:(NSArray *)systemEvents;

/**
 *  Unsubscribes for system events.
 *
 * @param systemEvents An array of strings representing the system events. See PACSystemV1 Notifications for possible values.
 */

- (void) unsubscribe:(NSArray *)systemEvents;

@end

/**
 * Dispatched when decompression of system happens
 * @owner PACSystemV1
 */

FOUNDATION_EXPORT NSString *const PACSystemDecompressionNotification;

/**
 * Dispatched when the PA state changes
 * @owner PACSystemV1
 */

FOUNDATION_EXPORT NSString *const PACSystemPAStateNotification;

/**
 * Dispatched when the aircraft lands on the ground
 * @owner PACSystemV1
 */

FOUNDATION_EXPORT NSString *const PACSystemWeightOnWheelsNotification;

/**
 * Dispatched when a crew member sends a message to all connected PED devices.
 *
 * The notification includes a payload with information regarding the message
 *
 * *userinfo* The payload associated with the notification.
 * - *message* An NSString object representing the message that was sent.
 * - *timestamp* An NSNumber object representing the timestamp of when the message was sent.
 *
 * @owner PACSystemV1
 */
FOUNDATION_EXPORT NSString* const   PACSystemCrewMessageReceivedForAllPEDsNotification;
FOUNDATION_EXPORT NSString* const       PACSystemCrewMessageReceivedForAllPEDsUserInfo_MessageKey;
FOUNDATION_EXPORT NSString* const       PACSystemCrewMessageReceivedForAllPEDsUserInfo_TimestampKey;
