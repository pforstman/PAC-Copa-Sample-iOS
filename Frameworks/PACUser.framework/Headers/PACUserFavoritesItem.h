/** @module PACUser.framework *///
//  PACUserFavoritesItem.h
//  User
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>

/**
 * An item of [PACFavoritesListV1 items]
 */
@interface PACUserFavoritesItem : NSObject

/**
 * @name Static Initializers
 */

/**
 * Returns an array of favorites list items from serialized data.
 * @param serializedData The serialized data as returned from [PACFavoritesListV1 serializedData] or [PACFavoritesListItem serializedData].
 * @return An array of favorites list items from serialized data.
 */
+ (NSArray <PACUserFavoritesItem *> * _Nullable)favoritesListItemsWithSerializedData:(NSArray <NSDictionary *> * _Nonnull)serializedData;

/**
 * The availability options of the favorites list item.
 */
typedef enum {
    /** The availability is not yet known. */
    PACUserFavoritesItemAvailabilityUnknown = 0,
    /** The item is available. */
    PACUserFavoritesItemAvailabilityAvailable = 1 << 0,
    /** The item's trailer is available. */
    PACUserFavoritesItemAvailabilityTrailer = 1 << 1,
}PACUserFavoritesItemAvailabilityOptions;

/**
 * @name Properties
 */

/**
 * Media identifier.
 */
@property (nonatomic,copy) NSString * _Nonnull mediaUri;

/**
 * Global identifier.
 */
@property (nonatomic,copy) NSString * _Nonnull globalUri;

/**
 * Parent media identifier.
 */
@property (nonatomic,copy) NSString * _Nonnull parentMediaUri;

/**
 * Media content type, such as video or audio.
 *
 * Please refer to PACMetadataV1 items response field 'content_type'.
 */
@property (nonatomic,copy) NSString * _Nonnull contentType;

/**
 * Title of the media item.
 */
@property (nonatomic,copy) NSString * _Nonnull title;

/**
 * Poster URL of the media item. This displays content, such as movie poster or CD cover.
 */
@property (nonatomic,copy) NSString * _Nullable posterUrl;

/**
 * Custom tag associated to the media item.
 */
@property (nonatomic,copy) NSString * _Nullable tag;

/**
 * The number of times the item has been viewed. *** NOT IMPLEMENTED ***
 */
@property (nonatomic,copy) NSNumber * _Nullable viewCount;

/**
 * The elapsed time of the last playing session. This allows the media to replay from the stopped time. *** NOT IMPLEMENTED ***
 */
@property (nonatomic,copy) NSNumber * _Nullable elapsedTime;

/**
 * The rating of the item as assigned by the passenger. This allows the app developer to log the items by rating.
 *
 * The rating is a float from 1 to 5.
 */
@property (nonatomic,copy) NSNumber * _Nullable userRating;

/**
 * Returns the availability options of the favorites list item. *** NOT IMPLEMENTED ***
 */
@property (nonatomic,assign,readonly) PACUserFavoritesItemAvailabilityOptions availabilityOptions;

/**
 * @name Serialization
 */

/**
 * Returns a serialized data representation for the item.
 * @return A serialized data representation for the item.
 */
- (NSArray <NSDictionary *> * _Nonnull)serializedData;

@end
