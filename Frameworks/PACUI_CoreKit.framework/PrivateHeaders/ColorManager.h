//
//  ColorManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 10/16/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ColorManager : NSObject

+ (ColorManager*)sharedColorManager;

@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, strong) UIColor *primaryColor;
@property (nonatomic, strong) UIColor *primary_pressedColor;
@property (nonatomic, strong) UIColor *primary_disabledColor;
@property (nonatomic, strong) UIColor *primary_60Color;
@property (nonatomic, strong) UIColor *primary_inactiveColor;
@property (nonatomic, strong) UIColor *primary_inactive_textColor;
@property (nonatomic, strong) UIColor *bg_colorColor;
@property (nonatomic, strong) UIColor *bg_color_for_bg_imageColor;
@property (nonatomic, strong) UIColor *button_iconColor;
@property (nonatomic, strong) UIColor *entertainment_divider_lineColor;
@property (nonatomic, strong) UIColor *entertainment_chevronColor;
@property (nonatomic, strong) UIColor *favorite_star_badgeColor;
@property (nonatomic, strong) UIColor *live_highlightColor;
@property (nonatomic, strong) UIColor *live_shellColor;
@property (nonatomic, strong) UIColor *live_shell_inactiveColor;
@property (nonatomic, strong) UIColor *secondaryColor;
@property (nonatomic, strong) UIColor *secondary_pressedColor;
@property (nonatomic, strong) UIColor *nav_bgColor;
@property (nonatomic, strong) UIColor *nav_connection_barColor;
@property (nonatomic, strong) UIColor *nav_connect_iconColor;
@property (nonatomic, strong) UIColor *nav_connectActive_iconColor;
@property (nonatomic, strong) UIColor *nav_selected_blockColor;
@property (nonatomic, strong) UIColor *nav_selected_iconColor;
@property (nonatomic, strong) UIColor *nav_pressed_blockColor;
@property (nonatomic, strong) UIColor *nav_top_barColor;
@property (nonatomic, strong) UIColor *nav_iconsColor;
@property (nonatomic, strong) UIColor *top_barColor;
@property (nonatomic, strong) UIColor *top_bar_popoverColor;
@property (nonatomic, strong) UIColor *popover_bgColor;
@property (nonatomic, strong) UIColor *flight_tracker_leftColor;
@property (nonatomic, strong) UIColor *top_bar_activeColor;
@property (nonatomic, strong) UIColor *top_bar_inactiveColor;
@property (nonatomic, strong) UIColor *top_bar_iconsColor;
@property (nonatomic, strong) UIColor *top_bar_nav_activeColor;
@property (nonatomic, strong) UIColor *flight_tracker_rightColor;
@property (nonatomic, strong) UIColor *flight_tracker_textColor;
@property (nonatomic, strong) UIColor *flight_tracker_text_primaryColor;
@property (nonatomic, strong) UIColor *flight_tracker_planeColor;
@property (nonatomic, strong) UIColor *miniplayer_unplayedColor;
@property (nonatomic, strong) UIColor *overlay_bgColor;
@property (nonatomic, strong) UIColor *alert_iconColor;
@property (nonatomic, strong) UIColor *miniplayer_bgColor;
@property (nonatomic, strong) UIColor *player_scrubberColor;
@property (nonatomic, strong) UIColor *miniplayer_scrubberColor;
@property (nonatomic, strong) UIColor *blackColor;
@property (nonatomic, strong) UIColor *black_90Color;
@property (nonatomic, strong) UIColor *black_60Color;
@property (nonatomic, strong) UIColor *black_50Color;
@property (nonatomic, strong) UIColor *black_40Color;
@property (nonatomic, strong) UIColor *black_15Color;
@property (nonatomic, strong) UIColor *black_6Color;
@property (nonatomic, strong) UIColor *whiteColor;
@property (nonatomic, strong) UIColor *clearColor;
@property (nonatomic, strong) UIColor *player_iconsColor;
@property (nonatomic, strong) UIColor *player_highlightColor;
@property (nonatomic, strong) UIColor *miniplayer_iconsColor;
@property (nonatomic, strong) UIColor *kids_zone_bgColor;
@property (nonatomic, strong) UIColor *play_btn_mdColor;
@property (nonatomic, strong) UIColor *star_ratingColor;
@property (nonatomic, strong) UIColor *err_colorColor;
@property (nonatomic, strong) UIColor *success_colorColor;
@property (nonatomic, strong) UIColor *nav_icon_exitColor;
@property (nonatomic, strong) UIColor *player_nav_barsColor;
@property (nonatomic, strong) UIColor *player_playedColor;
@property (nonatomic, strong) UIColor *miniplayer_playedColor;
@property (nonatomic, strong) UIColor *player_unplayedColor;
@property (nonatomic, strong) UIColor *player_flight_tracker_leftColor;
@property (nonatomic, strong) UIColor *player_flight_tracker_rightColor;
@property (nonatomic, strong) UIColor *player_flight_tracker_planeColor;
@property (nonatomic, strong) UIColor *flight_tracker_plane_moduleColor;
@property (nonatomic, strong) UIColor *player_flight_tracker_textColor;
@property (nonatomic, strong) UIColor *search_iconsColor;
@property (nonatomic, strong) UIColor *carousel_placeholderColor;
@property (nonatomic, strong) UIColor *carousel_placeholder_bgColor;

+ (UILabel *)labelForStyle:(NSString *)styleName;
@end
