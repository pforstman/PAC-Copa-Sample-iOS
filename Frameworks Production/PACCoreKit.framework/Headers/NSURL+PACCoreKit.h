/** @module PACCoreKit.framework *///
//  NSURL+PACCoreKit.h
//  InFlight iOS SDK
//
//  Created by Gary L. Wade on 06/21/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (PACCoreKit)

-(instancetype )pac_URLWithSecureHTTPSSchemeAndPort:(NSInteger )portOrZeroForStandard;

-(instancetype )pac_URLWithStandardHTTPSchemeAndPort:(NSInteger )portOrZeroForStandard;

@end
