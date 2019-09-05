/** @module PACSeatPairing.framework *///
//  PACSeatRemoteControlV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015-2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PACSeatPairingV1.h"
#import "PACSeatMediaPlayerInfo.h"
#import "PACSeatMediaRemoteController.h"
#import <PACCoreKit/PACCoreKit.h>

/**
  This class is responsible for sending remote commands to the seatback monitor.
 */
@interface PACSeatRemoteControlV1 : NSObject

/**
 * Returns the list of seat media remote controllers. These are used
 * to control the media player playback in the seatback monitor. 
 * @return The array of PACSeatMediaRemoteController objects.
 */
- (NSArray *)seatMediaRemoteControllers;

/**
 Send a launch media request.

 Send a launch media request.

        PACSeatMediaRemoteCommandResult result =
         [self.seatRemoteControl launchMediaWithMediaURI:@"112"
                                               globalURI:nil
                                             contentType:PACSeatRemoteControlLaunchMediaContentTypeMovie
                                                 options:@{PACSeatRemoteControlLaunchMediaStartOffsetKey:[NSNumber numberWithInteger:30]}
                                       completionHandler:^(NSError *error){
            if (!error) {
                NSLog(@"Request sent successfully.";
            }
            else{
                NSLog(@"Error in sending request: %@", error);
            }
         }];
 
        if (result == PACSeatMediaRemoteCommandResultNotPaired){
            NSLog(@"Device is not paired. Please verify you set the seat pairing session using the api useSeatPairing and that session is paired.");
        }
        else if (result == PACSeatMediaRemoteCommandResultInvalidParams){
            NSLog(@"One or more params are missing or incorrect.";
        }
        else{
            NSLog(@"Request queued successfully.";
        }

  @param mediaURI The media URI of the media to launch. The media URI is a media identifier that may only apply to a single flight.
<br> You can get the media URI by doing a PACMetadataV1 or a PACGroundMetadataV1 request for the specific media. This field is required if global URI is not provided.
  @param globalURI The global URI of the media to launch. The global URI is a media identifier that is common among all flights. 
<br> You can get the global URI by doing a PACMetadataV1 or a PACGroundMetadataV1 request for the specific media. This field is required if media URI is not provided.
  @param contentType The content type of the media that is sent.  For example, audio or video media. Please refer to the PACSeatRemoteControlLaunchMediaContentTypes section for values.
  @param options This dictionary holds extra parameters to pass with the launch media command. Please refer to PACSeatRemoteControlLaunchMediaKeys for options.
  @param completion The completion handler.
 
 - *error* If error is nil, no error has occurred. Please refer to
 PACSeatRemoteControlErrorCode for error codes.
  @return The result of the launch media request. The media is appended to the media queue, then the media queue jumps to the added item. 
 */
- (PACSeatMediaRemoteCommandResult)launchMediaWithMediaURI:(NSString *)mediaURI
                                              globalURI:(NSString *)globalURI
                                            contentType:(NSString *)contentType
                                                options:(NSDictionary *)options
                                      completionHandler:(void (^)(NSError *error))completion;


@end



/**
 * This class category handles controlling properties, such as  on the seatback monitor.
 */
@interface PACSeatRemoteControlV1 (display)

/**
 * Sets brightness level of the light for the seatback.
 *
 * @param level Absolute percentage of brightness level to set in the seatback.
 * @param completion The completion handler.
 *
 * - *error* If error is nil, no error has occurred. Please refer to
 * PACSeatControlErrorCode for possible error codes.
 */
- (void)setBrightnessLevel:(NSUInteger)level withCompletionHandler:(void (^)(NSError *error))completion;

@end

#pragma mark - Error Codes
/**
 * The error codes returned by the remote control requests.
 */
typedef enum{
    /** The request has failed due to an unknown error. */
    PACSeatRemoteControlErrorUnknown                          = 1500,
    /** The request has failed due to invalid or missing parameters. */
    PACSeatRemoteControlErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatRemoteControlErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatRemoteControlErrorConnectionError                  = 1503,
    /** The request has failed due to an unexpected response from the server. */
    PACSeatRemoteControlErrorBadResponse                      = 1504,
    /** The request has failed due to the unavailability of the service. */
    PACSeatRemoteControlErrorServiceNotFound                  = 1505,
    /** The request has failed due to a passenger announcement being in progress on the seatback monitor */
    PACSeatRemoteControlErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to the device not being paired. */
    PACSeatRemoteControlErrorNotPaired                        = 1600
}PACSeatRemoteControlErrorCode;

#pragma mark - Notifications

/**
 * This event is dispatched when a seat media remote control is added or removed.
 * No userinfo available. Refresh list of remote controllers by querying seatMediaRemoteControllers.
 * @owner PACSeatRemoteControlV1
 */
extern NSString *const PACSeatMediaRemoteControllerDidChangeNotification;

/**
 * This event is dispatched when the media player information on the seatback monitor changes.
 * Payload contains the array of remote controller objects with the changed player information.
 *
 *   userinfo = @{ @"value" = [<array_of_SeatMediaRemoteControllers>] }
 *
 * @owner PACSeatRemoteControlV1
 */
extern NSString *const PACSeatMediaPlayerInfoDidChangeNotification;

#pragma mark - Launch Media Keys
/**
 * @constantgroup PACSeatRemoteControlLaunchMediaKeys
 * The list of launch media keys.
 * @owner PACSeatRemoteControlV1
 */

/**
 * This key defines the media type, such as audio or video, of the launch media command. 
 *
 * Please see the PACSeatRemoteControlLaunchMediaTypes section for available values.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaTypeKey;

/**
 * This key defines the start offset of the launch media command. This is used to start a media at a specific playback time.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaStartOffsetKey;

/**
 * This key defines the category id of the launch media command.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaCIDKey;

/**
 * This key defines the subtitle language code to be used with the launch media command.
 * The value should be a NSString object stating the language code as received my the metadata request.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaSubtitleKey;

/**
 * This key defines the soundtrack language code to be used with the launch media command.
 * The value should be a NSString object stating the language code as received by the metadata request.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaSoundtrackKey;

#pragma mark - Launch Media Types
/**
 * @constantgroup PACSeatRemoteControlLaunchMediaTypes
 * The list of launch media type options.
 * @owner PACSeatRemoteControlV1
 */

/**
 * The media type is Audio.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaTypeAudio;

/**
 * The media type is Audio Aggregate.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaTypeAudioAggregate;

/**
 * The media type is Video.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaTypeVideo;

/**
 * The media type is Video Aggregate.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaTypeVideoAggregate;


#pragma mark - Launch Media Content Types
/**
 * @constantgroup PACSeatRemoteControlLaunchMediaContentTypes
 * The list of available launch media content types.
 * @owner PACSeatRemoteControlV1
 */

/**
 * The content type is Movie.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeMovie;

/**
 * The content type is Episode.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeTVEpisode;

/**
 * The content type is TV Series.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeTVSeries;

/**
 * The content type is Trailer.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeTrailer;

/**
 * The content type is Track.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeTrack;

/**
 * The content type is Album.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeAlbum;

/**
 * The content type is ebook.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeEbook;

/**
 * The content type is Audio Book.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeAlbumAudioBook;

/**
 * The content type is Audio Book Chapter.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeTrackAudioBookChapter;

/**
 * The content type is Bundle.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeBundle;

/**
 * The content type is tv channel.
 */
extern NSString *const PACSeatRemoteControlLaunchMediaContentTypeTvChannel;
