//
//  SeatPairingManager.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 9/25/15.
//  Copyright © 2015 Mercury. All rights reserved.
//

#import <PACSeatPairing/PACSeatPairing.h>

@class PSMedia;

#define kSeatPairingConnectAnimationDuration 1.3f

typedef void(^SuccessCompletion)(BOOL result, NSError *error);

typedef enum : NSUInteger {
    PairingInputModeUnknown = 0,
    PairingInputModeSeatNumber,
    PairingInputModePasscode,
} PairingInputMode;

@interface SeatPairingManager : NSObject

+ (SeatPairingManager *)sharedSeatPairingManager;

@property (nonatomic, assign, readonly) BOOL isPaired;
@property (nonatomic, copy) NSString *seatNumber;
@property (nonatomic, assign) PACSeatMediaPlayerPlaybackState videoPlaybackState;
@property (nonatomic, assign) PACSeatMediaPlayerPlaybackState audioPlaybackState;
@property (nonatomic, copy) NSString *currentMediaUri;
@property (nonatomic, copy) NSString *currentAudioUri;
@property (nonatomic, assign) double elapsedTime;
@property (nonatomic, assign) double elapsedAudioTime;
@property (nonatomic, assign) NSInteger currentVolume;
@property (nonatomic, assign) NSInteger currentAudioVolume;
@property (nonatomic, copy) NSString *soundtrack;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, assign) BOOL isManualPairingInProgress;
@property (nonatomic, readonly) PairingInputMode pairingInputMode;

- (void)openSeatPairingOverlay;
- (void)openSeatPairingOverlayWithTargetIdentifier:(NSString *)targetIdentifier;
- (void)setIsPaired:(BOOL)isPaired;
- (void)checkPlaylistsNeedSyncingWithCompletion:(void (^)(BOOL result))completion;
- (void)askToPeformSyncWithSeatback;
- (void)performSyncWithSeatback;
- (void)performFavoritesSync;
- (void)performPlaylistSync;
- (void)performPlaylistSync:(SuccessCompletion)completion;
- (void)initiatePairingWithSeatNumber:(NSString *)seatNumber completion:(SuccessCompletion)completion;
- (void)pairWithPasscode:(NSString *)passcode completion:(SuccessCompletion)completion;
- (void)unpairWithCompletion:(SuccessCompletion)completion;
- (NSString *)lookupSeatClass;
- (BOOL)checkPairingState;
- (void)requestPlayerInfo;
- (void)launchMedia:(PSMedia *)media;
- (void)launchMediaWith:(NSString *)uri type:(NSString *)contentType category:(NSInteger)categoryID;
- (void)launchVideoQueue:(NSArray *)data withIndex:(NSInteger)index source:(NSString *)source;
- (void)launchVideoQueue:(NSArray *)data withIndex:(NSInteger)index source:(NSString *)source soundtrack:(NSString *)soundtrack subtitle:(NSString *)subtitlel;
- (void)launchAudioQueue:(NSArray *)data withIndex:(NSInteger)index source:(NSString *)source;
- (void)playAlbumOnSeatback:(PSMedia *)album;
- (void)stepBack;
- (void)stepForward;
- (void)playQueue;
- (void)playAudio;
- (void)playVideo;
- (void)pauseQueue;
- (void)pauseAudio;
- (void)pauseVideo;
- (void)stopQueue;
- (void)jumpToNextItemInQueue;
- (void)jumpToPreviousItemInQueue;
- (void)jumpToIndexInQueue:(NSUInteger)index;
- (void)setQueueSoundtrack:(NSString *)soundtrack;
- (void)setQueueSubtitle:(NSString *)subtitle;
- (BOOL)isQueuePlaying:(NSArray *)queue;
- (void)performUserProfileSyncWithCompletionHandler:(void (^)(NSError *error))completion;
- (void)stopAudio;
- (void)stopVideo;
- (void)nextAudioTrack;
- (void)previousAudioTrack;
- (void)seekAudioToPosition:(NSInteger)position;
- (void)seekVideoToPosition:(NSInteger)position;
- (void)volumeUpAudio;
- (void)volumeUpVideo;
- (void)volumeDownAudio;
- (void)volumeDownVideo;
- (void)setVideoVolume:(NSInteger)volume;
- (void)setAudioVolume:(NSInteger)volume;
- (void)setSoundtrack:(NSString *)soundtrack;
- (void)setSubtitle:(NSString *)subtitle;
- (BOOL)isMediaUriNowPlaying:(NSString *)mediaUri;
- (BOOL)isMediaUriNowPaused:(NSString *)mediaUri;
- (BOOL)isAudioUriNowPlaying:(NSString *)mediaUri inQueue:(NSArray *)queue;
- (PACSeatPairingPairStatus)pairStatus;
- (void)showInFlightOnlyAlertView;
- (void)sendRequestToShareFavorites:(NSArray *)newItems withCompletionHandler:(void (^)(NSError *error))completion;
- (void)sendRequestToSharePlaylist:(NSArray *)newItems withCompletionHandler:(void (^)(NSError *error))completion;
- (void)sendRequestToRemoveItemFromFavorites:(NSArray *)item;
- (void)checkPlayingRemoteState;
@end
