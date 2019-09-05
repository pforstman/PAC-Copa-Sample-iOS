/** @module PACEXTV.framework *///
//  PACEXTVProgramGuideV1Program.h
//  eXTV
//
//  Created by Rawad Hilal on 6/17/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACEXTV/PACEXTVProgramGuideV1Category.h>

/** Model class representing a program, such as tv episode or newscast, in the program guide. */
@interface PACEXTVProgramGuideV1Program : NSObject

/** The identifier of the channel airing he program. */
@property (nonatomic, copy, nonnull)    NSString *                              channelMediaUri;
/** Call sign of the channel playing the program. */
@property (nonatomic, copy, nonnull)    NSString *                              channelCallSign;

/**
 * Category, such as news or sports, for the program.
 * @see PACEXTVProgramGuideV1Category
 */
@property (nonatomic, retain, nonnull)    PACEXTVProgramGuideV1Category *       category;

/**
 * Subcategory, such as newscast or soccer, for the program.
 * @see PACEXTVProgramGuideV1Category
 */
@property (nonatomic, retain, nonnull)    PACEXTVProgramGuideV1Category *       subCategory;

/** The title of the program. */
@property (nonatomic, copy, nonnull)    NSString *                              title;

/** The summary or synopsis of the program. */
@property (nonatomic, copy, nonnull)    NSString *                              summary;

/** The duration of the program in minutes. */
@property (nonatomic, copy, nonnull)    NSNumber *                              duration;

/** The time that the program is scheduled to air. */
@property (nonatomic, retain, nonnull)  NSDate *                                airingTime;

/** Raw data of the program model. This can be used to read unspecified fields */
@property (nonatomic, retain, nonnull)  NSDictionary *                          rawData;

@end
