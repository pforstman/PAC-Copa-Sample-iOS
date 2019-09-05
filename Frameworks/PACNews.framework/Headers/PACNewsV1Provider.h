/** @module PACNews.framework *///
//  PACNewsV1Provider.h
//  News
//
//  Created by Rawad Hilal on 2/25/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class is a model structure for news providers.
 */
@interface PACNewsV1Provider : NSObject

/**
 * The news provider id.
 */
@property (nonatomic, copy) NSString * _Nonnull id;

/**
 * The news provider language code.
 *
 * The language code standard is ISO 639-1.
 */
@property (nonatomic, copy) NSString * _Nonnull languageCode;

/**
 * The news provider name.
 */
@property (nonatomic, copy) NSString * _Nonnull name;

@end
