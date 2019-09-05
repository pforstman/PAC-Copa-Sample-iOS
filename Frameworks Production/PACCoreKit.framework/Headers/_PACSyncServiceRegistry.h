/** @module PACCoreKit.framework *///
//  PACSyncServiceRegistry.h
//  syncclient
//
//  Created by Tom Stamm (MLS) on 12/4/17.
//  Copyright © 2017 Rawad Hilal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "_PACSyncServiceRemoteAdapterProtocol.h"

@interface _PACSyncServiceRegistry : NSObject

@property (strong, nonatomic) NSMutableArray<NSObject<_PACSyncServiceRemoteAdapterProtocol>*> *services;

+(_PACSyncServiceRegistry *) sharedInstance;

-(void) registerService:(NSObject<_PACSyncServiceRemoteAdapterProtocol> *) service;
-(NSArray<NSObject<_PACSyncServiceRemoteAdapterProtocol>*> *)registeredServices;

@end
