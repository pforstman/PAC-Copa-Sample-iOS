/** @module PACCoreKit.framework *///
//  UITableView+PACCoreKit.h
//  PACCoreKit
//
//  Created by Gary L. Wade (MLS Technologies) on 03/04/2016.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableView (PACCoreKit)

-(UITableViewCell* )pac_prototypeOfCellWithReuseIdentifier:(NSString* )identifier;

@end
