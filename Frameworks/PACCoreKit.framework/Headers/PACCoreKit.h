/** @module PACCoreKit.framework *///
//  PACCoreKit.h
//  PACCoreKit
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#ifndef PACCoreKit_h
#define PACCoreKit_h

#import <UIKit/UIKit.h>

#import <PACCoreKit/Version.h>

// Base objects
#import <PACCoreKit/InFlight.h>
#import <PACCoreKit/InFlightService.h>

// Price
#import <PACCoreKit/PACPrice.h>

// Service Discovery
#import <PACCoreKit/PACServiceDiscoveryV1.h>
#import <PACCoreKit/PACServiceDiscoveryService.h>

// System
#import <PACCoreKit/PACSystemV1.h>

// System Services
#import <PACCoreKit/PACSystemServiceV1.h>

// Helper Categories
#import <PACCoreKit/NSArray+kindOfClass.h>
#import <PACCoreKit/NSBundle+name.h>
#import <PACCoreKit/NSDictionary+kindOfClass.h>
#import <PACCoreKit/UIColor+PACCoreKit.h>
#import <PACCoreKit/UINavigationController+PACCoreKit.h>
#import <PACCoreKit/UINavigationItem+PACCoreKit.h>
#import <PACCoreKit/UIResponder+PACCoreKit.h>
#import <PACCoreKit/UIScrollView+PACCoreKit.h>
#import <PACCoreKit/UITableView+PACCoreKit.h>
#import <PACCoreKit/UITableViewCell+PACCoreKit.h>
#import <PACCoreKit/UIViewController+PACCoreKit.h>
#import <PACCoreKit/UIView+PACCoreKit.h>
#import <PACCoreKit/NSJSONSerialization+PACCoreKit.h>
#import <PACCoreKit/UIImageView+PACCoreKit.h>
#import <PACCoreKit/NSNumber+PACCoreKit.h>
#import <PACCoreKit/NSNumberFormatter+PACCoreKit.h>
#import <PACCoreKit/NSString+SoftHyphenation.h>
#import <PACCoreKit/NSDate+PACCoreKit.h>
#import <PACCoreKit/NSTimeZone+PACCoreKit.h>
#import <PACCoreKit/NSURL+PACCoreKit.h>

// Utilities
#import <PACCoreKit/PACBezierPathView.h>
#import <PACCoreKit/PACUITableViewCellStyleSubtitleCell.h>

// Speed
#import <PACCoreKit/PACSpeed.h>

// Distance
#import <PACCoreKit/PACDistance.h>
#import <PACCoreKit/PACCoordinate.h>
#import <PACCoreKit/PACTemperature.h>

// Bookmark
#import <PACCoreKit/PACMediaBookmark.h>

// sync client
#import <PACCoreKit/_PACSyncServiceRemoteAdapterProtocol.h>
#import <PACCoreKit/_PACSyncServiceRegistry.h>
#import <PACCoreKit/_PACSyncTransaction.h>

// language unit
#import <PACCoreKit/PACLocalizedItem.h>

#endif /* CoreKit_h */
