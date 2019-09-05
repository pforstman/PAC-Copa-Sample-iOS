//
//  FlightDataManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 10/23/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@class FlightData;

#define kMyFlightsFlightNumber          @"MyFlightsFlightNumber"
#define kMyFlightsDepartureDate         @"MyFlightsDepartureDate"
#define kMyFlightsDestinationAITA       @"MyFlightsDestinationAITA"
#define kMyFlightsDepartureAITA         @"MyFlightsDepartureAITA"
#define kMyFlightsWeatherLocationChange @"SelectedWeatherLocation"

typedef enum : NSUInteger {
    
    FlightDataItemFlightNumber = 0,
    FlightDataItemDepartureIATA,
    FlightDataItemDestinationIATA,
    FlightDataItemDestinationICAO,
    FlightDataItemPercentComplete,
    FlightDataItemTimeToDestinationInMinutes,
    FlightDataItemDistanceToDestinationInNauticalMiles,
    FlightDataItemAltitudeFeet,
    FlightDataItemTailNumber,
    FlightDataItemEstimatedArrivalTime
    
} FlightDataItem;

@interface FlightDataManager : NSObject

+ (FlightDataManager *)sharedFlightDataManager;
- (BOOL)isFlightDataAvailable;
- (BOOL)shouldShowFlightStatusView;
- (id)flightDataForItem:(FlightDataItem)item;

@property (nonatomic, readonly) NSString *departureIATA;
@property (nonatomic, readonly) NSString *destinationIATA;
@property (nonatomic, readonly) NSString *destinationICAO;
@property (nonatomic, readonly) NSString *flightNumber;
@property (nonatomic, readonly) NSNumber *timeToDestinationMinutes;
@property (nonatomic, readonly) CGFloat percentComplete;
@property (nonatomic, readonly) NSNumber *distanceToDestinationNauticalMiles;
@property (nonatomic, readonly) NSNumber *altitudeFeet;
@property (nonatomic, assign) BOOL firstTimeFlag;

- (NSString *)departureCity;
- (NSString *)destinationCity;
- (NSString *)cityNameFromIATA:(NSString *)IATA;
- (NSString *)takeoffTimeUTC;
- (NSString *)estimatedArrivalTime;
- (void)runFlightCheck;
- (void)postAccessibilityNotification;
- (NSString *)accessibilityNotificationText;
- (void)manualFlightDataReset;
- (BOOL)isTailNumberValid;

@end
