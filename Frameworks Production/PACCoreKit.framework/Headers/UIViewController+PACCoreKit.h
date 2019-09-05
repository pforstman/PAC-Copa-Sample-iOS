/** @module PACCoreKit.framework *///
//  UIViewController+PACCoreKit.h
//  CrewMessageSDKTest
//
//  Created by Gary L. Wade (MLS Technologies) on 12/05/2015.
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (PACCoreKit)

-(void)pac_presentViewControllerNamed:(NSString* )nameOfViewController
    fromStoryboardWithName:(NSString* )nameOfStoryboard
    bundle:(nullable NSBundle* )storyboardBundleOrNil
    animated:(BOOL )animated
    completion:(void(^ __nullable)(void) )completion;

+ (UIViewController * __nullable)pac_topViewController;

-(void)pac_replaceViewWithNewSuperviewAndSiblingView:(UIView* )newSiblingView
    positionSiblingViewAboveOriginalView:(BOOL )positionSiblingAboveUs;

-(void)pac_showChildViewController:(UIViewController* )childViewController
    coveringSubview:(UIView* )subview
    animated:(BOOL )animated;

-(void)pac_hideChildViewController:(UIViewController* )childViewController
    coveringSubview:(UIView* )subview
    animated:(BOOL )animated;

-(void)pac_attachWithinSuperviewTopConstraint:(NSNumber* )topConstraintValue
    leadingConstraint:(NSNumber* )leadingConstraintValue
    bottomConstraint:(NSNumber* )bottomConstraintValue
    trailingConstraint:(NSNumber* )trailingConstraintValue;

-(void)pac_addSubviewController:(UIViewController* )childViewController
    intoView:(UIView* )subview
    topConstraint:(NSNumber* )topConstraintValue
    leadingConstraint:(NSNumber* )leadingConstraintValue
    bottomConstraint:(NSNumber* )bottomConstraintValue
    trailingConstraint:(NSNumber* )trailingConstraintValue
    layoutIfNeeded:(BOOL )layoutIfNeeded;

@end

NS_ASSUME_NONNULL_END
