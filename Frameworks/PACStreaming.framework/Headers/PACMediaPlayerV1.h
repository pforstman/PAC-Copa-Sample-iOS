/** @module PACStreaming.framework *///
//  PACMediaPlayerV1.h
//  InFlight iOS SDK
//  Copyright (c) 2014 Panasonic Avionics Corporation. All rights reserved.
//

#import "PACMediaPlayerCommon.h"
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 * This is the class for media player service object on which application developers call media player or playlist related APIs. Media items are identified by media URIs. The "Meta Data" module (TBD) provides information on available media items along with their URIs.
 */

@interface PACMediaPlayerV1 : InFlightService

#pragma mark - Player Initialization
/** @name Player Initialization */

/**
 * Creates a media player with specified mediaPlayerType, viewport, skin view and super view.
 * @param mediaPlayerType The type of player. Please refer to PACMediaPlayerType for possible types.
 * @param viewport Viewport size of the player. If CGRectNull is passed, the player view will always match the parent view, even if the parent view is resized.
 * @param skinView Skin view for player controls
 * @param view Super view which the player will be set on top of
 *
 *
 */

- (void) initialize:(PACMediaPlayerType)mediaPlayerType withFrame:(CGRect)viewport withSkinView:(UIView *)skinView withView:(UIView *)view;

/**
 * Creates a media player with specified mediaPlayerType, viewport, JSON skin string and super view.
 * @param mediaPlayerType The type of player. Please refer to PACMediaPlayerType for possible types.
 * @param viewport Viewport size of the player. If CGRectNull is passed, the player view will always match the parent view, even if the parent view is resized.
 * @param skinString JSON data string for skinning the player controls. Pass nil to use default controls. Pass @"{}" for removing all controls.
 * @param view Super view which the player will be set on top of
 *
 *
 */

- (void) initialize:(PACMediaPlayerType)mediaPlayerType withFrame:(CGRect)viewport withSkin:(NSString *)skinString withView:(UIView *)view;

#pragma mark - Player Customization
/** @name Player Customization */

/**
 * Sets player's viewport.
 * @param viewport Viewport size of the player. If CGRectNull is passed, the player view will always match the parent view, even if the parent view is resized.
 *
 *
 */

- (void) setViewport:(CGRect)viewport;

/**
 * Changes skin for player control with JSON skin string
 * @param skinString JSON data string for skinning the player controls. Pass nil to use default controls. Pass @"{}" for removing all controls.
 *
 *
 */

- (void) configureGUI :(NSString *)skinString;

/**
 * Changes skin for player control with skin view
 * @param skinView Skin view for player controls
 */

- (void)configureGUIWithSkinView:(UIView *)skinView;

#pragma mark - Load Media
/** @name Load Media */

/**
 Load a list of media URIs to the player.

 The following provides an example on how the API can be used.

        - (void) viewDidLoad
        {
          //register for playlist change notification

          [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playlistChange:)
          name:PACMediaPlayerPlaylistDidChangeNotification object:mediaPlayerObject];
        }

        - (void) playlistChange:(NSNotification*)notification
        {
          //populate playlist on playlist change notification
        }

        - (void) load
        {
          //call load media on the playlist player object

          [mediaPlayerObject loadMediaWithMediaURIs:@[@"101", @"102", @"103"] 
                                            options:@{PACMediaPlayerLoadMediaOptionAutoplay:[NSNumber numberWithBool:YES]}];
        }

  @param mediaURIs An array of media URI strings.
  @param options Additional options associated to loading the media. Please refer to PACMediaPlayerLoadMediaOptions for possible keys.
 */
- (void)loadMediaWithMediaURIs:(NSArray<NSString*> *)mediaURIs options:(NSDictionary *)options;

/**
 * Load a list of media URIs to the player.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param options Additional options associated to loading the media. Please refer to PACMediaPlayerLoadMediaOptions for possible keys.
 */
- (void)loadMediaWithMediaURIs:(NSArray<NSString*> *)mediaURIs autoplay:(BOOL)autoplay options:(NSDictionary *)options;

/**
 Loads media by the list of mediaURIs.

 Loads media by the list of mediaURIs.
  
        - (void) viewDidLoad
        {
          //register for playlist change notification

          [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playlistChange:)
          name:PACMediaPlayerPlaylistDidChangeNotification object:mediaPlayerObject];
        }

        - (void) playlistChange:(NSNotification*)notification
        {
          //populate playlist on playlist change notification
        }

        - (void) load
        {
          //call load media on the playlist player object

          [mediaPlayerObject loadMedia:@[@"101", @"102", @"103"]];
        }
 

 @param mediaURIs An array of media URI strings.
 @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 */
- (void) loadMedia:(NSMutableArray *)mediaURIs
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));
;

/**
 * Loads media by the list of mediaURIs and ppvToken.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 */
- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken.
 * @param mediaURIs An array of media URI strings.
 * @param ppvToken The pay per view payment token.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 *
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withPPVToken:(NSString *)ppvToken
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken and autoplay.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param ppvToken The pay per view payment token.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 *
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay withPPVToken:(NSString *)ppvToken
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken and autoplay and default soundtrack code.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param soundtrackCode The soundtrack code.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 *
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay withSoundtrack:(NSString *)soundtrackCode
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken and autoplay and default subtitle code.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param subtitleCode The subtitle code.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 *
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay withSubtitle:(NSString *)subtitleCode
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken and autoplay and default soundtrack code.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param ppvToken The pay per view payment token.
 * @param soundtrackCode The soundtrack code.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 *
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay withPPVToken:(NSString *)ppvToken withSoundtrack:(NSString *)soundtrackCode
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken and autoplay and default subtitle code.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param ppvToken The pay per view payment token.
 * @param subtitleCode The subtitle code.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 *
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay withPPVToken:(NSString *)ppvToken withSubtitle:(NSString *)subtitleCode
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

/**
 * Loads media by the list of mediaURIs and ppvToken and autoplay and default soundtrack code and default subtitle code.
 * @param mediaURIs An array of media URI strings.
 * @param autoplay A bool to determine whether to start playing media after media is loaded.
 * @param ppvToken The pay per view payment token.
 * @param soundtrackCode The soundtrack code.
 * @param subtitleCode The subtitle code.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.
 */

- (void) loadMedia:(NSMutableArray *)mediaURIs withAutoplay:(BOOL)autoplay withPPVToken:(NSString *)ppvToken withSoundtrack:(NSString *)soundtrackCode withSubtitle:(NSString *)subtitleCode
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.10.00.00. Please use [PACMediaPlayerV1 loadMediaWithMediaURIs:options:] instead.")));

#pragma mark - Player Properties
/** @name Player Properties */

/**
 * Returns the player type of playlist player (VOD, AOD, TV, Radio).
 *
 * @see PACMediaPlayerType
 * @return Returns player type.
 */

- (PACMediaPlayerType) getPlayerType;

/** @name Playback Info */

/**
 * Returns the duration of the current media.
 *
 * @return Returns the duration of the current media.
 */

- (double) getDuration;

/**
 * Gets the current seek time
 *
 *
 * @return {NSTimeInterval}
 */

-(NSTimeInterval)getCurrentTime;

/**
 * Gets the current Display State of the player
 *
 *
 * @return {NSString}
 */

-(NSString *)getDisplayState;

/**
 * This method provides a collection of time ranges for which the download task has media data already
 * downloaded and playable. The ranges provided might be discontinuous.
 *
 * @return Returns an NSArray of NSValues containing CMTimeRanges.
 */
- (NSArray <NSValue *> *)loadedTimeRanges;

#pragma mark - Playlist methods
/** @name Playlist Methods */

/**
 * Returns current index of the playlist player.
 *
 * @return Returns current index.
 */

- (int) playlistGetCurrentItemIndex;

/**
 * Add items at the end of the playlist by passing in its media uris.
 *
 * @param mediaURIs An array of media URI strings.
 * @param options Additional options associated to loading the media. Please refer to PACMediaPlayerAddMediaOptions for possible keys.
 *
 */
- (void) playlistAddItemsWithMediaURIs:(NSArray<NSString*> *)mediaURIs
                               options:(NSDictionary*)options;

/**
 * Add items at particular index by passing in its media uri.
 *
 * @param mediaURIs An array of media URI strings.
 * @param index The index in the playlist to which the items should be added at.
 * @param options Additional options associated to loading the media. Please refer to PACMediaPlayerAddMediaOptions for possible keys.
 *
 */
- (void) playlistAddItemsWithMediaURIs:(NSArray<NSString*> *)mediaURIs
                               atIndex:(NSInteger)index
                               options:(NSDictionary*)options;

/**
 * Adds an item by passing in its media uri.
 *
 * @param mediaURI An array of media URI strings.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 03.09.01.00. Please use [PACMediaPlayerV1 playlistAddItemsWithMediaURIs:options:] instead.
 */

- (void) playlistAddItemByMediaURI:(NSMutableArray *)mediaURI
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 03.09.01.00. Please use [PACMediaPlayerV1 playlistAddItemsWithMediaURIs:options:] instead.")));

/**
 * Adds an item by passing in its media uri and ppv token.
 *
 * @param mediaURIs An array of media URI strings.
 * @param ppvToken The pay per view payment token.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 03.09.01.00. Please use [PACMediaPlayerV1 playlistAddItemsWithMediaURIs:options:] instead.
 */

- (void) playlistAddItemByMediaURI:(NSMutableArray *)mediaURIs withPPVToken:(NSString *)ppvToken
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 03.09.01.00. Please use [PACMediaPlayerV1 playlistAddItemsWithMediaURIs:options:] instead.")));
;

/**
 * Adds an item at particular index by passing in its media uri and ppv token.
 *
 * @param mediaURIs An array of media URI strings.
 * @param index The index in the playlist to which the items should be added at.
 * @param ppvToken The pay per view payment token.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 03.09.01.00. Please use [PACMediaPlayerV1 playlistAddItemsWithMediaURIs:atIndex:options:] instead.
 */

- (void) playlistAddItemByMediaURI:(NSMutableArray *)mediaURIs atIndex:(int)index withPPVToken:(NSString *)ppvToken
__attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 03.09.01.00. Please use [PACMediaPlayerV1 playlistAddItemsWithMediaURIs:atIndex:options:] instead.")));
;

/**
 * Returns whether the playlist has a next item.
 *
 * This API can be used to decide whether you need to enable/disable the next button on index change, shuffle mode changed, repeate mode changed events. This API honors
 * the playlist repeat mode.
 */
- (BOOL) playlistHasNext;

/**
 * Returns whether the playlist has a previous item.
 *
 * This API can be used to decide whether you need to enable/disable the previous button on index change, shuffle mode changed, repeate mode changed events. This API honors
 * the playlist repeat mode.
 */
- (BOOL) playlistHasPrevious;

/**
 * Plays an item by passing in its index.
 *
 * @param index The index of the item in the playlist to play
 * @return TRUE if method call was successful.
 */

- (BOOL) playlistPlayItemByIndex:(int)index;

/**
 * Returns an array containing all media URIs that make up the playlist.
 *
 * @return Returns an array of media URIs
 */

- (NSMutableArray *) playlistGetInfo;

/**
 * Plays an item by passing in its media uri.
 *
 * @param mediaURI The media URI to play.
 * @return TRUE if method call was successful.
 */

- (BOOL) playlistPlayItemByMediaURI:(NSString *)mediaURI;

/**
 * Resume playing an item in the playlist identified by the bookmark.
 *
 * @param bookmark A bookmark, that identifies a media in the playlist and elapsed time, to be used to resume media playback.
 * @return YES if the the operation was successful. NO if bookmark is invalid or playlist item referred by bookmark does not exist.
 */
- (BOOL) playlistPlayItemByBookmark:(PACMediaBookmark *)bookmark;

/**
 * Plays next item in the playlist.
 */

- (void) playlistPlayNext;

/**
 * Plays previous item in the playlist.
 */

- (void) playlistPlayPrevious;

/**
 * Removes an item by its index.
 *
 * @param index The index of the item in the playlist to remove,
 * @return TRUE if method call was successful.
 */

- (BOOL) playlistRemoveItemByIndex:(int)index;

/**
 * Removes an item by its media uri.
 *
 * @param mediaURI The media URI to remove.
 * @return TRUE if method call was successful.
 */

- (BOOL) playlistRemoveItemByMediaURI:(NSString *)mediaURI;

/**
 * Move playlist item at index.
 *
 * @param fromIndex The index of the playlist item to move.
 * @param toIndex The index in the array at which to move the playlist item to. This value must not be greater than the count of elements in the array - 1.
 * @return Returns TRUE if the operation was successful.
 */
- (BOOL)playlistMoveItemAtIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

/**
 * Move playlist item in range.
 *
 * @param range The range of playlist items to move.
 * @param toIndex The index in the array at which to move the playlist item to. This value must not be greater than the count of elements in the array - the number of items to move.
 * @return Returns TRUE if the operation was successful.
 */
- (BOOL)playlistMoveItemsInRange:(NSRange)range toIndex:(NSUInteger)toIndex;

/**
 * Clear all playlist items.
 *
 * @return TRUE if method call was successful.
 */

- (BOOL) playlistClear;

/**
 * Sets repeat mode for the playlist.
 *
 * @see PACMediaPlayerRepeatMode
 * @param mode The repeat mode.
 *
 */

- (void) playlistSetRepeatMode:(PACMediaPlayerRepeatMode)mode;

/**
 *  Returns repeat mode for the playlist.
 *
 *
 * @return Returns the value of the player's repeat mode. Refer to PACMediaPlayerRepeatMode.
 */
- (PACMediaPlayerRepeatMode) playlistGetRepeatMode;

/**
 * Sets shuffle on or off
 *
 *
 * @param mode If TRUE, the playlist will be set in shuffle mode.
 *
 */

- (void) playlistSetShuffle:(BOOL)mode;

/**
 * Gets shuffle state
 *
 * @return The shuffle state.
 */

- (BOOL) playlistGetShuffle;

#pragma mark - Player Controls
/** @name Player Controls */

/**
 * Plays current item in the playlist. Resumes the playback if paused.
 */

- (void) play;

/**
 * Plays current item in the playlist with ppvToken. Resumes the playback if paused.
 *
 * @param ppvToken The pay per view payment token.
 */

- (void) play:(NSString *)ppvToken;

/**
 * Pauses the playback.
 */

- (void) pause;

/**
 * Stops the playback.
 */

- (void) stop;

/**
 * Seeks to the specified time.
 * @param sec The time to the point that the player should seek to.
 */

- (void) seek:(NSTimeInterval)sec;

#pragma mark - Fullscreen Methods
/** @name Fullscreen Methods */

/**
 * Requests for fullscreen mode.
 */
- (void) requestFullScreen;

/**
 * Cancels for fullscreen mode.
 */
- (void) cancelFullScreen;

/**
 * Gets the fullscreen state.
 * @return Returns true if player is in fullscreen mode.
 */
- (BOOL) isFullScreen;

#pragma mark - Player Visibility
/** @name Player Visibility Methods */

/**
 * Shows the media player that has been hidden.
 */

- (void) show;

/**
 * Hides the media player.
 */

- (void) hide;

/**
 * Removes the media player.
 * This call will stop the player and clears the playlist.
 */

- (void) remove;

#pragma mark - Bookmarks
/** @name Bookmarks */

/**
 * Returns the bookmark of the current playback.
 *
 * @return The bookmark of the current playback. Nil, if no valid bookmark can be returned. Please refer to PACMediaBookmark for more details.
 */
- (PACMediaBookmark *)currentBookmark;

#pragma mark - Advertisements
/** @name Advertisements */

/**
 * Skips advertisement.
 * @return TRUE if advertisement was skipped. FALSE if current media is not advertisement or advertisement can't be skipped at the time.
 */
- (BOOL)skipAdvertisement;

/**
 * Returns whether user can skip advertisement.
 * @return TRUE if advertisment is allowed to be skipped.
 */
- (BOOL)canSkipAdvertisement;

/**
 * Returns whether advertisement is currently playing.
 * @return TRUE if advertisment is playing.
 */
- (BOOL)isPlayingAdvertisement;

@end

/**
 * PACMediaPlayerV1 'soundtracks' category introduces new APIs to add support for multiple soundtracks.
 */
@interface PACMediaPlayerV1 (soundtracks)

/**
 * This method will change the soundtrack to the corresponding track defined by the language code.
 *
 * @param code The language code of the soundtrack to switch to. The code can be retrieved by using the metadata apis.
 * @return Returns TRUE if successful.
 */
- (BOOL)setSoundtrack:(NSString *)code;

/**
 * This method will return the code of the currently playing soundtrack.
 *
 * @return The code of the currently playing soundtrack.
 */
- (NSString *)soundtrack;

/**
 * This method will return the code of all available soundtrack.
 *
 * @return The array of available soundtrack code.
 */
- (NSArray*)audioTracks;
@end

/**
 * PACMediaPlayerV1 'subtitles' category introduces new APIs to add support for subtitles.
 */
@interface PACMediaPlayerV1 (subtitles)

/**
 * This method will change the subtitle to the corresponding track defined by the language code.
 *
 * @param code The language code of the soundtrack to switch to. The code can be retrieved by using the metadata apis. If nil, subtitles will be turned off.
 * @return Returns TRUE if successful.
 */
- (BOOL)setSubtitle:(NSString *)code;

/**
 * This method will return the code of the currently playing subtitle.
 *
 * @return The code of the currently playing subtitle.
 */
- (NSString *)subtitle;

/**
 * This method will return the code of all available subtitle.
 *
 * @return The array of available subtitle code.
 */
- (NSArray*)subtitleTracks;


#pragma mark - Closed Caption
/*!
 * Return true, if video has CEA-608/CEA-708 closed caption available. Otherwise, return false.
 * @return True for video with closed caption.
 */
- (BOOL)hasClosedCaption;

/*!
 * Return true, if video has CEA-608/CEA-708 closed caption available, then enable closed caption track. Otherwise, return false.
 * @return True for video enable closed caption.
 */
- (BOOL)isClosedCaptionEnabled;

/*!
 * Enable or disable closed caption CEA-608/CEA-708 track.
 * @param enable True to enable closed caption and False to disable closed caption.
 */
- (void)enableClosedCaption:(BOOL)enable;

@end

/**
 * PACMediaPlayerV1 'remoteevents' category handles remote control events from the iOS Control Center, ear phones, etc.
 */
@interface PACMediaPlayerV1 (remoteevents)

/**
 * Sent to the receiver when a remote-control event is received.
 * Remote-control events originate as commands from external accessories, including headsets. An application responds to these commands by controlling audio or video media presented to the user. ViewController that is the first responder needs to implement this function on their ViewController class and call this api to handle it.
 *
 * @param event An event object encapsulating a remote-control command. Remote-control events have a type of UIEventTypeRemoteControl.
 *
 */
- (void)remoteControlReceivedWithEvent:(UIEvent *)event;

@end



/**
 * Dispatched when there's enough data in the buffer to play
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerCanPlayNotification;

/**
 * Dispatched when the buffer runs to the end of the media date
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerCanPlayThroughNotification;

/**
 * Dispatched when the player cannot download the rest of the media
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidStallNotification;

/**
 * Dispatched when buffering
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerWaitingNotification;

/**
 * Dispatched when the player begins playing
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerPlayingNotification;

/**
 * Dispatched when the player has been set to stop
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidStopNotification;

/**
 * Dispatched when the player has been set to pause
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidPauseNotification;

/**
 * Dispatched when the player has begun seeking
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerSeekingNotification;

/**
 * Dispatched when the player has finished playing the media
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidEndNotification;

/**
 * Dispatched when the next or previous item in a playlist is started
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerPlaylistIndexDidChangeNotification;

/**
 * Dispatched when the playlist has changed
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerPlaylistDidChangeNotification;

/**
 * Dispatched on warning
 *
 * *userinfo* The payload of the notification.
 *
 *  - *text* Text description of the warning
 *  - *code* Integer code of the warning. Please refer to PACMediaPlayerWarningCode for possible warning codes.
 *
 */

extern NSString *const PACMediaPlayerWarningNotification;

/**
 * Dispatched on error
 *
 * *userinfo* The payload of the notification.
 *
 *  - *text* Text description of the warning
 *  - *code* Integer code of the warning. Please refer to PACMediaPlayerErrorCode for possible error codes.
 *
 */

extern NSString *const PACMediaPlayerErrorNotification;

/**
 * Dispatched when the duration has changed
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDurationDidChangeNotification;

/**
 * Dispatched when the player's buffer has been emptied
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidEmptyNotification;

/**
 * Dispatched when the fullscreen state has changed
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerFullScreenChangeNotification;

/**
 * Dispatched when the fullscreen state will be changed
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerFullScreenWillChangeNotification;

/**
 * Dispatched when new media information is being loaded
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerLoadDidStartNotification;

/**
 * Dispatched when the player has enough buffer to play for the first time
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidLoadDataNotification;

/**
 * Dispatched when the media meta data has been parsed
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerDidLoadMetaDataNotification;

/**
 * Dispatched when all items in a playlist have finished playing
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerPlaylistDidEndNotification;

/**
 * Dispatched when the player has been instantiated in the DOM and is ready for commands
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerReadyNotification;

/**
 * Dispatched when the player has been set to play
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerPlayNotification;

/**
 * Dispatched when the player has been interrupted
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerInterruptedNotification;

/**
 * Dispatched when the player has been seeked
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerSeekedNotification;

/**
 * Dispatched when the player's current time is changed
 *
 *
 * @param TBD
 */

extern NSString *const PACMediaPlayerTimeUpdateNotification;

/**
 * Dispatched when the loaded media time ranges has changed. Useful for buffering progress bar.
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerMediaLoadedTimeRangesDidChangeNotification;

/**
 * Dispatched when the repeat mode changes.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerPlaylistRepeatModeChangedNotification;

/**
 * Dispatched when the shuffle mode changes.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerPlaylistShuffleModeChangedNotification;

/**
 * Dispatched when volume has changed.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerVolumeDidChangeNotification;

/**
 * Dispatched when hyperlink is clicked.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerHyperlinkClickedNotification;
extern NSString *const PACMediaPlayerHyperlinkClicked;

/**
 * Dispatched when player was removed.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerRemoveNotification;


/**
 * The media player event that notifies the seek delay in which the player
 * can seek after.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerSeekDelayChangeNotification;

/**
 * The media player event that notifies that the player is able to seek.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerCanSeekNotification;

/**
 * The media player event that notifies that the player has skipped an advertisement.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerSkippedAdvertisementNotification;


/**
 * Dispatched when user selects a different subtitle.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerSubtitlesChangedNotification;

/**
 * Dispatched when user enable or disable the closed caption.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerClosedCaptionChangedNotification;


/**
 * Dispatched when user selects a different soundtrack.
 *
 *
 * @param TBD
 */
extern NSString *const PACMediaPlayerSoundtrackChangedNotification;


/**
 * @constantgroup PACMediaPlayerLoadMediaOptions
 * The load media accepts a number of options to customize the load command.
 * @owner PACMediaPlayerV1
 */

/**
 * Play media automatically after successful load. 
 *
 * The value of that key should be a NSNumber object of type bool.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionAutoplay;

/**
 * The pay per view payment token.
 *
 * This token is used to authorize the playback of purchased media. The value associated to this key should be of type NSString.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionPPVToken;

/**
 * The soundtrack language code.
 *
 * This value can be retrieved by doing a metadata request. The value associated to this key should be of type NSString.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionSoundtrackCode;

/**
 * The subtitle language code.
 *
 * This value can be retrieved by doing a metadata request. The value associated to this key should be of type NSString.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionSubtitleCode;

/**
 * The index of the playlist to play after a successful load.
 *
 * This value can be retrieved by doing a metadata request. The value associated to this key should be of type NSString.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionItemIndex;

/**
 * A bookmark, that identifies a media in the playlist and elapsed time, to be used to resume media playback.
 *
 * The value associated to this key should be of type PACMediaBookmark.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionBookmark;

/**
 * An array of category ids strings. 
 *
 * Please note that the number of items in this array should match the number of items passed in mediaUris.
 * For mediaUris that has not category id info, pass in an empty string.
 */
extern NSString *const PACMediaPlayerLoadMediaOptionCategoryIds;


/**
 * @constantgroup PACMediaPlayerAddMediaOptions
 * The playlist add items accepts a number of options to customize the add command.
 * @owner PACMediaPlayerV1
 */

/**
 * The pay per view payment token.
 *
 * This token is used to authorize the playback of purchased media. The value associated to this key should be of type NSString.
 */
extern NSString *const PACMediaPlayerAddMediaOptionPPVToken;

/**
 * An array of category ids strings.
 *
 * Please note that the number of items in this array should match the number of items passed in mediaUris.
 * For mediaUris that has not category id info, pass in an empty string.
 */
extern NSString *const PACMediaPlayerAddMediaOptionCategoryIds;
