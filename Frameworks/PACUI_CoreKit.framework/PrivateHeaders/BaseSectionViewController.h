//
//  BaseSectionViewController.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 8/18/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "MainMenuViewController.h"
#import "AdaptiveController.h"
#import "FlightStatusView.h"
#import "MediaPlaceholderView.h"
#import "SeatPairingManager.h"
#import "AdvertisingManager.h"
#import "LoadingIndicatorView.h"

#define kSearchPopoverKey @"searchPopover"
#define kPlaylistPopoverKey @"playlistPopover"
#define kVideoPlaylistPopoverKey @"videoPlaylistPopover"
#define kCategoriesPopoverKey @"categoriesPopover"
#define kFlightInfoPopoverKey @"flightInfoPopover"
#define kAudioAndSubtitlesPopoverKey @"audioAndSubtitlesPopover"
#define kPlaybackLocationPopoverKey @"playbackLocationPopover"
#define kChannelsListPopoverKey @"channelsListPopover"
#define kGuidePopoverKey @"guidePopover"
#define kNewsCategoriesPopoverKey @"newsCategoriesPopover"
#define kWeatherLocationsPopoverKey @"weatherLocationsPopover"

#define CUSTOM_NAV_BAR_HEIGHT 64

#define NAV_BUTTON_BASE_TAG 2000
#define NAV_BUTTON_MENU_TAG 2000
#define NAV_BUTTON_BACK_TAG 2001
#define NAV_BUTTON_WEB_BACK_TAG 2002
#define NAV_BUTTON_WEB_FORWARD_TAG 2002
#define NAV_BUTTON_FLIGHT_STATUS_TAG 2500
#define NAV_BUTTON_TITLE_TAG 3000
#define NAV_BUTTON_SYNC_TAG 3500
#define NAV_BUTTON_EDIT_TAG 3600
#define NAV_BUTTON_CATEGORIES_TAG 4005
#define NAV_BUTTON_FULLSCREEN_TAG 4010
#define NAV_BUTTON_REFRESH_TAG 4011
#define NAV_BUTTON_ACTION_TAG 4012
#define NAV_BUTTON_SHOPPING_TAG 4020
#define NAV_BUTTON_SEARCH_TAG 5000
#define NAV_BUTTON_PLAYLIST_TAG 5010
#define NAV_BUTTON_LOCATIONS_TAG 5020
#define NAV_BUTTON_CLOSE_TAG 5100


extern NSString * const BaseSectionNavigationTitleTappedNotification;   // note.object property is the sender

@protocol SectionViewControllerDelegate <NSObject>

@required
- (void)showHideMenu;

@end

@interface BaseSectionViewController : UIViewController <AdaptiveController, UIGestureRecognizerDelegate, PSAdViewDelegate>
@property (nonatomic, assign) BOOL isPushed;
@property (nonatomic, assign) BOOL disableCustomLayout;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *topConstraint;
@property (nonatomic, strong) FlightStatusView *flightStatusView;
@property (nonatomic, strong) NSDictionary *configuration;
@property (nonatomic, strong) NSDictionary *dynamicConfiguration;
@property (nonatomic, copy) NSString *mediaTemplateID;
@property (nonatomic, strong) NSNumber *mediaCategoryID;
@property (nonatomic, strong) NSNumber *selectedMediaCategoryID;
@property (nonatomic, assign) id<SectionViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet UIButton *menuButton;
@property (nonatomic, weak) IBOutlet UIImageView *backgroundImageView;
@property (nonatomic, strong) NSLayoutConstraint *leftConstraint;
@property (nonatomic, strong) NSLayoutConstraint *rightConstraint;
@property (nonatomic, copy) NSString *alternatePlaneIcon;
@property (nonatomic, assign) BOOL shouldSuppressParentalControlsLockIcon;
@property (nonatomic, assign) CGFloat customNavBarHeight;
@property (nonatomic, strong) MediaPlaceholderView *mediaPlaceholderView;
@property (nonatomic, assign) BOOL suppressAnalytics;
@property (nonatomic, copy) NSString *adZone;
@property (nonatomic, weak) IBOutlet UIView *bannerAdContainerView;
@property (nonatomic, weak) IBOutlet UIView *bannerAdContainerViewMask;
@property (nonatomic, weak) IBOutlet PSAdView *adView;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *adContainerViewHeightConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *adViewWidthConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *adViewHeightConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *adViewTopConstraint;
@property (nonatomic, strong) LoadingIndicatorView *loadingIndicatorView;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *adContainerBottomToSuperview;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint *adContainerBottomToSafeArea; //Used to move ad banner up with mini player view
@property (nonatomic, weak) IBOutlet UIView *accessibilityContainerView;

- (void)accessibilityNotification;
- (void)processAnalytics;
- (BOOL)usingBackgroundImage;
- (void)addMenuButtonToNavigationBar;
- (void)setBackButtonTitle:(NSString *)backButtonTitle;
- (void)addCategoriesButton;
- (void)addSearchButton;
- (void)addSyncButton;
- (void)addPlaylistButton;
- (void)addVideoPlaylistButton;
- (void)addShoppingBagButton;
- (void)addLoadingIndicatorView;
- (void)addLoadingIndicatorViewWithBackgroundColor:(UIColor *)backgroundColor;
- (void)releaseLoadingIndicatorView;
- (void)updateTitleAlignment;
- (void)loadFlightStatusView;
- (void)loadFlightStatusViewWithTargetIdentifier:(NSString *)targetIdentifier;
- (void)loadFlightStatusViewWithTargetIdentifier:(NSString *)targetIdentifier intoView:(UIView *)view;
- (void)setupAdvertising;
- (void)refreshBannerAd;
- (void)refreshContentInsets;
- (void)reloadContent;
- (void)updateFlightStatusView;
- (void)disableAccessibility;
- (void)enableAccessibility;
- (void)refreshBackgroundImageForOrientation:(UIInterfaceOrientation)orientation;
- (BOOL)isX;

@end

@interface PSCustomNavigationBar : UINavigationBar
@end

@interface BaseNavigationController : UINavigationController <UINavigationControllerDelegate, UINavigationBarDelegate>
@property (nonatomic, assign) CGFloat customNavigationBarHeight;
@property (nonatomic, strong) UIImageView *customBackgroundImageView;
@property (nonatomic, strong) PSCustomNavigationBar *customNavigationBar;
@property (nonatomic, strong) NSLayoutConstraint *leftConstraint;
@property (nonatomic, strong) NSLayoutConstraint *rightConstraint;
- (void)resizeIt;
- (CGFloat)calcCustomHeight;
- (void)setCustomNavigationBarColor:(UIColor *)color;
- (void)hideCustomNavigationBar:(BOOL)shouldHide;
- (void)setCustomNavigationTitle:(NSString *)title;
- (void)addLeftBarButtonItem:(UIBarButtonItem *)leftBarButtonItem;
- (void)addRightBarButtonItem:(UIBarButtonItem *)rightBarButtonItem;
- (void)setRightBarButtonItem:(UIBarButtonItem *)rightBarButtonItem;
- (void)setLeftBarButtonItem:(UIBarButtonItem *)leftBarButtonItem;
- (void)setBackBarButtonItem:(UIBarButtonItem *)leftBarButtonItem;
- (void)disableAccessibility;
- (void)enableAccessibility;
@end

@interface ShoppingBadgeView : UIView
@property (nonatomic, assign) NSUInteger count;
@end

