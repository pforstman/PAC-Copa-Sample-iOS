/** @module PACUser.framework *///
//  PACUserSyncService.h
//  User
//
//  Copyright © 2017 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import "PACUserConflict.h"

/**
 * This class is responsible for holding and persisting user information.
 */
@interface PACUserSyncService : InFlightService

/**
 * Dispatched when synchronization was successful.
 */
FOUNDATION_EXPORT NSString * _Nonnull PACUserSyncServiceSuccessNotification;

/**
 * Dispatched when synchronization was unsuccessful.
 *
 * The notification's userInfo will include a 'status' key to specify the reason of the failure. Check PACUserSyncServiceStatusCode for possible values.
 */
FOUNDATION_EXPORT NSString * _Nonnull PACUserSyncServiceErrorNotification;

/**
 * Dispatched when synchronization stopped due to conflicts.
 *
 * Conflicts need to be resolved before sync resumes. Please call resolveConflicts to resolve current conflicts.
 * After resolving all conflicts, call synchronize to resume synchronization.
 */
FOUNDATION_EXPORT NSString * _Nonnull PACUserSyncServiceConflictsNotification;

/**
 * The sync service possible return codes.
 *
 * @owner PACUserSyncService
 */
typedef enum _PACUserSyncServiceStatusCode
{
    /** The operation completed successfully. */
    PACUserSyncServiceStatusSuccess,
    /** The operation failed because of bad parameters. */
    PACUserSyncServiceStatusBadParameters,
    /** The operation failed because of an internal error. */
    PACUserSyncServiceStatusInternalError,
    /** The operation failed because of a database corruption error. */
    PACUserSyncServiceStatusDatabaseError,
    /** The operation failed because the key provided is not found. */
    PACUserSyncServiceStatusKeyNotFound,
    /** The operation failed because the conflict provided is not found. */
    PACUserSyncServiceStatusConflictNotFound,
    /** The operation failed because the conflicts are found. */
    PACUserSyncServiceStatusConflictsFound,
    /** The operation failed because the conflict resolution is needed. */
    PACUserSyncServiceStatusConflictResolutionNeeded,
    /** The operation failed because sync is already in progress. */
    PACUserSyncServiceStatusSyncInProgress,
    /** The operation failed because of a sync error. */
    PACUserSyncServiceStatusSyncError,
}
PACUserSyncServiceStatusCode;

/**
 * Writes any modifications to the server.
 * @return YES if the data was saved successfully to server, otherwise NO.
 */
- (BOOL)synchronize;

/**
 * Return the date in which the data has been last synchronized.
 * @return The date object.
 */
- (NSDate* _Nullable)lastSyncedTimestamp;

/**
 * Return the date in which the data has been last modified.
 * @return The date object.
 */
- (NSDate* _Nullable)lastModifiedTimestamp;

/**
 * Returns whether conflicts exists.
 *
 * Conflicts need to be resolved prior to synchronization.
 * @return YES if conflicts exist.
 */
- (BOOL)hasConflicts;

/**
 * Resolve a conflict.
 *
 * To select a conflict resolution call [PACUserConflict setResolution:] prior to passing to this function.
 * @return PACUserSyncServiceStatusSuccess on success. Check PACUserSyncServiceStatusCode.
 */
- (PACUserSyncServiceStatusCode)resolveConflicts:(PACUserConflict * _Nonnull)conflict;

@end

