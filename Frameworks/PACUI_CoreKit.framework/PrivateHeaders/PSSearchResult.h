//
//  PSSearchResult.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 6/2/15.
//  Copyright (c) 2015 Mercury. All rights reserved.
//

@import MantleTouch;
@class PSSearchPosterURL;

#define MAX_MEDIA_COUNT 10

@interface PSSearchResult : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy, readwrite) NSString *duration;
@property (nonatomic, copy, readwrite) NSString *media_uri;
@property (nonatomic, copy, readwrite) NSString *parent_media_uri;
@property (nonatomic, copy, readwrite) NSNumber *rating;
@property (nonatomic, copy, readwrite) NSString *rating_description;
@property (nonatomic, copy, readwrite) NSDictionary *title;
@property (nonatomic, copy, readwrite) NSDictionary *artist;
@property (nonatomic, copy, readwrite) NSString *content_type;
@property (nonatomic, copy, readwrite) NSString *media_template_id;
@property (nonatomic, copy, readwrite) PSSearchPosterURL *images;
@property (nonatomic, copy, readwrite) NSString *critic_score;

- (NSString *)durationInHoursMinutes;
- (NSString *)getLocalizedTitle;
- (NSString *)getLocalizedArtist;
- (BOOL)isTypeVideo;
- (BOOL)isTypeAudioTrack;
- (BOOL)isTypeTvEpisode;
- (BOOL)isTypeAlbum;
- (BOOL)isUnknownType;
- (BOOL)isValidSearchType;

@end
