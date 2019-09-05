/** @module PACCoreKit.framework *///
//  UIImageView+PACCoreKit.h
//  PACCoreKit
//
//  Created by Rawad Hilal on 3/1/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (PACCoreKit)

/**
 * Set the image for the image view from a url source.
 * @param url The image url.
 * @param expiry The time in minutes to cache the response for.
 */
- (void)pac_setImageFromUrl:(NSURL *)url expiry:(NSInteger) expiry;

/**
 * Cancel downloading an image.
 */
- (void)pac_cancelSetImageFromUrl;

@end
