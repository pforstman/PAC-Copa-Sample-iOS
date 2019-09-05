/** @module PACSeatPairing.framework *///
//  PACSeatLoginV1.h
//  SeatPairing
//
//

#ifndef PACSeatLoginV1_h
#define PACSeatLoginV1_h

#import <PACCoreKit/PACCoreKit.h>

/**
 * This seat pairing login service allows a user to push the login credentials to login the seat.
 */
@interface PACSeatLoginV1 : NSObject

/**
 * The possible login status.
 */
typedef enum
{
    /** The seat login status is unknown. */
    PACSeatLoginStatusUnknown,
    /** The seat is not logged in. */
    PACSeatLoginStatusNotLoggedIn,
    /** The seat is logged in. */
    PACSeatLoginStatusLoggedIn,
}
PACSeatLoginStatus;

/**
 * @constantgroup PACSeatLoginErrorDomains
 * The list of error domains for PACSeatLoginV1.
 * @owner PACSeatLoginV1
 */

/**
 * This key defines the general error domain for PACSeatLoginV1.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatLoginErrorDomain;

/**
 * The error codes returned.
 */
typedef enum
{
    /** The request has failed due to an unknown error. */
    PACSeatLoginErrorUnknown                          = 1500,
    /** The request has failed due to invalid or missing parameters in the request. */
    PACSeatLoginErrorBadRequest                       = 1501,
    /** The request has failed due to an unexpected internal error. */
    PACSeatLoginErrorInternalError                    = 1502,
    /** The request has failed due to a connection error. */
    PACSeatLoginErrorConnectionError                  = 1503,
    /** The request has failed due to the server returning an unexpected response. */
    PACSeatLoginErrorBadResponse                      = 1504,
    /** The request has failed due to the service being unavailable. */
    PACSeatLoginErrorServiceNotFound                  = 1505,
    /** The request has failed due to a passenger announcement on the seatback monitor is in progress */
    PACSeatLoginErrorSeatPAInProgress                 = 1506,
    /** The request has failed due to the device not being paired to the seatback monitor. */
    PACSeatLoginErrorNotPaired                        = 1600,
    /** The request has failed due to an invalid or missing parameter in the request. */
    PACSeatLoginErrorInvalidParameters                = 1601,
    /** The request has failed because the seat rejected the command. */
    PACSeatLoginErrorRejected                         = 1701,
    /** The request has failed because the authentication credentials are invalid. */
    PACSeatLoginErrorAuthenticationFailure            = 1701
}
PACSeatLoginErrorCode;


/**
 * The completion block that is called when loginSeatWithCredentials:completionHandler: finished executing the request.
 * @param error The error object that defined the reason why the request has failed. Please refer to PACSeatLoginErrorCode for possible error codes.
 */
typedef void (^PACSeatLoginV1LoginCompletionBlock)(NSError * _Nullable error);

/**
 * Retrieve login status for user credentials.
 * @param credentials The credentials to pass to the seat. Please refer to PACSeatLoginCredentials for possible credentials.
 * @param completion The completion handler that will be called when an error occurs or when the request ends.
 */
- (void)retrieveLoginStatusWithCredentials:(NSDictionary<NSString *,NSString *> * _Nonnull)credentials
                         completionHandler:(void (^ _Nonnull)(PACSeatLoginStatus status, NSError * _Nullable error))completion;

/**
 * Log the seat in using user credentials.
 *
 * Please note that the confirmation of the log in will be on the seat back.
 * @param credentials The credentials to pass to the seat. Please refer to PACSeatLoginCredentials for possible credentials.
 * @param completion The completion handler that will be called when an error occurs or when the request ends.
 */
- (void)loginSeatWithCredentials:(NSDictionary<NSString *,NSString *> * _Nonnull)credentials
               completionHandler:(PACSeatLoginV1LoginCompletionBlock _Nonnull)completion;

/**
 * The login status has changed.
 **/
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatLoginV1LoginStatusChangedNotification;

/**
 * @constantgroup PACSeatLoginCredentials
 * List of seat login credentials.
 * @owner PACSeatLoginV1
 */

/**
 * This key defines the frequent flyer credential.
 * 
 * The frequent flyer will be lower cased and then hashed using SHA256 before sending to seat.
 * The value should be a NSString object.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatLoginV1CredentialFrequentFlyerNumber;

/**
 * This key defines an already hashed frequent flyer credential.
 *
 * The frequent flyer should be hashed by lowercasing the string first and the hashing using SHA256.
 * The value should be a NSString object.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatLoginV1CredentialFrequentFlyerHash;

/**
 * This key defines the email credential.
 *
 * The email will be lower cased and then hashed using SHA256 before sending to seat.
 * The value should be a NSString object.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatLoginV1CredentialEmail;

/**
 * This key defines the email credential.
 *
 * The frequent flyer should be hashed by lowercasing the string first and the hashing using SHA256.
 * The value should be a NSString object.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACSeatLoginV1CredentialEmailHash;

@end


#endif /* PACSeatLoginV1_h */
