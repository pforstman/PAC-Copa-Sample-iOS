/*!
 @module PACUI_CoreKit.framework
 */
//
//  PACUI_MiniApp.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 5/23/17.
//  Copyright © 2017 Panasonic Avionics Corporation. All rights reserved.
//


/*!
 * @typedef PACUI_MiniAppModule
 * @brief A list of Mini-App modules.
 * @owner PACUI_MiniApp
 */
typedef enum
{
    /// The Full module experience
    PACUI_MiniAppModuleFull = 100,
    /// The Featured module.
    PACUI_MiniAppModuleFeatured,
    /// The Favorites module.
    PACUI_MiniAppModuleFavorites,
    /// The Movies module.
    PACUI_MiniAppModuleMovies,
    /// The TV module.
    PACUI_MiniAppModuleTV,
    /// The Music module.
    PACUI_MiniAppModuleMusic,
    /// The Radio module.
    PACUI_MiniAppModuleRadio,
    /// The Audiobooks module.
    PACUI_MiniAppModuleAudiobooks,
    /// The Games module.
    PACUI_MiniAppModuleGames,
    /// The Kids module.
    PACUI_MiniAppModuleKids,
    /// The Video Playlist module.
    PACUI_MiniAppModuleVideoPlaylist,
    /// The Music Playlist module.
    PACUI_MiniAppModuleMusicPlaylist,
    /// The Maps module.
    PACUI_MiniAppModuleMaps,
    /// The Live TV module.
    PACUI_MiniAppModuleLiveTV,
    /// The News module.
    PACUI_MiniAppModuleNews,
    /// The Weather module.
    PACUI_MiniAppModuleWeather,
    /// The Shopping module.
    PACUI_MiniAppModuleShopping,
    /// The Parental Controls module.
    PACUI_MiniAppModuleParentalControls,
} PACUI_MiniAppModule;


/*!
 * This class is the root point of contact for interfacing with the Mini-App.
 */
@interface PACUI_MiniApp : NSObject


/*!
 * @discussion Property for setting custom headers to be added to outgoing url requests.
 */
@property (nonatomic, strong, readwrite) NSDictionary * _Nullable customHeaders;


/*!
 * @discussion Asks the Mini-App to initialize the framework. Must be called before attempting to open any Mini-App modules via the openURL method.
 */
- (void)initialize;


/*!
 * @discussion Asks the Mini-App to initialize the framework. Must be called before attempting to open any Mini-App modules via the openURL method.
 * @param appIdEnabled Boolean flag to determine if the "app_id" property from AdaptiveConfig.json will be used to configure the InFlight SDK.
 */
- (void)initializeWithAppIdEnabled:(BOOL)appIdEnabled;


/*!
 * @discussion Directs the Mini-App to watch the specified file path in support of live edits to the stylesheet when running in the iOS simulator
 */
- (void)watchStylesheetFilepath:(NSString *_Nonnull)stylesheetPath;


/*!
 * @discussion Asks the Mini-App to open a resource identified by a URL.
 * @param url The URL resource to open. Use urlForModule helper method to easily construct resource URL's in the correct format.
 * @param sourceApplication The bundle ID of the app that is requesting to open the URL (url).
 * @return Returns YES if the Mini-App successfully handled the request or NO if the attempt to open the URL resource failed.
 */
- (BOOL)openURL:(NSURL * _Nonnull)url sourceApplication:( NSString * _Nullable )sourceApplication;


/*!
 * @discussion Allows the Mini-App to perform any cleanup tasks prior to termination. Should be called from the application delegate's applicationWillTerminate method.
  */
- (void)shutdown;


/*!
 * @discussion Sets a flag within the framework enabling certain debug behaviors for the current run.
 */
- (void)enableDebugMode;


/*!
 * @discussion Asks the Mini-App to generate a URL to be used with the openURL method.
 * @param module The PACUI_MiniAppModule type identifying a specific module.
 * @return The formatted URL.
 */
+ (NSURL * _Nullable)urlForModule:(PACUI_MiniAppModule)module;


/*!
 * @discussion Asks the Mini-App if the mini player is currently visible on screen.
 * @return Returns YES if the Miniplayer is currently visible, NO if not.
 */
+ (BOOL)isMiniPlayerVisible;


/*!
 * @discussion Asks the Mini-App for the height of the mini player.
 * @return If the mini player is currently visible, returns the height in pixels of the mini player's view; returns 0.0 if the mini player is not visible.
 */
+ (CGFloat)miniPlayerHeight;


/*!
 * @discussion Asks the Mini-App to stop any media playback and close the mini-player view.
 */
+ (void)stopPlayback;


/*!
 * @discussion Asks the Mini-App to disable the seat pairing service availability check.
 */
- (void)disablePairingServiceCheck;


/*!
 * @discussion Asks the Mini-App to close all modules.
 */
+ (void)shutdownModules;


#pragma mark - Notifications


/*!
 * @brief Event dispatched when the mini plalyer's visiblity status changes.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACUIMiniPlayerVisibilityDidChangeNotification;


/*!
 * @brief Event dispatched when the modules is exiting.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACUIModulesWillExitNotification;


@end
