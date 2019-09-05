//
//  FavoritesManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 10/3/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "PSMedia.h"

@interface FavoritesManager : NSObject

+ (FavoritesManager *)sharedFavoritesManager;

@property (nonatomic, strong) NSMutableDictionary *favoritesData;
@property (nonatomic, strong) NSMutableDictionary *filteredFavoritesData;
@property (nonatomic, assign) BOOL isFirstTime;
@property (nonatomic, readonly) BOOL isFavoritesEditModeEnabled;

- (void)writeToDisk;
- (void)flushToDisk;
- (void)addItem:(NSArray *)items withTemplateID:(NSString *)templateID;
- (void)addItem:(NSArray *)items withTemplateID:(NSString *)templateID flush:(BOOL)flush;
- (void)removeItem:(NSArray *)items withTemplateID:(NSString *)templateID;
- (void)removeAllItems;
- (BOOL)isFavorite:(PSMedia *)item withTemplateID:(NSString *)templateID;
- (BOOL)isFavoriteURI:(NSString *)favoriteURI withTemplateID:(NSString *)templateID;
- (BOOL)containsMediaTemplateID:(NSString *)mediaTemplateID;
- (void)setIsFirstTime:(BOOL)isFirstTime;
- (NSMutableArray *)allFavoritesData;
- (void)enableEditMode:(BOOL)enabled;
- (BOOL)isFavoriteAvailable:(PSMedia *)favoriteItem;
- (UIImage *)favoritesCornerIcon;
- (UIImage *)retrievePosterImageForMedia:(PSMedia *)media;
- (void)beginFavoritesAvailableLookup;
- (void)beginFavoritesAvailableLookupWithCompletion:(void (^)(BOOL result))completion;
- (void)requestFavoritesReloadForTemplateID:(NSString *)media_template_id;
- (void)applyParentalControls;
- (BOOL)canTypeBeFavorited:(NSString *)media_template_id;
- (BOOL)canMediaBeFavorite:(PSMedia *)media;
- (NSArray *)favoritesFromFavoritesService:(NSArray *)items;

//MARK: TV Favorites Methods
- (BOOL)isAnyTVEpisodesFavorited:(NSArray *)episodes;
- (BOOL)isTVEpisodeFavoriteURI:(NSString *)favoriteURI;
- (NSArray *)findTVEpisodesWithParentMedia:(NSString *)media_uri;
- (NSArray *)allParentsInTVEpisodes:(NSArray *)episodes;
- (BOOL)isAnyTypeTVEpisode:(NSArray *)episodes;
- (BOOL)areAllChildrenFavorited:(NSArray *)episodes;
- (NSArray *)episodesWithoutParent:(NSArray *)episodes;
- (NSArray *)favoriteEpisodesWithoutParent:(NSArray *)episodes;
- (NSString *)parseMediaTemplateID:(NSString *)template_id;
@end
