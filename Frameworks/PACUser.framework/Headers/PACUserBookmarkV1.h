/** @module PACUser.framework *///
//  PACUserBookmarkV1.h
//  User
//
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PACUserSyncService.h"

@class PACUserBookmarkConflict;

/**
 * User bookmark allows passenger to store media bookmarks. It is locally persisted and can be synchronized with playlist on seatback monitor.
 */

@interface PACUserBookmarkV1 : PACUserSyncService

/**
 * add a bookmark.
 * @param bookmark Media bookmark object.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACMediaBookmark
 */
-(BOOL)addBookmark:(PACMediaBookmark* _Nonnull)bookmark error:(NSError* _Nonnull *_Nullable)error;

/**
 * Remove a bookmark.
 * @param bookmark Media bookmark object.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACMediaBookmark
 */
-(BOOL)removeBookmark:(PACMediaBookmark* _Nonnull)bookmark error:(NSError* _Nullable * _Nullable)error;

/**
 * Remove bookmarks with a specific media uri.
 * @param mediaUri Media uri for bookmarks to remove.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACMediaBookmark
 */
-(BOOL)removeBookmarksWithMediaUri:(NSString* _Nonnull)mediaUri error:(NSError* _Nullable * _Nullable)error;

/**
 * Remove all bookmarks.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACMediaBookmark
 */
-(BOOL)clearBookmarksWithError:(NSError* _Nullable * _Nullable)error;

/**
 * Returns all bookmarks.
 * @return Returns a mapping between mediaUri and array of bookmark objects.
 * @see PACMediaBookmark
 */
-(NSDictionary <NSString*, NSArray<PACMediaBookmark*> *>* _Nullable)bookmarks;

/**
 * Return an array of bookmarks associated to a media uri.
 * @param mediaUri Media uri for bookmarks to retrieve bookmarks.
 * @return Array of bookmark objects.
 * @see PACMediaBookmark
 */
-(NSArray <PACMediaBookmark*> * _Nullable)bookmarksForMediaUri:(NSString* _Nonnull)mediaUri;

/**
 * Retrieve all registered conflicts.
 *
 * Conflicts need to be resolved prior to synchronization.
 * @param error The pointer to the error object that will be set if an error has occurred. Check PACUserSyncServiceStatusCode for possible status code.
 * @return The list of conflict items. Nil on error.
 * @see PACUserConflict
 * @see PACUserBookmarkConflict
 */
- (NSArray <PACUserBookmarkConflict*> * _Nullable)retrieveConflicts:(NSError * _Nullable * _Nullable)error;

@end
