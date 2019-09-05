/** @module PACNews.framework *///
//  PACNewsV1ArticleSummary.h
//  News
//
//  Created by Rawad Hilal on 2/25/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class is a model structure for an article summary.
 */
@interface PACNewsV1ArticleSummary : NSObject

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
 * The article image url.
 */
@property (nonatomic, copy) NSString * _Nullable imageUrl;

/**
 * The article timestamp for the posting date.
 *
 * Timestamps are in RFC 2822 format.
 */
@property (nonatomic, copy) NSString * _Nonnull timestamp;
//@property (nonatomic, copy) NSString * _Nullable articleUrl;

/**
 * The article source URL.
 *
 * This field is only provided if the category feed type is set to NewsV1CategoryFeedTypeRSS.
 * Please refer to [NewsV1Category feedType].
 */
@property (nonatomic, copy) NSString * _Nullable sourceUrl;

@end
