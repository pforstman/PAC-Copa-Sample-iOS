/** @module PACCoreKit.framework *///
//  PACServiceDiscoveryV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>
#import <PACCoreKit/PACServiceDiscoveryService.h>

/**
 The PACServiceDiscovery API allows passengers to quickly discover the services, such as media or hospitality, available on the aircraft. For instance, passengers on the ground can access the movies available on their flight and create a playlist for viewing during their flight.
 
 This class lists all available services and their corresponding state. You can also verify the reachability with the InFlight server.

 [Download Sample Project](../../samples/PACCoreKit/SampleServiceDiscoveryApplication.zip)
 
 ***Example***
 
        // Class vairables and properties
        PACServiceDiscoveryV1 *serviceDiscovery;
 
        //to initialize a PACServiceDiscoveryV1, you can
        - (void) initializeServiceDiscovery{
            // Init service discovery service.
            [PACServiceDiscoveryV1 initServiceWithCompletionBlock:^(id serviceObject, NSError *error) {
                
                if (error !=  nil) {
                    NSLog(@"Failed to initialize ServiceDiscoveryV1 due to an error: %@", error);
                    return;
                }
                
                
                self.serviceDiscovery = serviceObject;
                
                // Add observers for reachability notification
                [[NSNotificationCenter defaultCenter] addObserver:self
                                                         selector:@selector(reachabilityDidChange:)
                                                             name:PACServiceDiscoveryReachabilityDidChangeNotification
                                                           object:self.serviceDiscovery];
            }];
        }
 
        // Reachability notification handler
        - (void)reachabilityDidChange:(NSNotification *)n{
            NSLog(@"Reachability changed: %@",self.serviceDiscovery.isServerReachable?@"connected":@"disconnected");
        }
 
 */
@interface PACServiceDiscoveryV1 : InFlightService

/**
 * The list of available services.
 *
 * This property includes the list of available services. The type of object inside this array is
 * PACServiceDiscoveryService. When the state of available services or services change, the PACServiceDiscoveryServiceStateDidChangeNotification
 * will be dispatched.
 *
 * Please note that nil is returned, if disconnected from the InFlight server.
 */
@property (nonatomic,retain,readonly) NSArray * _Nullable availableServices;

/**
 * Sends a server reachability request.
 *
 * This is a convenience function that checks whether the InFlight server is reachable without initializing a PACServiceDiscoveryV1 instance.
 * @param reachabilityBlock The block executed when reachability request has finished.
 *
 * - *isAvailable* TRUE if server is reachable. FALSE if server is not reachable.
 */
+ (void)sendServerReachabilityRequest:(void (^  _Nonnull)(BOOL isAvailable))reachabilityBlock;

/**
 * The current state of a specific service.
 * @param serviceName The service name of a particular service. Please refer to PACServiceDiscoveryServiceNames for possible service names.
 * @return Returns the current state of the service. Please refer to PACServiceDiscoveryServiceState for possible states.
 */
- (PACServiceDiscoveryServiceState)stateForService:(NSString * _Nonnull)serviceName;

/**
 * The capabilities for a specific service.
 * @param serviceName The service name of a particular service. Please refer to PACServiceDiscoveryServiceNames for possible service names.
 * @return Returns the array of capabilities for the service. Please refer to PACServiceDiscoveryServiceCapibilities for possible capabilities.
 */
- (NSArray <NSString *> * _Nullable)capabilitiesForService:(NSString * _Nonnull)serviceName;

/**
 * Returns whether InFlight server is reachable.
 *
 * A PACServiceDiscoveryReachabilityDidChangeNotification event will be dispatched when the state changes.
 * @return TRUE if server is reachable.
 */
- (BOOL)isServerReachable;

/**
 * Dispatched when a service state has changed.
 *
 * *userinfo* The notification includes a payload identifying the changed service.
 *
 *  - *services* The service objects that changed. The type of the value associated with this key is an NSArray that holds PACServiceDiscoveryService objects.
 *
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceStateDidChangeNotification;

/**
 * Dispatched when the reachability to the server changes.
 *
 * This event is not associated with any notification object.
 *
 * *userinfo* The notification includes a payload identifying the reachability status.
 *
 *  - *value* The value of the reachability state. The object is a boolean of type NSNumber.
 *
 */
extern NSString * _Nonnull const PACServiceDiscoveryReachabilityDidChangeNotification;

/**
 * @constantgroup PACServiceDiscoveryServiceNames
 * Registered service names.
 */

/**
 * Service name for the audio and video on demand (AVOD) metadata service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameAVODMetadata;

/**
 * Service name for the audio and video on demand (AVOD) streaming service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameAVODStreaming;

/**
 * Service name for the search for AVOD service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameSearchAVOD;

/**
 * Service name for the search for games service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameSearchGames; // TBD

/**
 * Service name for the search for shopping items service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameSearchShopping; // TBD

/**
 * Service name for the AVOD payment service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNamePaymentAVOD;

/**
 * Service name for the shopping payment service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNamePaymentShopping;

/**
 * Service name for the eXTV streaming service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameeXTVStreaming;

/**
 * Service name for the eXTV metadata service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameeXTVMetadata;

/**
 * Service name for the metadata news service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameNewsMetadata;

/**
 * Service name for the video news service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameNewsVideo;

/**
 * Service name for the text news service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameNewsText;

/**
 * Service name for the weather news service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameNewsWeather;

/**
 * Service name for the flightdata info service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameFlightdataInfo;

/**
 * Service name for the flightdata progress service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameFlightdataProgress;

/**
 * Service name for the cart AVOD service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCartAVOD; // TBD

/**
 * Service name for the cart shopping service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCartShopping;  // TBD

/**
 * Service name for the cart hospitality service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCartHospitality; // TBD

/**
 * Service name for the parental control service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameParentalControl;

/**
 * Service name for the interactive maps service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameMapsInteractive;

/**
 * Service name for the broadcast maps service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameMapsBroadcast;

/**
 * Service name for the airport info service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameAirportInfo;

/**
 * Service name for the seat pairing remote control service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameSeatPairingRemoteControl;

/**
 * Service name for the seat pairing Wi-Fi pairing service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameSeatPairingWiFiPairing;

/**
 * Service name for the analytic logging service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameAnalyticsLogging;

/**
 * Service name for the analytic statistic service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameAnalyticsStats; // TBD

/**
 * Service name for the advertising service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameAdvertising;

/**
 * Service name for the survey service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameSurvey; // TVD

/**
 * Service name for the cellular service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCellular;

/**
 * Service name for the connecting gate service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameConnectingGate; // TBD

/**
 * Service name for catalog browsing of the shopping service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCatalogBrowsingShopping;

/**
 * Service name for the catalog browsing of the hospitality service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCatalogBrowsingHospitality; // TBD

/**
 * Service name for the catalog browsing of the games service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameCatalogBrowsingGames; // TBD

/**
 * Service name for the Internet service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNameInternet;

/**
 * Service name for the push notification service.
 */
extern NSString * _Nonnull const PACServiceDiscoveryServiceNamePushNotifications;

/**
 * @constantgroup PACServiceDiscoveryServiceCapibilities
 * Registered service capabilities.
 */

/**
 * The seat pairing's wifi pairing service have a capability to initiate pairing from PED.
 */
extern NSString * _Nonnull const PACServiceDiscoverySeatPairingWiFiPairingCapabilityPEDInitiated;

/**
 * The seat pairing's wifi pairing service have a capability to initiate pairing from Seat.
 */
extern NSString * _Nonnull const PACServiceDiscoverySeatPairingWiFiPairingCapabilitySeatInitiated;



@end
