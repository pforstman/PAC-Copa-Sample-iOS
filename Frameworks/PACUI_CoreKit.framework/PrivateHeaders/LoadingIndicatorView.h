//
//  LoadingIndicatorView.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 8/20/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

#define LOADING_INDICATOR_TAG 1001

@interface LoadingIndicatorView : UIView

- (id)initWithFrame:(CGRect)frame;
- (id)initWithFrame:(CGRect)frame style:(UIActivityIndicatorViewStyle)style;
- (void)start;
- (void)invalidate;

@end
