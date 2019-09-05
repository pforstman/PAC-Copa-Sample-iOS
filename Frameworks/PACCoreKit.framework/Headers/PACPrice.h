/** @module PACCoreKit.framework *///
//  PACPrice.h
//  PACCoreKit
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * The class provides generic APIs for price. Price consists of currency and amount.
 */
@interface PACPrice : NSObject

/**
 * Indicates the type of currency for a price. The currency value is based on the ISO-4217 three-letter alphabetic code. For example, American currency is specified as USD, Australian currency is AUD and the Swiss franc is CHF. If the currency code is not specified or available, it defaults to the currency code provided by the airline data.
 */
@property (nonatomic,copy,readonly) NSString *currency;

/**
 * Indicates the cost of an item. The returned value is based on the currency code.
 */
@property (nonatomic,copy,readonly) NSDecimalNumber *amount;

/**
 * Initializes a price object based on currency and amount.
 */
-(instancetype )initWithCurrency:(NSString* )currencySymbol
                          amount:(NSDecimalNumber* )currencyAmount;

@end
