/** @module PACUser.framework *///
//  PACUserPlaylistItem.h
//  User
//
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * A class representing a playlist item.
 */
@interface PACUserPlaylistItem : NSObject

/** Item ID of the item */
@property (nonatomic,copy,readonly) NSString* _Nonnull itemId;

/** Media URI of the item */
@property (nonatomic,copy) NSString* _Nonnull mediaUri;

/** Parent media URI of the item */
@property (nonatomic,copy) NSString* _Nullable parentMediaUri;

/** Content type of the item */
@property (nonatomic,copy) NSString* _Nullable contentType;

/**
 * Initialize a playlist item.
 * @param mediaUri Media URI of the item
 * @param parentMediaUri Parent media URI
 * @param contentType Content type
 * @return Playlist item
 */
- (instancetype _Nonnull)initWithMediaUri:(NSString* _Nonnull)mediaUri
                           parentMediaUri:(NSString* _Nullable)parentMediaUri
                              contentType:(NSString* _Nullable)contentType;

@end
