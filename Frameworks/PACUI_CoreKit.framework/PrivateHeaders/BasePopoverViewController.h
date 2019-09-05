//
//  BasePopoverViewController.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 9/28/16.
//  Copyright © 2016 Mercury. All rights reserved.
//

#import "AnalyticsManager.h"
#import "AdaptiveController.h"

@interface BasePopoverViewController : UIViewController <AdaptiveController>

@property (nonatomic, assign) BOOL isPushed;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *topConstraint;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *bottomConstraint;
@property (nonatomic, assign) BOOL isAnalyticsOpen;

- (void)refreshContentInsets;
- (void)openAnalytics;
- (void)closeAnalytics;

@property (strong, nonatomic) NSDictionary *configuration;

@end
