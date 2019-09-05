/** @module PACSeatPairing.framework *///
//  PACSeatMediaPlayerInfo.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#pragma mark - Enums

@class PACMediaBookmark;

/**
 * The seat media player's playback state.
 * @owner PACSeatMediaPlayerInfo
 */
typedef enum{
    /** The playback state is unknown. */
    PACSeatMediaPlayerPlaybackStateUnknown,
    /** The playback state is playing. */
    PACSeatMediaPlayerPlaybackStatePlaying,
    /** The playback state is paused. */
    PACSeatMediaPlayerPlaybackStatePaused,
    /** The playback state is seeking. */
    PACSeatMediaPlayerPlaybackStateSeeking,
    /** The playback state is stopped. */
    PACSeatMediaPlayerPlaybackStateStopped
}PACSeatMediaPlayerPlaybackState;

#pragma mark - Interface

/**
 * This class is model of the seat media player.
 */
@interface PACSeatMediaPlayerInfo : NSObject

/**
 * The remote controller ID.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSString *remoteControllerID;

/**
 * The seat player's playback state.
 * Default is PACSeatMediaPlayerPlaybackStateUnknown.
 */
@property (nonatomic, assign, readonly) PACSeatMediaPlayerPlaybackState playbackState;

/**
 * The current elapsed playback time.
 * Default is 0.
 */
@property (nonatomic, assign, readonly) float elapsedTime;

/**
 * The duration of the media.
 * Default is 0.
 */
@property (nonatomic, assign, readonly) float duration;

/**
 * The global identifier of the currently playing media. This field may not always be provided.
 * If not provided, the media URI should be available.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSString *globalURI;

/**
 * The media identifier of the currently playing media. This field may not always be provided.
 * If not provided, the global URI should be available.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSString *mediaURI;

/**
 * The parent media identifier of the currently playing media. This field may not always be provided.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSString *parentMediaURI;

/**
 * The media type of the currently playing media.
 * Default is nil
 */
@property (nonatomic, strong, readonly) NSString *mediaType;

/**
 * The content type of the currently playing media.
 * Default is nil
 */
@property (nonatomic, strong, readonly) NSString *contentType;

/**
 * The language code of the subtitle that is currently set.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSString *subtitle;

/**
 * The language code of the soundtrack that is currently set.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSString *soundtrack;

/**
 * The player volume. The volume is in percent aka 0 to 100.
 * Default is 0
 */
@property (nonatomic, assign, readonly) NSUInteger volume;

/**
 * The time in which the PACSeatMediaPlayerInfo instance object was last updated.
 * Default is nil.
 */
@property (nonatomic, strong, readonly) NSDate *timeLastUpdated;

/**
 * Returns the current bookmark.
 */
- (PACMediaBookmark*)currentBookmark;

@end

