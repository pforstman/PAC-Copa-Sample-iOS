//
//  UserManager.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/9/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PSMediaCategory;
@class PSFlight;
@class PSMedia;
#import "PanaSkySDK.h"
#import <PACStreaming/PACStreaming.h>

#define USER_PROFILE_KEY @"PSUserProfileKey"
#define CURRENT_SELECTED_MOVIE_CATEOGRY_ID_KEY @"CurrentSelectedMovieCategoryID"
#define CURRENT_SELECTED_TV_CATEOGRY_ID_KEY @"CurrentSelectedTVCategoryID"
#define SELECTED_MEDIA_CATEGORY_ID_KEY_FORMAT @"Selected%@CategoryID"
#define SELECTED_FLIGHTS_KEY @"SelectedFlightsID"
#define SELECTED_NEWS_CATEGORY_ID_KEY @"SelectedNewsCategoryID"
#define CURRENT_LIVE_TV_URI_KEY @"CurrrentLiveTVUriID"
#define CURRENT_MOVIE_URI_KEY @"CurrentMovieUriID"
#define CURRENT_MOVIE_PROGRESS_KEY @"CurrentMovieProgressID"

@interface UserManager : NSObject

@property (nonatomic, strong, readwrite) PSMedia *currentlyPlayingMovie;
@property (nonatomic, strong, readwrite) PACEXTVProgramGuideV1Channel *currentlyPlayingLiveTV;
@property (nonatomic, strong, readwrite) PACeXTVMetadataStationInfo *currentlyPlayingExtv;
@property (nonatomic, strong) NSNumber *currentMovieProgress;
@property (nonatomic, strong) NSString *pendingVideoMediaURI;
@property (nonatomic, strong) NSString *pendingAudioMediaURI;
@property (nonatomic, strong) PACMediaPlayerV1 *videoPlayer;
@property (nonatomic, copy) NSString *currentOverlayMediaUri;
@property (nonatomic, copy) NSString *lastSearchString;
@property (nonatomic, strong) NSMutableArray *bookmarkArray;
@property (nonatomic, strong) NSArray *bookmarkReferences;
@property (nonatomic, strong) NSArray *watchedVideos;
@property (nonatomic, copy) NSString *currentShoppingCatalogID;

+ (instancetype)sharedUserManager;

- (void)saveSelectedMediaCategoryID:(NSNumber *)selectedTVCategoryID forTemplateID:(NSString *)mediaTemplateID;
- (NSNumber *)savedSelectedMediaCategoryIDForTemplateID:(NSString *)mediaTemplateID;
- (BOOL)validateUserProfile:(NSDictionary *)userProfile;
- (void)saveUserProfile:(NSDictionary *)userProfile;
- (NSDictionary *)savedUserProfile;
- (BOOL)hasLoggedIn;
- (void)saveFlight:(PSFlight*)flight;
- (void)removeFlight:(PSFlight*)flight;
- (NSArray *)retrieveFlights;
- (void)saveSelectedNewsCategoryID:(NSString *)newsCategoryID;
- (NSString *)savedSelectedNewsCategoryID;
- (BOOL)mediaPassesParentalControls:(PSMedia *)media;
- (BOOL)isMiniPlayerVisible;
- (BOOL)isMiniPlayerExpanded;
- (PACMediaBookmark *)getBookmarkWithIdentifier:(NSString *)identifier;
- (BOOL)hasSavedBookmarkWithIdentifier:(NSString *)identifer;
- (void)postPendingBookmark:(PACMediaBookmark *)bookmark;
- (void)checkForPendingBookmarkSave;
- (void)saveBookmark:(PACMediaBookmark *)bookmark;
- (void)deleteBookmark:(PACMediaBookmark *)bookmark;
- (void)deleteAllBookmarks;
- (void)saveWatchedVideo:(NSString *)identifier;
- (void)deleteWatchedVideoWithIdentifier:(NSString *)identifier;
- (void)deleteAllWatchedVideos;
- (BOOL)videoHasBeenWatched:(NSString *)identifier;
+ (BOOL)initiatePairingFromPEDEnabled;
+ (void)setInitiatePairingFromPEDEnabled:(BOOL)enabled;

@end

@interface PSMediaPlayerBookmark : PACMediaBookmark
@property (nonatomic, strong, readwrite) NSString *myMediaURI;
@property (nonatomic, assign, readwrite) NSTimeInterval myElapsedTime;
@end
