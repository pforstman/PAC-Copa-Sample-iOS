/** @module PACUser.framework *///
//  PACUserPlaylistConflict.h
//  User
//
//  Created by Rawad Hilal on 7/5/18.
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACUser/PACUser.h>

@class PACUserPlaylistItem;

/**
 * The class that represents a conflict within PACUserPlaylistManagerV1.
 */
@interface PACUserPlaylistConflict : PACUserConflict

/**
 * The index path of the item that is conflicting.
 * The format is <playlist_name>[.<item_id>]. If nil, then all playlists are conflicting.
 *
 * For example, if a playlist name itself is conflicting, the key will be "playlist1". 
 * If an item in the playlist is conflicting, it will be "playlist1.12345678".
 *
 */
@property (nonatomic, strong, readonly) NSString* _Nullable conflictingItem;

/**
 * The playlists if local changes are selected.
 *
 * The dictionary consists of a mapping between the playlist name and the array of playlist items.
 */
- (NSDictionary<NSString*, NSArray<PACUserPlaylistItem*>*>* _Nullable)localPlaylists;

/**
 * The playlists if remote changes are selected.
 *
 * The dictionary consists of a mapping between the playlist name and the array of playlist items.
 */
- (NSDictionary<NSString*, NSArray<PACUserPlaylistItem*>*>* _Nullable)remotePlaylists;


@end

