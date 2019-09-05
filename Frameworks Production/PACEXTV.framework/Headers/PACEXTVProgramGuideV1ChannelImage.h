/** @module PACEXTV.framework *///
//  PACEXTVProgramGuideV1ChannelImage.h
//  eXTV
//
//  Created by Rawad Hilal on 6/17/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Model class representing an image or icon for the channel in the program guide. */
@interface PACEXTVProgramGuideV1ChannelImage : NSObject
/** The image width. */
@property (nonatomic, copy, nonnull)    NSNumber *                              width;
/** The image height. */
@property (nonatomic, copy, nonnull)    NSNumber *                              height;
/** The image url. */
@property (nonatomic, copy, nonnull)    NSString *                              url;
/** The image type, such as .png or jpg. Please refer to PACEXTVProgramGuideV1ChannelImageTypes for image types. */
@property (nonatomic, copy, nonnull)    NSString *                              type;

/** Raw data of the program model. This can be used to read unspecified fields */
@property (nonatomic, retain, nonnull)  NSDictionary *                          rawData;

/**
 * @constantgroup PACEXTVProgramGuideV1ChannelImageTypes
 * The image types.
 */

/**
 * Image is a poster.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ChannelImageTypePoster;

/**
 * Image is a synopsis or summary.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ChannelImageTypeSynopsis;

/**
 * Image type is a default type.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ChannelImageTypeDefault;


@end
