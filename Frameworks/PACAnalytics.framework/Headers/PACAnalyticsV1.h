/** @module PACAnalytics.framework *///
//  PACAnalyticsV1.h
//  InFlight iOS SDK
//
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>


/**
 AnalyticsV1 logs airline passenger usage on the IFEC system. Information is logged from flight origin to destination.
 
 The Analytics service is powered by Paxus (Passenger Usage Logging Software), a software library used by airlines to capture and offload IFEC user or passenger usage information.
 
   Example:
 
        PACAnalyticsV1 *analytics;
     
        - (void)viewDidLoad{
            [super viewDidLoad];
     
            // Initializes the service.
            [PACAnalyticsV1 initServiceWithCompletionBlock:^(id object, NSError *error) {
                if (error != nil) {
                    NSLog(@"Error loading analytics service. Error: %@", error);
                    return;
                }
                self.analytics = object;
            }];
        }
 
        // To log screen transition
        - (void)logScreenTransition{
            [self.analytics logScreenTransitionWithSource:@"Screen 1"
                                            toDestination:@"Screen 2"];
        }
 
        // To log language transition
        - (void)logLanguageTransition{
            [self.analytics logLanguageChangeWithSource:@"eng"
                                          toDestination:@"fra"];
        }
 
 */
@interface PACAnalyticsV1 : InFlightService

/**
 * Log the start of an application.
 * @param appName Name of the application that has started.
 */
- (void)logApplicationHasStarted:(NSString * _Nonnull)appName;

/**
 * Log the stopping of an application.
 * @param appName Name of the application that stopped.
 */
- (void)logApplicationHasStopped:(NSString * _Nonnull)appName;

/**
 * Log a screen transition from source to destination.
 * @param source Name of the source screen. This field can be nil.
 * @param destination Name of the destination screen. This field cannot be nil.
 */
- (void)logScreenTransitionFromSource:(NSString * _Nullable)source
                        toDestination:(NSString * _Nonnull)destination;

/**
 * Log a screen transition from source to destination with category, language and content information.
 * @param source Name of the source screen. This field can be nil.
 * @param destination Name of the destination screen. This field cannot be nil.
 * @param screenContent Dynamic content which is the focus of the page being rendered. This field is only intended to be used when rendering dynamic content. This field can be nil.
 * @param screenCategory Category where the page exists. The category value for each page should be pre-determined by the Airline's analytics team. This field can be nil.
 * @param screenLanguage The locale object representing the language code of the current screen. This field can be nil.
 */
- (void)logScreenTransitionFromSource:(NSString * _Nullable)source
                        toDestination:(NSString * _Nonnull)destination
                              content:(NSString * _Nullable)screenContent
                             category:(NSString * _Nullable)screenCategory
                             language:(NSLocale * _Nullable)screenLanguage;

/**
 * Log a language change from source to destination.
 * @param source The source language name. This field can be nil.
 * @param destination The language name changed to. This field cannot be nil.
 */
- (void)logLanguageChangeFromSource:(NSString * _Nullable)source
                      toDestination:(NSString * _Nonnull)destination;
@end
