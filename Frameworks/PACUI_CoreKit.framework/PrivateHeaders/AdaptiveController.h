//
//  AdaptiveController.h
//  Adaptive
//
//  Created by Tyson Tune on 5/28/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AdaptiveController <NSObject>
@required
// adaptive controllers must be able to affect a transition to a new view controller when requested
- (void)adaptive_transitionToViewController:(UIViewController *)viewController completion:(void(^)(BOOL success))completion;

@optional
- (void)adaptive_pushToViewController:(UIViewController *)viewController completion:(void(^)(BOOL success))completion;
- (CGRect)adaptive_fromRectForPopoverWithKey:(NSString *)popoverKey;

@property (strong, nonatomic) NSDictionary *configuration;

@end
