//
//  PasscodeEntryView.h
//  PanaSkyKit-iOS
//
//  Created by Demetri Miller on 4/1/15.
//  Copyright (c) 2015 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PasscodeCircleContainerView;

@interface PasscodeEntryView : UIView

@property (nonatomic, strong) UILabel *headerLabel;
@property (nonatomic, strong) UIButton *forgotPasscodeButton;
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicatorView;
@property (nonatomic, assign) NSInteger currentPasscodeLength;

@property (nonatomic, strong) PasscodeCircleContainerView *circleContainerView;
@property (nonatomic, strong) UIColor *circleFillColor;     // Default to black_90Color
@property (nonatomic, strong) UIColor *circleStrokeColor;   // Default to black_15Color

/// Animations
- (void)runShakeAnimationOnEntryCircles;

@end

// ==============================
// PasscodeCircleContainerView
// ==============================
@interface PasscodeCircleContainerView : UIView

@end

