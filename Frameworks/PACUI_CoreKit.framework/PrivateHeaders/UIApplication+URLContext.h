//
//  UIApplication+URLContext.h
//  Adaptive
//
//  Created by Mohssen Fathi on 12/13/16.
//  Copyright © 2016 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIApplication (URLContext)

- (void)openURL:(NSURL *)url withContext:(NSDictionary *)context;

@end
