//
//  BaseMediaCollectionViewCell.h
//  PanaSkyKit-iOS
//
//  Created by Paul Forstman on 3/31/15.
//  Copyright (c) 2015 Mercury. All rights reserved.
//

#import "PSMedia.h"
#import "CollectionViewHighlightCell.h"

@interface BaseMediaCollectionViewCell : CollectionViewHighlightCell
@property (nonatomic, strong) PSMedia *media;
@property (nonatomic, assign) BOOL isFavoritesMode;
@end
