//
//  PSShoppingCatalog.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 6/21/17.
//  Copyright © 2017 Mercury. All rights reserved.
//

@import MantleTouch;

@interface PSShoppingCatalog : MTLModel <MTLJSONSerializing>

@property (nonatomic, copy, readwrite) NSDictionary *media_description;
@property (nonatomic, copy, readwrite) NSString *catalog_id;
@property (nonatomic, copy, readwrite) NSDictionary *image;
@property (nonatomic, copy, readwrite) NSDictionary *title;
@property (nonatomic, copy, readwrite) NSString *cellType;

- (NSString *)getLocalizedTitle;

@end
