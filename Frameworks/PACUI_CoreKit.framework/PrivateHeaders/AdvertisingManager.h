//
//  AdvertisingManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 5/10/16.
//  Copyright (c) 2016 Mercury. All rights reserved.
//

#import <PACAdvertising/PACAdvertisingV1.h>

@protocol PSAdViewDelegate <NSObject>
- (void)adViewDidLoad:(NSInteger)tag;
- (void)adViewDidClose:(NSInteger)tag;
@end

@interface AdvertisingManager : NSObject
+ (AdvertisingManager *)sharedAdvertisingManager;
- (void)requestVideoAdForZone:(NSString *)zone withCompletion:(void(^)(NSString *object, NSError *error))completion;
@end

@interface PSAdView : UIView <UIGestureRecognizerDelegate>
@property (nonatomic, assign) BOOL isAdLoaded;

// TODO: temp - replace with type system
@property (nonatomic, assign) BOOL isFeatured;

@property (nonatomic, strong) PACAdvertisingItem *advertisingItem;
@property (nonatomic, strong) UITapGestureRecognizer *tapGesture;
@property (nonatomic, assign) BOOL highlighted;
@property (nonatomic, strong) UIView *highlightedView;
@property (nonatomic, assign) BOOL isCloseable;
@property (nonatomic, assign) BOOL hasBeenClosed;
@property (nonatomic, weak) id<PSAdViewDelegate> delegate;

- (void)loadAdForZone:(NSString *)zone withSize:(CGSize)size withCompletion:(void(^)(BOOL success, NSError *error))completion;

@end
