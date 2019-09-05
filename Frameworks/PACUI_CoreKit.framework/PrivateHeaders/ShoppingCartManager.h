//
//  ShoppingCartManager.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 6/27/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

@class PSMedia;
@class PSShoppingItem;

@interface ShoppingCartManager : NSObject

@property (nonatomic, strong) NSMutableArray *savedForLaterItems;

+ (ShoppingCartManager *)sharedShoppingCartManager;
- (void)saveItemForLater:(PSShoppingItem *)shoppingItem;
- (BOOL)isSavedForLater:(PSShoppingItem *)shoppingItem;
- (void)removeSavedForLaterItem:(PSShoppingItem *)shoppingItem;
- (void)removeAllSavedForLaterItems;
- (UIImage *)checkmarkCornerIcon;

@end
