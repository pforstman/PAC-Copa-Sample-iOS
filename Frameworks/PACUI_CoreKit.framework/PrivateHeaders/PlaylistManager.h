//
//  PlaylistManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 5/12/15.
//  Copyright (c) 2015 Mercury. All rights reserved.
//

#import "PSMedia.h"

#define kDefaultPlaylistID @"defaultPlaylistID"
#define kDefaultVideoPlaylistID @"video1"

@interface PlaylistManager : NSObject

@property (nonatomic, strong) NSMutableArray *playlist;
@property (nonatomic, strong) NSMutableDictionary *playlistData;
@property (nonatomic, copy) NSString *diskCachePath;

+ (PlaylistManager *)sharedPlaylistManager;

- (void)flushToDisk;
- (NSMutableArray *)playlistForPlaylistID:(NSString *)playlistID;
- (void)addItem:(PSMedia *)playlistItem forAlbum:(PSMedia *)album;
- (void)addItem:(PSMedia *)playlistItem forAlbum:(PSMedia *)album withFlush:(BOOL)flush;
- (void)addItem:(PSMedia *)playlistItem playlistID:(NSString *)playlistID;
- (void)addAlbum:(PSMedia *)album;
- (void)removeItem:(PSMedia *)playlistItem forAlbum:(PSMedia *)album;
- (void)removeItem:(PSMedia *)playlistItem playlistID:(NSString *)playlistID;
- (void)removeItem:(PSMedia *)playlistItem forAlbum:(PSMedia *)album playlistID:(NSString *)playlistID withFlush:(BOOL)flush;
- (void)removeAlbum:(PSMedia *)album;
- (void)moveItemInPlaylist:(NSString *)playlistID fromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;
- (BOOL)isUriInPlaylist:(NSString *)media_uri;
- (BOOL)isItemInPlaylist:(PSMedia *)playlistItem;
- (BOOL)isItemInPlaylist:(PSMedia *)playlistItem playlistID:(NSString *)playlistID;
- (void)findAlbumInPlaylist:(PSMedia *)album withCompletion:(void(^)(id result))completion;
- (void)savePlaylistData;
- (void)clearPlaylist;
- (void)clearPlaylistWithPlaylistID:(NSString *)playlistID;
- (NSInteger)numberOfSongsInPlaylist;
- (NSInteger)numberOfSongsInPlaylistWithPlaylistID:(NSString *)playlistID;
- (NSString *)totalTrackTimeOfPlaylist;
- (NSString *)totalTrackTimeOfPlaylistWithPlaylistID:(NSString *)playlistID;
- (PSMedia *)nextItemInPlaylistFromMediaURI:(NSString *)mediaURI;
- (PSMedia *)nextItemInPlaylist:(NSString *)playlistID fromMediaURI:(NSString *)mediaURI;
- (NSInteger)nextIndexInPlaylistFromMediaURI:(NSString *)mediaURI;
- (PSMedia *)prevItemInPlaylistFromMediaURI:(NSString *)mediaURI;
- (PSMedia *)prevItemInPlaylist:(NSString *)playlistID fromMediaURI:(NSString *)mediaURI;
- (NSInteger)prevIndexInPlaylistFromMediaURI:(NSString *)mediaURI;
- (void)handleParentalControlsChanged;

@end
