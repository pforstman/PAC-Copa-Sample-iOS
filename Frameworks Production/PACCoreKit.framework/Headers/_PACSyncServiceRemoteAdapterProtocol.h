/** @module PACCoreKit.framework *///
//  PACSyncServiceRemoteAdapterProtocol.h
//  syncclient
//
//  Created by Tom Stamm (MLS) on 12/4/17.
//  Copyright © 2017 Rawad Hilal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "_PACSyncTransaction.h"

@protocol _PACSyncServiceRemoteAdapterProtocol
@required

/**
 * This callback is used by the engine to pull changes from remote server.
 * @param last_transaction_id Last synced transaction id.
 * @param transactions The array of transactions that will be populated.
  * @return SYNC_CLIENT_REMOTE_ADAPTER_SUCCESS on success. Possible error codes: SYNC_CLIENT_REMOTE_ADAPTER_CONNECTION_ERROR, SYNC_CLIENT_REMOTE_ADAPTER_TID_NOT_FOUND.
 */
-(int) pull:(NSString *)last_transaction_id count:(NSUInteger)count transactions:(NSMutableArray<_PACSyncTransaction *> *)transactions head:(NSString **)head_id tail:(NSString **)tail_id hasMoreTransactions:(NSNumber**)hasMoreTransactions forGroupName:(NSString*)groupName;

/**
 * This callback is used by the engine to pull snapshot from remote server.
 * @param snapshot The snapshot object that will be populated with what's is returned from the server.
 * @return SYNC_CLIENT_REMOTE_ADAPTER_SUCCESS on success. Possible error codes: SYNC_CLIENT_REMOTE_ADAPTER_CONNECTION_ERROR.
 */
-(int) pullSnapshot:(NSString **)snapshot forGroupName:(NSString*)groupName;

/**
 * This callback is used by the engine to push local changes to remote server.
 * @param transactions The array of transactions that will be pushed to remote server.
 * @return SYNC_CLIENT_REMOTE_ADAPTER_SUCCESS on success. Possible error codes: SYNC_CLIENT_REMOTE_ADAPTER_CONNECTION_ERROR, SYNC_CLIENT_REMOTE_ADAPTER_NEED_PULL.
 */
-(int) push:(NSArray<_PACSyncTransaction *> *)transactions forGroupName:(NSString*)groupName;

/**
 * This callback is used by the engine to push local snapshot to remote server. NOT_USED
 * @param snapshot The snapshot object that will be pushed to the server.
 * @param tailId The tail id that last modified the provided snapshot.
 * @return SYNC_CLIENT_REMOTE_ADAPTER_SUCCESS on success. Possible error codes: SYNC_CLIENT_REMOTE_ADAPTER_CONNECTION_ERROR.
 */
-(int) pushSnapshot:(NSString *)snapshot withTailId:(NSString*)tailId forGroupName:(NSString*)groupName;

/**
 * This callback is used by the engine to check whether remote server is available.
 * @return YES if available. NO otherwise.
 */
-(BOOL) isAvaliable;

/**
 * This callback is used by the engine to check the priority of the remote server in case multiple exist.
 *
 * Higher priority has larger number.
 * @return priority of remote server.
 */
-(int) getPriority;

/**
 * This callback is used by the engine to check if the remote transactions came from a reliable source. Ex. Ground
 *
 * @return YES if reliable. NO otherwise.
 */
-(BOOL) isReliable;

@optional
// No optionals yet.
@end

