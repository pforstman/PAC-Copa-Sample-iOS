/** @module PACStreaming.framework *///
//  PACMediaPlayerCommon.h
//  InFlight iOS SDK
//  Copyright (c) 2014 Panasonic Avionics Corporation. All rights reserved.
//

#ifndef Library_MediaPlayerCommon_h
#define Library_MediaPlayerCommon_h

/**
 * This enum contains constants representing the playlist player types available to the client.
 * @owner PACMediaPlayerV1
 */
typedef enum {
    /** The playlist player's type is none or unknown. */
    PACMediaPlayerTypeNone = 0,
    /** The playlist player's type is AOD. */
    PACMediaPlayerTypeAOD = 1,
    /** The playlist player's type is VOD. */
    PACMediaPlayerTypeVOD = 2,
    /** The playlist player's type is TV. */
    PACMediaPlayerTypeTV = 3 ,
    /** The playlist player's type is Radio. */
    PACMediaPlayerTypeRadio = 4
} PACMediaPlayerType;

#define MPPlayerType        PACMediaPlayerType
#define MPTypeNone          PACMediaPlayerTypeNone
#define MPTypeAOD           PACMediaPlayerTypeAOD
#define MPTypeVOD           PACMediaPlayerTypeVOD
#define MPTypeTV            PACMediaPlayerTypeTV
#define MPTypeRadio         PACMediaPlayerTypeRadio

/**
 * This enum contains constants representing the playlist player repeat mode available to the client.
 * @owner PACMediaPlayerV1
 */
typedef enum {
    /** When set to this mode, the playlist doesn't repeat and stops after the last item finishes playing. */
    PACMediaPlayerRepeatModeNone,
    /** When set to this mode, the playlist repeats currently playing item over and over. */
    PACMediaPlayerRepeatModeOne,
    /** When set to this mode, the playlist repeats the the entire list over and over. */
    PACMediaPlayerRepeatModeAll
} PACMediaPlayerRepeatMode;

#define MPRepeatMode            PACMediaPlayerRepeatMode
#define MPRepeatModeNone        PACMediaPlayerRepeatModeNone
#define MPRepeatModeOne         PACMediaPlayerRepeatModeOne
#define MPRepeatModeAll         PACMediaPlayerRepeatModeAll

#define MEDIA_PLAYER_ERROR_BASE         1000
#define MEDIA_PLAYER_WARNING_BASE       2000

/**
 * The media player error codes.
 * @owner PACMediaPlayerV1
 */
typedef enum{
    /** Unknown error has occured */
    PACMediaPlayerErrorUnknown                     =   MEDIA_PLAYER_ERROR_BASE + 0,
    /** Bandwidth Allocation Error. If the player is not provided bandwidth allocation, then the media cannot be played. */
    PACMediaPlayerErrorBandwidthAllocationError    =   MEDIA_PLAYER_ERROR_BASE + 1,
    /** Network Unavailable or MID is invalid. If the Bandwidth Allocation Service is unreachable/unavailable, then the player cannot be granted bandwidth allocation to play any media. */
    PACMediaPlayerErrorNetworkUnavailable          =   MEDIA_PLAYER_ERROR_BASE + 2,
    /** Bad Request. The request to allocate bandwidth was unsuccessful because of error in the request itself. */
    PACMediaPlayerErrorBadRequest                  =   MEDIA_PLAYER_ERROR_BASE + 3,
    /** Reserved. */
    PACMediaPlayerErrorReserved                    =   MEDIA_PLAYER_ERROR_BASE + 4,
    /** Certificate check failed. The certificate on the server is invalid. */
    PACMediaPlayerErrorCertificateError            =   MEDIA_PLAYER_ERROR_BASE + 5,
    /** Purchase is required. The media requires to be purchased before you can play it. */
    PACMediaPlayerErrorPurchaseRequired            =   MEDIA_PLAYER_ERROR_BASE + 6,
    /** Device is blacklisted. The current device is not authorized to work on this system. */
    PACMediaPlayerErrorDeviceBlacklisted           =   MEDIA_PLAYER_ERROR_BASE + 7,
    /** DRM Error. If the player tried to play DRM media after DRM failing to initialize. */
    PACMediaPlayerErrorDRMFailure                  =   MEDIA_PLAYER_ERROR_BASE + 8,
    /** AVOD service is disabled. If the AVOD service is disabled from the server, the error would be thrown. */
    PACMediaPlayerErrorServiceDisabled             =   MEDIA_PLAYER_ERROR_BASE + 9,
    /** MID's rating exceed user set rating. */
    PACMediaPlayerErrorParentalControlRestricted   =   MEDIA_PLAYER_ERROR_BASE + 10,
    /** Playback Error. Occurs when playback is attempted while screen is being recorded. */
    PACMediaPlayerErrorScreenRecordingInProgress   =   MEDIA_PLAYER_ERROR_BASE + 11,
} PACMediaPlayerErrorCode;

/**
 * The media player warning codes.
 * @owner PACMediaPlayerV1
 */
typedef enum{
    /** Unknown warning has occured */
    PACMediaPlayerWarningUnknown                   =   MEDIA_PLAYER_WARNING_BASE + 0,
    /** Network Timeout. The network appears to be unavailable. Upon dispatching this warning, the player will attempt to reconnect every 30 seconds or so. */
    PACMediaPlayerWarningNetworkTimeout            =   MEDIA_PLAYER_WARNING_BASE + 2,
    /** One or media URIs received failed. When loading multiple items to a playlist, it’s possible that one or several of the media URIs that are sent failed. If at at least one media URI fails and at least one succeeds, then this warning will be dispatched. */
    PACMediaPlayerWarningInvalidMediaURIs          =   MEDIA_PLAYER_WARNING_BASE + 3,
    /** The bookmark provided is invalid. */
    PACMediaPlayerWarningInvalidBookmark          =   MEDIA_PLAYER_WARNING_BASE + 4
} PACMediaPlayerWarningCode;

// Undocumented
typedef enum {
    PACMPPlaybackStateUnknown,
    PACMPPlaybackStateAboutToPlay,
    PACMPPlaybackStatePlaying,
    PACMPPlaybackStatePaused,
    PACMPPlaybackStateStopped,
    PACMPPlaybackStateSeeking
} PACMPPlaybackState;

typedef enum {
    PACMPLoadStateUnknown,
    PACMPLoadStateCanPlayThrough,
    PACMPLoadStateStalled
} PACMPLoadState;


#endif
