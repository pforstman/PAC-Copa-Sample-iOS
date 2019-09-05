//
//  MediaViewController.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 5/28/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "AdaptiveDataProvider.h"
#import "BaseSectionViewController.h"
@class PSShoppingCatalog;
@class PSShoppingCategory;

typedef enum {
    MediaViewControllerModeNormal = 0,
    MediaViewControllerModeKidsZone = 1,
} MediaViewControllerMode;

@interface MediaViewController : BaseSectionViewController
@property (nonatomic, strong, readwrite) id <AdaptiveDataProvider> dataProvider;
@property (nonatomic, copy, readwrite) NSString *selectionModuleIdentifier;
@property (nonatomic, copy, readwrite) NSString *selectionPresentationStyle;
@property (nonatomic, copy, readwrite) NSString *selectionTargetIdentifier;
@property (nonatomic, assign) MediaViewControllerMode mediaViewControllerMode;
@property (nonatomic, strong) PSShoppingCatalog *shoppingCatalog;
@property (nonatomic, strong) PSShoppingCategory *shoppingCategory;
@end
