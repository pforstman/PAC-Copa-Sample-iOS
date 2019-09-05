/** @module PACAdvertising.framework *///
//  PACAdvertisingItem.h
//  Advertising
//
//  Created by Rawad Hilal on 2/16/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * PACAdvertisingItem is a model class that defines a OneMedia advertisement item.
 *
 * The PACAdvertisingItemV1 is divided into two categories: one pertaining to the banner or interstitial content of the advertisement and
 * the other pertaining to the destination of the advertisement after clicking through the banner or interstitial.
 */
@interface PACAdvertisingItem : NSObject

/**
 * The types of the advertisement item.
 */
typedef enum {
    /**
     * The type of the advertising item is banner.
     * @see [PACAdvertisingV1 sendBannerRequestWithZonePath:attributes:operationQueue:completionHandler:]
     */
    PACAdvertisingItemTypeBanner,
    /**
     * The type of the advertising item is interstitial.
     * @see [PACAdvertisingV1 sendInterstitialRequestWithZonePath:attributes:operationQueue:completionHandler:]
     */
    PACAdvertisingItemTypeInterstitial,
}PACAdvertisingItemType;

/**
 * The advertising item type.
 *
 * This property defines the type of this advertising item.
 * Please refer to PACAdvertisingItemType for types.
 */
@property (nonatomic, assign) PACAdvertisingItemType itemType;


/**
 * @name Content
 */

/**
 * The mime type of the contentUri for the ad content.
 *
 * The contentType can vary based on the type of media located at the contentUri. For example, content type could be `image/png`.
 */
@property (nonatomic, copy) NSString * _Nonnull contentType;

/**
 * The URI for the media content that will be loaded on the banner or interstitial.
 */
@property (nonatomic, copy) NSString * _Nonnull contentUri;

/**
 * The duration, in seconds, that the content will display.
 */
@property (nonatomic, copy) NSNumber * _Nullable contentDisplayDuration;


/**
 * @name Click Through
 */

/**
 * The destination type of the advertising item.
 */
typedef enum
{
    /** The destination type does not exist. The destinationUri is nil. */
    PACAdvertisingItemDestinationTypeNone,
    /** The destination type is an advertisement using content from a website. */
    PACAdvertisingItemDestinationTypeWebsite,
    /** The destination type is an advertisement using media, such as a video. */
    PACAdvertisingItemDestinationTypeMedia,
}PACAdvertisingItemDestinationType;

/**
 * The type of destination content that displays after clicking through the banner or interstitial.
 *
 * This property defines the type of the destination.
 * Please refer to PACAdvertisingItemDestinationType for types.
 */
@property (nonatomic, assign) PACAdvertisingItemDestinationType destinationType;

/**
 * The destination that the passenger's click or touch on the advertisement will link to.
 *
 * This property can be nil if the destinationType is set to PACAdvertisingItemDestinationTypeNone.
 * If nil, there is no destination where the passenger can navigate.
 *
 * If the destinationType is set to PACAdvertisingItemDestinationTypeWebsite, the value of the property would be
 * the URL for a website that can display.
 *
 * If the destinationType is set to PACAdvertisingItemDestinationTypeMedia, the value of the property would be
 * the media URI that can be loaded using the PACMediaPlayerV1 service class.
 */
@property (nonatomic, copy) NSString * _Nullable destinationUri;

@end

