//
//  PayPerViewManager.h
//  PACUI_CoreKit
//
//  Created by Paul Forstman on 10/10/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

#import <PACStreaming/PACStreaming.h>

@interface PayPerViewManager : NSObject

NS_ASSUME_NONNULL_BEGIN
+ (PayPerViewManager *)sharedPayPerViewManager;

- (void)startPaymentRequest:(PACPayPerViewPurchasableMediaItem *)item withCompletion:(void(^)(NSError *error, BOOL failed))completion;
- (void)completePaymentRequest:(void(^)(BOOL success, NSError *error))completion;
- (void)cancelPaymentRequest;
NS_ASSUME_NONNULL_END

- (void)lookupPurchaseInfoForMediaURI:(nonnull NSString *)mediaURI withCompletion:(void (^ _Nullable)(BOOL paymentRequired, NSArray<PACPayPerViewPurchasableMediaItem *> * _Nullable purchasableMediaItems, NSError * _Nullable error))completion;


@end
