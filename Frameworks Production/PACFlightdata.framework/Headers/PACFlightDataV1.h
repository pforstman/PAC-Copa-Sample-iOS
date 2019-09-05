/** @module PACFlightdata.framework *///
//  PACFlightDataV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2014 - 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

@class PACFlightDataCoordinate;
@class PACCoordinate;

/**
PACFlightDataV1 provides real-time access to flight data and event notifications as the data updates. The data can include the operating flight number, destination and estimated arrival time.

The FlightData API is read-only and can handle both on-demand requests and subscriptions to an event stream.

**Note:** The list of flight data parameters is based on the configuration of the aircraft and not all functions will return data. If no data is available, the APIs will return null.
 
 [Download Sample Project](../../samples/PACFlightdata/SampleFlightDataApplication.zip)
 
 ***Example***
         // Declared in class interface
         UILabel *altitudeLabel = ...;
         PACFlightDataV1 *flightdata = nil;
 
         - (void)viewDidLoad{
            [super viewDidLoad];
 
            // Initialize PACFlightDataV1 instance.
            [PACFlightDataV1 initServiceWithCompletionBlock:^(id serviceObject, NSError *error) {
                if (error != nil) {
                    NSLog(@"Failed to initialize service FlightdataV1. Reason: %@",error);
                    return;
                }
                // Get service object
                self.flightdata = serviceObject;
 
                // Add observer to PACFlightDataV1 data DidChange event.
                [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(flightDataAltitudeUpdated:)
                    name:PACFlightDataAltitudeFeetDidChangeNotification object:self.flightdata];
                [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(flightDataCoordinatesUpdated:)
                    name:PACFlightDataCurrentCoordinatesDidChangeNotification object:self.flightdata];
                .
                .
                .
 
                // Subscribe to real-time flight data events and notifications, such as altitude, distance to destination and estimated arrival time.

                [self.flightdata subscribe:@[PACFlightDataAltitudeFeetDidChangeNotification,PACFlightDataAltitudeFeetDidChangeNotification,...]];
            }];
         }
 
 
         - (void)flightDataCoordinatesUpdated:(NSNotification *)notification{
            // Get current coordinate
            PACFlightDataCoordinate *coordinate = [self.flightdata currentCoordinate];
            // Set the coordinate label with the value.
            [coordinateLabel setText:[NSString stringWithFormat:@"%@,%@",coordinate.longitude,coordinate.latitude]];
         }
 
         - (void)flightDataAltitudeUpdated:(NSNotification *)notification{
            // Get altitude
            NSNumber *altitudeValue = [self.flightdata altitudeFeet];
 
            // Set the altitude label with the value.
            [altitudeLabel setText:[NSString stringWithFormat:@"%.2f",altitudeValue.floatValue]];
         }
 
 */

@interface PACFlightDataV1 : InFlightService

#pragma mark - Event Subscription

/**
 * @name Event Subscription
 */

/**
 * Subscribe to a list of flight data events and notifications, such as altitude, distance to destination and estimated arrival time.
 *
 * The data parameters are based on the configuration of the aircraft and not all functions will return data. If no data is available, the APIs will return nil.
 *
 * @param flightDataEvents Ex) @[FlightDataTimeAtOriginDidChangeNotification,FlightDataTimeAtDestinationDidChangeNotification]
 * @return {void}
 */
- (void) subscribe:(NSArray *)flightDataEvents;


/**
 * Unsubscribe from receiving events for specified notifications.
 *
 * @param flightdataEvents An array of flight data events
 * @return {void}
 */
- (void) unsubscribe:(NSArray *)flightdataEvents;

/**
 * @name Flight data
 */
#pragma mark - Flight Data

/**
 * Return the unique ID for the current flight.
 *
 * This can be used as a session identifier for the current flight. This value will change at
 * every open and closed flight. The flight state can be identified using [PACFlightDataV1 flightState].
 *
 * @return Current flight ID.
 */
- (NSString *) flightId;

/**
 * Return the flight number for the operator.
 *
 * @return Operator flight number
 */
- (NSString *) flightNumber;

/**
 * Return tail number of the airplane.
 *
 * @return Airplane tail number.
 */
- (NSString *) tailNumber;

/**
 * Return the current flight state, such as open or closed.
 *
 * The flight state typically indicates the availability of the InFlight (IFE) system.
 * @return The current flight state. Please refer to PACFlightDataFlightState section for the results.
 */
- (NSString *) flightState;

/**
 * Return the phase of the current flight. The values include power up, engine start, accelerating, cruising, descending and touchdown.  Please refer to the PACFlightDataFlightPhase section.
 * @return Phase of the current flight.
 */
- (NSString *) flightPhase;


#pragma mark - Airport Information

/**
 * Return the IATA code of the destination airport. The format is the 3-letter IATA code.
 *
 * @return IATA code for the destination airport
 */
- (NSString *) destinationIATA;

/**
 * Return the ICAO code of the destination airport. The format is the 4-letter ICAO code.
 *
 * @return ICAO code of the destination airport
 */
- (NSString *) destinationICAO;

/**
 * Return the IATA code of the departure airport. The format is the 3-letter IATA code.
 *
 * @return IATA code for the departure airport
 */
- (NSString *) departureIATA;

/**
 * Return the ICAO code of the departure airport. The format is the 4-letter ICAO code.
 *
 * @return ICAO code for the departure airport
 */
- (NSString *) departureICAO;

#pragma mark - Airport and Flight Coordinates

/**
 * Return the longitude and latitude of the departure airport.
 *
 * @return Departure airport longitude and latitude
 */
- (PACFlightDataCoordinate *) departureCoordinate;

/**
 * Return the longitude and latitude of the current flight.
 *
 * @return Current flight longitude and latitude
 */
- (PACFlightDataCoordinate *) currentCoordinate;

/**
 * Return the longitude and latitude of the destination airport.
 *
 * @return Destination airport longitude and latitude
 */
- (PACFlightDataCoordinate *) destinationCoordinate;


#pragma mark - Flight Information


/**
 * Return altitude of the airplane. The format is in feet.
 *
 * @return Flight altitude in feet. */

- (NSNumber *) altitudeFeet;

/**
 * Return altitude of the airplane. You can specify the format as meters, miles, feet, kilometers, nautical miles or yards.
 * For additional information, please refer to PACDistance.
 *
 * @return Altitude of the airplane.
 */
- (PACDistance *)altitude;


/**
 * Return the path of the flght in true degrees. The format is in a degree from 0 to 360.
 *
 * @return True heading degree
 */
- (NSNumber *) trueHeadingDegree;


#pragma mark - Distance

/**
 * Return the distance from the departure airport.
 *
 * @return Distance from the departure airport
 */
- (PACDistance *) distanceFromDeparture;

/**
 * Return distance to destination airport.
 *
 * @return Distance to the destination airport
 */
- (PACDistance *) distanceToDestination;

/**
 * Return the distance from the departure airport. The value is in nautical miles.
 *
 * @return Distance from the departure airport
 */
- (NSNumber *) distanceFromDepartureNauticalMiles;

/**
 * Return distance to destination airport. The value is in nautical miles.
 *
 * @return Distance to the destination airport
 */
- (NSNumber *) distanceToDestinationNauticalMiles;

#pragma mark - Speed and Temperature

/**
 * Return ground speed of the airplane. You can specify the speed as kilometers per hours, miles per hour, knots, Mach and meters per hour.
 * For additional information, please refer to PACSpeed.
 *
 * @return Ground speed of airplane
 */
- (PACSpeed *) groundSpeed;

/**
 * Return flight speed of the airplane. You can specify the speed as kilometers per hours, miles per hour, knots, Mach and meters per hour.
 * For additional information, please refer to PACSpeed.
 *
 * @return Flight speed of airplane
 */
- (PACSpeed *) flightSpeed;

/**
 * Return the head wind speed of the airplane. You can specify the speed as kilometers per hours, miles per hour, knots, Mach and meters per hour.
 * For additional information, please refer to PACSpeed.
 *
 * @return Head wind speed of airplane
 */
- (PACSpeed *) headWindSpeed;

/**
 * Return the ground speed of the airplane. The format is in knots from -999 to 999.
 *
 * @return Ground speed in knots
 */
- (NSNumber *) groundSpeedKnots;

/**
 * Return the speed of the current flight. The format is in Mach.
 *
 * @return Flight speed in Mach
 */
- (NSNumber *) flightSpeedMach;

/**
 * Return the temperature of the outside air. The value is in Celsius.
 *
 * @return Temperature of the outside air
 */
- (NSNumber *) outsideAirTempCelsius;

/**
 * Return outside air temperature. You can specify the format as Fahrenheit or Celsius. For additional information, please refer to PACTemperature.
 *
 * @return Outside temperature
 */
- (PACTemperature *) outsideAirTemperature;

/**
 * Return wind direction. The format is a degree from 0 to 360.
 *
 * @return Wind direction degree
 */
- (NSNumber *) windDirectionDegree;

/**
 * Return the wind speed. The format is in knots from -999 to 999.
 *
 * @return Wind speed
 */
- (NSNumber *) windSpeedKnots;

/**
* Return the wind speed. You can specify the format as kilometers per hour, miles per hour, knots, meters per hour or Mach. For additional information, please refer to PACSpeed.
*
* @return Wind speed
*/
- (PACSpeed *) windSpeed;


/**
 * Return the head wind speed of the flight. The format is in knots from -999 to 999.
 *
 * @return Head wind speed
 */
- (NSNumber *) headWindSpeedKnots;

/**
 * Return the aircraft type
 *
 * @return aircraft type
 */
- (NSString*)aircraftType;

#pragma mark - Time


/**
 * Return the departure date and time for the current flight. The value is ISO 8601 UTC date and time in a 24 hour format. Example: YYYY-MM-DD hh:mm.
 *
 * @return Departure time for the current flight.
 */
- (NSString *) takeoffTimeUTC;

/**
 * Return the local time at the departure airport. The format is the local time in a 24-hour format. Both time zone and daylight savings time rules are pre-applied.
 *
 * @return Time at the departure airport
 */
- (NSString *) timeAtOrigin;


/**
 * Return the remaining flight time to the destination airport. The format is in minutes from 0 to 9999.
 *
 * @return Time to destination
 */
- (NSNumber *) timeToDestinationMinutes;


/**
 * Return estimated arrival time of the flight. The value is in the local time in a 24-hour format. Both time zone and daylight savings time rules are pre-applied.
 *
 * @return Estimated arrival time of the flight
 */
- (NSString *) estimatedArrivalTimeUTC;

/**
 * Return the distance that the flight has flown. The format is a percentage of the total flight distance.
 * @return Distance as a percentage
 */
- (NSNumber *) distanceCoveredPercent;


/**
 * Return the local time at the destination airport. The value is in the local time in a 24-hour format. Both time zone and daylight savings time rules are pre-applied.
 *
 * @return Time at destination
 */
- (NSString *) timeAtDestination;

/**
 * Return the difference from Coordinated Universal Time (UTC) for the destination airport. The format is in minutes.
 *
 * @return Difference in minutes from UTC
 */
- (NSNumber *) destinationUTCOffsetMinutes;

/**
 * Return the difference from Coordinated Universal Time (UTC) for the departure airport. The format is in minutes.
 *
 * @return Difference in minutes from UTC
 */
- (NSNumber *) departureUTCOffsetMinutes;

@end

/**
 * PACFlightDataCoordinate is a class used to represent the flight coordinate with longitude and latitude. You can specify the coordinate as either longitude or latitude or both longitude or latitude. For additional information, please refer to @PACCoordinate.
 */
@interface PACFlightDataCoordinate : PACCoordinate

@end

#pragma mark - Notifications
/**
 * Event dispatched when an error occurred while downloading data.
 * All data fields will be cleared,
 * then repopulated when the service reconnects with the server. This field is not subscribable.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataErrorNotification;

/*!
 * Event dispatched when altitude changed.
 * @event PACFlightDataAltitudeDidChangeNotification
 */
extern NSString *const PACFlightDataAltitudeDidChangeNotification;

/*!
 * Event dispatched when distance from departure changed.
 * @event PACFlightDataDistanceFromDepartureDidChangeNotification
 */
extern NSString *const PACFlightDataDistanceFromDepartureDidChangeNotification;

/*!
 * Event dispatched when distance to destination changed.
 * @event PACFlightDataDistanceToDestinationDidChangeNotification
 */
extern NSString *const PACFlightDataDistanceToDestinationDidChangeNotification;

/*!
 * Event dispatched when ground speed changed.
 * @event PACFlightDataGroundSpeedDidChangeNotification
 */
extern NSString *const PACFlightDataGroundSpeedDidChangeNotification;

/*!
 * Event dispatched when flight speed changed.
 * @event PACFlightDataFlightSpeedDidChangeNotification
 */
extern NSString *const PACFlightDataFlightSpeedDidChangeNotification;

/*!
 * Event dispatched when outside air temperature changed.
 * @event PACFlightDataOutsideAirTempDidChangeNotification
 */
extern NSString *const PACFlightDataOutsideAirTempDidChangeNotification;

/*!
 * Event dispatched when wind speed changed.
 * @event PACFlightDataWindSpeedDidChangeNotification
 */
extern NSString *const PACFlightDataWindSpeedDidChangeNotification;

/*!
 * Event dispatched when head wind speed changed.
 * @event PACFlightDataHeadWindSpeedDidChangeNotification
 */
extern NSString *const PACFlightDataHeadWindSpeedDidChangeNotification;

/**
 * Event dispatched when the aircraft type has changed.
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataAircraftTypeDidChangeNotification;

/**
 * Event dispatched when the tail number has changed.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataTailNumberDidChangeNotification;

/**
 * Event dispatched when altitude changes. The value is in feet.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataAltitudeFeetDidChangeNotification;

/**
 * Event dispatched when destination IATA code changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDestinationIATADidChangeNotification;

/**
 * Event dispatched when destination ICAO code changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDestinationICAODidChangeNotification;

/**
 * Event dispatched when departure IATA code changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDepartureIATADidChangeNotification;

/**
 * Event dispatched when departure ICAO code changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDepartureICAODidChangeNotification;

/**
 * Event dispatched when distance from departure changes. The value is in feet.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDistanceFromDepartureNauticalMilesDidChangeNotification;

/**
 * Event dispatched when the distance to destination changes. The value is in nautical miles.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDistanceToDestinationNauticalMilesDidChangeNotification;

/**
 * Event dispatched when the operating flight number changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataFlightNumberDidChangeNotification;

/**
 * Event dispatched when ground speed changes. The value is in knots.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataGroundSpeedKnotsDidChangeNotification;

/**
 * Event dispatched when departure coordinate changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDepartureCoordinateDidChangeNotification;

/**
 * Event dispatched when current coordinate changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataCurrentCoordinateDidChangeNotification;

/**
 * Event dispatched when destination coordinate changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDestinationCoordinateDidChangeNotification;

/**
 * Event dispatched when flight speed changes. The value is in Mach.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataFlightSpeedMachDidChangeNotification;

/**
 * Event dispatched when the outside air temperature changes. The value is in Celsius.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataOutsideAirTempCelsiusDidChangeNotification;

/**
 * Event dispatched when the time to destination changes. The value is in minutes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataTimeToDestinationMinutesDidChangeNotification;

/**
 * Event dispatched when true heading changes. The value is in degrees.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataTrueHeadingDegreeDidChangeNotification;

/**
 * Event dispatched when wind direction changes. The value is in degrees.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataWindDirectionDegreeDidChangeNotification;

/**
 * Event dispatched when wind speed changes. The value is in knots.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataWindSpeedKnotsDidChangeNotification;

/**
 * Event dispatched when head wind speed changes. The value is in knots.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataHeadWindSpeedKnotsDidChangeNotification;

/**
 * Event dispatched when UTC offset time to destination changes. The value is in minutes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDestinationUTCOffsetMinutesDidChangeNotification;

/**
 * Event dispatched when UTC offset time to departure changes. The value is in minutes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDepartureUTCOffsetMinutesDidChangeNotification;

/**
 * Event dispatched when estimated arrival time changes. The value is in local time in a 24-hour format.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataEstimatedArrivalTimeUTCDidChangeNotification;

/**
 * Event dispatched when takeoff time changes. The value is in UTC time.

 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataTakeoffTimeUTCDidChangeNotification;

/**
 * Event dispatched when time at origin changes. The value is in local time in a 24-hour format.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataTimeAtOriginDidChangeNotification;

/**
 * Event dispatched when time to destination changes. The value is in local time in a 24-hour format.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataTimeAtDestinationDidChangeNotification;

/**
 * Event dispatched when the percentage of distance covered changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataDistanceCoveredPercentDidChangeNotification;

/**
 * Event dispatched when the flight phase changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataFlightPhaseDidChangeNotification;

/**
 * Event dispatched when the unique ID for the flight changes.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataFlightIdDidChangeNotification;

/**
 * Event dispatched when the flight state is open or closed.
 *
 * @owner PACFlightDataV1
 */
extern NSString *const PACFlightDataFlightStateDidChangeNotification;

/**
 * @constantgroup PACFlightDataFlightState
 * The following are the values for the flight state property.
 * @owner PACFlightDataV1
 */

/**
 * The current flight state is open.
 */
extern NSString *const PACFlightDataFlightStateOpen;

/**
 * The current flight state is closed.
 */
extern NSString *const PACFlightDataFlightStateClose;

/**
 * @constantgroup PACFlightDataFlightPhase
 * The following are the values for the flight phase property.
 * @owner PACFlightDataV1
 */

/**
 * The current flight phase is unknown.
 */
extern NSString *const PACFlightDataFlightPhaseUnknown;

/**
 * The airplane has powered up.
 */
extern NSString *const PACFlightDataFlightPhasePowerUp;

/**
 * The airplane engines have started.
 */
extern NSString *const PACFlightDataFlightPhaseEnginesStart;

/**
 * The airplane is powering up for take off.
 */
extern NSString *const PACFlightDataFlightPhaseTakeOffPower;

/**
 * The airplane is accelerating.
 */
extern NSString *const PACFlightDataFlightPhaseAccelerating;

/**
 * The airplane has achieved lift off.
 */
extern NSString *const PACFlightDataFlightPhaseLiftOff;

/**
 * The airplane is climbing to a higher altitude.
 */
extern NSString *const PACFlightDataFlightPhaseClimb;

/**
 * The airplane is cruising at a steady altitude.
 */
extern NSString *const PACFlightDataFlightPhaseCruising;

/**
 * The airplane is descending to a lower altitude.
 */
extern NSString *const PACFlightDataFlightPhaseDescending;

/**
 * The airplane is approaching the runway.
 */
extern NSString *const PACFlightDataFlightPhaseApproach;

/**
 * The airplane is circling the airport.
 */
extern NSString *const PACFlightDataFlightPhaseGoAround;

/**
 * The current flight phase is flare.
 */
extern NSString *const PACFlightDataFlightPhaseFlare;

/**
 * The airplane has landed.
 */
extern NSString *const PACFlightDataFlightPhaseTouchDown;

/**
 * The airplane is taxiing to a stop.
 */
extern NSString *const PACFlightDataFlightPhaseTaxiToStop;

/**
 * The airplane engines have stopped.
 */
extern NSString *const PACFlightDataFlightPhaseEnginesStop;

/**
 * The airplane is in maintenance mode.
 */
extern NSString *const PACFlightDataFlightPhaseMaintenance;

