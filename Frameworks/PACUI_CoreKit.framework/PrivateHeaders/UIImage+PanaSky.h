//
//  UIImage+PanaSky.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/4/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@interface UIImage (PanaSky)
+ (UIImage *)panaImageNamed:(NSString *)name;
- (UIImage *)imageWithMaskImage:(UIImage *)maskImage;
- (UIImage *)convertToGrayScale;
+ (UIImage *)imageWithView:(UIView *)view;
+ (UIImage *)imageWithColor:(UIColor *)color;
+ (UIImage *)imageForParentalControlRating:(NSInteger)rating;

dispatch_queue_t dispatch_get_queue_for_loading_images(void);

@end
