/** @module PACUser.framework *///
//  PACUserPlaylist.h
//  User
//
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACUser/PACUserPlaylistItem.h>

/**
 * Playlist class stores and retrieves playlist items, such as movies, tv shows and music.
 */
@interface PACUserPlaylist : NSObject

/**
 * The name that the passenger call the Playlist.
 */
@property(nonatomic,copy) NSString* _Nonnull name;

/**
 * Add item to playlist.
 * @param item Item to add to playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)addPlaylistItem:(PACUserPlaylistItem* _Nonnull)item error:(NSError* _Nullable * _Nullable)error;

/**
 * Add an array of items to playlist.
 * @param items Array of items to add to playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)addPlaylistItems:(NSArray<PACUserPlaylistItem*> * _Nonnull)items error:(NSError* _Nullable * _Nullable)error;

/**
 * Remove item from playlist.
 * @param item Item to remove from playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)removePlaylistItem:(PACUserPlaylistItem* _Nonnull)item error:(NSError* _Nullable * _Nullable)error;

/**
 * Remove an array of items from playlist.
 * @param items Array of items to remove from playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)removePlaylistItems:(NSArray<PACUserPlaylistItem*> * _Nonnull)items error:(NSError* _Nullable * _Nullable)error;

/**
 * Remove specific item ID from playlist.
 * @param itemId Item ID to be removed from playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)removePlaylistItemsWithItemId:(NSString* _Nonnull)itemId error:(NSError* _Nullable * _Nullable)error;

/**
 * Remove an array of item IDs from playlist.
 * @param itemIds Array of item IDs to be removed from playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)removePlaylistItemsWithItemIds:(NSArray<NSString*> * _Nonnull)itemIds error:(NSError* _Nullable * _Nullable)error;

/**
 * Clear all playlist items.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserPlaylistItem
 */
- (BOOL)clearPlaylistItemsWithError:(NSError* _Nullable * _Nullable)error;

/**
 * Returns list of items in playlist.
 * @return Array of playlist items.
 * @see PACUserPlaylistItem
 */
- (NSArray<PACUserPlaylistItem*> * _Nullable)items;

@end

