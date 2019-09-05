/** @module PACCoreKit.framework *///
//  UINavigationController+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 12/05/2015.
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationController (PACCoreKit)

-(void)pac_pushViewControllerNamed:(NSString* )nameOfViewController
    fromStoryboardWithName:(NSString* )nameOfStoryboard
    bundle:(nullable NSBundle* )storyboardBundleOrNil
    animated:(BOOL )animated;

@end

NS_ASSUME_NONNULL_END
