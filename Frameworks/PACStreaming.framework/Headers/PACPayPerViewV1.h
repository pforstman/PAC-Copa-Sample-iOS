/** @module PACStreaming.framework *///
//  PPVV1.h
//  InFlight iOS SDK
//
//  Created by Rawad Hilal on 12/23/15.
//  Copyright © 2015 - 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

@class PACPayPerViewPurchasableMediaItem;

/**
* A class that initializes payment services for applications requiring the purchase of items, such as pay per view (PPV) media, and handles the processing of PPV payments and tokens. Application developers can verify an item can be purchased, initiate payment process and purchase an item. 

**Note:**When testing the PPV logic flow, the device cannot be connected to a debugger on iOS. A debugger will prevent the logic flow from working. 
 */
@interface PACPayPerViewV1 : InFlightService

/**
 * @constantgroup Error Domain
 * The domains that are associated to the error codes.
 * @owner PACPayPerViewV1
 */

/**
 * The error domain for PACPayPerView service.
 * @owner PACPayPerViewV1
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACPayPerViewErrorDomain;

/**
 * The error codes of the pair api call.
 * @owner PACPayPerViewV1
 */
typedef enum {
    /** The request has failed due to an unknown error. */
    PACPayPerViewErrorUnknown                           = 9000,
    /** The request has missing or incorrect parameters. */
    PACPayPerViewErrorBadRequest                        = 9001,
    /** The request has failed due to a connection error. */
    PACPayPerViewErrorConnectionError                   = 9002,
    /** The request has failed due an unexpected response from the server. */
    PACPayPerViewErrorBadResponse                       = 9003,
    /** The request has failed due the service being unavailable. */
    PACPayPerViewErrorServiceNotFound                   = 9004,
    /*! Internal error occurred. */
    PACPayPerViewErrorInternalError                     = 9005,
    /*! Server error occurred. */
    PACPayPerViewErrorServerError                       = 9006,
    /*! The payment form was cancelled by the user. */
    PACPayPerViewErrorPaymentFormCancelled              = 9007,
    /*! Media URI provided is not found. */
    PACPayPerViewErrorMidNotFound                       = 9008,
    /*! Media URI provided is not purchasable. */
    PACPayPerViewErrorMidNotPurchasable                 = 9009,
    /*! Media URI provided does not require purchase. */
    PACPayPerViewErrorPurchaseNotRequried               = 9010,
    /*! Input parameter provided is not valid. */
    PACPayPerViewErrorInvalidParameter                  = 9011,
    /*! Purchase was declined due to insufficient funds. */
    PACPayPerViewErrorPurchaseDeclined                  = 9012,
    /*! Payment method not supported or deprecated. */
    PACPayPerViewErrorPaymentMethodDeprecated           = 9013,
    /*! Payment transaction already started. */
    PACPayPerViewErrorPaymentTransactionAlreadyStarted  = 9014,
    /*! Payment transaction has not yet started. */
    PACPayPerViewErrorPaymentTransactionNotStarted      = 9015,
    /*! Purchase is not allowed with card type. */
    PACPayPerViewErrorCardTypeNotSupported              = 9016,
}PACPayPerViewErrorCodes;

/**
 * The completion block called when the payment form has been processed.
 * @param error Error object that is set when an error occurs. Please refer to PACPayPerViewErrorCodes for error codes.
 */
typedef void (^PACPayPerViewStartPaymentTransactionCompletionBlock)(NSError * _Nullable error);

/**
 * The completion block that is called when the purchasing of a media item has completed or failed.
 * @param amountCharged Amount that was charged on the credit or voucher card.
 * @param error Error object that is set when an error occurs. Please refer to PACPayPerViewErrorCodes for error codes.
 */
typedef void (^PACPayPerViewCompletePaymentTransactionCompletionBlock)(NSString * _Nullable amountCharged, NSError * _Nullable error);

/**
 * The completion block that is called when retrieving the purchasable media for a media URI that has completed or failed.
 *
 * If media URI is not purchasable, purchasableMediaItems will be nil and an error will be set with an error code. PACPayPerViewErrorPurchaseNotRequried.
 * @param paymentRequired A flag that determines whether the item requires payment. On error or when no payment is required, this argument will be set to false.
 * @param purchasableMediaItems The list of purchasable media items associated to the media URI.
 * @param error Error object that is set when an error occurs. Please refer to PACPayPerViewErrorCodes for error codes.
 */
typedef void (^PACPayPerViewPurchaseRetrievePurchaseInfoCompletionBlock)(BOOL paymentRequired, NSArray <PACPayPerViewPurchasableMediaItem *> * _Nullable purchasableMediaItems, NSError * _Nullable error);

/*!
 * The theme IDs used for branding the payment form with the airline's specific theme. Please contact the airline for the theme ID.
 *
 * This field is optional.
 */
@property (nonatomic,copy) NSString * _Nullable themeId;

/*!
 * The ISO 639-2 language code for localizing the language that displays on the payment form.
 *
 * This field is optional.
 */
@property (nonatomic,copy) NSString * _Nullable language;

/**
 * Retrieve purchase information, such as payment requirement and purchasable media items, for a specific media URI.
 * @param mediaUri Unique identifier for the media.
 * @param completion The block that will be called when the request has finished or failed. Please refer to PACPayPerViewPurchaseRetrievePurchaseInfoCompletionBlock for more information.
 */
- (void)requestPurchaseInfo:(NSString * _Nonnull)mediaUri
            completionBlock:(PACPayPerViewPurchaseRetrievePurchaseInfoCompletionBlock _Nonnull)completion;

/**
 * Start a payment transaction for a purchasable media item.
 *
 * This API will display the payment form to capture the payment details from the passenger. Passengers enter their information, such as payment type, expiration date and cardholder name. At any point in the payment process, passengers have the option to proceed or cancel the payment.
 * @param purchasableMediaItem The purchasable media item as returned from retrievePurchasableMediaForMediaUri:completionBlock:.
 * @param completion The completion block that will be called when payment transaction started or failed to start.
 */
- (void)startPaymentTransaction:(PACPayPerViewPurchasableMediaItem * _Nonnull)purchasableMediaItem
                completionBlock:(PACPayPerViewStartPaymentTransactionCompletionBlock _Nonnull)completion;

/**
 * Complete the started payment transaction.
 *
 * This method will execute the purchase. You may wish to prompt the passenger for purchase confirmation prior to calling this function.
 * @param purchasableMediaItem Purchasable media item as returned from retrievePurchasableMediaForMediaUri:completionBlock:.
 * @param completion The completion block that will be called when payment transaction started or failed to start. Please refer to PACPayPerViewCompletePaymentTransactionCompletionBlock for more details.
 */
- (void)completePaymentTransactionWithCompletionBlock:(PACPayPerViewCompletePaymentTransactionCompletionBlock _Nonnull)completion;

/**
 * Cancel the started payment transaction.
 */
- (void)cancelPaymentTransaction;

@end

