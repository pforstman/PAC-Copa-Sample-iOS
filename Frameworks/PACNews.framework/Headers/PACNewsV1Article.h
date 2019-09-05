/** @module PACNews.framework *///
//  PACNewsV1Article.h
//  News
//
//  Created by Rawad Hilal on 2/25/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACNews/PACNewsV1ArticleImage.h>

/**
 * This class is a model structure for an article.
 */
@interface PACNewsV1Article : NSObject

/**
 * The article id.
 */
@property (nonatomic, copy) NSString * _Nonnull id;

/**
 * The article headline.
 */
@property (nonatomic, copy) NSString * _Nullable headline;

/**
 * The article synopsis.
 */
@property (nonatomic, copy) NSString * _Nullable synopsis;

/**
 * The article body.
 */
@property (nonatomic, copy) NSString * _Nullable body;

/**
 * The article byline.
 */
@property (nonatomic, copy) NSString * _Nullable byline;

/**
 * The posting timestamp for the article.
 *
 * Timestamps are in RFC2822 format.
 */
@property (nonatomic, copy) NSString * _Nonnull timestamp;

/**
 * Get the images associated to the article.
 *
 * An array of NewsV1ArticleImage objects. These include all images associated to the article.
 * Please refer to NewsV1ArticleImage.
 */
@property (nonatomic, strong) NSArray<PACNewsV1ArticleImage *> * _Nullable images;

@end
