/** @module PACCoreKit.framework *///
//  PACLocalizedItem.h
//  PACCoreKit
//
//  Created by Jeff Chen (MLS Technologies) on 12/11/18.
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 This class is a model structure for a localized item.
 */
@interface PACLocalizedItem : NSObject

/**
 initialize function with input array
 */
-(id)initWithLanguageDictionary:(NSDictionary*)LanguageDictionary;

/**
 Returns the value for a specific language code. Example: all movies in Japanese.
 */
- (NSString*_Nonnull)valueForLanguageCode:(NSString* _Nonnull)code;

/**
 Returns all language codes available on the flight.
 */
- (NSArray<NSString*>*_Nonnull)availableLanguages;

- (NSDictionary*)rawData;

@end

NS_ASSUME_NONNULL_END
