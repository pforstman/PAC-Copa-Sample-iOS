/** @module PACCoreKit.framework *///
//  PACServiceDiscoveryService.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  The service object containing information about a specific service. 

Service discovery provides a list of services, such as media and hospitality, that a passenger can access on their flight. For instance, passengers on the ground can access the movies available on their flight and create a playlist for viewing during their flight.
 */
@interface PACServiceDiscoveryService : NSObject

/**
 * The state of a service.
 */
typedef enum{
    /**
     * The service state is currently unknown.
     * Please wait for PACServiceDiscoveryServiceStateDidChangeNotification.
     */
    PACServiceDiscoveryServiceStateUnknown,
    /** Service is enabled. */
    PACServiceDiscoveryServiceStateEnabled,
    /** Service is disabled. */
    PACServiceDiscoveryServiceStateDisabled,
    /** Service is not available. */
    PACServiceDiscoveryServiceStateNotAvailable
}PACServiceDiscoveryServiceState;

/**
 * Service name.
 *
 * Please refer to PACServiceDiscoveryServiceNames for a list of the service names.
 */
@property (nonatomic,retain, readonly) NSString * _Nonnull serviceName;

/**
 * Service state.
 *
 * Please refer to PACServiceDiscoveryServiceState for a list of service states.
 */
@property (nonatomic,assign, readonly) PACServiceDiscoveryServiceState serviceState;

/**
 * Service capabilities.
 *
 * Please refer to PACServiceDiscoveryServiceCapibilities for a list of service capabilities.
 */
@property (nonatomic,retain, readonly) NSArray <NSString *> *  _Nullable serviceCapabilities;

@end
