/** @module PACNews.framework *///
//  PACNewsV1ArticleImage.h
//  News
//
//  Created by Rawad Hilal on 2/25/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class is a model structure for an article image.
 */
@interface PACNewsV1ArticleImage : NSObject

/**
 * The image caption.
 */
@property (nonatomic, copy) NSString * _Nullable caption;

/**
 * The image URL.
 */
@property (nonatomic, copy) NSString * _Nonnull imageUrl;

@end
