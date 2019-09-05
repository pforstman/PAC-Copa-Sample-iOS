//
//  FlightStatusView.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 9/12/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSInteger {
    FlightStatusStyleModeDefault = 0,
    FlightStatusStyleModePlayer,
    FlightStatusStyleModeGround
} FlightStatusStyleMode;

@interface FlightStatusView : UIView

@property (nonatomic, copy, readwrite) NSString *targetIdentifier;
@property (nonatomic, assign) FlightStatusStyleMode styleMode;
@property (nonatomic, weak) IBOutlet UIButton *currentPositionButton;
@property (nonatomic, strong) NSString *flightIconImageName;

+ (instancetype)viewFromNib;

- (void)refreshFlightStatus;

@end

@interface PSAccessibilityButton : UIButton

@end
