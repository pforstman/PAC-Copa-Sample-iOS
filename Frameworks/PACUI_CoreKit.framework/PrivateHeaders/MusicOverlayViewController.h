//
//  MusicOverlayViewController.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/14/15.
//  Copyright (c) 2015 Mercury. All rights reserved.
//

#import "BaseOverlayViewController.h"
@class PSMedia;

typedef enum {
    MusicOverlayModeNormal = 0,
    MusicOverlayModeKidsZone = 1,
} MusicOverlayMode;

@interface MusicOverlayViewController : BaseOverlayViewController <AdaptiveController>
@property (nonatomic, strong, readwrite) PSMedia *album;
@property (nonatomic, strong) NSArray *submodules;
@property (nonatomic, assign) MusicOverlayMode musicOverlayMode;
@end
