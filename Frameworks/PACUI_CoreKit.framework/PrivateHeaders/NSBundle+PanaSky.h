//
//  NSBundle+PanaSky.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/4/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSBundle (PanaSky)
+ (NSBundle *)panaSkyKitBundle;
+ (NSBundle *)panaSkyLocalizedLibraryBundle;
+ (NSString *)panaSkyLocalizedString:(NSString *)aString;
+ (NSString *)panaSkyLanguageKeyFromLangID:(NSString *)langID;
+ (NSString *)panaSkyLanguageKeyAbbreviatedFromLangID:(NSString *)langID;
+ (NSString *)panaSkyGenericLanguageKeyFromLangID:(NSString *)langID;
@end
