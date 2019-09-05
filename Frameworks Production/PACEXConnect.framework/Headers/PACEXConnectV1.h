/** @module PACEXConnect.framework *///
//  PACEXConnectV1.h
//  eXConnect
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>


#pragma mark
#pragma mark - Events

/**
 * The status for the global connection has changed
 * @owner PACEXConnectV1
 *
 * The notification includes a payload with a description of the change
 *
 * *userinfo* The payload associated with the notification.
 *
 * - *PACEXConnectGlobalConnectStatusDidChangeStatusKey* The value of this key is an NSNumber with a boolean value of @YES, if connected, or @NO, if not connected
 *
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACEXConnectGlobalConnectStatusDidChangeNotification;
FOUNDATION_EXPORT NSString * _Nonnull const PACEXConnectGlobalConnectStatusDidChangeStatusKey;

/**
 * The remaining minutes of coverage has changed. For example, the passenger purchases additional coverage during the flight.
 * @owner PACEXConnectV1
 *
 * The notification includes a payload with a description of the change
 *
 * *userinfo* The payload associated to the notification.
 *
 * - *PACEXConnectTotalCoverageRemainDidChangeStatusKey* The value of this key is an NSNumber with an NSInteger value for the remaining minutes of connection coverage
 *
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACEXConnectTotalCoverageRemainDidChangeNotification;
FOUNDATION_EXPORT NSString * _Nonnull const PACEXConnectTotalCoverageRemainDidChangeStatusKey;

/**
 * The time remaining until coverage resumes has changed. For example, if connection is lost during a flight, this call counts down the minutes until the connection is available. 
 * @owner PACEXConnectV1
 *
 * The notification includes a payload with a description of the change 
 *
 * *userinfo* The payload associated with the notification.
 *
 * - *PACEXConnectTimeUntilCoverageChangesDidChangeStatusKey* The value of this key is an NSNumber with an NSInteger value representing the countdown of minutes until coverage changes
 *
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACEXConnectTimeUntilCoverageChangesDidChangeNotification;
FOUNDATION_EXPORT NSString * _Nonnull const PACEXConnectTimeUntilCoverageChangesDidChangeStatusKey;


#pragma mark
#pragma mark constant group
/**
 * The request error codes for the eXConnect.
 *
 * @owner PACEXConnectV1
 */
typedef enum PACEXConnectV1ErrorCode
{
    /** The request has failed due to an unknown error. */
    PACEXConnectV1ErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACEXConnectV1ErrorBadRequest = 1001,
    /** The request has failed due to the unavailability of the service. */
    PACEXConnectV1ErrorServiceNotFound = 1002,
    /** The request has failed due to an unexpected internal error. */
    PACEXConnectV1ErrorInternalError = 1003,
    /** The request has failed due to an unexpected response from the server. */
    PACEXConnectV1ErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACEXConnectV1ErrorConnectionError = 1005
}
PACEXConnectV1ErrorCode;

@class PACEXConnectV1GroundConnectivityStatus;

/**
 The PACEXConnectV1 class is a service that allows passengers to connect to the Internet durin a flight. The following example details how to use the PACEXConnectV1 service

 ***Example***

        - (void)viewDidLoad
        {
            [super viewDidLoad];
        
            [PACEXConnectV1 initServiceWithCompletionBlock:^(id object, NSError *error)
            {
                if (error)
                {
                    NSLog(@"Failed to initialize service %@. Reason: %@",NSStringFromClass([PACEXConnectV1 class]), error);
                    return;
                }
             
                self.connectManager = object;
             
                // listen to notification
                [[NSNotificationCenter defaultCenter] addObserver:self
                                                         selector:@selector(globalConnectStatusDidChange:)
                                                             name:PACEXConnectGlobalConnectStatusDidChangeNotification
                                                           object:nil];
                
                [[NSNotificationCenter defaultCenter] addObserver:self
                                                         selector:@selector(totalCoverageRemainDidChange:)
                                                             name:PACEXConnectTotalCoverageRemainDidChangeNotification
                                                           object:nil];
                
                [[NSNotificationCenter defaultCenter] addObserver:self
                                                         selector:@selector(timeUntilCoverageChangesDidChange:)
                                                             name:PACEXConnectTimeUntilCoverageChangesDidChangeNotification
                                                           object:nil];
            }];
        }
 
        -(void)globalConnectStatusDidChange:(NSNotification*)notification
        {
            NSDictionary* dic = notification.userInfo;
            
            NSNumber* num = dic[PACEXConnectGlobalConnectStatusDidChangeStatusKey];
                
            self.lblGlobalConnect.text = [num boolValue] ? @"On": @"Off";
        }

        -(void)totalCoverageRemainDidChange:(NSNotification*)notification
        {
            NSDictionary* dic = notification.userInfo;
            
            NSNumber* num = dic[PACEXConnectTotalCoverageRemainDidChangeStatusKey];
                
            self.lblTotalCoverage.text = [NSString stringWithFormat:@"%ld", (long)[num integerValue]];
            
        }

        -(void)timeUntilCoverageChangesDidChange:(NSNotification*)notification
        {
            NSDictionary* dic = notification.userInfo;
            
            NSNumber* num = dic[PACEXConnectTimeUntilCoverageChangesDidChangeStatusKey];
                
            self.lblTimeUntilCoverage.text = [NSString stringWithFormat:@"%ld", (long)[num integerValue]];
        }
 */
@interface PACEXConnectV1 : InFlightService

/**
 * The completion block that will be called when retrieveGroundConnectivityStatus function completes.
 * @param object An object of type PACEXConnectV1GroundConnectivityStatus that represents the current connectivity status if request is successful
 * @param error The error object set if an error has occurred or nil if successful. Please refer to PACEXConnectV1ErrorCode for the error codes.
 */
typedef void (^PACEXConnectStatusCompletionBlock)(PACEXConnectV1GroundConnectivityStatus* _Nullable object, NSError* _Nullable error);

/**
 * Retrieve the current eXConnect status.
 * @param completionHandler called when the request completes. For additional details, please refer to PACEXConnectStatusCompletionBlock.
 */
-(void)retrieveGroundConnectivityStatus:(PACEXConnectStatusCompletionBlock _Nullable)completionHandler;

@end
