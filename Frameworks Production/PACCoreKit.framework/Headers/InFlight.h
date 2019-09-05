/** @module PACCoreKit.framework *///
//  InFlight.h
//  CoreKit
//
//  Created by Rawad Hilal on 11/24/15.
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  This class allows you to set the In-Flight configurations.
 
   ***Associating Application to an Airline***
 
  App ID allows developers to associate their application to a specific airline. The airline then allows or restricts onboard services based on the App ID. 
 
  The airline can use a single App ID or multiple App IDs, depending on their policies. For example, an airline could assign specific App IDs to various application types, such as one App ID for games and a second ID for maps. If the application is permitted on an airline not associated with the App ID, passengers might have restricted access or no access to the application, depending on the policy set by the airlines.
 
  **Note:** Developers must request the App ID from the airline.
 
  The following example shows how to set an App ID in your application.
 
        - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
        {
            // This call may throw an exception, if an incorrect Application ID is provided.
            [InFlight setApplicationId:@"...."];
        }
 
 */
@interface InFlight : NSObject

/**
 * Set the airline specific application Id.
 *
 * App ID allows developers to associate their application to a specific airline. The airline then allows or restricts onboard services based on the App ID.
 *
 * The airline can use a single App ID or multiple App IDs, depending on their policies. For example, an airline could assign specific App IDs to various application types, such as one App ID for games and a second ID for maps. If the application is permitted on an airline not associated with the App ID, passengers might have restricted access or no access to the application, depending on the policy set by the airlines.
 *
 * **Note:** Developers must request the App ID from the airline.
 *
 * This function call will throw an InvalidArgumentException if the application id provided is not valid.
 *
 * @param applicationId The customer application id.
 */
+ (void)setApplicationId:(NSString *)applicationId;

@end
