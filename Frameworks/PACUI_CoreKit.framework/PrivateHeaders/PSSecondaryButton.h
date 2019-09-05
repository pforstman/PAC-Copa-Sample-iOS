//
//  PSSecondaryButton.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 3/28/15.
//  Copyright (c) 2015 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LocalizedButton.h"

typedef enum : NSInteger {
    PSSecondaryButtonOutlineModeOff = 0,
    PSSecondaryButtonOutlineModeOn = 1
} PSSecondaryButtonOutlineMode;

@interface PSSecondaryButton : LocalizedButton
@property (nonatomic, assign) PSSecondaryButtonOutlineMode outlineMode;
@end
