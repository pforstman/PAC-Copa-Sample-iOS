/** @module PACCoreKit.framework *///
//  NSDictionary+kindOfClass.h
//  InFlight iOS SDK
//
//  Created by Gary L. Wade on 12/21/2015.
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (kindOfClass)

-(id )pac_objectForKey:(id )aKey
    kindOfClass:(Class )aClass;

@end
