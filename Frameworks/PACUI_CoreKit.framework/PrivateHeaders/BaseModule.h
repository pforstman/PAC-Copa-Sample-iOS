//
//  BaseModule.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 5/2/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

#import "AdaptiveModule.h"
#import "AdaptiveRouter.h"
#import "UIViewController+Adaptive.h"

@interface BaseModule : NSObject <AdaptiveModule>
- (void)extendedInit; 
@property (nonatomic, strong, readwrite) NSDictionary *configuration;
@end
