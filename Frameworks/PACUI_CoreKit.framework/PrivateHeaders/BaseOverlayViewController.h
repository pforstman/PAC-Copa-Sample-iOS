//
//  BaseOverlayViewController.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 7/8/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "AdaptiveController.h"

#define LOADING_VIEW_TAG 1001

@interface BaseOverlayViewController : UIViewController <UIGestureRecognizerDelegate, AdaptiveController>

@property (nonatomic, assign) BOOL isPushed;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *topConstraint;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *bottomConstraint;
@property (nonatomic, weak) IBOutlet UIView *overlayView;
@property (strong, nonatomic) NSDictionary *configuration;

- (void)processAnalytics;
- (void)refreshContentInsets;
- (void)addOpenPlaylistButton;
- (void)handleDismissButtonPress:(id)sender;
- (void)addLoadingView;
- (void)removeLoadingView;

@end
