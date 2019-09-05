/** @module PACMetadata.framework *///
//  PACeXTVMetadataV1.h
//  InFlight iOS SDK
//
//  Copyright © 2015-2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 The PACeXTVMetadataV1 class is a service that allows applications to retrieve information from the eXTV TV Manager service.

 [Download Sample Project](../../samples/PACMetadata/SampleEXTVMetadataApplication.zip)
 
 ***Example***
 
 An example on how to use the PACeXTVMetadataV1 service:

     NSString* const kEnglishLanguageKey = @"eng";

     @property (readwrite,nonatomic,strong)  PACeXTVMetadataV1*      extvMetadataService;
     @property (readwrite,nonatomic,assign)  BOOL                    stationsChangedNotificationHasBeenSetUp;
     @property (readwrite,nonatomic,strong)  NSMutableArray*         availableMetadataOfTheStations;
     @property (readwrite,nonatomic,assign)  BOOL                    sortStationsByIDOverTitle;
     @property (readwrite,nonatomic,weak)    IBOutlet UITableView*   availableStationsToChoose;

     -(void)viewDidLoad
     {
         [super viewDidLoad];

         [PACeXTVMetadataV1 initServiceWithCompletionBlock:
         ^(
             id          serviceObject,
             NSError*    error
         )
         {
             if (nil == error)
             {
                 self.extvMetadataService = serviceObject;
                 [self setUpAppWithAvailableStations];
             }
             else
             {
                 NSLog (@"Failed to initialize the service PACeXTVMetadataV1. Reason: %1$@",error);
                 [self setUpAppWithNoStations];
             }
         }];
     }

     -(void)dealloc
     {
         if (self.stationsChangedNotificationHasBeenSetUp)
         {
             [[NSNotificationCenter defaultCenter] removeObserver:self
                 name:PACeXTVMetadataStationsChangedNotification
                 object:nil];

             self.stationsChangedNotificationHasBeenSetUp = NO;
         }
     }

     #pragma mark - View refreshing from model
     -(void)setUpAppWithNoStations
     {
         dispatch_async (dispatch_get_main_queue (),
         ^{
             self.availableMetadataOfTheStations = nil;
             [self.availableStationsToChoose reloadData];
         });
     }

     -(void)setUpAppWithAvailableStations
     {
         [self.extvMetadataService availableStations:
         ^(
             NSArray*    availableStations,
             NSError*    error
         )
         {
             if (!self.stationsChangedNotificationHasBeenSetUp)
             {
                 [[NSNotificationCenter defaultCenter] addObserver:self
                     selector:@selector (setUpAppWithAvailableStations:)
                     name:PACeXTVMetadataStationsChangedNotification
                     object:nil];

                 self.stationsChangedNotificationHasBeenSetUp = YES;
             }

             if (nil == error)
             {
                 NSMutableArray* currentlyAvailableMetadataOfTheStations;

                 currentlyAvailableMetadataOfTheStations = [availableStations mutableCopy];
                 if (self.sortStationsByIDOverTitle)
                 {
                     [currentlyAvailableMetadataOfTheStations sortUsingComparator:
                     ^NSComparisonResult
                     (
                         PACeXTVMetadataStationInfo* obj1,
                         PACeXTVMetadataStationInfo* obj2
                     )
                     {
                         NSString*   stationIDOfObj1;
                         NSString*   stationIDOfObj2;

                         stationIDOfObj1 = obj1.stationID;
                         stationIDOfObj2 = obj2.stationID;

                         return [stationIDOfObj1 localizedStandardCompare:stationIDOfObj2];
                     }];
                 }
                 else
                 {
                     [currentlyAvailableMetadataOfTheStations sortUsingComparator:
                     ^NSComparisonResult
                     (
                         PACeXTVMetadataStationInfo* obj1,
                         PACeXTVMetadataStationInfo* obj2
                     )
                     {
                         NSDictionary*   titleValuesOfObj1;
                         NSString*       titleOfObj1;
                         NSDictionary*   titleValuesOfObj2;
                         NSString*       titleOfObj2;

                         titleValuesOfObj1 = obj1.titleInAudioLanguages;
                         titleOfObj1 = [titleValuesOfObj1 objectForKey:kEnglishLanguageKey];

                         titleValuesOfObj2 = obj2.titleInAudioLanguages;
                         titleOfObj2 = [titleValuesOfObj2 objectForKey:kEnglishLanguageKey];

                         return [titleOfObj1 localizedStandardCompare:titleOfObj2];
                     }];
                 }

                 dispatch_async (dispatch_get_main_queue (),
                 ^{
                     self.availableMetadataOfTheStations = currentlyAvailableMetadataOfTheStations;
                     [self.availableStationsToChoose reloadData];
                 });
             }
             else
             {
                 [self setUpAppWithNoStations];
             }
         }];
     }

 */

@interface PACeXTVMetadataV1 : InFlightService

/**
 * Retrieve metadata for all available stations.
 * @param completionHandler The completion block called when the request is finished.
 *
 *- *availableStations* The array of all available stations.  Each object is of class PACeXTVMetadataStationInfo, encapsulating a station's metadata.
 *- *error* The NSError object set if an error occurs.
 */
-(void)availableStations:(void(^)(NSArray* availableStations,NSError* error) )completionHandler;

/**
 * Retrieve the status of a specific station.
 * @param stationID The ID for the station whose status is requested.
 * @param completionHandler The completion block called when the request is finished.
 *
 *- *error* The NSError object set if an error occurs or nil if the station is being received properly. Please refer to the domain PACeXTVMetadataStationStatusDomain and PACeXTVMetadataStationStatus for error codes.
 */
-(void)statusOfStationID:(NSString* )stationID
    completionBlock:(void(^)(NSError* error) )completionHandler;

@end

/**
 * eXTV Metadata API error codes that may be set in the NSError object. The NSError object is passed to the completion handler that is supplied to the method initServiceWithCompletionBlock: with the domain set to PACeXTVMetadataServiceStatusDomain.
 * @owner PACeXTVMetadataV1
 */
typedef enum
{
    /** An unknown result was returned by the service. */
    PACeXTVMetadataServiceStatusUnknown         = -1,
    /** The service has been commissioned; not actually returned, but may be used in a switch/case with a nil-value -[NSError code] with other possible results. */
    PACeXTVMetadataServiceStatusSuccessful      = 0,
    /** The service failed in the process of being commissioned. */
    PACeXTVMetadataServiceStatusFailed          = 1,
    /** The service is in the process of being commissioned. */
    PACeXTVMetadataServiceStatusInProgress      = 2,
    /** The service's commissioning status has been revoked. */
    PACeXTVMetadataServiceStatusRevoked         = 3,
    /** The service was not commissioned. */
    PACeXTVMetadataServiceStatusNotCommissioned = 4,
    /** The service's commissioning status has expired. */
    PACeXTVMetadataServiceStatusExpired         = 5,
}
PACeXTVMetadataServiceStatus;

/**
 * eXTV Metadata API error codes that may be set in the NSError object. The NSError object is passed to the completion handler supplied to the method statusOfStationID:completionBlock: with the domain set to PACeXTVMetadataStationStatusDomain.
 * @owner PACeXTVMetadataV1
 */
typedef enum
{
    /** An unknown result was returned by the service. */
    PACeXTVMetadataStationStatusUnknown        = -1,
    /** The station is being received properly, but not actually returned. It may be used in a switch/case with a nil-value -[NSError code] and other possible results. */
    PACeXTVMetadataStationStatusSuccessful     = 0,
    /** The station is being administratively blocked. */
    PACeXTVMetadataStationStatusBlocked        = 1,
    /** The station is not authorized to be viewed on this aircraft. */
    PACeXTVMetadataStationStatusNotAuthorized  = 2,
    /** All stations of the eXTV service is being administratively blocked. */
    PACeXTVMetadataStationStatusTVBlocked      = 3,
    /** The station cannot be viewed due to signal loss. */
    PACeXTVMetadataStationStatusSignalLoss     = 4,
    /** The station was previously defined, but is no longer available. */
    PACeXTVMetadataStationStatusNotPresent     = 5,
    /** The station is invalid or never defined. */
    PACeXTVMetadataStationStatusInvalid        = 6,
}
PACeXTVMetadataStationStatus;

/**
 * @constantgroup Domain Constants for NSError Results
 * @owner PACeXTVMetadataV1
 */
/** The domain that an NSError has when the code represents a value from PACeXTVMetadataServiceStatus */
FOUNDATION_EXPORT NSString* const   PACeXTVMetadataServiceStatusDomain;
/** The domain that an NSError has when the code represents a value from PACeXTVMetadataStationStatus */
FOUNDATION_EXPORT NSString* const   PACeXTVMetadataStationStatusDomain;

/**
 * A change has occurred in the list of available stations.
 * @owner PACeXTVMetadataV1
 *
 * The notification does not include any payload; a call to availableStations: should be performed
 *
 */
FOUNDATION_EXPORT NSString* const   PACeXTVMetadataStationsChangedNotification;

/**
 The PACeXTVMetadataStationInfo class is an object describing a station returned by the instance method availableStations: of the class PACeXTVMetadataV1
 */
@interface PACeXTVMetadataStationInfo : NSObject

/** The ID of the station */
@property (readonly,nonatomic,copy)     NSString*       stationID;

/** An array of three-letter language codes used for mapping the title and description of the station into the respective languages. */
@property (readonly,nonatomic,copy)     NSArray*        audioLanguages;

/** A dictionary with keys of three-letter language codes mapped to the title of the station in the respective languages. */
@property (readonly,nonatomic,copy)     NSDictionary*   titleInAudioLanguages;

/** A dictionary with keys of three-letter language codes mapped to the description of the station in the respective languages. */
@property (readonly,nonatomic,copy)     NSDictionary*   descriptionInAudioLanguages;

/** The call sign of the station. */
@property (readonly,nonatomic,copy)     NSString*       callSign;

/** The location of the media. */
@property (readonly,nonatomic,copy)     NSString*       mediaURI;

/** The MID associated with this station.  This will only be populated if the station is not dynamic.  Otherwise it will be empty. */
@property (readonly,nonatomic,copy)     NSString*       mediaID;

/** A flag indicating whether the station is static (predetermined in the media load) or dynamic (enabled mid-cycle). */
@property (readonly,nonatomic,assign)   BOOL            isDynamic;

/** A dictionary with keys of image sizes from mediaDb to their poster image URL. */
@property (readonly,nonatomic,copy)     NSDictionary*   posterURL;

/** A dictionary with keys of image sizes from mediaDb to the respective synopsis image URL if the station is static. */
@property (readonly,nonatomic,copy)     NSDictionary*   synopsisURL;

/** The URL to the service providing real-time status of the station.  A station's status must be checked before streaming a station, as its status may change frequently. */
@property (readonly,nonatomic,copy)     NSString*       stationStatusURL;

/** A flag indicating if the station has video content. */
@property (readonly,nonatomic,assign)   BOOL            hasVideoData;

/** A flag indicating if the station has audio content. */
@property (readonly,nonatomic,assign)   BOOL            hasAudioData;

@end
