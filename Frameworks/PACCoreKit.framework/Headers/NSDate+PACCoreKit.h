/** @module PACCoreKit.framework *///
//  NSDate+PACCoreKit.h
//  InFlight iOS SDK
//
//  Created by Gary L. Wade on 05/23/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (PACCoreKit)

+(NSDate* )pac_parseISO8601DateWithBaseDate:(NSDate* )baseDate
    primaryDateString:(NSString* )primaryDateString
    alternateDateString:(NSString* )alternateDateString;

@end
