/** @module PACUser.framework *///
//  PACUserProfileConflict.h
//  User
//
//  Created by Rawad Hilal on 7/5/18.
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACUser/PACUser.h>

/**
 * The class that represents the value of each of the preferences for a conflict.
 */
@interface PACUserProfileConflictItem : NSObject
/**
 * The user's first name.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable firstName;

/**
 * The user's middle name.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable middleName;

/**
 * The user's last name.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable lastName;

/**
 * The user's prefix.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable prefix;

/**
 * The user's suffix.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable suffix;

/**
 * The user's gender.
 */
@property (nonatomic, assign, readonly) PACUserProfileGender gender;

@end

/**
 * The class that represents a conflict within PACUserProfileV1.
 */
@interface PACUserProfileConflict : PACUserConflict

/**
 * The index path that is conflicting. If nil, then root item is conflicting.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable conflictingAttribute;

/**
 * The profile values if local changes are selected.
 */
@property (nonatomic, copy, readonly) PACUserProfileConflictItem* _Nonnull localProfile;

/**
 * The profile values if remote changes are selected.
 */
@property (nonatomic, copy, readonly) PACUserProfileConflictItem* _Nonnull remoteProfile;

@end

