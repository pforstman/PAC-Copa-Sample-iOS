//
//  AdaptiveDataProvider.h
//  Adaptive
//
//  Created by Tyson Tune on 5/27/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AdaptiveDataProvider <NSObject>

@required
+ (instancetype)providerWithConfiguration:(NSDictionary *)configuration;
- (NSDictionary *)configuration;
- (NSArray *)data;

@optional
- (BOOL)updateSynchronously:(NSError *__autoreleasing *)error;
- (void)updateAsynchronously:(void(^)(BOOL success, BOOL contentsChanged, NSError *error))completion;

@end
