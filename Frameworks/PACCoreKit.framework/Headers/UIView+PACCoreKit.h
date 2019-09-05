/** @module PACCoreKit.framework *///
//  UIView+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 02/12/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (PACCoreKit)

@property (readwrite,nonatomic,assign)  UIColor*    pac_borderColor;
@property (readwrite,nonatomic,assign)  CGFloat     pac_borderCornerRadius;
@property (readwrite,nonatomic,assign)  CGFloat     pac_borderWidth;

-(void)pac_setBorderColorIsTinted:(id )nilValue;

-(UIView* )pac_superviewOfClass:(Class )theClass;

-(void)pac_enumerateSubviewsWithKindOfClass:(Class )theClass
block:(void(^)(UIView* aViewMatchingClass,BOOL* stop) )block;

@end
