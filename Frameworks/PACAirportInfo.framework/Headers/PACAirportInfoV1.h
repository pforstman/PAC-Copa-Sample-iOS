/** @module PACAirportInfo.framework *///
//  PACAirportInfoV1.h
//  InFlight iOS SDK
//  Copyright (c) 2015 - 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>
#import "PACAirportdata.h"

@class PACAirportInfoV1;

/**
 * The delegate of PACAirportInfoV1 must adopt the PACAirportInfoV1Delegate protocol. This allows PACAirportInfoV1
 to dispatch airport information to the application.
 */
@protocol PACAirportInfoV1Delegate <NSObject>
@required

/**
 * Called when the sender has the city name for a specific ICAO code.
 * @param sender The PACAirportInfoV1 instance object that made the call.
 * @param ICAOCodeToAirportInfo A key value pair defining an ICAO code associated to Airportdata object.
 * @see Airportdata
 */
- (void)airportInfo:(PACAirportInfoV1 *)sender didRetrieveAirportInfoForICAOCodes:(NSDictionary *)ICAOCodeToAirportInfo;

/**
 * Called when the sender failed to retrieve the city name for a specific ICAO code.
 * @param sender The PACAirportInfoV1 instance object that made the call.
 * @param ICAOCodeToError A key value pair defining an ICAO code to the associated error object.
 */
- (void)airportInfo:(PACAirportInfoV1 *)sender didFailRetrievingAirportInfoForICAOCodes:(NSDictionary *)ICAOCodeToError;

@optional
/**
 * Called when the sender finishes retrieving all requested info.
 * @param sender The PACAirportInfoV1 instance object that made the call.
 */
- (void)airportInfoDidFinishRetrievingInfo:(PACAirportInfoV1 *)sender;

@end

/**
AirportInfoV1 provides information related to airports. This includes the cities nearest to airports. The airports are represented by ICAO codes.

[Download Sample Project](../../samples/PACAirportInfo/SampleAirportInfoApplication.zip)

***Example***

@interface ViewController () <PACAirportInfoV1Delegate>
@property (nonatomic, strong) PACAirportInfoV1 *airportInfo;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Initialize the airport info service
    [PACAirportInfoV1 initServiceWithCompletionBlock:^(id object, NSError *error)
     {
         if (error != nil)
             return;
         
         // convert serviceObject to AirportInfo
         self.airportInfo = object;
         
         self.airportInfo.delegate = self;
     }];
    
    // Complete the text field with sample values that have extra whitespace for testing.
    // More values can be found in https://en.wikipedia.org/wiki/List_of_airports_by_ICAO_code:_K
    self.txtInput.text = @"KLAX, KJFK, KDFW, KSNA";
}

- (IBAction)actionClickSubmit:(id)sender
{
    NSArray* enteredICAOCodes = @[@"KLAX", @"KJFK", @"KDFW", @"KSNA"];
    .....
    
    dispatch_async
    (
     dispatch_get_main_queue (),
     ^{
         [self.airportInfo requestAirportInfoByICAO:enteredICAOCodes];
     }
     );
    
    .....
}

// delegate
- (void)airportInfo:(PACAirportInfoV1 *)sender didRetrieveAirportInfoForICAOCodes:(NSDictionary *)ICAOCodeToAirportInfo
{
    ...
    [self.tableList reloadData];
}

- (void)airportInfo:(PACAirportInfoV1 *)sender didFailRetrievingAirportInfoForICAOCodes:(NSDictionary *)ICAOCodeToError
{
    ...
    [self.tableList reloadData];
}

*/

@interface PACAirportInfoV1 : InFlightService

/**
 * The object that implements the PACAirportInfoV1Delegate callback functions.
 */
@property (nonatomic,weak) NSObject <PACAirportInfoV1Delegate> *delegate;

/**
 * This call requests the name of the cities nearest to the specified airports.
 *
 * This method call will make a request to return the name of the cities nearest to the specified airports.
 * The request that is made may result in multiple calls to the delegate function [AirportInfoV1Delegate airportInfo:didRetrieveAirportInfoForICAOCodes:].
 * Similarly, calling the request multiple times, when the initial request has not finished, may result in the delegate callback including all city names
 * of all the requested ICAO codes.
 * @param ICAOCodes ICAO codes of the airports.
 * @deprecated This method is deprecated starting InFlight iOS SDK version 02.13.00.00. Please use [AirportInfoV1 requestAirportInfoByICAO:].
 */
- (void)requestCityNamesByICAO:(NSArray *)ICAOCodes __attribute__((deprecated("This method is deprecated starting InFlight iOS SDK version 02.13.00.00. Please use [AirportInfoV1 requestAirportInfoByICAO:] instead.")));

/**
 * This method call requests information on the specified airports. Information such as the name of the cities next to the specified airports.
 *
 * This method call will request to return the name of the cities nearest to the specified airports.
 * The request that is made may result in multiple calls to the delegate function [AirportInfoV1Delegate airportInfo:didRetrieveAirportInfoForICAOCodes:].
 * Similarly, calling the request multiple times, when the initial request has not finished, may result in the delegate callback to include all city names
 * of all the requested ICAO codes.
 * @param ICAOCodes ICAO codes of the airports.
 */
- (void)requestAirportInfoByICAO:(NSArray *)ICAOCodes;

@end


/**
 * Error codes for the PACAirportInfoV1 API calls.
 * @owner PACAirportInfoV1
 */
typedef enum{
    /** An unknown error has occurred. */
    PACAirportInfoErrorUnknown                             = 1000,
    /** Request has failed due to a bad request from the client. */
    PACAirportInfoErrorBadRequest                          = 1001,
    /** Request has failed due to a connection problem with the server. */
    PACAirportInfoErrorConnectionError                     = 1002,
    /** Request has failed due to a bad response from the server. */
    PACAirportInfoErrorBadResponse                         = 1003,
    /** Request has failed due to the service not existing on the connected server. */
    PACAirportInfoErrorServiceNotFound                     = 1004,
    /** Request has failed because the ICAO code provided is not valid. */
    PACAirportInfoErrorInvalidICAOCode                     = 1005,
}PACAirportInfoErrorCode;

