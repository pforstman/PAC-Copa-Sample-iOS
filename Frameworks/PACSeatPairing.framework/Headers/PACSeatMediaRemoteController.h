/** @module PACSeatPairing.framework *///
//  PACSeatMediaRemoteController.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import "PACSeatMediaPlayerInfo.h"

/**
 * The return code of the remote control API calls for the seatback monitor.
 * @owner PACSeatMediaRemoteController
 */
typedef enum{
    /** The request was queued successfully. */
    PACSeatMediaRemoteCommandResultQueued = 0,
    /** Request failed because the device is not paired. */
    PACSeatMediaRemoteCommandResultNotPaired,
    /** Request failed because the parameters provided are invalid. */
    PACSeatMediaRemoteCommandResultInvalidParams,
}PACSeatMediaRemoteCommandResult;

/**
 * This class allows the paired device to send remote messages that control media playback in the seatback monitor.
 */
@interface PACSeatMediaRemoteController : NSObject

/**
 * The current player information on the seatback monitor.
 * @see PACSeatMediaPlayerInfo
 */
@property (nonatomic,strong,readonly) PACSeatMediaPlayerInfo *playerInfo;

/**
 * Send a play command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendPlayCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a pause command to the player on the seatback monitor. 
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendPauseCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a stop command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendStopCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a seek command to the player on the seatback monitor.
 *
 * @param seconds The seek point in time. This parameter is in seconds.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendSeekCommand:(NSUInteger)seconds withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a next track command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendNextTrackCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a previous track command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendPreviousTrackCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a step forward command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendStepForwardCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a step forward command to the player on the seatback monitor.
 *
 * @param interval Relative interval in seconds from current point to jump forward by.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for possible error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendStepForwardCommand:(NSUInteger)interval withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a step backward command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendStepBackwardCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a step backward command to the player on the seatback monitor.
 *
 * @param interval Relative interval in seconds from current point to jump backward by.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for possible error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendStepBackwardCommand:(NSUInteger)interval withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a command to set absolute volume level for the seat's player.
 *
 * @param volume Absolute volume level in percent to set. Value is from 0-100.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for possible error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendSetVolumeCommand:(NSUInteger)volume withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a volume up command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendVolumeUpCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a volume up command to the player on the seatback monitor.
 *
 * @param step Relative step value in percent to increase the volume by.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for possible error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendVolumeUpCommand:(NSUInteger)step withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a volume down command to the player on the seatback monitor.
 *
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendVolumeDownCommandWithCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a volume down command to the player on the seatback monitor.
 *
 * @param step Relative step value in percent to decrease the volume by.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for possible error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendVolumeDownCommand:(NSUInteger)step withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a subtitle change command to the player on the seatback monitor.
 *
 * @param subtitle The subtitle language code being switched to. If Nil, hide subtitles.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendSetSubtitleCommand:(NSString *)subtitle withCompletionHandler:(void (^)(NSError *error))completion;

/**
 * Send a soundtrack change command to the player on the seatback monitor.
 *
 * @param soundtrack The subtitle language code being switched to. If Nil, set default soundtrack.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatRemoteControlErrorCode for error codes.
 * @return The result of the request.
 */
- (PACSeatMediaRemoteCommandResult)sendSetSoundtrackCommand:(NSString *)soundtrack withCompletionHandler:(void (^)(NSError *error))completion;

@end
