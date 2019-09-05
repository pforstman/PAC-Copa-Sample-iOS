/** @module PACCoreKit.framework *///
//  NSNumberFormatter+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 03/04/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSNumberFormatter (PACCoreKit)

+(NSString* )pac_localizedSpelledOutStringFromNumber:(NSNumber* )number
    formattingContext:(NSFormattingContext )formattingContext;

@end
