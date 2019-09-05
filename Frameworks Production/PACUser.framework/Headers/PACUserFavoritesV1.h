/** @module PACUser.framework *///
//  PACUserFavoritesV1.h
//  User
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import <PACUser/PACUserFavoritesItem.h>

/**
 * This class manages the favorites list on a PED.
 */
@interface PACUserFavoritesV1 : InFlightService

/**
 * @name Properties
 */

/**
 * An array representing the favorite items.
 *
 * Please refer to PACUserFavoritesItem for additional information.
 */
- (NSArray <PACUserFavoritesItem *> * _Nonnull)items;

/**
 * The number of items in the favorites list.
 */
@property (nonatomic, assign, readonly) NSInteger count;

/**
 * @name Add, Remove, Clear List
 */

/**
 * Add item to the end of the queue.
 *
 * @param item The favorite item that is being added.
 * @return TRUE if item was added.
 */
- (BOOL)addItem:(PACUserFavoritesItem * _Nonnull)item;

/**
 * Add item to queue at a specified index.
 *
 * @param items The array of favorite items that are being added.
 * @return Returns number of items added to favorites.
 */
- (NSInteger)addItems:(NSArray <PACUserFavoritesItem *> * _Nonnull)items;

/**
 * Remove item from the queue.
 *
 * @param item The queue item being removed.
 * @return TRUE if item was removed.
 */
- (BOOL)removeItem:(PACUserFavoritesItem * _Nonnull)item;

/**
 * Remove items from the queue.
 *
 * @param items The queue items being removed.
 * @return Returns number of items removed from favorites.
 */
- (NSInteger)removeItems:(NSArray<PACUserFavoritesItem *> * _Nonnull)items;

/**
 * Remove item from the queue at a specified index.
 *
 * @param index The index of the item in the queue being removed.
 * @return TRUE if item was removed.
 */
- (BOOL)removeItemAtIndex:(NSInteger)index;

/**
 * Clear all items.
 */
- (void)clearFavoriteList;

/**
 * @name Filters
 */

/**
 * Returns filtered list of the favorites list by contentType
 *
 * @param contentType The contentType used to filter the favorites list.
 */
- (NSArray <PACUserFavoritesItem *> * _Nullable)itemsByContentType:(NSString * _Nonnull)contentType;

/**
 * @name Persistent
 */

/**
 * Writes any modifications to the favorites list to disk.
 * @return YES if the data was saved successfully to disk, otherwise NO.
 */
- (BOOL)synchronize;

/**
 * @name Serialization
 */

/**
 * Exports the favorites list to native NSDictionary elements.
 *
 * This function can be used when you wish to push favorites to the seat using the seat pairing service.
 * @return An array of dictionaries representing the favorites list items.
 */
- (NSArray <NSDictionary *> * _Nullable)serializedData;

@end
