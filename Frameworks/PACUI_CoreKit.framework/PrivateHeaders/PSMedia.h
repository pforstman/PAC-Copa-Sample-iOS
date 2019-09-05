//
//  PSMedia.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/4/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@import MantleTouch;
#import "PSPosterURL.h"

#define MAX_MEDIA_COUNT 10

typedef enum : NSUInteger {
    MediaAvailableStatusUnknown = 0,
    MediaAvailableStatusNotAvailable,
    MediaAvailableStatusAvailable
} MediaAvailableStatus;

@interface PSMedia : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy, readwrite, getter = getTitle) NSDictionary *title;
@property (nonatomic, copy, readwrite, getter = getShortTitle) NSDictionary *shortTitle;
@property (nonatomic, copy, readwrite, getter = getArtist) NSDictionary *artist;
@property (nonatomic, copy, readwrite) NSDictionary *media_description;
@property (nonatomic, copy, readwrite) PSPosterURL *poster_url;
@property (nonatomic, copy, readwrite) PSPosterURL *synopsis_url;
@property (nonatomic, copy, readwrite) NSString *media_uri;
@property (nonatomic, copy, readwrite) NSString *media_template_id;
@property (nonatomic, copy, readwrite) NSString *favoritedImage;
@property (nonatomic, copy, readwrite) NSString *duration;
@property (nonatomic, copy, readwrite) NSString *rating;
@property (nonatomic, copy, readwrite) NSString *rating_description;
@property (nonatomic, copy, readwrite) NSDictionary *genre;
@property (nonatomic, copy, readwrite) NSDictionary *year;
@property (nonatomic, copy, readwrite) NSDictionary *cast;
@property (nonatomic, copy, readwrite) NSDictionary *director;
@property (nonatomic, copy, readwrite) NSDictionary *critic_score;
@property (nonatomic, copy, readwrite) NSDictionary *peoplescore;
@property (nonatomic, copy, readwrite) NSDictionary *trailer_media_uri;
@property (nonatomic, copy, readwrite) NSDictionary *review;
@property (nonatomic, copy, readwrite) NSArray *soundtrack;
@property (nonatomic, copy, readwrite) NSArray *soundtracks;
@property (nonatomic, copy, readwrite) NSArray *subtitles;
@property (nonatomic, copy, readwrite) NSDictionary *attributes;
@property (nonatomic, copy, readwrite) NSString *content_type;
@property (nonatomic, copy, readwrite) NSString *contentType;
@property (nonatomic, copy, readwrite) NSString *cellType;
@property (nonatomic, copy, readwrite) NSString *parent_media_uri;
@property (nonatomic, copy, readwrite) NSArray *bundles;
@property (nonatomic, copy, readwrite) NSDictionary *price;
@property (nonatomic, copy, readwrite) NSString *type;
@property (nonatomic, copy, readwrite) NSString *media_badge;
@property (nonatomic, copy, readwrite) NSString *advisory_text;
@property (nonatomic, copy, readwrite) NSArray *children;
@property (nonatomic, assign) MediaAvailableStatus mediaAvailableStatus;
@property (nonatomic, assign) NSInteger categoryID;
@property (nonatomic, assign, readwrite) BOOL isTypeVideoNews;
@property (nonatomic, assign, readwrite) BOOL isFavorite;
@property (nonatomic, copy, readwrite) NSString *selectedSoundtrackCode;
@property (nonatomic, copy, readwrite) NSString *selectedSubtitleCode;

+ (NSString *)contentTypeFromDictionary:(NSDictionary *)dictionary;

- (NSInteger)durationInSeconds;
- (NSInteger)durationInMinutes;
- (NSString *)durationInHoursMinutes;
- (NSString *)getLocalizedTitle;
- (NSString *)getLocalizedShortTitle;
- (NSString *)getLocalizedArtist;
- (NSString *)getLocalizedDescription;
- (NSString *)getLocalizedGenre;
- (NSString *)getLocalizedYear;
- (NSString *)getLocalizedCast;
- (NSString *)getLocalizedDirector;
- (float)getLocalizedCriticScore;
- (float)getLocalizedPeopleScore;
- (NSString *)getLocalizedTrailerMediaUri;
- (NSString *)getLocalizedReview;
- (NSString *)getLocalizedLanguages;
- (NSString *)getLocalizedSubtitles;
- (BOOL)isPPVItem;
- (BOOL)containsBundles;
- (NSString *)getLocalizedPrice;
- (NSInteger)likeCount;
- (BOOL)isNew;
- (BOOL)isTypeVideo;
- (BOOL)isTypeMovie;
- (BOOL)isTypeAlbum;
- (BOOL)isTypePlaylist;
- (BOOL)isTypeTVSeries;
- (BOOL)isTypeTVEpisode;
- (BOOL)isTypeTVAny;
- (BOOL)isTypeGame;
- (BOOL)isTypeRadio;
- (BOOL)isTypeTV;
- (BOOL)isTypeLiveTV;
- (BOOL)isTypeTrailer;
- (BOOL)hasTrailer;
- (BOOL)hasSelectableSubtitles;
- (BOOL)hasSelectableAudio;
- (BOOL)hasSelectableSounds;
- (BOOL)isContentSubTypeAudioBooks;
- (BOOL)isContentSubTypeQuran;
- (BOOL)isParent;
- (UIImage *)placeholderImageForSize:(NSString *)imageSize;
- (NSString *)overlayModuleIdentifier;
+ (NSString *)overlayModuleIdentifierForTemplateID:(NSString *)templateID;
+ (NSString *)overlayModuleIdentifierForTemplateID:(NSString *)templateID isKidsMode:(BOOL)isKidsMode;

@end
