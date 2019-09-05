/** @module PACUser.framework *///
//  PACUserProfileV1.h
//  User
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import <PACUser/PACUserSyncService.h>

@class PACUserProfileConflict;

/**
 * This class is responsible for holding and persisting user profile information.
 */
@interface PACUserProfileV1 : PACUserSyncService

/**
 * The gender types.
 */
typedef enum{
    /** The gender is not specified. */
    PACUserProfileGenderNotSpecified = 0,
    /** The user is a male. */
    PACUserProfileGenderMale,
    /** The gender is a female. */
    PACUserProfileGenderFemale,
}PACUserProfileGender;

/**
 * @name User Info
 */

/**
 * The user's first name.
 */
@property (nonatomic, copy) NSString * _Nullable firstName;

/**
 * The user's middle name.
 */
@property (nonatomic, copy) NSString * _Nullable middleName;

/**
 * The user's last name.
 */
@property (nonatomic, copy) NSString * _Nullable lastName;

/**
 * The user's prefix.
 */
@property (nonatomic, copy) NSString * _Nullable prefix;

/**
 * The user's suffix.
 */
@property (nonatomic, copy) NSString * _Nullable suffix;

/**
 * The user's gender.
 */
@property (nonatomic, assign) PACUserProfileGender gender;

/**
 * Set the user's first name.
 * @param firstName The first name.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setFirstName:(NSString * _Nullable)firstName error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set the user's middle name.
 * @param middleName The middle name.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setMiddleName:(NSString * _Nullable)middleName error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set the user's last name.
 * @param lastName The last name.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setLastName:(NSString * _Nullable)lastName error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set the user's prefix.
 * @param prefix The prefix.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPrefix:(NSString * _Nullable)prefix error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set the user's suffix.
 * @param suffix The suffix.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setSuffix:(NSString * _Nullable)suffix error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set the user's gender.
 * @param gender The gender.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 * @see PACUserProfileGender
 */
- (BOOL)setGender:(PACUserProfileGender)gender error:(NSError* _Nonnull *_Nullable)error;

/**
 * @name RAW
 */

/**
 * Returns a dictionary holding the user profile.
 *
 * The return value can be used with PACSeatPreferencesV1 to update the user profile on the seat.
 * @return A dictionary holding the user profile.
 */
- (NSDictionary * _Nullable)serializedData;

/**
 * @name Conflicts
 */

/**
 * Retrieve all registered conflicts.
 *
 * Conflicts need to be resolved prior to synchronization.
 * @param error The pointer to the error object that will be set if an error has occurred. Check PACUserSyncServiceStatusCode for possible status code.
 * @return The list of conflict items. Nil on error.
 * @see PACUserConflict
 * @see PACUserProfileConflict
 */
- (NSArray <PACUserProfileConflict*> * _Nullable)retrieveConflicts:(NSError * _Nullable * _Nullable)error;

@end
