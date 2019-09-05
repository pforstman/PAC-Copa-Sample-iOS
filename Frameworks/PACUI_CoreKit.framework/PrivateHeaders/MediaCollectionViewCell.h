//
//  MediaCollectionViewCell.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/5/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "BaseMediaCollectionViewCell.h"
#import "PSMedia.h"
#import "PanaSkyImageView.h"

#define kMediaCollectionViewCellIdentifier @"MediaCollectionViewCellID"

@interface MediaCollectionViewCell : BaseMediaCollectionViewCell
@property (nonatomic, weak) IBOutlet PanaSkyImageView *imageView;
@property (nonatomic, weak) IBOutlet UILabel *titleLabel;
@property (nonatomic, weak) IBOutlet UILabel *subtitleLabel;
@property (nonatomic, weak) IBOutlet UIImageView *favoriteImage;
@property (nonatomic, assign) BOOL isKidsMode;
@end
