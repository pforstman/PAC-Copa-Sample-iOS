//
//  PSShoppingCategory.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 6/15/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

//#import <MantleTouch/MantleTouch.h>

@import MantleTouch;

@interface PSShoppingCategory : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy, readwrite) NSDictionary *media_description;
@property (nonatomic, copy, readwrite) NSString *category_id;
@property (nonatomic, copy, readwrite) NSDictionary *image;
@property (nonatomic, copy, readwrite) NSString *parent_category_id;
@property (nonatomic, copy, readwrite) NSArray *sub_category_ids;
@property (nonatomic, copy, readwrite) NSDictionary *title;
@property (nonatomic, copy, readwrite) NSString *cellType;

- (NSString *)getLocalizedTitle;

@end
