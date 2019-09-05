/** @module PACCoreKit.framework *///
//  PACBezierPathView.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 02/18/2016.
//  Copyright © 2016 Panasonic Avionics. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * A Class that handles creating a dotted bezier path view.
 */
@interface PACBezierPathView : UIView

@property (readwrite,nonatomic,strong)  UIBezierPath*   bezierPath;
@property (readwrite,nonatomic,strong)  UIColor*        fillColor;
@property (readwrite,nonatomic,strong)  UIColor*        strokeColor;

+(instancetype )dottedPathBezierPathViewWithFrame:(CGRect )frame
    strokeColor:(UIColor* )strokeColor;

@end
