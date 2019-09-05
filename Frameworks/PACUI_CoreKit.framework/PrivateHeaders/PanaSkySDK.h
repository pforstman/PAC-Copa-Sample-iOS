//
//  PanaSkySDK.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 8/11/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACMetadata/PACMetadataV1.h>
#import <PACMetadata/PACGroundMetadataV1.h>
#import <PACWeather/PACWeatherV1.h>
#import <PACEXTV/PACEXTV.h>
#import <PACAirportInfo/PACAirportInfo.h>
#import "PSMedia.h"

// Media temaplate IDs
#define PANA_SKY_API_MOVIE_TEMPLATE_KEY @"movie"
#define PANA_SKY_API_TV_TEMPLATE_KEY @"tv"
#define PANA_SKY_API_TV_EPISODE_TEMPLATE_KEY @"tvepisode"
#define PANA_SKY_API_MUSIC_TEMPLATE_KEY @"album"
#define PANA_SKY_API_MUSIC_TRACK_TEMPLATE_KEY @"track"
#define PANA_SKY_API_RADIO_TEMPLATE_KEY @"radio"
#define PANA_SKY_API_MAGAZINE_TEMPLATE_KEY @"magazine"
#define PANA_SKY_API_GAME_TEMPLATE_KEY @"game"
#define PANA_SKY_API_SUBCATEGORY_TEMPLATE_KEY @"subcategory"
#define PANA_SKY_API_LIVETV_TEMPLATE_KEY @"liveTV"
#define PANA_SKY_API_VIDEO_NEWS_TEMPLATE_KEY @"videoNews"
#define PANA_SKY_API_AUDIO_BOOK_TEMPLATE_KEY @"audiobook"
#define PANA_SKY_API_SHOPPING_CATALOG_TEMPLATE_KEY @"shopping_catalog"
#define PANA_SKY_API_SHOPPING_CATEGORY_TEMPLATE_KEY @"shopping_category"
#define PANA_SKY_API_SHOPPING_ITEM_TEMPLATE_KEY @"shopping_item"
#define PANA_SKY_API_KIDS_TEMPLATE_KEY @"kids"
#define PANA_SKY_API_AD_TEMPLATE_KEY @"ad"
#define PANA_SKY_API_BUNDLE_TEMPLATE_KEY @"bundle"

#define Placeholder(media, size)           [NSString stringWithFormat:@"Placeholder%@%@", media, size]
#define PanaSkyMoviesPlaceholder(size)     Placeholder(@"Movies", size)
#define PanaSkyTVPlaceholder(size)         Placeholder(@"TV", size)
#define PanaSkyLiveTVPlaceholder(size)     Placeholder(@"LiveTV", size)
#define PanaSkyMusicPlaceholder(size)      Placeholder(@"Music", size)
#define PanaSkyRadioPlaceholder(size)      Placeholder(@"Radio", size)
#define PanaSkyAudioBooksPlaceholder(size) Placeholder(@"Audiobooks", size)
#define PanaSkyGamesPlaceholder(size)      Placeholder(@"Games", size)
#define PanaSkyNewsPlaceholder(size)       Placeholder(@"News", size)
#define PanaSkyKidsPlaceholder(size)       Placeholder(@"Kids", size)
#define PanaSkyNewsPlaceholder(size)       Placeholder(@"News", size)
#define PanaSkyHomePlaceholder(size)       Placeholder(@"Home", size)
#define PanaSkyConciergePlaceholder(size)  Placeholder(@"Concierge", size)
#define PanaSkyFavoritesPlaceholder(size)  Placeholder(@"Favorites", size)
#define PanaSkyWeatherPlaceholder(size)    Placeholder(@"Weather", size)
#define PanaSkyShoppingPlaceholder(size)   Placeholder(@"Shopping", size)
#define PanaSkyPlaylistPlaceholder(size)   Placeholder(@"Playlist", size)
#define PanaSkyBundlePlaceholder(size)     Placeholder(@"Bundle", size)
#define PanaSkyVideoPlaylistPlaceholder(size)   Placeholder(@"VideoPlaylist", size)

// Cell Type
typedef enum {
    PSMediaCellTypeUnknown = 0,
    PSMediaCellTypeVideo = 1,
    PSMediaCellTypeMusic = 2,
} PSMediaCellType;

typedef void(^PanaSkyExecutionBlock)(void);

@interface PanaSkySDK : NSObject

- (id)init;
- (id)initWithExecutionBlock:(PanaSkyExecutionBlock)executionBlock;
-(PACMetadataV1* )metadata;
- (id)initWithSuppressErrors:(BOOL)suppressErrors executionBlock:(PanaSkyExecutionBlock)executionBlock;
- (void)fetchMediaCategoriesWithCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaCategoryTitleForID:(NSNumber *)mediaCategoryID withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaCategoriesForTemplateID:(NSString *)mediaTemplateID withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaCategoriesForCategoryID:(NSNumber *)categoryID withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaForCategoryID:(NSInteger)categoryID withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaForCategoryID:(NSInteger)categoryID maxItems:(NSInteger)maxItems withCompletion:(void(^)(id result, NSError *error))completion;
- (void)batchFetchMediaForCategoryID:(NSInteger)categoryID withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaCountForCategoryID:(NSInteger)categoryID withCompletion:(void(^)(NSInteger count, id firstItem, NSError *error))completion;
- (void)fetchMediaForURI:(NSString *)mediaURI withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaListWithIDs:(NSArray *)URIs withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchMediaWithSeatClassDisabled:(BOOL)disableSeatClass forURI:(NSString *)mediaURI withCompletion:(void(^)(id result, NSError *error))completion;
- (id<PACMetadataV1Request>)fetchMediaImageForURL:(NSString *)url withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchChildMediaForParentURI:(NSString *)url withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchChildMediaForParentURI:(NSString *)uri forCategoryID:(NSInteger)categoryID withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchSearchResultsByText:(NSString *)searchText attributes:(NSDictionary *)attributes withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchWeatherForICAOCode:(NSString *)ICAOCode withCompletion:(void(^)(PACWeatherV1WeatherForecast *forecast, NSError *error))completion;
- (void)fetchWeatherLocations:(void(^)(id weatherLocations, NSError *error))completion;
- (void)fetchAirportInfoWith:(NSArray *)ICAOCodes airportInfoDelegate:(id)currentDelegate;
- (void)fetchEXTVProgramGuideWithCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchEXTVProgramChannelsWithCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchEXTVProgramGuideForChannel:(NSNumber *)channel withCompletion:(void(^)(id result, NSError *error))completion;
- (void)fetchAirlineRoutesForFlightNumber:(NSString *)flightNumber withCompletion:(void(^)(id result, NSError *error))completion;
- (void)testFetchWithCompletion:(void(^)(id result, NSError *error))completion;
+ (PSMediaCellType)cellTypeForMediaTemplateID:(NSString *)mediaTemplateID;

@end

#pragma mark - Temporary generated LiveTV EPG data

//typedef enum
//{
//    PACEXTVProgramGuideV1ChannelStatusNone      = 0,
//    PACEXTVProgramGuideV1ChannelStatusActive    = 1 << 0,
//}
//PACEXTVProgramGuideV1ChannelStatus;

//@interface PACEXTVProgramGuideV1Category : NSObject
//@property (nonatomic, copy) NSString *name;
//@end

//@interface PACEXTVProgramGuideV1ChannelImage : NSObject
//@property (nonatomic, copy) NSNumber *width;
//@property (nonatomic, copy) NSNumber *height;
//@property (nonatomic, copy) NSString *url;
//@property (nonatomic, copy) NSString *type;
//@end

//@interface PACEXTVProgramGuideV1Channel : NSObject
//@property (nonatomic, copy) NSString *mediaUri;
//@property (nonatomic, copy) NSString *title;
//@property (nonatomic, copy) NSString *summary;
//@property (nonatomic, copy) NSString *callSign;
//@property (nonatomic, assign) PACEXTVProgramGuideV1ChannelStatus status;
//@property (nonatomic, retain) NSArray<PACEXTVProgramGuideV1ChannelImage*> *images;
//@end

//@interface PACEXTVProgramGuideV1Program : NSObject
//@property (nonatomic, copy) NSString *channelUri;
//@property (nonatomic, copy) NSString *channelCallSign;
//@property (nonatomic, copy) PACEXTVProgramGuideV1Category *category;
//@property (nonatomic, copy) PACEXTVProgramGuideV1Category *subCategory;
//@property (nonatomic, copy) NSString *title;
//@property (nonatomic, copy) NSString *summary;
//@property (nonatomic, copy) NSNumber *duration;
//@property (nonatomic, retain) NSDate *airingTime;
//@end

//@interface PACEXTVProgramGuideV1ChannelProgramResult : NSObject
//@property (nonatomic, retain) PACEXTVProgramGuideV1Channel *channel;
//@property (nonatomic, retain) NSArray<PACEXTVProgramGuideV1Program*> *programs;
//@end
