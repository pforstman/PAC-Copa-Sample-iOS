/** @module PACSeatPairing.framework *///
//  PACSeatRemoteMediaQueueV1.h
//  SeatPairing
//
//  Created by Rawad Hilal on 3/29/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACSeatPairing/PACSeatRemoteMediaQueueItem.h>

@class PACMediaBookmark;

/**
 * This class manages a shared media queue between the personal electronic device (PED)and the seatback monitor.
 */
@interface PACSeatRemoteMediaQueueV1 : NSObject

/**
 * @constantgroup PACSeatRemoteMediaQueueErrorDomains
 * The list of error domains for PACSeatRemoteMediaQueueV1.
 * @owner PACSeatRemoteMediaQueueV1
 */

/**
 * This key defines the general error domain for PACSeatRemoteMediaQueueV1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueErrorDomain;

/**
 * The error codes returned the remote control requests.
 */
typedef enum{
    /** The request has failed due to an unknown error. */
    PACSeatRemoteMediaQueueErrorUnknown                          = 1500,
    /** The request has failed due to invalid or missing parameters in the request. 
 */
    PACSeatRemoteMediaQueueErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatRemoteMediaQueueErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatRemoteMediaQueueErrorConnectionError                  = 1503,
    /** The request has failed due to the server returning an unexpected response. */
    PACSeatRemoteMediaQueueErrorBadResponse                      = 1504,
    /** The request has failed due to the service being unavailable. */
    PACSeatRemoteMediaQueueErrorServiceNotFound                  = 1505,
    /** The request has failed due to a passenger announcement on the seatback monitor is in progress */
    PACSeatRemoteMediaQueueErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to the device not being paired to the seatback monitor. */
    PACSeatRemoteMediaQueueErrorNotPaired                        = 1600,
    /** The request has failed due to an invalid or missing parameter in the request. */
    PACSeatRemoteMediaQueueErrorInvalidParameters                = 1601
}PACSeatRemoteMediaQueueErrorCode;

/**
 * The queue playback state.
 */
typedef enum{
    /** Queue playback state is unknown. */
    PACSeatRemoteMediaQueuePlaybackStateUnknown,
    /** Queue playback state is stopped. */
    PACSeatRemoteMediaQueuePlaybackStateStopped,
    /** Queue playback state is playing. */
    PACSeatRemoteMediaQueuePlaybackStatePlaying,
    /** Queue playback state is paused. */
    PACSeatRemoteMediaQueuePlaybackStatePaused
}PACSeatRemoteMediaQueuePlaybackState;

/**
 * The repeat mode.
 */
typedef enum{
    /** Repeat mode is unknown. */
    PACSeatRemoteMediaQueueRepeatModeUnknown,
    /** Do not repeat playing items in the queue. */
    PACSeatRemoteMediaQueueRepeatNone,
    /** Repeat playing selected item in the queue. */
    PACSeatRemoteMediaQueueRepeatOne,
    /** Repeat playing all items in the queue. */
    PACSeatRemoteMediaQueueRepeatAll
}PACSeatRemoteMediaQueueRepeatMode;

/**
 * The default specified subtitle language code.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable defaultSubtitleCode;

/**
 * The default specified soundtrack language code.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable defaultSoundtrackCode;

/**
 * The repeat mode of the queue.
 */
@property (nonatomic, assign, readonly) PACSeatRemoteMediaQueueRepeatMode repeatMode;

/**
 * The shuffle mode of the queue.
 */
@property (nonatomic, assign, readonly) BOOL shuffleMode;
/**
 * Returns whether a next item in the queue exists.
 */
@property (nonatomic, assign, readonly) BOOL hasNext;

/**
 * Returns whether a previous item in the queue exists.
 */
@property (nonatomic, assign, readonly) BOOL hasPrevious;

/**
 * The current index.
 */
@property (nonatomic, assign, readonly) NSInteger currentIndex;

/**
 * The time in seconds when the queue was last updated.
 *
 * Received as a delta from the seatback monitor, but processed according to device unix timestamp.
 */
@property (nonatomic, assign, readonly) NSTimeInterval lastUpdated;

/**
 * The number of items in the queue. This parameter is configurable.
 */
@property (nonatomic, assign, readonly) NSInteger count;

/**
 * Returns whether the queue is active.
 */
@property (nonatomic, assign, readonly, getter=isActive) BOOL active;

/**
 * Returns the playback state of the queue.
 */
@property (nonatomic, assign, readonly) PACSeatRemoteMediaQueuePlaybackState queuePlaybackState;

/**
 * The remote controller that can control playback of the media player handling the queue.
 */
//@property (nonatomic, retain, readonly) PACSeatMediaRemoteController *seatMediaRemoteController;


/**
 * Returns the array of media queue items.
 * @return An NSArray object containing a list of PACSeatRemoteMediaQueueItem objects.
 */
- (NSArray<PACSeatRemoteMediaQueueItem *> * _Nonnull)items;

/**
 * Returns the current queue item.
 *
 * @return Current queue item.
 */
- (PACSeatRemoteMediaQueueItem * _Nullable)currentItem;

/**
 * Returns the current bookmark for the playing item.
 *
 * @return Current bookmark item.
 */
- (PACMediaBookmark * _Nullable)currentBookmark;

/**
 * Sets queue repeat mode.
 *
 * @param repeatMode The repeat mode.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)setRepeatMode:(PACSeatRemoteMediaQueueRepeatMode)repeatMode
           completion:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Sets queue shuffle mode.
 *
 * @param shuffleMode The shuffle mode.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)setShuffleMode:(BOOL)shuffleMode
           completion:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Sets the default soundtrack language code for the queue.
 *
 * @param code The soundtrack language code. If nil, use default soundtrack.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)setDefaultSoundtrackCode:(NSString * _Nullable)code
                      completion:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Sets the default subtitle language code for the queue.
 *
 * @param code The subtitle language code.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)setDefaultSubtitleCode:(NSString * _Nullable)code
                    completion:(void (^ _Nullable)(NSError * _Nullable error))completion;



/**
 * @constantgroup PACSeatRemoteMediaQueueRequestOptions
 * Available options for [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:options:] API.
 */

/**
 * The global identifier that identifies any variant of the same media.
 *
 * The value should be a NSString object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionGlobalUri;

/**
 * The parent media identifier.
 *
 * The value should be a NSString object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionParentMediaUri;

/**
 * The iso language code 639-2 to be used for the soundtrack when playing the media.
 *
 * The value should be a NSString object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionSoundtrackCode;

/**
 * The iso language code 639-2 to be used for the subtitle when playing the media.
 *
 * The value should be a NSString object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionSubtitleCode;

/**
 * User defined parameters to be passed to the queue.
 *
 * The value should be a NSDictionary object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionExtras;

/**
 * The media bookmark object that tells where the user left of.
 *
 * The value should be a PACMediaBookmark object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionBookmark;

/**
 * The category id for the media item.
 *
 * The value should be a NSString object.
 */
extern NSString *const _Nonnull PACSeatRemoteMediaQueueRequestOptionCategoryId;

/**
 * This function prepares a request item based on the media uri, global uri, soundtrack code and subtitle code.
 * @param mediaUri The media identifier that identifies the media available on a specific flight.
 * @param options The request options to be added to the request. Please refer to PACSeatRemoteMediaQueueRequestOptions for available options.
 * @return Returns the request item.
 */
+ (NSDictionary * _Nonnull)mediaQueueRequestItemWithMediaUri:(NSString * _Nonnull)mediaUri
                                                     options:(NSDictionary * _Nullable)options;


/**
 * This function prepares a request item based on the media uri, global uri, soundtrack code and subtitle code.
 * @param mediaUri The media identifier that identifies the media available on a specific flight.
 * @param globalUri The global identifier that identifies any variant of the same media. This is optional.
 * @param parentMediaUri The parent media identifier. This is optional.
 * @param soundtrackCode The iso language code 639-2 to be used for the soundtrack when playing the media. This is optional.
 * @param subtitleCode The iso language code 639-2 to be used for the subtitle when playing the media. This is optional.
 * @param extras User defined parameters to be passed to the queue. This is optional.
 * @return Returns the request item.
 */
+ (NSDictionary * _Nonnull)mediaQueueRequestItemWithMediaUri:(NSString * _Nonnull)mediaUri
                                                   globalUri:(NSString * _Nullable)globalUri
                                              parentMediaUri:(NSString * _Nullable)parentMediaUri
                                                  soundtrack:(NSString * _Nullable)soundtrackCode
                                                    subtitle:(NSString * _Nullable)subtitleCode
                                                      extras:(NSDictionary * _Nullable)extras;
/**
 * This function prepares a request item based on the media uri, global uri, soundtrack code and subtitle code.
 * @param mediaUri The media identifier that identifies the media available on a specific flight.
 * @param globalUri The global identifier that identifies any variant of the same media. This is optional.
 * @param parentMediaUri The parent media identifier. This is optional.
 * @param soundtrackCode The iso language code 639-2 to be used for the soundtrack when playing the media. This is optional.
 * @param subtitleCode The iso language code 639-2 to be used for the subtitle when playing the media. This is optional.
 * @param bookmark The media bookmark object that tells where the user left of.
 * @param extras User defined parameters to be passed to the queue. This is optional.
 * @return Returns the request item.
 */
+ (NSDictionary * _Nonnull)mediaQueueRequestItemWithMediaUri:(NSString * _Nonnull)mediaUri
                                                   globalUri:(NSString * _Nullable)globalUri
                                              parentMediaUri:(NSString * _Nullable)parentMediaUri
                                                  soundtrack:(NSString * _Nullable)soundtrackCode
                                                    subtitle:(NSString * _Nullable)subtitleCode
                                                    bookmark:(PACMediaBookmark * _Nullable)bookmark
                                                      extras:(NSDictionary * _Nullable)extras;

/**
 * Clears existing items and loads new items to the queue.
 *
 * @param items The list of media items to be launched and added to the queue on the seatback  monitor. Please refer
 * to [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:globalUri:soundtrack:subtitle:] function to create the items.
 * @param autoplay Set whether media plays automatically after adding to the queue.
 * @param startIndex The index of the item in the array to be selected and potentially played.
 * @param repeatMode The repeat mode of the queue. This is a NSNumber object with value corresponding to PACSeatRemoteMediaQueueRepeatMode. If nil,
 * repeateMode would not be modified.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)loadQueueWithItems:(NSArray<NSDictionary *> * _Nonnull)items
                  autoplay:(BOOL)autoplay
                startIndex:(NSUInteger)startIndex
                repeatMode:(NSNumber * _Nullable)repeatMode
                completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsAdded, NSError * _Nullable error))completion;


/**
 * Adds media items to the end of the existing queue.
 *
 * This method will add the items to the end of the queue and will automatically start playing them.
 * @param items The list of media items to be launched and added to the queue on the seatback monitor. Please refer 
 * to [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:globalUri:soundtrack:subtitle:] function to create the items.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)launchMediaWithItems:(NSArray<NSDictionary *> * _Nonnull)items
                  completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsAdded, NSError * _Nullable error))completion;


/**
 * Adds item to the end of the queue and automatically launches playback in the seatback monitor.
 *
 * @param item The item to be added to the queue. Please refer
 * to [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:globalUri:soundtrack:subtitle:] function to create the item.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)addItem:(NSDictionary * _Nonnull)item
     completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsAdded, NSError * _Nullable error))completion;

/**
 * Adds items to end of the queue and immediately launches playback in the seatback monitor.
 *
 * @param items The array of items to be added to the queue. Please refer
 * to [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:globalUri:soundtrack:subtitle:] function to create the item.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)addItems:(NSArray<NSDictionary *> * _Nonnull)items
      completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsAdded, NSError * _Nullable error))completion;

/**
 * Adds item to queue at a specified index.
 *
 * @param item The item to be added to the queue. Please refer
 * to [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:globalUri:soundtrack:subtitle:] function to create the item.
 * @param index The index in the queue to add the item to.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)addItem:(NSDictionary * _Nonnull)item
        atIndex: (NSInteger)index
     completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsAdded, NSError * _Nullable error))completion;

/**
 * Add items to queue at a specified index.
 *
 * @param items The array of items to be added to the queue. Please refer
 * to [PACSeatRemoteMediaQueueV1 mediaQueueRequestItemWithMediaUri:globalUri:soundtrack:subtitle:] function to create the item.
 * @param index The index in the queue to add the items to.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)addItems:(NSArray<NSDictionary *> * _Nonnull)items
         atIndex: (NSInteger)index
      completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsAdded, NSError * _Nullable error))completion;

/**
 * Remove item from the queue.
 *
 * @param item The queue item to remove.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)removeItem:(PACSeatRemoteMediaQueueItem * _Nonnull)item
        completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsRemoved, NSError * _Nullable error))completion;

/**
 * Remove item from the queue at a specified index.
 *
 * @param index The index of the item in the queue to remove.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)removeItemAtIndex:(NSInteger)index
               completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsRemoved, NSError * _Nullable error))completion;

/**
 * Remove items from the queue.
 *
 * @param items The queue items to remove.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)removeItems:(NSArray <PACSeatRemoteMediaQueueItem *> * _Nonnull)items
        completion:(void (^ _Nullable)(NSArray<NSDictionary *> * _Nullable itemsRemoved, NSError * _Nullable error))completion;

/**
 * Clears all queue items.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)emptyQueueWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Starts or continues playback of the queue.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)playWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Starts or continues playback of the queue.
 *
 * If content type is nil, the function acts as resume. If not nil, the queue will play the content type from the beginning.
 * @param contentType The content type.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)playQueueByContentType:(NSString * _Nullable)contentType
         withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Pauses playback of the queue.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)pauseWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Stops playback of the queue.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)stopWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Jumps to item at a specified index.
 * @param index The index of the item in the queue.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)jumpToIndex:(NSUInteger) index withCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Jumps to the next item in the queue.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)jumpToNextItemWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Jumps to the previous item in the queue.
 * @param completion The completion block that is called when operation finishes. If error is set, then an error has occurred.
 */
- (void)jumpToPreviousItemWithCompletionHandler:(void (^ _Nullable)(NSError * _Nullable error))completion;

/**
 Dispatched when the items in the queue has changed.
 
 The userInfo dictionary will include the changes to the queue item.
 - *items* The queue items that has changed. The type is NSArray of NSDictionary with the following format
 
 ```
 [
    {
        "item" : <PACSeatRemoteMediaQueueItem *>,
        "index" : 1,
        "operation" : "added/removed/changed"
    }
 ]
 
 ```
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueItemsDidChangeNotification;

/**
 Dispatched when the queue index has changed.
 
 The userInfo dictionary will include the changes to the queue item.
 
 - *index* The current queue index. The type is NSNumber.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueIndexDidChangeNotification;

/**
 Dispatched when the default subtitle language code on the queue has changed.
 
 The userInfo dictionary will include the changes to the queue.
 
 - *code* The subtitle code. The type is NSString or NSNull if none.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueDefaultSubtitleDidChangeNotification;

/**
 Dispatched when the default soundtrack language code on the queue has changed.
 
 The userInfo dictionary will include the changes to the queue.
 
 - *code* The soundtrack code. The type is NSString or NSNull if none.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueDefaultSoundtrackDidChangeNotification;

/**
 Dispatched when the repeat mode on the queue has changed.
 
 The userInfo dictionary will include the changes to the queue.
 
 - *mode* The repeat mode. The type is NSNumber representing PACSeatRemoteMediaQueueRepeatMode.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueRepeatModeDidChangeNotification;

/**
 Dispatched when the shuffle mode on the queue has changed.
 
 The userInfo dictionary will include the changes to the queue.
 
 - *mode* The shuffle mode. The type is NSNumber boolean.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueShuffleModeDidChangeNotification;

/**
 Dispatched when the active status on the queue has changed.
 
 The userInfo dictionary will include the changes to the queue.
 
 - *status* The active status of the queue. The type is NSNumber boolean.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueStatusDidChangeNotification;

/**
 Dispatched when the playback state on the queue has changed.
 
 The userInfo dictionary will include the changes to the queue.
 
 - *state* The playback state of the queue. The type is NSNumber representing PACSeatRemoteMediaQueuePlaybackState.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueuePlaybackStateDidChangeNotification;

/**
 Dispatched when a item ended playing on the queue.
 
 The userInfo dictionary will include the item that has been ended.
 
 - *item* The PACSeatRemoteMediaQueueItem object in the items that has ended.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueuePlaybackEndedNotification;

/**
 Dispatched when the hasNext property changes.
 
 The userInfo dictionary will include the value.
 
 - *value* An NSNumber containing the boolean value for whether there is a next item.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueHasNextDidChangeNotification;

/**
 Dispatched when the hasPrevious property changes.
 
 The userInfo dictionary will include the value.
 
 - *value* An NSNumber containing the boolean value for whether there is a previous item.
 
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueHasPreviousDidChangeNotification;

/**
 Dispatched when the media remote controller on the seatback monitor has changed to handle different content type, such as movie or album.
 */
//FOUNDATION_EXPORT NSString * _Nonnull const PACSeatRemoteMediaQueueRemoteControllerDidChangeNotification;

@end

