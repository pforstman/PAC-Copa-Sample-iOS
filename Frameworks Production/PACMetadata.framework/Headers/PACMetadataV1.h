/** @module PACMetadata.framework *///
//  PACMetadataV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2014 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 * The return code of a PACMetadataV1Request start api call.
 * @owner PACMetadataV1Request
 */
typedef enum PACMetadataV1RequestReturnCode{
    /** Request started successfully. */
    PACMetadataV1RequestStarted,
    /** Request failed to start because it is already running. */
    PACMetadataV1RequestFailedReasonAlreadyStarted
}PACMetadataV1RequestReturnCode;

/**
 * Request object that implements the start and stop functions
 */
@protocol PACMetadataV1Request <NSObject>

/**
 * Starts the request.
 * @return Returns PACMetadataV1RequestReturnCode. See PACMetadataV1RequestReturnCode for possible results.
 */
- (PACMetadataV1RequestReturnCode)start;

/**
 * Cancels the request.
 */
- (void)stop;

/**
 * Returns the operation queue in which the completion block will be called upon.
 * The default queue is the main operation queue.
 * @return The queue that will execute the completion block.
 */
- (NSOperationQueue *)operationQueue;

/**
  Sets the operation queue in which the completion block will be called upon.

  This call must be made after initializing request with startImmediately set to NO.
  And this call must be made before calling start on the initialized request.
  If not set or set to nil, the main operation queue will be used.

        PACMetadataV1 *metadataV1 = …;
        UITableView *tableView = …;
        id <<MetadataV1Request>> request;
        NSOperationQueue *otherQueue = ...;
        -(void)viewDidLoad{
            [super viewDidLoad];
            request = [metadataV1 initializeCategoriesListRequestWithCompletionHandler:^(id object, NSError *error) {
                .
                .
                .
            } startImmediately:NO]; // Do not start immediately
            
            // Completion block will be executed on another NSOperationQueue, not the main operation queue.
            [request setOperationQueue:self.otherQueue];
        }

        -(void)refresh{
            // Start request
            [request start];
        }

        -(void)cancelRequest{
            [request stop];
        }
 
 @param queue The queue that will execute the completion block.
 */
- (void)setOperationQueue:(NSOperationQueue *)queue;

/**
 * Set the filters for the metadata request that are defined by the PACMetadataFieldKeys.
 * @param predicates The key-value pair for the filter fields. Please refer to the PACMetadataFieldKeys in PACMetadataV1.
 */
- (void)setPredicates:(NSDictionary *)predicates;

/**
 * Returns the specified filters for the metadata request.
 * @return The key-value pair for the filter fields. Please refer to the PACMetadataFieldKeys in PACMetadataV1.
 */
- (NSDictionary *)predicates;

@end

/**
 PACMetadataV1 allows developers to extract a media library from the system. Developers  can define the hierarchical structure as tree or flat. The media library is returned by media categories and sub-categories specific to individual airlines. <br><br>   
 The response contains information about the content, such as the category ID, title, description, images, subcategories and media URIs. The media URI is the identifier for the media. 

[Download Sample Project](../../samples/PACMetadata/SampleMetadataApplication.zip)
 
 Example
 
        //Categories contains all categories and subcategories in the metadata
        //Media list contains all medias under a specific category
        //Media children contains all children medias, such as TV episodes, under a media
        //Media metadata contains all metadata information for a media
        //Media image contains synopsis or album image for a media

        //InFlight service object for metadata
        PACMetadataV1 *metadataV1 = nil;
        //request object to start and stop the metadata request
        id <<MetadataV1Request>> _request;

        NSMutableArray *_categoryList = ...;
        UITableView *_tableView = ...;

        //to initialize a category list request, you can
        - (void) initialize(){
            [PACMetadataV1 initServiceWithCompletionBlock:^(id serviceObject, NSError *error) {
                if (error != nil) {
                    NSLog(@"Failed to initialize service PACMetadataV1. Reason: %@",error);
                    return;
                }
                self.metadataV1 = serviceObject;

                [self refresh];
            }];
        }

        //refresh contents of a table view that displays English title of all categories
        - (void)refresh{
            [_categoryList removeAllObjects];
            //request not initialized, so initialize it first.
            if (!_request) {
                //request to get all categories and start the request immediately
                _request = [metadataV1 requestCategoriesListWithCompletionHandler:^(id object, NSError *error) {
                    if (!error) {
                        //the response object is an array because requestCategoriesList requests for a list of categories
                        //the response object type may differ for other type of requests
                        NSArray *response = (NSArray *)object;
                        //the following may vary depending on the server response.
                        for (int i=0; i<response.count; i++) {
                            NSDictionary *category = [response objectAtIndex:i];
                            [_categoryList addObject:category[@"title"][@"eng"]];
                        }
                        [_tableView reloadData];
                    }
                }];
            }
            else{
                //request already initialized so reuse the object.
                [_request start];
            }
        }

        //cancel the request.
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
 */

@interface PACMetadataV1 : InFlightService

/**
  PACMetadataV1 completion block
  @param object The response object from the server. It can be either a NSDictionary, a NSArray, or an UIImage depending on the request.
  @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACMetadataV1CompletionHandler)(id object,NSError *error);

/**
 Initialize and start a category list request.
 
 The function initializes a category list request which will return the list of
 all categories and child categories. The request will start automatically upon initialization. If you wish not to start it automatically please use the
 [MetadataV1 requestCategoriesListWithCompletionHandler:startImmediately:] function.
 
 <br><br><b>Note</b><br>
 You can apply a seat class filter, such as first class, to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.
 
         _request = [metadataV1 requestCategoriesListWithCompletionHandler:^(id object, NSError *error) {
            if (!error) {
                //the response object is an array of categories and subcategories
                NSArray *response = (NSArray *)object;
                for (int i=0; i<response.count; i++) {
                    NSDictionary *category = [response objectAtIndex:i];
                    
                    //retrieve category title in English
                    NSString *title = category[@"title"][@"eng"];
                    
                    //retrieve category description in English
                    NSString *description = category[@"description"][@"eng"];
                    
                    //retrieve category poster URL
                    NSString *posterURL = category[@"poster_url"][@"size_1"];
                    
                    //retrieve category id
                    NSString *id = category[@"id"];
                    
                    //retrieve subcategory ids, if any
                    NSArray *subcategoryIDs = category[@"subcategory_ids"];
                    
                    //retrieve other attributes, based on need
                }
            }
        }];
 
 Sample response:
 
     [
       {
          "description" : {
             "eng" : "",
             "jpn" : "",
             "kor" : ""
          },
          "id" : "100",
          "images" : [],
          "media_uris" : [],
          "parent_id" : "-1",
          "poster_url" : {  // Deprecated; Use "images"
             "size_4" : "<image_url>"
          },
          "short_description" : {},
          "subcategory_ids" : [
             "101",
             "102"
          ],
          "synopsis_url" : {},  // Deprecated; Use "images"
          "title" : {
             "eng" : "Watch Movies",
             "jpn" : "映画を見る",
             "kor" : "영화"
          }
       },
       {
          "description" : {
             "eng" : ""
          },
          "id" : "101",
          "images" : [],
          "media_uris" : [
             "310452",
             "307919",
             "310464",
             "307920",
             "310338",
             "307924",
             "310495",
             "307925",
             "307927"
          ],
          "parent_id" : "100",
          "poster_url" : {},    // Deprecated; Use "images"
          "short_description" : {},
          "subcategory_ids" : [],
          "synopsis_url" : {},  // Deprecated; Use "images"
          "title" : {
             "eng" : "New Releases"
          }
       },
       {..},
       ..
    ]
 
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data

 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestCategoriesListWithCompletionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initialize a category list request. The function initializes a category list request which will return the list of all categories and child categories.
 * <br><br><b>Note</b><br>
 * You can apply a seat class filter, such as first class, to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data.
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestCategoriesListWithCompletionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;


/**
  Initialize and start a category list request. 
 
  The function initializes a category list request which will return the list of
  categories and child categories within the root category ID. The request will start automatically upon initialization. If you wish not to start it automatically please use the
  [MetadataV1 requestCategoriesListWithRootCategory:completionHandler:startImmediately:] function.
  <br><br><b>Note</b><br>
  You can apply a seat class filter to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.

        _request = [metadataV1 requestCategoriesListWithRootCategory:PACMetadataRootCategoryMovies
                                                   completionHandler:^(id object, NSError *error) {
            if (!error) {
                //the response object is an array of categories and subcategories
                NSArray *response = (NSArray *)object;
                for (int i=0; i<response.count; i++) {
                    NSDictionary *category = [response objectAtIndex:i];
                    
                    //retrieve category title in English
                    NSString *title = category[@"title"][@"eng"];
                    
                    //retrieve category description in English
                    NSString *description = category[@"description"][@"eng"];
                    
                    //retrieve category poster URL
                    NSString *posterURL = category[@"poster_url"][@"size_1"];
                    
                    //retrieve category ID
                    NSString *id = category[@"id"];
                    
                    //retrieve subcategory ids, if any
                    NSArray *subcategoryIDs = category[@"subcategory_ids"];
                    
                    //retrieve other attributes based on need
                }
            }
        }];
 
 @param rootCategory The root category. Please see PACMetadataRootCategories for values.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data.
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
  @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestCategoriesListWithRootCategory:(NSString *)rootCategory
                                              completionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initializes a category list request. 
 *
 * The function initializes a category list request which will return the list of
 * categories and child categories within a root category ID.
 * <br><br><b>Note</b><br>
 * You can apply a seat class filter to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.
 * @param rootCategory The root category. Please see PACMetadataRootCategories for values.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data.
 *
 *- *object* The response object.
 *- *error* The error object if an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestCategoriesListWithRootCategory:(NSString *)rootCategory
                                              completionHandler:(PACMetadataV1CompletionHandler)completion
                                               startImmediately:(BOOL)start;

/**
  Initializes and start a media list request.
 
  The function initializes a media list request which will return the list of all medias associated with the category.
  The request will start automatically upon initialization. If you wish not to start it automatically, please use the
  [MetadataV1 requestMediaListWithCategoryID:completionHandler:startImmediately:] function.
  <br><br><b>Note</b><br>
  You can apply a seat class filter to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.

        _request = [metadataV1 requestMediaListWithCategoryID:@"100" completionHandler:^(id object, NSError *error) {
            if (!error) {
                //the response object is an array of media infos
                NSArray *response = (NSArray *)object;
                for (int i=0; i<response.count; i++) {
                    NSDictionary *media = [response objectAtIndex:i];
                    
                    //retrieve media title in English
                    NSString *title = media[@"title"][@"eng"];
                    
                    //retrieve media genre in English
                    NSString *genre = media[@"genre"][@"eng"];
                    
                    //retrieve media poster URL
                    NSString *posterURL = media[@"poster_url"][@"size_1"];
                    
                    //retrieve media URI
                    NSString *mediaURI = media[@"media_uri"];
                    
                    //retrieve other attributes based on need
                }
            }
        }];
 
 Sample response:
 
     [
       {
          "artist" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "childMediaCount" : 0,
          "content_type" : "tvepisode",
          "copyright" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "description" : {
             "eng" : "Don't miss the highlights from this year's show, which features the biggest stars and cars of F1 and BTCC, as well as bikes and a host of motorsport glitterati.",
             "sch" : "别错过今年的精点推介，包括巨星及名车云集的F1及英国房车赛，以及摩托车及连串的汽车巨擘的表演。",
             "tch" : "別錯過今年的精點推介，包括巨星及名車雲集的F1及英國房車賽，以及摩托車及連串的汽車巨擘的表演。"
          },
          "duration" : "00:45:00",
          "genre" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "global_uri" : "",
          "images" : {
             "1_1" : {
                "height" : "",
                "src" : "<image_url>",
                "width" : ""
             },
             "1_5" : {
                "height" : "",
                "src" : "<image_url>",
                "width" : ""
             },
             "2_1" : {
                "height" : "",
                "src" : "<image_url>",
                "width" : ""
             }
          },
          "key_type" : 8,
          "media_uri" : "323815",
          "parent_media_uri" : "316720",
          "poster_url" : {  // Deprecated; Use "images"
             "size_4" : "<image_url>"
          },
          "rating" : "215",
          "rating_description" : "Not Rated",
          "short_description" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "short_title" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "soundtracks" : [
             {
                "language_code" : "49",
                "language_iso" : "eng",
                "language_name" : {
                   "eng" : "english",
                   "fre" : "anglais",
                   "ger" : "englisch",
                   "jpn" : "英語",
                   "kor" : "영어",
                   "sch" : "英语",
                   "tch" : "英語"
                }
             }
          ],
          "subtitles" : [
             {
                "language_code" : "0",
                "language_iso" : "tch",
                "language_name" : {
                   "eng" : "t chinese",
                   "fre" : "chinois traditionnel",
                   "ger" : "traditionelles chinesisch",
                   "jpn" : "繁体中国語",
                   "kor" : "중문번체",
                   "sch" : "繁体中文",
                   "tch" : "繁體中文"
                }
             }
          ],
          "synopsis_url" : {    // Deprecated; Use "images"
             "size_4" : "<image_url>"
          },
          "title" : {
             "eng" : "Goodwood Festival of Speed",
             "sch" : "Goodwood Festival of Speed",
             "tch" : "Goodwood Festival of Speed"
          },
          "type" : "video",
          "year" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          }
       }
    ]
 
 @param catid The category ID to be used to query the request.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data 
 @return Returns the request object.
 
 - *object* The response object.
 - *error* The error object if an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaListWithCategoryID:(NSString *)catid completionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initializes a media list request. 
 *
 * The function initializes a media list request which will return the list of all medias associated with the category.
 * <br><br><b>Note</b><br>
 * You can apply a seat class filter to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.
 * @param catid The category ID to be used to query the request.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object if an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaListWithCategoryID:(NSString *)catid completionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;

/**
 Initializes and start a media list request.
 
 The function initializes a media list request which will return the list of all medias associated with each category.
 The request will start automatically upon initialization. If you wish not to start it automatically, please use the
 [MetadataV1 requestMediaListWithCategoryIDs:completionHandler:startImmediately:] function.
 <br><br><b>Note</b><br>
 You can apply a seat class filter to this request by setting the predicates property of the PACMetadataV1Request object. The key to set that filter is PACMetadataFieldSeatClassKey.

        _request = [metadataV1 requestMediaListWithCategoryIDs:@[@"1", @"2", @"3"] completionHandler:^(id object, NSError *error) {
            if (!error) {
 
                NSDictionary *response = (NSDictionary *)object;
                // get all data elements
                NSArray *dataElements = object[@"data"];
                // loop through data elements
                for (NSDictionary *element in dataElements) {
                    // retrieve category id for element
                    NSString *categoryId = element[@"category_id"];
                    // retrieve items for category.
                    NSArray *items = element[@"items"];
                    for (int i=0; i<items.count; i++) {
                        NSDictionary *media = [items objectAtIndex:i];
                        
                        //retrieve media title in English
                        NSString *title = media[@"title"][@"eng"];
                        
                        //retrieve media genre in English
                        NSString *genre = media[@"genre"][@"eng"];
                        
                        //retrieve media poster URL
                        NSString *posterURL = media[@"poster_url"][@"size_1"];
                        
                        //retrieve media URI
                        NSString *mediaURI = media[@"media_uri"];
                        
                        //retrieve other attributes based on need
                    }
                }
            }
        }];
 
 Sample Response:
 
         {
          "data": [
            {
              "category_id": 1,
              "total_count": 5,
              "items": [
                {
                  "media_uri": "77678",
                  "title": {
                    "eng": "#Entertainment Highlights"
                  },
                  ...
                },
                {
                  "media_uri": "78473",
                  "title": {
                    "eng": "St. Vincent"
                  },
                  ...
                }
              ]
            },
            {
              "category_id": 2,
              "total_count": 6,
              "items": [
                {
                  "media_uri": "77679",
                  "title": {
                    "eng": "Mike & Molly: Season 4"
                  },
                  ...
                },
                {
                  "media_uri": "78463",
                  "title": {
                    "eng": "4 Kings"
                  },
                  ...
                }
              ]
            }
          ],
          "error": [
            {
              "category_id": "3",
              "code": 404,
              "text": "Not found"
            }
          ]
        }
 
  @param catids The category IDs to be used to query the request.
  @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data
  @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaListWithCategoryIDs:(NSArray<NSString *> *)catids completionHandler:(PACMetadataV1CompletionHandler)completion;


/**
 Initializes a media list request.
 The function initializes a media list request which will return the list of all medias associated with each category.
 
 @param catids The category ID to be used to query the request.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaListWithCategoryIDs:(NSArray<NSString *> *)catids completionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;


/**
 Initializes and start a child media list request.

 The function initializes a child media list request which will return the list of all the child medias associated with the parent media.
 The request will start automatically upon initialization. To stop the request from automatically starting, please use the
 [MetadataV1 requestChildMediaWithParentURI:completionHandler:startImmediately:] function.

        _request = [metadataV1 requestChildMediaWithParentURI:@"501" completionHandler:^(id object, NSError *error) {
            if (!error) {
                //the response object is an array of child media infos, such as TV episodes
                NSArray *response = (NSArray *)object;
                for (int i=0; i<response.count; i++) {
                    NSDictionary *child = [response objectAtIndex:i];
                    
                    //retrieve media title in English
                    NSString *title = child[@"title"][@"eng"];
                    
                    //retrieve short description
                    NSString *shortDescription = child[@"short_description"];
                    
                    //retrieve media URI
                    NSString *mediaURI = child[@"media_uri"];
                    
                    //retrieve other attributes based on need
                }
            }
        }];
 
 Sample response:
 
     [
       {
          "artist" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "childMediaCount" : 0,
          "content_type" : "tvepisode",
          "copyright" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "description" : {
             "eng" : "Mixing together behind-the-scenes footage from professional tours and interviews, with destination reviews, lifestyle features and tips to improve your game.",
             "sch" : "包罗高球界的职业赛事片段、球手访问和挥杆心得及秘诀。",
             "tch" : "包羅高球界的職業賽事片段、球手訪問和揮杆心得及秘訣。"
          },
          "duration" : "00:29:00",
          "genre" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "global_uri" : "",
          "images" : {
             "1_1" : {
                "height" : "",
                "src" : "<image_url>",
                "width" : ""
             },
             "1_5" : {
                "height" : "",
                "src" : "<image_url>",
                "width" : ""
             }
          },
          "key_type" : 8,
          "media_uri" : "323812",
          "parent_media_uri" : "316719",
          "poster_url" : {  // Deprecated; Use "images"
             "size_4" : "<image_url>"
          },
          "rating" : "215",
          "rating_description" : "Not Rated",
          "short_description" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "short_title" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          },
          "soundtracks" : [
             {
                "language_code" : "49",
                "language_iso" : "eng",
                "language_name" : {
                   "eng" : "english",
                   "fre" : "anglais",
                   "ger" : "englisch",
                   "jpn" : "英語",
                   "kor" : "영어",
                   "sch" : "英语",
                   "tch" : "英語"
                }
             }
          ],
          "subtitles" : [
             {
                "language_code" : "0",
                "language_iso" : "tch",
                "language_name" : {
                   "eng" : "t chinese",
                   "fre" : "chinois traditionnel",
                   "ger" : "traditionelles chinesisch",
                   "jpn" : "繁体中国語",
                   "kor" : "중문번체",
                   "sch" : "繁体中文",
                   "tch" : "繁體中文"
                }
             }
          ],
          "synopsis_url" : {    // Deprecated; Use "images"
             "size_4" : "<image_url>"
          },
          "title" : {
             "eng" : "HSBC Golfing World #54",
             "sch" : "HSBC Golfing World 第54集",
             "tch" : "HSBC Golfing World 第54集"
          },
          "type" : "video",
          "year" : {
             "eng" : "",
             "sch" : "",
             "tch" : ""
          }
       }
    ]
 
 @param mediaURI The media URI to be used to query the request.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data.
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestChildMediaWithParentURI:(NSString *)mediaURI completionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initializes a child media list request. 
 *
 * The function initializes a child media list request which will return the list of all the child medias associated with the parent media.
 * @param mediaURI The media URI to be used to query the request.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSArray. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestChildMediaWithParentURI:(NSString *)mediaURI completionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;

/**
 Initializes and start a media metadata request.
 
 The function initializes a media metadata request which will return the list of all the media metadata associated with the media URI.
 The request will start automatically upon initialization. To start the request manually, please use the
 [MetadataV1 requestMediaMetadataWithMediaURI:completionHandler:startImmediately:] function.

        _request = [metadataV1 requestMediaMetadataWithMediaURI:@"505" completionHandler:^(id object, NSError *error) {
            if (!error) {
                //the response object is a dictionary that contains a media's metadata
                NSDictionary *metadata = (NSDictionary *)object;
                
                //retrieve media title in English
                NSString *title = metadata[@"title"][@"eng"];
                
                //retrieve description
                NSString *description = metadata[@"description"];
                
                //retrieve director
                NSString *director = metadata[@"director"];
                
                //retrieve genre
                NSString *genre = metadata[@"genre"];
                
                //retrieve duration
                NSString *duration = metadata[@"duration"];
                
                //retrieve rating
                NSString *rating = metadata[@"rating"];
                
                //retrieve other attributes based on need
            }
        }];
 
 Sample response:
 
     {
       "artist" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       },
       "childMediaCount" : 24,
       "content_type" : "tvseries",
       "copyright" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       },
       "description" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       },
       "duration" : "08:48:00",
       "genre" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       },
       "global_uri" : "",
       "images" : {
          "1_1" : {
             "height" : "",
             "src" : "<image_url>",
             "width" : ""
          }
       },
       "key_type" : 8,
       "media_uri" : "321001",
       "parent_media_uri" : "",
       "poster_url" : {},   // Deprecated; Use "images"
       "rating" : "215",
       "rating_description" : "Not Rated",
       "short_description" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       },
       "short_title" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       },
       "soundtracks" : [
          {
             "language_code" : "49",
             "language_iso" : "eng",
             "language_name" : {
                "eng" : "english",
                "fre" : "anglais",
                "ger" : "englisch",
                "jpn" : "英語",
                "kor" : "영어",
                "sch" : "英语",
                "tch" : "英語"
             }
          }
       ],
       "subtitles" : {},
       "synopsis_url" : {   // Deprecated; Use "images"
          "size_4" : "<image_url>"
       },
       "title" : {
          "eng" : "2 Broke Girls: S3 (x24)",
          "sch" : "患难姊妹花: 第3 （24集）",
          "tch" : "患難姊妹花: 第3 (24集)"
       },
       "type" : "video",
       "year" : {
          "eng" : "",
          "sch" : "",
          "tch" : ""
       }
    }
 
 @param mediaURI The media URI to be used to query the request. The media URI is the identifier for the media.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaMetadataWithMediaURI:(NSString *)mediaURI completionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initialize a media metadata request. 
 *
 * The function initializes a media metadata request which will return the list of all the media metadata associated with the media URI. The media URI is the identifier for the media.
 * @param mediaURI The media URI to be used to query the request.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaMetadataWithMediaURI:(NSString *)mediaURI completionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;

/**
 Initializes and start a batch media metadata request.
 
 The function initializes a media metadata request which will return the list of all the media metadata associated with the media URI.
 The request will start automatically upon initialization. To start the request manually, please use the
 [MetadataV1 requestMediaMetadataWithMediaURIs:completionHandler:startImmediately:] function.
 
       _request = [metadataV1 requestMediaMetadataWithMediaURIs:@[@"505",@"506"] completionHandler:^(id object, NSError *error) {
            if (!error) {
                //the response object is a dictionary that contains a media's metadata
                NSDictionary *metadata = (NSDictionary *)object;
 
                //retrieve other attributes based on need
            }
        }];
 
 Sample response:
 
        {
           "data" : [
              {
                 "children" : [],
                 "media_uri" : "77678",
                 "title" : {
                    "eng" : "#Entertainment Highlights"
                 }
              },
              {
                 "children" : [],
                 "media_uri" : "78473",
                 "title" : {
                    "eng" : "#Entertainment Highlights"
                 }
              },
              {
                 "children" : [
                    {
                       "media_uri" : "77621",
                       "title" : {
                          "eng" : "4 Könige  (4 Kings)"
                       }
                    }
                 ],
                 "media_uri" : "77731",
                 "title" : {
                    "eng" : "4 Könige  (4 Kings)"
                 }
              },
              {
                 "children" : [],
                 "media_uri" : "77678",
                 "title" : {
                    "eng" : "#Entertainment Highlights"
                 }
              }
           ],
           "error" : [
              {
                 "code" : 404,
                 "media_uri" : "784",
                 "text" : "Not found"
              },
              {
                 "code" : 404,
                 "media_uri" : "321",
                 "text" : "Not found"
              }
           ]
        }
 
 @param mediaURIs The array of media URIs to be used to query the request. The media URI is the identifier for the media.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaMetadataWithMediaURIs:(NSArray<NSString *> *)mediaURIs completionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initialize a batch media metadata request.
 *
 * The function initializes a media metadata request which will return the list of all the media metadata associated with the media URI. The media URI is an identifier for the media.
 * @param mediaURIs The array of media URIs to be used to query the request. The media URI is the identifier for the media.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaMetadataWithMediaURIs:(NSArray<NSString *> *)mediaURIs completionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;

/**
  Initialize and automatically start an image download request.
 
  The request will start automatically upon initialization. To start the request manually, please use the
  [MetadataV1 requestMediaImageWithImageURL:completionHandler:startImmediately:] function.
  The function initializes an image request which will download the image and return it through the completion block. If image was downloaded previously, it will use the cached version instead of doing the request.

         //get a category from list of categories at specific index determined by the row.
         NSDictionary *category = [response objectAtIndex:indexPath.row];

         [metadata requestMediaImageWithImageURL:media[@"poster_url"][@"size_1"] completionHandler:^(id object, NSError *error) {
         //save image object to images variable.
             [self.images setObject:object forKey:media[@"poster_url"][@"size_1"]];
             [self.tableView reloadData];
         }];

 @param imageURL The image URL to be used to query the request.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type UIImage. The error object refers to response error in case an error occured while retreiving data
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaImageWithImageURL:(NSString *)imageURL completionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initialize an image download request.
 *
 * The function initializes an image request which will download the image and return it through the completion block. If image was downloaded previously, it will use the cached version instead of doing the request.
 * @param imageURL The image URL to be used to query the request.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type UIImage. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaImageWithImageURL:(NSString *)imageURL completionHandler:(PACMetadataV1CompletionHandler)completion startImmediately:(BOOL)start;

/**
 Initialize and start a search request.
 
 The function initializes a search request which will search for media and return it through the completion block.
 The request will start automatically upon initialization. To start the request manually, please use the
 [MetadataV1 requestMediaSearchByFields:withCompletionHandler:startImmediately:] function. The search can
 allow for typos by adding the metadata field/attribute PACMetadataFieldMatchTypeKey with the requested match type.

         [metadata requestMediaSearchByFields:@{PACMetadataFieldTitleKey: @"My title",
                                                PACMetadataFieldExactMatchKey: [NSNumber numberWithBool:true]}
                        withCompletionHandler:^(id object, NSError *error) {
            if (!error) {
                NSLog(@"Response = %@",object);
                NSArray *data = object[@"data"];
                for (NSDictionary *media in self.data) {
                    // Get media URI
                    NSNumber *mediaURI = media[@"media_uri"];
                    
                    // Get title
                    NSString *title = media[@"title"][@"eng"];
                    
                    // Get rating
                    NSString *rating = media[@"rating_desc"];
                    
                    // Get duration
                    NSString *duration = media[@"duration"];
                    
                    // Get type
                    NSString *type = media[@"type"];
                    
                    // Get image URL
                    NSArray *images = media[@"images"];
                    
                    ...
                }
            }
            else{
                NSLog(@"Error in searching: %@", error);
            }
         }];
 
 Sample response:
 
        {
          "request_info": {
            "parameters":{"title":"horse of cards", "cast":"Kevin Space"},
            "pagination":{"offset":60, "pageSize":15}
          },
          "result_info": {
            "code":200,
            "version":"2.1",
            "pagination": {"offset":60, "pageSize":15, "count":15, "totalCount":93},
            "fuzzy": [{"param":"title", "alt":"house of cards"},{"param":"cast", "alt":"Kevin Spacey"}]
          }
          "data": [
            {
              "cast": {
                "eng": "Kevin Spacey"
              },
              "bundles" : ["142"],
              "content_type": "tv",
              "critic_score": "0.00",
              "director": {
                "eng": ""
              },
              "duration": "01:01:54",
              "genre": {
                "eng": "Western"
              },
              "global_uri": "",
              "images": {
                "1_1": {
                  "height": "",
                  "src": "https://cadev.panasonic.aero/inflight/services/metadata/v1/images/sq/1598MediaDB_sq1115_v3_images/metadata/v1/images/106053-4_1_1.jpg",
                  "width": ""
                },
                "1_5": {
                  "height": "",
                  "src": "https://cadev.panasonic.aero/inflight/services/metadata/v1/images/sq/1598MediaDB_sq1115_v3_images/metadata/v1/images/106053-4_1_5.jpg",
                  "width": ""
                },
                "2_1": {
                  "height": "",
                  "src": "https://cadev.panasonic.aero/inflight/services/metadata/v1/images/sq/1598MediaDB_sq1115_v3_images/metadata/v1/images/106053-4_2_1.jpg",
                  "width": ""
                }
              },
              "key_type": 0,
              "media_uri": "106053",
              "parent_media_uri": "",
              "rating": "150",
              "rating_description": "PG",
              "title": {
                "eng": "House of Cards Season 1"
              },
              "type": "tvseries",
              "matched_fields":[{"field":"title", "value": "house of cards"}, {"field":"cast", "value": "Kevin Spacey"}]
            },
            {
              "artist": {
                "eng": "Linda Lewis"
              },
              "content_type": "tv",
              "critic_score": "0.00",
              "director": {
                "eng": ""
              },
              "duration": "00:00:00",
              "genre": {
                "eng": ""
              },
              "global_uri": "",
              "images": {},
              "key_type": 0,
              "media_uri": "328418",
              "parent_media_uri": "328411",
              "rating": "150",
              "rating_description": "PG",
              "title": {
                "eng": "House of Cards Season 2"
              },
              "type": "tvseries",
              "matched_fields":[{"field":"title", "value": "house of cards"}]
            }
            ...
          ]
        }
 
 @param fields The search fields for the media search. See PACMetadataFieldKeys.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data.
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaSearchByFields:(NSDictionary *)fields
                               withCompletionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initialize a search request.
 *
 * The function initializes a search request which will search for media and return it through the completion block.
 * @param fields The search fields for the media search. See PACMetadataFieldKeys.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaSearchByFields:(NSDictionary *)fields
                               withCompletionHandler:(PACMetadataV1CompletionHandler)completion
                                    startImmediately:(BOOL)start;

/**
 Initialize and start a search request by text in any field.
 
 The function initializes a search request which will search for media and return it through the completion block.
 The request will start automatically upon initialization. If you wish not to start it automatically please use the
 PACMetadataV1 requestMediaSearchByText:attributes:withCompletionHandler:startImmediately:] function. The search can 
 allow for typos by adding the metadata field/attribute PACMetadataFieldMatchTypeKey with the requested match type.

         [metadata requestMediaSearchByText:@"The Beatles"
                                 attributes:@{PACMetadataFieldExactMatchKey, [NSNumber numberWithBool:TRUE]}
                      withCompletionHandler:^(id object, NSError *error){
            if (!error) {
                NSLog(@"Response = %@",object);
                NSArray *data = object[@"data"];
                for (NSDictionary *media in self.data) {
                    // Get media URI
                    NSNumber *mediaURI = media[@"media_uri"];
                    
                    // Get title
                    NSString *title = media[@"title"][@"eng"];
                    
                    // Get rating
                    NSString *rating = media[@"rating_desc"];
                    
                    // Get duration
                    NSString *duration = media[@"duration"];
                    
                    // Get type
                    NSString *type = media[@"type"];
                    
                    // Get image url
                    NSArray *images = media[@"images"];
                    
                    ...
                }
            }
            else{
                NSLog(@"Error in searching: %@", error);
            }
         }];
 
 Sample response:
 
        {
          "request_info": {
            "parameters":{"title":"horse of cards", "cast":"Kevin Space"},
            "pagination":{"offset":60, "pageSize":15}
          },
          "result_info": {
            "code":200,
            "version":"2.1",
            "pagination": {"offset":60, "pageSize":15, "count":15, "totalCount":93},
            "fuzzy": [{"param":"title", "alt":"house of cards"},{"param":"cast", "alt":"Kevin Spacey"}]
          }
          "data": [
            {
              "cast": {
                "eng": "Kevin Spacey"
              },
              "bundles" : ["142"],
              "content_type": "tv",
              "critic_score": "0.00",
              "director": {
                "eng": ""
              },
              "duration": "01:01:54",
              "genre": {
                "eng": "Western"
              },
              "global_uri": "",
              "images": {
                "1_1": {
                  "height": "",
                  "src": "https://cadev.panasonic.aero/inflight/services/metadata/v1/images/sq/1598MediaDB_sq1115_v3_images/metadata/v1/images/106053-4_1_1.jpg",
                  "width": ""
                },
                "1_5": {
                  "height": "",
                  "src": "https://cadev.panasonic.aero/inflight/services/metadata/v1/images/sq/1598MediaDB_sq1115_v3_images/metadata/v1/images/106053-4_1_5.jpg",
                  "width": ""
                },
                "2_1": {
                  "height": "",
                  "src": "https://cadev.panasonic.aero/inflight/services/metadata/v1/images/sq/1598MediaDB_sq1115_v3_images/metadata/v1/images/106053-4_2_1.jpg",
                  "width": ""
                }
              },
              "key_type": 0,
              "media_uri": "106053",
              "parent_media_uri": "",
              "rating": "150",
              "rating_description": "PG",
              "title": {
                "eng": "House of Cards Season 1"
              },
              "type": "tvseries",
              "matched_fields":[{"field":"title", "value": "house of cards"}, {"field":"cast", "value": "Kevin Spacey"}]
            },
            {
              "artist": {
                "eng": "Linda Lewis"
              },
              "content_type": "tv",
              "critic_score": "0.00",
              "director": {
                "eng": ""
              },
              "duration": "00:00:00",
              "genre": {
                "eng": ""
              },
              "global_uri": "",
              "images": {},
              "key_type": 0,
              "media_uri": "328418",
              "parent_media_uri": "328411",
              "rating": "150",
              "rating_description": "PG",
              "title": {
                "eng": "House of Cards Season 2"
              },
              "type": "tvseries",
              "matched_fields":[{"field":"title", "value": "house of cards"}]
            }
            ...
          ]
        }
 
 @param text The text to be searched in any specified field in the database. The only exception is genre. This field is required.
 @param attributes Additional search attributes to be used. Refer to PACMetadataFieldKeys.
 @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 
 - *object* The response object.
 - *error* The error object in case an error occurred.
 @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaSearchByText:(NSString *)text
                                        attributes:(NSDictionary *)attributes
                             withCompletionHandler:(PACMetadataV1CompletionHandler)completion;

/**
 * Initializes a search request by text in any field.
 *
 * The function initializes a search request which will search for media and return it through the completion block.
 * @param text The text to be searched in any of the specified (except for genre) field in DB. This field is required.
 * @param attributes Additional search attributes to be used. Refer to PACMetadataFieldKeys.
 * @param completion The completion block to be executed on finish. The response object returned from the server is of type NSDictionary. The error object refers to response error in case an error occured while retreiving data
 *
 *- *object* The response object.
 *- *error* The error object in case an error occurred.
 * @param start If set, the request will start automatically.
 * @return Returns the request object.
 */
- (id <PACMetadataV1Request>)requestMediaSearchByText:(NSString *)text
                                        attributes:(NSDictionary *)attributes
                             withCompletionHandler:(PACMetadataV1CompletionHandler)completion
                                  startImmediately:(BOOL)start;


/**
 * Cancel all requests.
 */
- (void)cancelAllRequests;

/**
 * Resume processing requests.
 */
- (void)resume;

/**
 * Pause processing requests.
 */
- (void)pause;

@end

#pragma mark - Root Categories
/**
 * @constantgroup PACMetadataRootCategories
 * The following represents the string constants defining the root categories.
 * @owner PACMetadataV1
 */

/**
 * The key to be used for querying the movies category.
 */
extern NSString *const PACMetadataRootCategoryMovies;

/**
 * The key to be used for querying the music category.
 */
extern NSString *const PACMetadataRootCategoryMusic;

/**
 * The key to be used for querying the TV category.
 */
extern NSString *const PACMetadataRootCategoryTV;

/**
 * The key to be used for querying the radio category.
 */
extern NSString *const PACMetadataRootCategoryRadio;

/**
 * The key to be used for querying the audiobooks category.
 */
extern NSString *const PACMetadataRootCategoryAudiobooks;

/**
 * The key to be used for querying the music video category.
 */
extern NSString *const PACMetadataRootCategoryMusicVideos;

/**
 * The key to be used for querying the featured category.
 */
extern NSString *const PACMetadataRootCategoryFeatured;

/**
 * The key to be used for querying the showcase category.
 */
extern NSString *const PACMetadataRootCategoryShowcase;

/**
 * The key to be used for querying the games category.
 */
extern NSString *const PACMetadataRootCategoryGames;

/**
 * The key to be used for querying the kids movies category.
 */
extern NSString *const PACMetadataRootCategoryKidsMovies;

/**
 * The key to be used for querying the kids music category.
 */
extern NSString *const PACMetadataRootCategoryKidsMusic;

/**
 * The key to be used for querying the kids TV category.
 */
extern NSString *const PACMetadataRootCategoryKidsTV;

/**
 * The key to be used for querying the kids radio category.
 */
extern NSString *const PACMetadataRootCategoryKidsRadio;

/**
 * The key to be used for querying the kids featured category.
 */
extern NSString *const PACMetadataRootCategoryKidsFeatured;

/**
 * The key to be used for querying the kids showcase category.
 */
extern NSString *const PACMetadataRootCategoryKidsShowcase;

/**
 * The key to be used for querying the kids games category.
 */
extern NSString *const PACMetadataRootCategoryKidsGames;

#pragma mark - Content Types

/**
 * @constantgroup PACMetadataContentType
 * The following represents the string constants defining the content type.
 * @owner PACMetadataV1
 */

/**
 * The content type is movie.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeMovie;

/**
 * The content type is TV.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeTV;

/**
 * The content type is TV episode.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeTVEpisode;

/**
 * The content type is TV series.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeTVSeries;

/**
 * The content type is album.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeAlbum;

/**
 * The content type is audio book.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeAlbumAudioBook;

/**
 * The content type is bundle.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeBundle;

/**
 * The content type is ebook.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeEBook;

/**
 * The content type is track.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeTrack;

/**
 * The content type is track audio.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeTrackAudio;

/**
 * The content type is trailer.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeTrailer;

/**
 * The content type is podcast track.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypePodcastTrack;

/**
 * The content type is podcast album.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypePodcastAlbum;

/**
 * The content type is radio track.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeRadioTrack;

/**
 * The content type is radio album.
 * The value is to be used for setting the content type in the search field.
 */
extern NSString *const PACMetadataContentTypeRadioAlbum;

#pragma mark - Media Types

/**
 * @constantgroup PACMetadataMediaType
 * The following represents the string constants defining the media type.
 * @owner PACMetadataV1
 * @deprecated First deprecated in InFlight iOS SDK 03.14.00.00. Use the identical attribute PACMetadataContentType instead.
 */

/**
 * The media type is movie.
 * The value is to be used for setting the media type in the search field.
 */
extern NSString *const PACMetadataMediaTypeMovieValue __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 03.14.00.00. Use the identical attribute PACMetadataContentTypeMovie instead.")));

/**
 * The media type is TV.
 * The value is to be used for setting the media type in the search field.
 */
extern NSString *const PACMetadataMediaTypeTVValue __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 03.14.00.00. Use the identical attribute PACMetadataContentTypeTV instead.")));

/**
 * The media type is album.
 * The value is to be used for setting the media type in the search field.
 */
extern NSString *const PACMetadataMediaTypeAlbumValue __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 03.14.00.00. Use the identical attribute PACMetadataContentTypeAlbum instead.")));

#pragma mark - Metadata Fields
/**
 * @constantgroup PACMetadataFieldKeys
 * The following represents the string constants defining the metadata key fields.
 * @owner PACMetadataV1
 */

/**
 * The key to be used for setting the media type in the search field.
 * The value of the key should be either PACMetadataMediaTypeMovieValue, PACMetadataMediaTypeTVValue, or PACMetadataMediaTypeAlbumValue.
 * This field is optional.
 * If not provided, the default value is all.
 */
extern NSString *const PACMetadataFieldMediaTypeKey __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 03.14.00.00. Use the identical attribute PACMetadataFieldContentTypeKey instead.")));

/**
 * The key to be used for setting the media type in the search field.
 * The value of the key should be one of PACMetadataContentType.
 * This field is optional.
 * If not provided, the default value is all.
 */
extern NSString *const PACMetadataFieldContentTypeKey;

/**
 * The key to be used for setting the title in the search field.
 * The value of the key should be a NSString object that holds the title. You can
 * search for multiple values of this field by separating the values with commas.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldTitleKey;

/**
 * The key to be used for setting the genres in the search field.
 * The value of the key should be a NSString object that holds the genre. You can
 * search for multiple values of this field by separating the values with commas.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldGenresKey;

/**
 * The key to be used for setting the language in the search field.
 * The value of the key should be a NSString object that holds the language.
 * The language should be iso639-2 string compliant.
 * This field is optional.
 * Default value is 'eng' (English)
 */
extern NSString *const PACMetadataFieldLanguageKey;

/**
 * The key to be used for setting the year in the search field.
 * The value of the key should be a NSString object that holds the year. You can
 * search for multiple values of this field by separating the values with commas.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldYearKey;

/**
 * The key to be used for setting the actor in the search field.
 * The value of the key should be a NSString object that holds the actor name. You can
 * search for multiple values of this field by separating the values with commas.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldActorKey __attribute__((deprecated("This field is deprecated. Please use PACMetadataFieldCastKey.")));

/**
 * The key to be used for setting the actor or artist in the search field.
 * The value of the key should be a NSString object that holds the actor name. You can
 * search for multiple values of this field by seperating the values with commas.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldCastKey;

/**
 * The key to be used for setting the director in the search field.
 * The value of the key should be a NSString object that holds the director name. You can
 * search for multiple values of this field by separating the values with commas.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldDirectorKey;

/**
 * The key to be used for setting the ratings in the search field.
 * The value of the key should be a NSString object that holds the ratings. You can
 * search for multiple values of this field by separating the values with commas.
 * Examples of ratings are: PG,PG 13 and R.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldRatingsKey;

/**
 * The key to be used for defining the search results as an exact match. 
 * The value of the key should be a NSNumber with a bool value.
 * This field is optional.
 * Default value is FALSE.
 */
extern NSString *const PACMetadataFieldExactMatchKey;

/**
 * The key to be used for defining the type of match for the search results. The match types are broad or fuzzy, phrase and exact. 
 * The value of the key should be an NSNumber.
 *
 * 0 for broad or fuzzy match. Search criteria includes: typo correction; not all words need to exist.
 * 1 for phrase match. Search criteria includes: typo correction; all words need to be included.
 * 2 for exact match. Search criteria includes: no typo correction; text needs to be exact.
 * 
 * This field is optional.
 * Default value is 0.
 */
extern NSString *const PACMetadataFieldMatchTypeKey;

/**
 * The key to be used for defining the seat class for the metadata request.
 * The value of the key should be a NSString object. Please look at PACMetadataSeatClass
 * for possible values.
 * This field is optional.
 * Default value is all.
 */
extern NSString *const PACMetadataFieldSeatClassKey;

/**
 * The key to be used for defining the frequent flyer tier for the metadata request.
 * 
 * The value of the key should be a NSString object. To get possible values, developer
 * must request tiers from Airline.
 *
 * This field is optional.
 */
extern NSString *const PACMetadataFieldFrequentFlyerTierKey;

/**
 * The key to be used for defining the start offset of the pagination option.
 * The value of the key should be a NSNumber.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldPaginationOptionStartOffsetKey;

/**
 * The key to be used for defining the number of elements to be returned per page.
 * The value of the key should be a NSNumber.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldPaginationOptionCountKey;

/**
 * The key to be used for defining the language of the subtitles associated with the media item.
 * The value of the key should be a NSString object that holds the language.
 * The language should be iso639-2 string compliant.
 * This field is optional.
 * Default value is 'eng'.
 */

extern NSString *const PACMetadataFieldSubtitleLanguageKey;

/**
 * The key to be used for defining the language of the soundtrack associated with the media item.
 * The value of the key should be a NSString object that holds the language.
 * The language should be iso639-2 string compliant.
 * This field is optional.
 * Default value is 'eng'.
 */

extern NSString *const PACMetadataFieldSoundtrackLanguageKey;

/**
 * The key is used to filter the response with specific fields.
 * The value of the key should be a NSString object that holds a comma separated list of keys.
 * This field is optional.
 */
extern NSString *const PACMetadataFieldRequestedFieldsKey;

#pragma mark - Seat Class
/**
 * @constantgroup PACMetadataSeatClass
 * The following represents the string constants defining the seat class.
 * @owner PACMetadataV1
 */

/**
 * The seat class pertaining to all common media to all classes, seatback monitors and personal electronic devices (PEDs).
 */
extern NSString *const PACMetadataSeatClassAll;

/**
 * The first class.
 */
extern NSString *const PACMetadataSeatClassFirst;

/**
 * The business class.
 */
extern NSString *const PACMetadataSeatClassBusiness;

/**
 * The economy class.
 */
extern NSString *const PACMetadataSeatClassEconomy;

/**
 * The premium economy class.
 */
extern NSString *const PACMetadataSeatClassPremiumEconomy;

/**
 * The PED (personal electronic device) class.
 */
extern NSString *const PACMetadataSeatClassPED;
