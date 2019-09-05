/** @module PACStreaming.framework *///
//  PACPayPerViewPurchasableMediaItem.h
//  Streaming
//
//  Created by Rawad Hilal on 2/4/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A model class that represents a price of a pay per view (PPV) media item based on the currency.
 */
@interface PACPayPerViewPurchasableMediaItemPrice : NSObject

/**
 * The price of the media item.
 */
@property (nonatomic,copy,readonly) NSDecimalNumber * _Nullable amount;

/**
 * The currency associated to the price.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable currency;

@end

/**
 * A model class that represents a purchasable PPV media item, such as a movie, television show or music.
 */
@interface PACPayPerViewPurchasableMediaItem : NSObject

/**
 * The media URI of the individual or bundled media.
 */
@property (nonatomic,copy,readonly) NSString * _Nonnull mediaUri;

/**
 * The price of the media item in all supported currencies. 
 * 
 */
@property (nonatomic,copy,readonly) NSArray <PACPayPerViewPurchasableMediaItemPrice *> * _Nullable price;

/**
 * Return whether a media item is a single item or packaged as a bundle.
 */
@property (nonatomic,assign,readonly,getter=isBundle) BOOL bundle;

@end
