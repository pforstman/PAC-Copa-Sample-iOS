/** @module PACUser.framework *///
//  PACUserPreferencesConflict.h
//  User
//
//  Created by Rawad Hilal on 7/5/18.
//  Copyright © 2018 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACUser/PACUser.h>

/**
 * The class that represents the value of each of the profile attributes for a conflict.
 */
@interface PACUserPreferencesConflictItem : NSObject

/**
 * The user's preferred parental control rating.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable preferredParentalControlRating;

/**
 * The user's preferred language.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable preferredLanguage;

/**
 * The user's preferred interactive theme.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable preferredInteractiveTheme;

/**
 * The user's preferred subtitle language.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable preferredSubtitleLanguage;

/**
 * The user's preferred soundtrack language.
 */
@property (nonatomic, copy, readonly) NSString * _Nullable preferredSoundtrackLanguage;

/**
 * The user's preferred genres.
 */
@property (nonatomic, copy, readonly) NSDictionary * _Nullable preferredGenres;

@end

/**
 * The class that represents a conflict within PACUserPreferencesV1.
 */
@interface PACUserPreferencesConflict : PACUserConflict

/**
 * The preference that is conflicting. If nil, then all preferences are conflicting.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable conflictingPreference;

/**
 * The preferences values if local changes are selected.
 */
@property (nonatomic, copy, readonly) PACUserPreferencesConflictItem* _Nonnull localPreferences;

/**
 * The preferences values if remote changes are selected.
 */
@property (nonatomic, copy, readonly) PACUserPreferencesConflictItem* _Nonnull remotePreferences;

@end
