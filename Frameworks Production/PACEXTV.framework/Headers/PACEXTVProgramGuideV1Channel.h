/** @module PACEXTV.framework *///
//  PACEXTVProgramGuideV1Channel.h
//  EXTV
//
//  Created by Rawad Hilal on 6/17/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACEXTV/PACEXTVProgramGuideV1ChannelImage.h>

/** Model class representing a channel in the program guide. */
@interface PACEXTVProgramGuideV1Channel : NSObject

/**
 * The bitmask stating the channel status, such as available or currently active.
 */
typedef enum
{
    /** No channel status is available. */
    PACEXTVProgramGuideV1ChannelStatusNone      = 0,
    /**
     * The channel is currently active. However, if the bit is not set that may mean no channel signal exists at that time and may become active at any moment throughout the flight.
     */
    PACEXTVProgramGuideV1ChannelStatusActive    = 1 << 0,
}
PACEXTVProgramGuideV1ChannelStatus;

/** The channel media Uri. */
@property (nonatomic, copy, readonly, nonnull)  NSString *                               mediaUri;
/** The channel title, such as British Broadcasting Corporation. */
@property (nonatomic, copy, nullable)           NSString *                               title;
/** The channel summary or synopsis. */
@property (nonatomic, copy, nullable)           NSString *                               summary;
/** The channel call sign or call letters, such as BBC or ESPN. */
@property (nonatomic, copy, nonnull)            NSString *                               callSign;
/** The channel status as available or currently active. */
@property (nonatomic, assign)                   PACEXTVProgramGuideV1ChannelStatus       status;
/**
 * The channel image or icon.
 * @see PACEXTVProgramGuideV1ChannelImage
 */
@property (nonatomic, retain, nullable) NSArray<PACEXTVProgramGuideV1ChannelImage *> *  images;

/** Raw data of the program model. This can be used to read unspecified fields */
@property (nonatomic, retain, nonnull)  NSDictionary *                                  rawData;

@end
