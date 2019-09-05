/** @module PACCoreKit.framework *///
//  NSNumber+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 02/24/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

#if CGFLOAT_IS_DOUBLE
#define CGFloatValue doubleValue
#else // CGFLOAT_IS_DOUBLE
#define CGFloatValue floatValue
#endif // CGFLOAT_IS_DOUBLE

FOUNDATION_EXPORT CGFloat
CGFloatCeiling
(
    CGFloat aValue
);

@interface NSNumber (PACCoreKit)
@end
