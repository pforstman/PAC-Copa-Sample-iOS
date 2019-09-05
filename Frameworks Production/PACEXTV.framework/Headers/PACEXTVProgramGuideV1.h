/** @module PACEXTV.framework *///
//  PACEXTVProgramGuideV1.h
//  eXTV
//
//  Created by Rawad Hilal on 6/17/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import <PACEXTV/PACEXTVProgramGuideV1Category.h>
#import <PACEXTV/PACEXTVProgramGuideV1Channel.h>
#import <PACEXTV/PACEXTVProgramGuideV1ChannelPrograms.h>
#import <PACEXTV/PACEXTVProgramGuideV1Program.h>

/**
 * Service class provides an interface for the eXTV program guide. 
*
Using this interface, developers can list all available channels, programs under specific channels and categories, such as News, Sports and Entertainment. 
*
This interface also provides a Search, based on filters, such as startRangeDate, endRangeDate, startOffset, ProgramTitle, category and text.
 */
@interface PACEXTVProgramGuideV1 : InFlightService

/**
 * The completion block that will be called when a category funtion gets completed.
 * @param programs The array of PACEXTVProgramGuideV1Category objects.
 * @param error The error object that will be set if an error has occurred.
 */
typedef void (^PACEXTVProgramGuideV1CategoryCompletionBlock)(NSArray <PACEXTVProgramGuideV1Category *> * _Nullable categories, NSError * _Nullable error);

/**
 * The completion block that will be called when a program funtion gets completed.
 * @param programs The array of PACEXTVProgramGuideV1Channel objects matching the listing criteria.
 * @param error The error object that will be set if an error has occurred.
 */
typedef void (^PACEXTVProgramGuideV1ChannelsCompletionBlock)(NSArray <PACEXTVProgramGuideV1Channel *> * _Nullable channels, NSError * _Nullable error);

/**
 * The completion block that will be called when a program funtion gets completed.
 * @param channelProgramsResults A model class representing a mapping between channels and the respective programs matching the listing criteria.
 * @param error The error object that will be set if an error has occurred.
 */
typedef void (^PACEXTVProgramGuideV1ProgramsCompletionBlock)(NSArray <PACEXTVProgramGuideV1ChannelPrograms *> * _Nullable channelProgramsResults, NSError * _Nullable error);

/**
 * The completion block that will be called when a search funtion gets completed.
 * @param programs The array of PACEXTVProgramGuideV1Program objects matching the search criteria.
 * @param error The error object that will be set if an error has occurred.
 */
typedef void (^PACEXTVProgramGuideV1SearchCompletionBlock)(NSArray <PACEXTVProgramGuideV1Program *> * _Nullable programs, NSError * _Nullable error);

/**
 * Retrieve categories, such as news or sports, that are available on the flight.
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1CategoryCompletionBlock for more details.
 */
- (void)categoriesWithCompletionHandler:(PACEXTVProgramGuideV1CategoryCompletionBlock _Nonnull)completed;

/**
 * Retrieve station channels, such as BBC and ESPN, available on the flight.
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1ChannelsCompletionBlock for more details.
 */
- (void)channelsWithCompletionHandler:(PACEXTVProgramGuideV1ChannelsCompletionBlock _Nonnull)completed;

/**
 * Retrieve programs based on specified criteria, such as date and time.
 * @param channels An array of channels to retrieve programs for.
 * @param category A specific category to filter by.
 * @param rangeStartDate Date/Time to define the start of the lookup range. If not provided, current time will be assumed.
 * @param rangeEndDate Date/Time to define the end of the lookup range. If not provided, the end of the lookup range is the date or time the flight completes. 
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1ProgramsCompletionBlock for more details.
 */

- (void)programsForChannels:(NSArray <PACEXTVProgramGuideV1Channel *> * _Nullable)channels
               withCategory:(PACEXTVProgramGuideV1Category * _Nullable)category
             rangeStartDate:(NSDate * _Nullable)rangeStartDate
               rangeEndDate:(NSDate * _Nullable)rangeEndDate
          completionHandler:(PACEXTVProgramGuideV1ProgramsCompletionBlock _Nonnull)completed;

/**
 * Retrieve programs based on specified criteria, such as date and time.
 * @param channels An array of channels to retrieve programs for.
 * @param category A specific category to filter by.
 * @param rangeStartDate Date or time to define the start of the lookup range. If not provided, current time will be assumed.
 * @param minutesFromStart Minutes from the start time to define the end of the lookup range. If not provided, the end of the lookup range is the date or time the flight completes. 
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1ProgramsCompletionBlock for more details.
 */
- (void)programsForChannels:(NSArray <PACEXTVProgramGuideV1Channel *> * _Nullable)channels
               withCategory:(PACEXTVProgramGuideV1Category * _Nullable)category
             rangeStartDate:(NSDate * _Nullable)rangeStartDate
              rangeDuration:(NSNumber * _Nullable)minutesFromStart
          completionHandler:(PACEXTVProgramGuideV1ProgramsCompletionBlock _Nonnull)completed;


/**
 * Retrieve programs based on speficied criteria, such as date and time.
 * @param channels An array of channels and their programs being retrieved. 
 * @param category A specific category, such as news, to filter by.
 * @param minutesFromNow Number of minutes from current time to define the start of the lookup range. If not provided, current time will be assumed.
 * @param minutesFromStart Number of minutes from the start time to define the end of the lookup range. If not provided, the end of the lookup range is the date or time the flight completes. 
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1ProgramsCompletionBlock for more details.
 */
- (void)programsForChannels:(NSArray <PACEXTVProgramGuideV1Channel *> * _Nullable)channels
               withCategory:(PACEXTVProgramGuideV1Category * _Nullable)category
           rangeStartOffset:(NSNumber * _Nullable)minutesFromNow
              rangeDuration:(NSNumber * _Nullable)minutesFromStart
          completionHandler:(PACEXTVProgramGuideV1ProgramsCompletionBlock _Nonnull)completed;

/**
 * Retrieve programs that are currently scheduled to air.
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1ProgramsCompletionBlock for more details.
 */
- (void)programsPlayingNowWithCompletionHandler:(PACEXTVProgramGuideV1ProgramsCompletionBlock _Nonnull)completed;

/**
 * Retrieve programs that are scheduled to play at a specific date or time. 
 * @param date Date for which programs are scheduled to air.
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1ProgramsCompletionBlock for more details.
 */
- (void)programsPlayingOnDate:(NSDate * _Nonnull)date
        withCompletionHandler:(PACEXTVProgramGuideV1ProgramsCompletionBlock _Nonnull)completed;

/**
 * Search for programs by fields, such as date or time.
 *
 * This api will throw an exception if wrong combination of fields are provided. Please look at the description of the
 * PACEXTVProgramGuideV1SearchField to see which fields may not go together.
 * @param fields Fields to be used when searching for a program. Please refer to PACEXTVProgramGuideV1SearchField for more details.
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1SearchCompletionBlock for more details.
 */
- (void)searchForProgramsByField:(NSDictionary * _Nonnull)fields
               completionHandler:(PACEXTVProgramGuideV1SearchCompletionBlock _Nonnull)completed;

/**
 * Search for programs by text. For example, you could search by an actor's name or programs with the word Space in their title or synopsis.
 * @param searchText String that will be used for searching for programs.
 * @param completed Completion block that will be called when the request gets completed. Please refer to PACEXTVProgramGuideV1SearchCompletionBlock for more details.
 */
- (void)searchForProgramsByText:(NSString * _Nonnull)searchText
              completionHandler:(PACEXTVProgramGuideV1SearchCompletionBlock _Nonnull)completed;

/**
 * @constantgroup PACEXTVProgramGuideV1ErrorDomains
 * List of error domains.
 */

/**
 * PACEXTVProgramGuideV1 general error domain.
 */
FOUNDATION_EXPORT NSString *const _Nonnull        PACEXTVProgramGuideV1ErrorDomain;

/**
 * The request error codes for the program guide.
 *
 * @owner PACEXTVProgramGuideV1
 */
typedef enum
{
    /** The request has failed due to an unknown error. */
    PACEXTVProgramGuideErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACEXTVProgramGuideErrorBadRequest = 1001,
    /** The request has failed due to the unavailability of the service. */
    PACEXTVProgramGuideErrorServiceNotFound = 1002,
    /** The request has failed due to an unexpected internal error. */
    PACEXTVProgramGuideErrorInternalError = 1003,
    /** The request has failed due to an unexpected response from the server. */
    PACEXTVProgramGuideErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACEXTVProgramGuideErrorConnectionError = 1005
}
PACEXTVProgramGuideErrorCode;


/**
 * @constantgroup PACEXTVProgramGuideV1SearchField
 * The fields that can be used when searching for a program.
 */

/**
 * The start point for the range lookup of programs based on airing time. If not provided, current
 * time will be assumed.
 *
 * This value of this field should be of type NSDate.
 * Throws an exception if PACEXTVProgramGuideV1StartRangeDateField is used along with PACEXTVProgramGuideV1StartOffsetInMinutesField.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1StartRangeDateField;

/**
 * The offset, specified in minutes, from the current time.
 *
 * This value of this field should be of type NSNumber.
 * Throws an exception if PACEXTVProgramGuideV1StartOffsetInMinutesField is used along with PACEXTVProgramGuideV1StartRangeDateField.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1StartOffsetInMinutesField;

/**
 * The end date or time for the lookup range. If not provided, no
 * end date will be provided and the date or time the flight completes will be used. 
 *
 * This value of this field should be of type NSDate.
 * Throws an exception if PACEXTVProgramGuideV1EndRangeDateField is used along with PACEXTVProgramGuideV1RangeDurationInMinutesField.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1EndRangeDateField;

/**
 * Offset from the end point of the lookup range for programs based on scheduled airing time. Value specified in minutes. Typically, this is a four hour window. If not specified, the end is the date or time the flight completes. 
 *
 * This value of this field should be of type NSNumber.
 * Throws an exception if PACEXTVProgramGuideV1RangeDurationInMinutesField is used along with PACEXTVProgramGuideV1EndRangeDateField.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1RangeDurationInMinutesField;

/**
 * Lookup based on program title.
 *
 * This value of this field should be of type NSString.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ProgramTitleField;

/**
 * Lookup based on channel call sign or letters, such as CNN, ESPN or ABC
 *
 * This value of this field should be of type NSString.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ChannelCallSignField;

/**
 * Lookup based on channel title, such as British Broadcasting Corporation *
 *
 * This value of this field should be of type NSString.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ChannelTitleField;

/**
 * Lookup based on category, such as news or sports, and subcategory fields, such as local or international, cricket or soccer.
 *
 * This value of this field should be of type NSString.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1CategoryField;


/**
 * The event is dispatched when programs has been updated.
 */
FOUNDATION_EXPORT NSString *const _Nonnull PACEXTVProgramGuideV1ProgramsDidChangeNotification;

@end

