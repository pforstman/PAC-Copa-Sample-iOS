/** @module PACCoreKit.framework *///
//  NSString+SoftHyphenation.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 03/18/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (SoftHyphenation)

-(NSString* )pac_softHyphenatedStringWithLocale:(NSLocale* )locale;

@end
