/** @module PACUser.framework *///
//  PACUserPlaylistV1.h
//  User
//
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACUser/PACUser.h>
#import <PACUser/PACUserPlaylist.h>

#define PAC_USER_PLAYLIST_MAX_NAME_LENGTH 24

@class PACUserPlaylistConflict;

/**
 * Playlist manager class manages multiple playlists created by the passenger. The playlist is locally persisted and can be synchronized with playlist on seatback monitor.
 */
@interface PACUserPlaylistManagerV1 : PACUserSyncService

/**
 * @constantgroup PACUserPlaylistNames
 * Reserved playlist names.
 */

/**
 * A playlist name reserved for favorites.
 *
 * When creating a favorites, duplicate playlist items are not allowed.
 */
FOUNDATION_EXPORT NSString* _Nonnull const PACUserPlaylistNameFavorites;

/**
 * Create a playlist with a specific name.
 * @param name Unique name identifying the playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)createPlaylistWithName:(NSString* _Nonnull)name error:(NSError* _Nullable * _Nullable)error;

/**
 * Delete a playlist with a specific name.
 * @param name Unique name identifying the playlist.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)deletePlaylistWithName:(NSString* _Nonnull)name error:(NSError* _Nullable * _Nullable)error;

// - (BOOL)renamePlaylist:(NSString* _Nonnull)fromName toName:(NSString* _Nonnull)toName;

/**
 * Returns a playlist with a specific name.
 * @param name Unique name identifying the playlist.
 * @return Playlist object. Nil, if no playlist with specified name exists.
 * @see PACUserPlaylist
 */
- (PACUserPlaylist* _Nullable)playlistWithName:(NSString* _Nonnull)name;

/**
 * Return all available playlists.
 * @return Array of playlist object.
 * @see PACUserPlaylist
 */
- (NSArray<PACUserPlaylist*> * _Nullable)playlists;

/**
 * Retrieve all registered conflicts.
 *
 * Conflicts need to be resolved prior to synchronization.
 * @param error The pointer to the error object that will be set if an error has occurred. Check PACUserSyncServiceStatusCode for possible status code.
 * @return The list of conflict items. Nil on error.
 * @see PACUserConflict
 * @see PACUserPlaylistConflict
 */
- (NSArray <PACUserPlaylistConflict*> * _Nullable)retrieveConflicts:(NSError * _Nullable * _Nullable)error;

@end
