/** @module PACUser.framework *///
//  PACUserConflict.h
//  User
//
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 * Class that represents a conflict item.
 */
@interface PACUserConflict : NSObject

/**
 * The conflict resolution choices.
 *
 * @owner PACUserConflict
 */
typedef enum _PACUserConflictResolution
{
    /** No resolution choice has yet been made. */
    PACUserConflictResolutionNone,
    /** Choose local value. */
    PACUserConflictResolutionChooseLocal,
    /** Choose remote value. */
    PACUserConflictResolutionChooseRemote,
    /** Choose latest value. */
    PACUserConflictResolutionChooseLatest,
}
PACUserConflictResolution;

/**
 * The date when the local value has been last modified.
 */
@property (nonatomic, readonly) NSDate* localModifiedDate;

/**
 * The date when the remote value has been last modified.
 */
@property (nonatomic, readonly) NSDate* remoteModifiedDate;

/**
 * The resolution choice for the conflict item.
 *
 * @see PACUserConflictResolution
 */
@property (nonatomic, readwrite) PACUserConflictResolution resolution;

@end
