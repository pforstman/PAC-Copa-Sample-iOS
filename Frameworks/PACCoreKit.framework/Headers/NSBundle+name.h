/** @module PACCoreKit.framework *///
//  NSBundle+name.h
//  InFlight iOS SDK
//
//  Created by Rawad Hilal on 12/17/2013.
//  Copyright © 2013 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * Extends the NSBundle class to support returning child bundles.
 */
@interface NSBundle (name)

/*!
 * @abstract Gets a bundle for a private framework by name.
 * @discussion This can be used to return a bundle associated with a private framework by name.
 * @param name The name of the private framework you wish to retrieve.  If the framework has the expected extension ".framework", there's no need to include it, but there's no issue if it's not included.
 * @return The bundle object for the private framework.
 */
-(NSBundle* )pac_bundleOfPrivateFrameworkWithName:(NSString* )name;

/*!
 * @abstract Gets a bundle for a resource (folder in a bundle's resource folder) by name.
 * @discussion This can be used to return a bundle associated with a resource by name.
 * @param name The name of the resource you wish to retrieve.
 * @return The bundle object for the resource.
 */
-(NSBundle* )pac_bundleOfResourceWithName:(NSString* )name;

@end
