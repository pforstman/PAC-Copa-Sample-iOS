/** @module PACUser.framework *///
//  PACUserPreferencesV1.h
//  User
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import <PACUser/PACUserSyncService.h>

@class PACUserPreferencesConflict;

/**
 * This class is responsible for holding and persisting user preferences.
 */
@interface PACUserPreferencesV1 : PACUserSyncService

/**
 * @name Preferences
 */

/**
 * The user's preferred parental control rating.
 */
@property (nonatomic, copy) NSString * _Nullable preferredParentalControlRating;

/**
 * The user's preferred interactive theme.
 */
@property (nonatomic, copy) NSString * _Nullable preferredInteractiveTheme;

/**
 * The user's preferred language.
 */
@property (nonatomic, copy) NSString * _Nullable preferredLanguage;

/**
 * The user's preferred subtitle language.
 */
@property (nonatomic, copy) NSString * _Nullable preferredSubtitleLanguage;

/**
 * The user's preferred soundtrack language.
 */
@property (nonatomic, copy) NSString * _Nullable preferredSoundtrackLanguage;

/**
 * The user's preferred genres.
 */
@property (nonatomic, copy, readonly) NSDictionary * _Nullable preferredGenres;

/**
 * Set preferred parental control ratings.
 * @param ratings The preferred parental control ratings.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPreferredParentalControlRating:(NSString * _Nullable)ratings error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set preferred interactive theme.
 * @param theme The preferred theme.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPreferredInteractiveTheme:(NSString * _Nullable)theme error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set preferred language.
 * @param language The preferred language.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPreferredLanguage:(NSString * _Nullable)language error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set preferred language for the subtitles during media playback.
 * @param language The preferred language.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPreferredSubtitleLanguage:(NSString * _Nullable)language error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set preferred language for the soundtrack during media playback.
 * @param language The preferred language.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPreferredSoundtrackLanguage:(NSString * _Nullable)language error:(NSError* _Nonnull *_Nullable)error;

/**
 * Set preferred genres for a specific content type.
 * @param genre An array of preferred genres. Ex. comedy.
 * @param contentType The content type for the preferred genres. Ex. 'media.video.movie'.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)setPreferredGenres:(NSArray* _Nullable)genre forContentType:(NSString* _Nonnull)contentType error:(NSError* _Nonnull *_Nullable)error;

/**
 * Remove preferred genres for a specific content type.
 * @param contentType The content type for the preferred genres. Ex. 'media.video.movie'.
 * @param error Pointer to an error object that will be populated on error.
 * @return YES on success. NO on error.
 */
- (BOOL)removePreferredGenresForContentType:(NSString* _Nonnull)contentType error:(NSError* _Nonnull *_Nullable)error;


/**
 * @name RAW
 */

/**
 * Returns a dictionary holding the user preferences.
 *
 * The return value can be used with PACSeatPreferencesV1 to update the user profile on the seat.
 * @return A dictionary holding the user preferences.
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
 * @see PACUserPreferencesConflict
 */
- (NSArray <PACUserPreferencesConflict*> * _Nullable)retrieveConflicts:(NSError * _Nullable * _Nullable)error;

@end
