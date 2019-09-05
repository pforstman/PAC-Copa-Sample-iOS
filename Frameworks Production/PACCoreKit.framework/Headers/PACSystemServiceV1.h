/** @module PACCoreKit.framework *///
//  PACSystemServiceInfoV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//


#import <PACCoreKit/PACCoreKit.h>

/**
 * The service state.
 * @owner PACSystemServiceInfo
 */
typedef enum {
    /** The service is currently disabled. */
    PACSystemServiceStateOff,
    /** The service is currently enabled. */
    PACSystemServiceStateOn,
    /** The service is blocked. */
    PACSystemServiceStateBlocked
}PACSystemServiceState;


/**
 * This class a data structure for service info
 */
@interface PACSystemServiceInfo : NSObject

/** 
 * The current service state. Please refer to PACSystemServiceState.
 */
@property (nonatomic,assign,readonly) PACSystemServiceState state;

/**
 * The service code of the system service.  Please refer to PACSystemServiceCodes.
 */
@property (nonatomic,strong,readonly) NSString *serviceCode;

/**
 * The display name of the system service.
 */
@property (nonatomic,copy,readonly) NSString *displayName;

@end

/**
 * @constantgroup PACSystemServiceCodes
 * The following list are some of the default service codes.
 * @owner PACSystemServiceV1
 */

/**
 * The service code for the AOD service.
 */
extern NSString *const PACSystemServiceCodeAOD;

/**
 * The service code for the VOD service.
 */
extern NSString *const PACSystemServiceCodeVOD;

/**
 * The service code for the AVOD service.
 */
extern NSString *const PACSystemServiceCodeAVOD;

/**
 * The service code for the PPV service.
 */
extern NSString *const PACSystemServiceCodePPV;


/**
 * The system service error codes.
 * @owner PACSystemServiceV1
 */
typedef enum {
    /** An unknown error occurred. */
    PACSystemServiceErrorCodeUnknown = 2000,
    /** The available service list is not ready. Illegal call. */
    PACSystemServiceErrorCodeServicesNotReady = 2001,
    /** The service code requested is not found. */
    PACSystemServiceErrorCodeServiceCodeNotFound = 2002,
    /** Failed to reach the server. */
    PACSystemServiceErrorCodeConnectionError = 2003,
}PACSystemServiceErrorCode;

/**
 * PACSystemServiceV1 is a service class that provides information about
 * all services on the headend and changes in the services
 *
 * [Download Sample Project](../../samples/PACCoreKit/SampleSystemServiceApplication.zip)
 */
@interface PACSystemServiceV1 : InFlightService

/**
 * Returns the state of the system service.
 * @param serviceCode The service code of the system service. Please see PACSystemServiceCodes for possible default values.
 * @param error A pointer to the error the object that would be populated if an error has occurred. Please refer to PACSystemServiceErrorCode for possible error codes.
 * @return The state of the service. Please refer to PACSystemServiceState for possible states. If error parameter is set, you should ignore the return value.
 */
- (PACSystemServiceState) stateForService:(NSString *)serviceCode error:(NSError **)error;

/**
 * Returns the display name of the system service.
 * @param serviceCode The service code of the system service. Please see PACSystemServiceCodes for possible default values.
 * @param error A pointer to the error the object that would be populated if an error has occurred. Please refer to PACSystemServiceErrorCode for possible error codes.
 * @return The display name of the service. If error parameter is set, you should ignore the return value.
 */
- (NSString* ) displayNameForService:(NSString *)serviceCode error:(NSError **)error;

/**
 * Returns an array of PACSystemServiceInfo objects for all available services.
 */
@property (nonatomic,strong,readonly) NSArray *availableServices;

@end

/**
 * Dispatched when the number of available services changed.
 * @owner PACSystemServiceV1
 */
extern NSString *const PACSystemServiceAvailableServicesDidChangeNotification;

/**
 * Dispatched when the info of a service changed.
 *
 * Dispatched when the info of a service changed.
 *
 * *userinfo* The payload of this notification will include an array of PACSystemServiceInfo objects that has changed.
 *
 * - *services* An array of PACSystemServiceInfo objects that has changed.
 *
 * @owner PACSystemServiceV1
 */
extern NSString *const PACSystemServiceStateDidChangeNotification;

/**
 * Dispatched when there was an error in retrieving info about services.
 *
 * Dispatched when there was an error in retrieving info about services.
 *
 * *userinfo* The payload of this notification will include the error object.
 *
 * - *error* The NSError object that describes the reason for the error.
 *
 * @owner PACSystemServiceV1
 */
extern NSString *const PACSystemServiceErrorNotification;

