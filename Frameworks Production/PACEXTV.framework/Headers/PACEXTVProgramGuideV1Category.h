/** @module PACEXTV.framework *///
//  PACEXTVProgramGuideV1Category.h
//  eXTV
//
//  Created by Rawad Hilal on 6/17/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Model class representing a category, such as news, sports or entertainment, in program guide. */
@interface PACEXTVProgramGuideV1Category : NSObject
/** Name of the category. */
@property (nonatomic, copy, nonnull) NSString *     name;
@end
