//
//  UIColor+PanaSky.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/5/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIColor (PanaSky)

+ (UIColor *)PScolorWithHexString:(NSString *)stringToConvert;
- (NSString *)hexStringValue;
- (NSString *)htmlStringValue;
- (UIImage *)imageFromColor;

@end
