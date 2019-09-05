//
//  AdaptiveRouter.h
//  Adaptive
//
//  Created by Tyson Tune on 5/22/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "AdaptiveDataProvider.h"
#import "AdaptiveController.h"
#import "AdaptiveModule.h"

extern NSString * const AdaptiveRouterDomain;

// Notifications
extern NSString * const kAdaptiveRouterWillPresentPopover;
extern NSString * const kAdaptiveRouterWillDismissPopover;
extern NSString * const kAdaptiveRouterDidPresentPopover;
extern NSString * const kAdaptiveRouterDidDismissPopover;

// Keys
extern NSString * const kAdaptiveRouterPopoverKey;
extern NSString * const kAdaptiveRouterTargetIdentifierKey;
extern NSString * const kAdaptiveRouterSectionTitleKey;
extern NSString * const kAdaptiveConfigSubmodulesKey;
extern NSString * const kAdaptiveConfigSubitemsKey;
extern NSString * const kAdaptiveConfigModuleIdentifierKey;
extern NSString * const kAdaptiveConfigSelectionModuleIdentifierKey;
extern NSString * const kAdaptiveConfigSelectionPresentationStyleKey;
extern NSString * const kAdaptiveConfigSelectedItemKey;
extern NSString * const kAdaptiveConfigIsActiveKey;
extern NSString * const kAdaptiveConfigUseNavigation;
extern NSString * const kAdaptiveConfigIsSelectionMomentary;
extern NSString * const kAdaptiveConfigRequiresConnection;
extern NSString * const kAdaptiveConfigAirlineName;
extern NSString * const kAdaptiveConfigAnalyticsApplicationName;
extern NSString * const kAdaptiveConfigRootModule;
extern NSString * const kAdaptiveConfigKioskModeRootModule;
extern NSString * const kAdaptiveConfigRootModule_iPhone;
extern NSString * const kAdaptiveConfigMainModule;
extern NSString * const kAdaptiveConfigMainTarget;
extern NSString * const kAdaptiveConfigStartupMode;
extern NSString * const kAdaptiveConfigLoginEnabled;
extern NSString * const kAdaptiveConfigMiniAppModeEnabled;
extern NSString * const kAdaptiveConfigMiniPlayerAdZoneAudio;
extern NSString * const kAdaptiveConfigMiniPlayerAdZoneVideo;
extern NSString * const kAdaptiveConfigMiniAppMenuEnabled;
extern NSString * const kAdaptiveConfigMiniAppHideExitButton;
extern NSString * const kAdaptiveConfigDynamicMainMenuEnabled;
extern NSString * const kAdaptiveConfigeXTVEnabled;
extern NSString * const kAdaptiveConfigDataProviderIdentifierKey;
extern NSString * const kAdaptiveConfigMediaCategoryID;
extern NSString * const kAdaptiveConfigCategoryRootType;
extern NSString * const kAdaptiveConfigParentCategoryRootType;
extern NSString * const kAdaptiveConfigParentCategoryIndex;
extern NSString * const kAdaptiveConfigCustomBackgroundImageNameKey;
extern NSString * const kAdaptiveConfigBackgroundColorValueKey;
extern NSString * const kAdaptiveConfigAdjustPositionForMiniPlayerKey;
extern NSString * const kAdaptiveConfigPermittedArrowDirections;
extern NSString * const kAdaptiveConfigShowPassengerInfo;
extern NSString * const kAdaptiveConfigShowSeatPairing;
extern NSString * const kAdaptiveConfigStatusBarStyle;
extern NSString * const kAdaptiveConfigSubcategoryImages;
extern NSString * const kAdaptiveConfigUseBackgroundImage;
extern NSString * const kAdaptiveConfigHideLogoOnLogin;
extern NSString * const kAdaptiveConfigHideLogo;
extern NSString * const kAdaptiveConfigSuppressBackgroundImage;
extern NSString * const kAdaptiveConfigBackgroundTiledImage;
extern NSString * const kAdaptiveConfigMediaCategoriesEnabled;
extern NSString * const kAdaptiveConfigMediaRatingsMode;
extern NSString * const kAdaptiveConfigSeatPairingEnabled;
extern NSString * const kAdaptiveConfigPlaylistFeatureEnabled;
extern NSString * const kAdaptiveConfigPlaylistPopoverDisabled;
extern NSString * const kAdaptiveConfigPointsOfInterestEnabled;
extern NSString * const kAdaptiveConfigAlternatePlaneIcon;
extern NSString * const kAdaptiveConfigModuleTitle;
extern NSString * const kAdaptiveConfigContainsDynamicContent;
extern NSString * const kAdaptiveConfigAternateModuleIdentifier;
extern NSString * const kAdaptiveConfigServiceDependency;
extern NSString * const kAdaptiveConfigServiceDependencyOffByDefault;
extern NSString * const kAdaptiveConfigSuppressParentalControlsButton;
extern NSString * const kAdaptiveConfigContentRatings;
extern NSString * const kAdaptiveConfigMasterCodes;
extern NSString * const kAdaptiveConfigAccessibilityContentRatings;
extern NSString * const kAdaptiveConfigContentRatingValues;
extern NSString * const kAdaptiveConfigEntertainmentActivityIndicatorStyle;
extern NSString * const kAdaptiveConfigImageSizeOffsetNumber;
extern NSString * const kAdaptiveConfigLogoInMainMenuAlignment;
extern NSString * const kAdaptiveConfigDisableAutoPaging;
extern NSString * const kAdaptiveConfigSwitchUsesPrimaryColor;
extern NSString * const kAdaptiveConfigAccountSettingsEnabled;
extern NSString * const kAdaptiveConfigPlaybackLocationOptionEnabled;
extern NSString * const kAdaptiveConfigPlayMediaOnSeatbackOnly;
extern NSString * const kAdaptiveConfigPlayLiveTVOnDeviceOnly;
extern NSString * const kAdaptiveConfigSuppressSoundtrackPicker;
extern NSString * const kAdaptiveConfigLiveTVMode;
extern NSString * const kMaxSeatbackFavorites;
extern NSString * const kAdaptiveConfigSupportedFavoritesTypes;
extern NSString * const kAdpativeConfigTVFavoritesAll;
extern NSString * const kAdaptiveConfigHidePageControl_iPhone;
extern NSString * const kAdaptiveConfigPairingAlertTimeoutPeriod;
extern NSString * const kAdaptiveConfigPairingHelpEnabled;
extern NSString * const kAdaptiveConfigShowLoyaltyNumber;
extern NSString * const kAdaptiveConfigVideoPlaylistEnabled;
extern NSString * const kAdaptiveConfigSeatPairingInitiateMode;
extern NSString * const kAdaptiveConfigDefaultSeatClass;
extern NSString * const kAdaptiveConfigAircraftDomain;
extern NSString * const kAdaptiveConfigChargeAlertEnabled;
extern NSString * const kAdaptiveConfigUseGroundServicesWhenServerUnavailable;
extern NSString * const kAdaptiveConfigUseVideoBookmarks;
extern NSString * const kAdaptiveConfigShowVideosWatched;
extern NSString * const kAdaptiveConfigLocationDependency;
extern NSString * const kAdaptiveConfigWeatherWidgetEnabled;
extern NSString * const kAdaptiveConfigFlightInfoWidgetEnabled;
extern NSString * const kAdaptiveConfigUseConnectAlertView;
extern NSString * const kAdaptiveConfigAdvertisingWidgetEnabled;
extern NSString * const kAdaptiveConfigFlightInfoModuleIdentifier;
extern NSString * const kAdaptiveConfigFlightInfoBackgroundColor;
extern NSString * const kAdaptiveConfigSuppressContentRatings;
extern NSString * const kAdaptiveConfigEnableContentRatingsImages;
extern NSString * const kAdaptiveConfigWeatherConditionsMap;
extern NSString * const kAdaptiveConfigEnableSeatPairingInitiateModeSettings;
extern NSString * const kAdaptiveConfigEnableNetworkThrottling;
extern NSString * const kAdaptiveConfigShowSSIDWhenNotOnboard;
extern NSString * const kAdaptiveConfigAdZone;
extern NSString * const kAdaptiveConfigDisableFlightNumber;
extern NSString * const kAdaptiveConfigIsStreamingMode;
extern NSString * const kAdaptiveConfigAnnounceTemplateDisabled;
extern NSString * const kAdaptiveConfigEnableBadgeOnHomeScreen;
extern NSString * const kAdaptiveConfigApplicationId;
extern NSString * const kAdaptiveConfigApplicationIdDebug;
extern NSString * const kAdaptiveConfigWebHideNavItems;
extern NSString * const kAdaptiveConfigWebAllowiPhoneRotation;
extern NSString * const kAdaptiveConfigPPVEnabled;
extern NSString * const kAdaptiveConfigPPVTheme;
extern NSString * const kAdaptiveConfigImageMapPosterAudio;
extern NSString * const kAdaptiveConfigImageMapSynopsisAudio;
extern NSString * const kAdaptiveConfigImageMapPosterVideo;
extern NSString * const kAdaptiveConfigImageMapSynopsisVideo;
extern NSString * const kAdaptiveConfigImageMapPosterCategory;
extern NSString * const kAdaptiveConfigImageMapSearchImage;
extern NSString * const kAdaptiveConfigTailNumbers;
extern NSString * const kAdaptiveConfigWeatherForecastNumberOfDays;
extern NSString * const kAdaptiveConfigImageMapDynamicMenuIcons;
extern NSString * const kAdaptiveConfigSuppressColoringForDynamicMenuIcons;
extern NSString * const kAdaptiveConfigFlightPathDoubleWidth;
extern NSString * const kAdaptiveConfigPrivacyPolicyLinkEnabled;
extern NSString * const kAdaptiveConfigEnableSoundtrackPickerOnDevice;
extern NSString * const kAdaptiveConfigAirportCodesBlacklist;
extern NSString * const kAdaptiveConfigLanguageCodes;
extern NSString * const kAdaptiveConfigUseInAppBrowserForAdClickThru;
extern NSString * const kAdaptiveConfigSupportedSearchTypes;

typedef NS_ENUM(NSInteger, AdaptiveRouterErrorType) {
    AdaptiveRouterErrorTypeMissingRootViewController = -1000,
    AdaptiveRouterErrorTypeMissingModule = -1001,
    AdaptiveRouterErrorTypeNonConformingClass = -1002,
    AdaptiveRouterErrorTypeInvalidModuleConfig = -1003,
    AdaptiveRouterErrorTypeNonConformingTarget = -1004
};

typedef NS_ENUM(NSUInteger, AdaptivePresentationStyle) {
    AdaptivePresentationStyleNone = 0,
    AdaptivePresentationStyleModal = 1,
    AdaptivePresentationStyleReplace = 2,
    AdaptivePresentationStylePopover = 3,
    AdaptivePresentationStyleOverlay = 4,
    AdaptivePresentationStylePush = 5
};

typedef NS_ENUM(NSUInteger, AdaptiveParentStyle) {
    AdaptiveParentStyleNone = 0,
    AdaptiveParentStyleNavigation = 1
};

@interface AdaptiveRouter : NSObject <UIPopoverPresentationControllerDelegate>

+ (instancetype)sharedRouter;

@property (nonatomic, strong, readwrite) NSDictionary *dataProvidersByIdentifier;
@property (nonatomic, strong, readwrite) NSDictionary *moduleClassNamesByIdentifier;
@property (nonatomic, strong, readwrite) NSDictionary *moduleConfigInfosByIdentifier;
@property (nonatomic, strong, readwrite) NSDictionary *moduleConfigURLsByIdentifier;
@property (nonatomic, strong, readwrite) NSMutableDictionary *globalConfig;
@property (nonatomic, copy, readwrite) NSString *URLScheme;

- (BOOL)loadModuleConfigFileNamed:(NSString *)fileName error:(NSError * __autoreleasing *)error;
- (BOOL)loadModuleConfigWithURL:(NSURL *)url error:(NSError *__autoreleasing *)error;

- (BOOL)canHandleURL:(NSURL *)url;
- (BOOL)openURL:(NSURL *)url error:(NSError * __autoreleasing *)error;
- (UIViewController *)viewControllerWithAdaptiveID:(NSString *)adaptiveID;
- (UIViewController *)viewControllerForURL:(NSURL *)url error:(NSError * __autoreleasing *)error;
- (NSString *)analyticsScreenNameForIdentifier:(NSString *)identifier;
- (void)updateAnalyticsScreenName:(NSString *)screenName forIdentifier:(NSString *)identifier;

- (id<AdaptiveDataProvider>)dataProviderForIdentifier:(NSString *)identifier;
- (id<AdaptiveDataProvider>)dataProviderForModuleIdentifier:(NSString *)identifier;
- (id<AdaptiveModule>)moduleForModuleIdentifier:(NSString *)moduleIdentifier error:(NSError *__autoreleasing *)error;
- (NSString *)globalConfigSettingForKey:(NSString *)key;
- (BOOL)globalBoolConfigSettingForKey:(NSString *)key;
- (NSArray *)globalConfigArrayForKey:(NSString *)key;
- (NSDictionary *)globalConfigDictionaryForKey:(NSString *)key;
- (void)setGlobalConfigSetting:(id)value forKey:(NSString *)key;

- (void)checkForReleaseHost;

- (NSURL *)urlForModuleWithIdentifier:(NSString *)identifier;
- (NSURL *)urlForModuleWithIdentifier:(NSString *)identifier presentation:(AdaptivePresentationStyle)style;
- (NSURL *)urlForModuleWithIdentifier:(NSString *)identifier presentation:(AdaptivePresentationStyle)style parent:(AdaptiveParentStyle)parent;
- (NSURL *)urlForModuleWithIdentifier:(NSString *)identifier presentation:(AdaptivePresentationStyle)style parent:(AdaptiveParentStyle)parent target:(NSString *)targetID;
- (NSURL *)urlForModuleWithIdentifier:(NSString *)identifier presentation:(AdaptivePresentationStyle)style parent:(AdaptiveParentStyle)parent target:(NSString *)targetID selectedItem:(id)selectedItem;

- (NSString *)flightInfoModuleIdentifier;
- (NSString *)flightInfoModuleClassName;

@end
