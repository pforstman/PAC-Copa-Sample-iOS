/** @module PACCoreKit.framework *///
//  NSArray+kindOfClass.h
//  InFlight iOS SDK
//
//  Created by Gary L. Wade on 04/07/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (kindOfClass)

-(id )pac_objectAtIndex:(NSUInteger )index
    kindOfClass:(Class )aClass;

@end
