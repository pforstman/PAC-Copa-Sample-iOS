/** @module PACCoreKit.framework *///
//  _PACSyncTransaction.h
//  SeatPairing
//
//  Created by Jeff Chen (MLS Technologies) on 12/5/17.
//  Copyright © 2017 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface _PACSyncTransaction : NSObject

-(void) setTransactionId:(NSString*) transaction_id;


-(NSString*) getTransactionId;

-(void) setParentTransactionId:(NSString*) transaction_id;


-(NSString*) getParentTransactionId;


-(void) setAuthorTimestamp:(NSNumber*)timestamp;


-(NSNumber*) getAuthorTimestamp;


-(void) setTarget:(NSString*) target;


-(NSString*) getTarget;


-(void) setCommand:(NSString*) command;


-(NSString*) getCommand;


-(void) setCommandArgs:(NSString*) command_args;


-(NSString*) getCommandArgs;


@end
