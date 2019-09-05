//
//  BaseFlightInfoViewController.h
//  PACUI_CoreKit
//
//  Created by Paul Forstman on 10/17/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, FlightInfoViewControllerMode)
{
    FlightInfoViewControllerModeConstant = 0,
    FlightInfoViewControllerModeFlight,
};

@interface BaseFlightInfoViewController : UIViewController

@property (nonatomic, assign) FlightInfoViewControllerMode mode;

+ (CGFloat)viewHeight;

@end
