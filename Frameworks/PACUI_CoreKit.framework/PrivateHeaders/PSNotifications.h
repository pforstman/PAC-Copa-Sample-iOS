//
//  PSNotifications.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/10/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kSelectedMediaCategoryDidChange;
extern NSString * const kMediaSearchTextDidChange;
extern NSString * const kNavigationTargetChange;
extern NSString * const kFavoritesAdded;
extern NSString * const kFavoritesRemoved;
extern NSString * const kFavoritesUpdated;
extern NSString * const kPlaylistUpdated;
extern NSString * const kFavoritesEditModeDidChange;
extern NSString * const kUserProfileDidChange;
extern NSString * const kUserFlightsDidChange;
extern NSString * const kConnectionStatusDidChange;
extern NSString * const kMetadataRefreshDidFinish;
extern NSString * const kRequestForFullScreenVideoPlayback;
extern NSString * const kRequestForMiniPlayerDisplay;
extern NSString * const kRequestForMiniPlayerHidden;
extern NSString * const kRequestForMiniPlayerResume;
extern NSString * const kRequestForMiniPlayerExpandCollapse;
extern NSString * const kMiniPlayerVisibilityDidChange;
extern NSString * const kMiniPlayerStateDidChange;
extern NSString * const kAudioPlaylistIndexDidChange;
extern NSString * const kCurrentAudioURIDidChange;
extern NSString * const kCurrentParentAudioURIDidChange;
extern NSString * const kSelectedNewsCategoryDidChange;
extern NSString * const kRequestForPresentMediaOverlay;
extern NSString * const kCurrentlyPlayingMovieDidChange;
extern NSString * const kCurrentlyPlayingLiveTVDidChange;
extern NSString * const kSelectedSoundtrackDidChange;
extern NSString * const kSelectedSubtitlesDidChange;
extern NSString * const kCurrentFlightDataDidChange;
extern NSString * const kCurrentFlightDataUpdate;
extern NSString * const kFlightAvailabilityStatusDidChange;
extern NSString * const kWiFiConnectionEnded;
extern NSString * const kWiFiConnectionRestored;
extern NSString * const kMediaAvailableStatusDidChange;
extern NSString * const kRequestForHideMainMenu;
extern NSString * const kHideMainMenuComplete;
extern NSString * const kRevealMainMenuComplete;
extern NSString * const kRequestForRootViewController;
extern NSString * const kExitInFlightEntertainment;
extern NSString * const kWeatherDegreesChanged;
extern NSString * const kWeatherLocationChanged;
extern NSString * const kWeatherDegreeChanged;
extern NSString * const kPauseCarouselAnimation;
extern NSString * const kResumeCarouselAnimation;
extern NSString * const kVideoPlayerPopoverDidOpen;
extern NSString * const kVideoPlayerPopoverDidClose;
extern NSString * const kSeatBackMediaPlayerInfoDidChange;
extern NSString * const kSeatBackCurrentAudioUriDidChange;
extern NSString * const kSeatBackCurrentAudioPlaybackStateDidChange;
extern NSString * const kServerAvailabilityStateDidChange;
extern NSString * const kMediaBookmarkStateDidChange;
extern NSString * const kAvailableServicesDidChange;
extern NSString * const kSeatPairingModeDidChange;
extern NSString * const kEXConnectStatusDidChange;
extern NSString * const kNavigationMenuWillShow;
extern NSString * const kNavigationMenuWillHide;
extern NSString * const kShoppingCartUpdated;
extern NSString * const kTailNumberDidChange;

@interface PSNotifications : NSObject

@end
