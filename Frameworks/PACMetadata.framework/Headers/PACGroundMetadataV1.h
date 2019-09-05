/** @module PACMetadata.framework *///
//  PACGroundMetadataV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACMetadata/PACMetadata.h>

/**
 PACGroundMetadataV1 is a class used to initialize request objects. PACGroundMetadataV1 requests include a category list, media list, child media list, and media metadata requests.
 
 Example
 
        //Categories list contains all categories and subcategories in the metadata
        //Media list contains all medias under a specific category
        //Media children contains all children medias (i.e. TV episodes) under a media
        //Media metadata contains all metadata info for a media
        //Media image contains synopsis or album image for a media

        //InFlight service object for metadata
        PACGroundMetadataV1 *groundMetadataV1 = nil;
        //request object to start and stop the metadata request
        id <MetadataV1Request> _request;

        NSMutableArray *_categoryList = ...;
        UITableView *_tableView = ...;

        //to initialize a category list request, you can
        - (void) initialize(){
            // Initialize the service.
            [PACGroundMetadataV1 initServiceWithCompletionBlock:^(id object, NSError *error) {
                if (error != nil) {
                    NSLog(@"Failed to initialize service PACGroundMetadataV1. Reason: %@",error);
                    return;
                }
                self.groundMetadataV1 = serviceObject;
                
                // Set Flight Parameters
                [self.groundMetadataV1 setFlightParameters:@{PACGroundMetadataFlightParameterFlightNumber:@"123",
                                                        PACGroundMetadataFlightParameterTravelDate:@"20160121"}];
 
                [self refresh];
            }];
        }

        //refreshs contents of a table view that displays English title of all categories
        - (void)refresh{
            [_categoryList removeAllObjects];
            //request not initialized, so initialize it first.
            if (!_request) {
                __weak typeof(self) weakSelf = self;
                //request to get all categories and start the request immediately
                _request = [groundMetadataV1 requestCategoriesListWithCompletionHandler:^(id object, NSError *error) {
                    if (!error) {
                        //the response object is an array because requestCategoriesList requests for a list of categories
                        //the response object type may differ for other type of requests
                        NSArray *response = (NSArray *)object;
                        //the following may vary depending on the server response.
                        for (int i=0; i<response.count; i++) {
                            NSDictionary *category = [response objectAtIndex:i];
                            [weakSelf.categoryList addObject:category[@"title"][@"eng"]];
                        }
                        [weakSelf.tableView reloadData];
                    }
                }];
            }
            else{
                //request already initialized so reuse the object.
                [_request start];
            }
        }

        //cancels the request that was made when refreshing
        -(void)cancelRequest{
            [_request stop];
        }


 Issues with Strong References in blocks
 
        // It is best avoid strong reference to self in a block.
        // If the request is cancelled and the retained instance object self.metadataRequest was not cleared,
        // there will be a circular reference which leads to the image view and the request
        // instance not to be freed from memory.

        __weak typeof(self) weakSelf = self;
        self.metadataRequest = [self.metadataV1 requestMediaImageWithImageURL:self.imageURL completionHandler:^(id object, NSError *error) {
            if (!error) {
                // Verify called on main thread
                dispatch_async(dispatch_get_main_queue(), ^{
                    [weakSelf setAlpha:0.0f];
                    [weakSelf setImage:object];
                    [UIView animateWithDuration:0.25 animations:^{
                        [weakSelf setAlpha:1.0f];
                    }];
                });
            }
        }];
 
  @available Ground 03.00.00.00 1
 */
@interface PACGroundMetadataV1 : PACMetadataV1

/**
 * Selects the flight that the metadata requests will query information for.
 *
 * This function must be called prior to any PACGroundMetadataV1 request.
 * @param parameters The flight parameters of the particular flight. Please refer to GroundMetadataFlightParameter section.
 */
- (void)setFlightParameters:(NSDictionary *)parameters;

@end

/**
 * @constantgroup PACGroundMetadataFlightParameter
 * These are the keys for the possible flight parameters used in [GroundMetadataV1 setFlightParameters:]
 *
 * @owner PACGroundMetadataV1
 */

/**
 * The date of travel of the particular flight. 
 *
 * The value for this key should be either of type string with date being in the following format 'yyyymmdd' or a NSDate object.
 */
extern NSString *const PACGroundMetadataFlightParameterTravelDate;

/**
 * The origin of the flight. It is case-insensitive 3 letter IATA code. I.e. "LAX", "jfk"
 */
extern NSString *const PACGroundMetadataFlightParameterOrigin;

/**
 * The destination of the flight. It is case-insensitive 3 letter IATA code. I.e. "LAX", "jfk"
 */
extern NSString *const PACGroundMetadataFlightParameterDestination;

/**
 * The aircraft's tail number.
 */
extern NSString *const PACGroundMetadataFlightParameterAircraftTailNumber;

/**
 * The aircraft type. For example, 747.
 */
extern NSString *const PACGroundMetadataFlightParameterAircraftType;

/**
 * The aircraft sub type. For example 400
 */
extern NSString *const PACGroundMetadataFlightParameterAircraftSubType;

/**
 * The flight number.
 */
extern NSString *const PACGroundMetadataFlightParameterFlightNumber;
