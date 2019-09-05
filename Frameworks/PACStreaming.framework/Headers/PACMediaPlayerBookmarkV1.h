/** @module PACStreaming.framework *///
//  PACMediaPlayerBookmarkV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACMediaBookmark.h>

/**
 * This class is a data model that holds the bookmark data of a specific media player playback.
 *
 * @deprecated This class is first deprecated in SDK version 03.06.00.03. Please use the identical class PACMediaBookmark inside PACCoreKit framework.
 */
__attribute__ ((deprecated("first deprecated in SDK version 03.06.00.03. Use the identical class PACMediaBookmark inside PACCoreKit framework.")))
@interface PACMediaPlayerBookmarkV1 : PACMediaBookmark

@end
