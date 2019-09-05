/** @module PACCoreKit.framework *///
//  NSTimeZone+PACCoreKit.h
//  InFlight iOS SDK
//
//  Created by Gary L. Wade on 05/23/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimeZone (PACCoreKit)

-(NSString* )pac_offsetInISO8601Format;

-(NSTimeZone* )pac_timeZoneAsOffsetOnly;

@end
