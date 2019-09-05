/** @module PACEXTV.framework *///
//  PACEXTVProgramGuideV1ChannelProgramResult.h
//  eXTV
//
//  Created by Rawad Hilal on 6/17/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACEXTV/PACEXTVProgramGuideV1Channel.h>
#import <PACEXTV/PACEXTVProgramGuideV1Program.h>

/** Model class representing a channel in the program guide. */
@interface PACEXTVProgramGuideV1ChannelPrograms : NSObject
/** The channel information or summary of program types. */
@property (nonatomic, retain, nonnull) PACEXTVProgramGuideV1Channel *channel;
/** The programs on a channel that are available on a specific flight. */
@property (nonatomic, retain, nonnull) NSArray <PACEXTVProgramGuideV1Program *> *programs;
@end

