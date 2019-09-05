/** @module PACCoreKit.framework *///
//  UINavigationItem+Utilities.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 03/23/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationItem (Utilities)

-(void)pac_removeBarButtonItemsWithAction:(SEL )actionToNotKeep
    animated:(BOOL )animated;

@end
