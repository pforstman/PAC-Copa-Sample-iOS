//
//  PSNavigationBar.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 9/29/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kDefaultNavigationBarHeight 44.0f
#define kDefaultNavigationBarHeight_ios11 64.0f
#define kCustomNavigationBarHeight  84.0f

@interface PSNavigationBar : UINavigationBar

@property (assign, nonatomic) CGFloat height;

- (void)updateHeight:(UIViewController *)sender;

@end
