//
//  UIViewController+Adaptive.h
//  Adaptive
//
//  Created by Tyson Tune on 5/22/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@interface UIViewController (Adaptive)
@property (nonatomic, copy, readwrite) NSString *adaptiveID;
- (void)willPresentCustomPopover;
- (void)willDismissCustomPopover;
@end
