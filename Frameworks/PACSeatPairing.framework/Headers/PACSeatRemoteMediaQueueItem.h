/** @module PACSeatPairing.framework *///
//  PACSeatRemoteMediaQueueItem.h
//  SeatPairing
//
//  Created by Rawad Hilal on 3/29/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An item of [PACSeatRemoteMediaQueueItemV1 items].
 */
@interface PACSeatRemoteMediaQueueItem : NSObject

/**
 * The media uri that identifies the parent.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable parentMediaUri;

/**
 * The media uri.
 */
@property (nonatomic,copy,readonly) NSString * _Nonnull mediaUri;

/**
 * The media category id.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable categoryId;

/**
 * The global uri.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable globalUri;

/**
 * The media content type.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable contentType;


/**
 * The title of the media. 
 *
 * The language depends on the language preference specified or the seatback monitor 
 * interactive defined language if preference not provided.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable title;

/**
 * The media synopsis image url.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable synopsisUrl;


/**
 * The elapsed time.
 */
@property (nonatomic,copy,readonly) NSNumber * _Nullable elapsedTime;

/**
 * The elapsed time. The format is hh:mm:ss.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable duration;

/**
 * The subtitle language code that will be used when playing the media.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable subtitleCode;

/**
 * The soundtrack language code that will be used when playing the media.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable soundtrackCode;


/**
 * The title of the parent media.
 *
 * The language depends on the language preference specified or the seatback 
 * interactive defined language if preference not provided.
 */
@property (nonatomic,copy,readonly) NSString * _Nullable parentTitle;

/**
 * A dictionary identifiying custom fields.
 */
@property (nonatomic,copy,readonly) NSDictionary * _Nullable extras;

@end
