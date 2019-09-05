/** @module PACCoreKit.framework *///
//  NSJSONSerialization+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 12/08/2015.
//  Copyright © 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString* const   PACCoreKitJSONSerializationErrorDomain;
FOUNDATION_EXPORT const NSInteger   PACCoreKitJSONSerializationErrorNoSourceJSONData;
FOUNDATION_EXPORT const NSInteger   PACCoreKitJSONSerializationErrorNoDestinationJSONObject;
FOUNDATION_EXPORT const NSInteger   PACCoreKitJSONSerializationErrorDestinationJSONObjectNotRightType;

@interface NSJSONSerialization (PACCoreKit)

 /**
 * A convenience method that creates a Foundation object from JSON data in a resource file in a bundle.
 * @param name The name of the resource file. If you specify nil, the method returns the first resource file it finds with the specified extension.
 * @param extension If extension is an empty string or nil, the extension is assumed not to exist and the file URL is the first file encountered that exactly matches name.
 * @param aBundle The bundle where the resource should be found.  A value of nil will consult the mainBundle.
 * @param readingOptions The reading options that are passed in to +[NSJSONSerialization JSONObjectWithData:options:error].
 * @param error If the returned value is nil, and the address of an NSError was passed in, the reason for the failure will be returned.
 */
+(nullable id )pac_JSONObjectFromResource:(NSString* )name
    withExtension:(nullable NSString* )extension
    inBundle:(nullable NSBundle* )aBundle
    options:(NSJSONReadingOptions )readingOptions
    error:(NSError** )error;

/**
 * Create a Foundation object from JSON data along with the addition of lots of boilerplate code that most parsing would typically do, such as pre-parsing the source object, post-parsing the result object, ensuring the type of the result matches the desired class, and returning the original top-level parsed object for further processing.
 * @param anObject The object that has some JSON data within it either in NSString or NSData format.
 * @param aKeyPathToTheJSONData The key path used to find the NSString or NSData object within anObject that represents the JSON data to parse.  If aKeyPathToTheJSONData is nil or empty, anObject must be of type NSString or NSData.  If aKeyPathToTheJSONData is not empty, anObject may be of any class provided that [anObject valueForKeyPath:aKeyPathToTheJSONData] returns an object of type NSString or NSData.  For example, if this method were called in a notification handler, and the JSON data is in an NSString as the value associated with the key @"data" in its userInfo property, the parameter anObject could be the NSNotification object, and aKeyPathToTheJSONData would be @"userInfo.data".
 * @param readingOptions The reading options that are passed in to +[NSJSONSerialization JSONObjectWithData:options:error].
 * @param aKeyPathWithinTheJSONData The key path used to return the relevant data from the parsed JSON data.  If nil/empty, the parsed root object is the one that will be returned.  Otherwise, for example, if the JSON data was "{ 'place' : { 'piece' : true, 'date' : { 'available' : false }, 'parse' : 'maybe' } }" and aKeyPathWithinTheJSONData were @"place.date.available", an NSNumber representing the boolean value false would be returned.
 * @param aClassForTheJSONObject The class the returned object should be.  If not of the right type, nil is returned.
 * @param theParsedRootJSONObject If the caller passed in a value for aKeyPathWithinTheJSONData but wants to also get the root object, an address to an object should be passed in.  For example, in the example for aKeyPathWithinTheJSONData, if @"place.date.available" were true, then the root object could be used to get the value for @"place.parse" or ignored otherwise.
 * @param anError If the returned value is nil, and the address of an NSError was passed in, the reason for the failure will be returned.  Some underlying errors may be returned, so verify the domain is PACCoreKitJSONSerializationErrorDomain before checking values in PACCoreKitJSONSerializationError.
 */
+(id )pac_JSONObjectFromObject:(id )anObject
    atKeyPath:(nullable NSString* )aKeyPathToTheJSONData
    options:(NSJSONReadingOptions )readingOptions
    returningObjectAtKeyPath:(nullable NSString* )aKeyPathWithinTheJSONData
    objectTypeExpected:(Class )aClassForTheJSONObject
    rootJSONObject:(_Nullable id* _Nullable )theParsedRootJSONObject
    error:(NSError** )anError;

@end

NS_ASSUME_NONNULL_END
