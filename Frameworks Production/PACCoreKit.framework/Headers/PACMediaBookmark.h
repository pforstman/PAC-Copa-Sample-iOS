/** @module PACCoreKit.framework *///
//  PACMediaBookmark.h
//  PACCoreKit
//
//  Created by Rawad Hilal on 10/24/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class is a data model that holds the bookmark data of a specific media player playback.
 */
@interface PACMediaBookmark : NSObject

/**
 * The media URI of the media that the bookmark points to.
 */
@property (nonatomic, retain, readonly) NSString *mediaURI;

/**
 * The parent media URI of the media that the bookmark points to.
 */
@property (nonatomic, retain, readonly) NSString *parentMediaURI;

/**
 * The elapsed time. The value is in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval elapsedTime;

/**
 * The time that the bookmark was last created or updated. The value is in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval lastUpdated;

/**
 * The soundtrack code.
 */
@property (nonatomic, retain, readonly) NSString *soundtrackCode;

/**
 * The subtitle code.
 */
@property (nonatomic, retain, readonly) NSString *subtitleCode;

/**
 * Loads a bookmark from file.
 * @param path The file path to where a bookmark was saved.
 * @param errorPtr If there is an error reading the data, upon return contains an NSError object that describes the problem.
 * @return The instance of the bookmark class that is loaded from file.
 */
+ (instancetype)bookmarkWithContentsOfFile:(NSString *)path error:(NSError **)errorPtr;

/**
 * Writes the bookmark to file.
 * @param path The location to which to write the bookmark to.
 * @param useAuxiliaryFile If YES, the array is written to an auxiliary file, and then the auxiliary file is renamed to path. If NO, the array is written directly to path. The YES option guarantees that path, if it exists at all, won’t be corrupted even if the system should crash during writing.
 * @param error If there is an error writing out the data, upon return contains an NSError object that describes the problem.
 * @return YES if the operation succeeds, otherwise NO.
 */
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile error:(NSError **)error;

@end
