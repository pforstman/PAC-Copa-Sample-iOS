//
//  MainMenuViewController.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 8/18/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MainMenuViewControllerDelegate <NSObject>

@required
- (NSUInteger)itemSelectedAtIndex:(NSInteger)selectedIndex;

@end

@interface MainMenuViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UIScrollViewDelegate>

@property (nonatomic, assign) id<MainMenuViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet UIImageView *logoSmallImage;
@property (nonatomic, weak) IBOutlet UILabel *passengerNameLabel;
@property (nonatomic, weak) IBOutlet UIView *seatPairingView;
@property (nonatomic, weak) IBOutlet UITableView *tableView;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *seatPairingViewBottomConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *seatPairingViewHeightConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *logoImageViewHeightConstraint;

@property (nonatomic, strong) NSArray *activeSubmodules;
@property (nonatomic, assign) BOOL showPassengerInfo;

@end
