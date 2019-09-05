/** @module PACUser.framework *///
//  PACUserBookmarkConflict.h
//  User
//
//  Created by Rawad Hilal on 7/3/18.
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACUser/PACUser.h>

/**
 * The class that represents a conflict within PACUserBookmarkV1.
 */
@interface PACUserBookmarkConflict : PACUserConflict

/**
 * The media uri that is conflicting. If nil, then all media uris are conflicting.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable conflictingMediaUri;

/**
 * The bookmarks map if local changes are selected.
 */
-(NSDictionary <NSString*, NSArray<PACMediaBookmark*> *>* _Nullable)localBookmarks;

/**
 * The bookmarks map if remote changes are selected.
 */
-(NSDictionary <NSString*, NSArray<PACMediaBookmark*> *>* _Nullable)remoteBookmarks;


@end
