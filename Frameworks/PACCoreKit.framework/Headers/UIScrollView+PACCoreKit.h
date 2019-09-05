/** @module PACCoreKit.framework *///
//  UIScrollView+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 02/24/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * Extenstion to scroll view used by some of the sample apps.
 */
@interface UIScrollView (PACCoreKit)

typedef NS_ENUM (NSInteger,UIScrollView_ScrollToCorner)
{
    UIScrollView_ScrollToCornerTopLeft      = 0,
    UIScrollView_ScrollToCornerTopRight     = 1,
    UIScrollView_ScrollToCornerBottomLeft   = 2,
    UIScrollView_ScrollToCornerBottomRight  = 3,
};


@property (readwrite,nonatomic,assign)  CGFloat pac_zoomInMultiplier;
@property (readwrite,nonatomic,assign)  CGFloat pac_zoomOutMultiplier;

-(void)pac_scrollToCorner:(UIScrollView_ScrollToCorner )corner
    animated:(BOOL )animated;

-(UIView* )pac_viewForZooming;

-(void)pac_scrollViewZoomIn:(UIGestureRecognizer* )gestureRecognizer;

-(void)pac_scrollViewZoomReset:(UIGestureRecognizer* )gestureRecognizer;

-(void)pac_scrollViewZoomOut:(UIGestureRecognizer* )gestureRecognizer;

@end
