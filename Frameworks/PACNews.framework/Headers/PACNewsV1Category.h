/** @module PACNews.framework *///
//  PACNewsV1Category.h
//  News
//
//  Created by Rawad Hilal on 2/25/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACNews/PACNewsV1ArticleSummary.h>

/**
 * This class is a model structure for a news category.
 */
@interface PACNewsV1Category : NSObject

/**
 * The category feed type.
 */
typedef enum {
    /** The feed type is unknown. */
    PACNewsV1CategoryFeedTypeUnknown,
    /** The feed type is custom. */
    PACNewsV1CategoryFeedTypeCustom,
    /** The feed type is RSS. */
    PACNewsV1CategoryFeedTypeRSS,
}PACNewsV1CategoryFeedType;

/**
 * The category id.
 */
@property (nonatomic, copy) NSString * _Nonnull id;

/**
 * The category name, such as Business, Sports, Culture or News.
 */
@property (nonatomic, copy) NSString * _Nonnull name;

/**
 * The category feed type.
 *
 * Please refer to NewsV1CategoryFeedType for more details.
 */
@property (nonatomic, assign) PACNewsV1CategoryFeedType feedType;

/**
 * The parent category.
 */
@property (nonatomic, weak) PACNewsV1Category * _Nullable parentCategory;

/**
 * The array of child categories.
 */
@property (nonatomic, strong) NSArray<PACNewsV1Category *> * _Nullable childCategories;

/**
 * An array of news articles associated to the category.
 *
 * Please refer to NewsV1ArticleSummary for more details regarding the objects inside the array.
 */
@property (nonatomic, strong) NSArray<PACNewsV1ArticleSummary *> * _Nullable articles;

@end
