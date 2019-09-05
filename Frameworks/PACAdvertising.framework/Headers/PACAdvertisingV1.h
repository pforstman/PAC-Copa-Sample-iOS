/** @module PACAdvertising.framework *///
//  PACAdvertisingV1.h
//  Advertising
//
//  Created by Rawad Hilal on 2/16/16.
//  Copyright ¬© 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>
#import <PACAdvertising/PACAdvertisingItem.h>

/**
 AdvertisingV1 provides an interface to the OneMedia advertising server hosted by Panasonic.  The API allows developers to request ads, process click-throughs, and log impressions and passenger clicks.
 The developer is responsible for providing the proper parameters with each call and for building their applications to display the advertisements correctly.
 
 [Download Sample Project](../../samples/PACAdvertising/SampleAdvertisingApplication.zip)
 
 *** FOR HACKATHON 2017 The following parameters are to be used. Width and height are provided by PACAdvertisingAttributePreferredWidth and PACAdvertisingAttributePreferredHeight attributes. ***
 
 *** Available Banners ***
 
 <section style="width:30%;">
 
 | zone | width | height |
 |:---:|:---:|:---:|
 | panasonic | 160 | 600 |
 | panasonic | 320 | 50 |
 | panasonic | 728 | 90 |
 
 <br/>
 *** Available Interstitials ***
 
 | zone | width | height |
 |:---:|:---:|:---:|
 | panasonic | 300 | 250 |
 
 <br/>
 *** Available Videos ***
 
 | zone |
 |:---:|
 |panasonic|
 
 <br/>
 </section>
 
 ***TERMS***
 
 **Zone**
 
 A specific location denoted on an application GUI where an advertisement will display. Ads are assigned a specific zone_path with a set zone_width and zone_height.
 For example, if a page on the portal was playing a sports TV channel, there can be a zone_path called ìsports-side-barî with a width of 100px and a height of 500px. Each time the Advertising API retrieves a banner for that zone, the application would specify the zone path, width and height to retrieve a banner that would fit in that zone.
 
 **Destinations**
 
 The location where the clicked ad directs the user. For example, an ad can redirect to a specific URL or a specific media_uri, such as a video. A destination is not required for an ad. Ads can be displayed on an impression basis.
 
 **Impressions vs Clicks**
 
 Each time an ad displays, it should be logged as an impression. Each time an ad is clicked, it should be logged as a click.
 
 **Interstitials**
 
 Full screen content-blocking advertisements that display during page transitions. They have a predefined display duration that states how long an advertisement should display until it transitions to the next page.

***Example***

```
    // Class vairables and properties
    PACAdvertisingV1 *advertisingService;

    //to initialize a PACAdvertisingV1, you can
    - (void) initializeAdvertisingService{
        [PACAdvertisingV1 initServiceWithCompletionBlock:^(id object, NSError *error) {
            if (error != nil) {
                NSLog(@"Error loading Advertising service. Error: %@", error);
                return;
            }
            self.advertisingService = object;
        }];
    }

    // Load banner
    - (void)loadBanner{
        [self.advertisingService sendBannerRequestWithZonePath:@"shopping_top_left"
                                                attributes:@{PACAdvertisingAttributeLanguageIso:@"eng"}
                                            operationQueue:[NSOperationQueue mainQueue]
                                         completionHandler:^(PACAdvertisingItem * _Nullable object, NSError * _Nullable error) {
                                             if (error)  {
                                                 NSLog(@"Error occurred while retrieving banner. Error: %@", error);
                                                 return;
                                             }
                                             // Process banner.
                                             ...
                                         }]:
        }
```

*/
@interface PACAdvertisingV1 : InFlightService


/**
 * @constantgroup PACAdvertisingErrorDomains
 * The error domains associated to the PACAdvertisingV1 class.
 */

/**
 * The generic error associated with the PACAdvertisingV1 class.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACAdvertisingErrorDomain;


/**
 * The Advertising request error codes.
 *
 * @owner PACAdvertisingV1
 */
typedef enum {
    /** The request has failed due to an unknown error. */
    PACAdvertisingErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACAdvertisingErrorBadRequest = 1001,
    /** The request has failed due to the service being unavailable. */
    PACAdvertisingErrorServiceNotFound = 1002,
    /** The request has failed due to an unexpected internal error. */
    PACAdvertisingErrorInternalError = 1003,
    /** The request has failed due to the server returning an unexpected response. */
    PACAdvertisingErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACAdvertisingErrorConnectionError = 1005,
    /** The request has failed due to no advertisement being found with the specified parameters. */
    PACAdvertisingErrorBannerNotAvailable = 1006,
    PACAdvertisingErrorAdvertisementNotAvailable = 1006
    
}PACAdvertisingErrorCode;

/**
 PACAdvertisingV1 completion block
 @param object The PACAdvertisingItem response object from the server.
 @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACAdvertisingV1CompletionHandler)(PACAdvertisingItem * _Nullable object, NSError * _Nullable error);


/**
 PACAdvertisingV1 video completion block
 @param object An array of NSString objects representing the media URI of the video banners to play.
 @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACAdvertisingV1VideoCompletionHandler)(NSArray <NSString *> * _Nullable object, NSError * _Nullable error);

/**
 Initializes an advertising banner request.
 
 @param zonePath The zone path of the banner as defined by Panasonic Unity OneMedia advertising service. OneMedia is a web-based interface used to create and target advertisements to their  application.
 @param attributes Additional attributes associated to the request. Please refer to PACAdvertisingAttributes for attributes.
 @param operationQueue The operation queue that will be used when calling the completion block. If nil, the main queue will be used.
 @param completion The completion block that will be executed when the request is finished. Please refer to PACAdvertisingV1CompletionHandler for more details.
 @see PACAdvertisingAttributes
 @see PACAdvertisingAttributePreferredWidth
 @see PACAdvertisingAttributePreferredHeight
 @see PACAdvertisingAttributeLanguageIso
 */
- (void) sendBannerRequestWithZonePath:(NSString * _Nonnull)zonePath
                            attributes:(NSDictionary * _Nullable)attributes
                        operationQueue:(NSOperationQueue * _Nonnull)operationQueue
                     completionHandler:(PACAdvertisingV1CompletionHandler _Nullable)completion;

/**
 Initializes an advertising interstitial request.
 
 @param zonePath The zone path of the banner. The zone path of the banner is defined by Panasonic Unity OneMedia advertising service. OneMedia is a web-based interface used to create and target advertisements to their  application
 @param attributes Additional attributes associated to the request. Please refer to PACAdvertisingAttributes for attributes.
 @param operationQueue The operation queue that will be used when calling the completion block. If nil, the main queue will be used.
 @param completion The completion block that will be executed when the request is finished. Please refer to PACAdvertisingV1CompletionHandler for more details.
 @see PACAdvertisingAttributes
 @see PACAdvertisingAttributePreferredWidth
 @see PACAdvertisingAttributePreferredHeight
 @see PACAdvertisingAttributeLanguageIso
 */
- (void) sendInterstitialRequestWithZonePath:(NSString * _Nonnull)zonePath
                                  attributes:(NSDictionary * _Nullable)attributes
                              operationQueue:(NSOperationQueue * _Nonnull)operationQueue
                           completionHandler:(PACAdvertisingV1CompletionHandler _Nullable)completion;

/**
 Initializes an advertising video banner request.
 
 @param zonePath The zone path of the banner. The zone path of the banner is defined by Panasonic Unity OneMedia advertising service. OneMedia is a web-based interface used to create and target advertisements to their  application.
 @param attributes Additional attributes associated to the request. Please refer to PACAdvertisingAttributes for attributes. Currently only PACAdvertisingAttributeLanguageIso is supported.
 @param operationQueue The operation queue that will be used when calling the completion block. If nil, the main queue will be used.
 @param completion The completion block that will be executed when the request is finished. Please refer to PACAdvertisingV1VideoCompletionHandler for more details.
 @see PACAdvertisingAttributes
 @see PACAdvertisingAttributeLanguageIso
 */
- (void) sendVideoBannerRequestWithZonePath:(NSString * _Nonnull)zonePath
                                 attributes:(NSDictionary * _Nullable)attributes
                             operationQueue:(NSOperationQueue * _Nonnull)operationQueue
                          completionHandler:(PACAdvertisingV1VideoCompletionHandler _Nullable)completion;

/**
 * @constantgroup PACAdvertisingAttributes
 * The additional advertising attributes for a specific request.
 *
 * The value associated with this key should be of type NSString.
 */

/**
 * The preferred width of the advertisement.
 *
 * The value associated with this key should be of type NSNumber.
 *
 * The value should be in pixels. Please note that on retina devices, you may choose to
 * convert from point system to pixels for better quality ads.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACAdvertisingAttributePreferredWidth;

/**
 * The preferred height of the advertisement.
 *
 * The value associated with this key should be of type NSNumber.
 *
 * The value should be in pixels. Please note that on retina devices, you may choose to
 * convert from point system to pixels for better quality ads.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACAdvertisingAttributePreferredHeight;

/**
 * The ISO 639-1 language code of the advertisment that is used for selective targeting.
 *
 * The value associated with this key should be of type NSString.
 * The language code standard is ISO 639-1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACAdvertisingAttributeLanguageIso;

/**
 * The destination type of the banner.
 *
 * The value associated with this key should be of type NSNumber of PACAdvertisingItemDestinationType.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACAdvertisingAttributeDestinationType;


@end

