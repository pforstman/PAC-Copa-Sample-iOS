//
//  PSShoppingItem.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 6/19/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

@import MantleTouch;

@interface PSShoppingItem : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy, readwrite) NSArray *category_ids;
@property (nonatomic, copy, readwrite) NSDictionary *media_description;
@property (nonatomic, copy, readwrite) NSString *item_id;
@property (nonatomic, copy, readwrite) NSDictionary *image;
@property (nonatomic, copy, readwrite) NSString *item_type;
@property (nonatomic, copy, readwrite) NSDictionary *price;
@property (nonatomic, copy, readwrite) NSString *sku;
@property (nonatomic, copy, readwrite) NSDictionary *title;

- (NSString *)getLocalizedDescription;
- (NSString *)getLocalizedTitle;
- (NSString *)getImageURLForWidth:(CGFloat)width;
- (NSString *)getFormattedPrice;

@end
