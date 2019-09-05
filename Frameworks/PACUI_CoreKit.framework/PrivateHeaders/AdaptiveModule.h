//
//  AdaptiveModule.h
//  Adaptive
//
//  Created by Tyson Tune on 5/27/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@protocol AdaptiveModule <NSObject>

@required

typedef void(^Module_CompletionBlock)(id <AdaptiveModule>);

+ (instancetype)moduleWithConfiguration:(NSDictionary *)configuration;

// view controller to use when presenting the module
- (UIViewController *)detailViewController;


@optional

// default summary view controller, should be flexible in layout
- (UIViewController *)summaryViewController;

// optional navigation controller to use when presenting the detail view controller
- (UINavigationController *)navigationController;

// data items for the module
@property (nonatomic, copy, readwrite) NSArray *items;
@property (nonatomic, copy, readwrite) Module_CompletionBlock completion;

@end
