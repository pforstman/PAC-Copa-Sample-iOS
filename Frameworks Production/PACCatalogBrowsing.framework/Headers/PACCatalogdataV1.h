/** @module PACCatalogBrowsing.framework *///
//  PACCatalogdataV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2015 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>

/**
 * The return code of PACCatalogdataV1Request start API call
 *
 * @owner PACCatalogdataV1
 */
typedef enum {
    /** Request started successfully. */
    PACCatalogdataV1RequestStarted,
    /** Request failed to start because it is already running. */
    PACCatalogdataV1RequestFailedReasonAlreadyStarted
}PACCatalogdataV1RequestReturnCode;


/**
 * The catalogdata request error codes.
 *
 * @owner PACCatalogdataV1
 */
typedef enum {
    /** The request has failed due to an unknown error. */
    PACCatalogdataErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACCatalogdataErrorBadRequest = 1001,
    /** The request has failed due to the unavailability of the service. */
    PACCatalogdataErrorServiceNotFound = 1002,
    /** The request has failed because of unexpected internal error. */
    PACCatalogdataErrorInternalError = 1003,
    /** The request has failed because the server returned an unexpected response. */
    PACCatalogdataErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACCatalogdataErrorConnectionError = 1005
}PACCatalogdataErrorCode;

/**
 * The catalog data type. The data types are shopping and hospitality.
 *
 * @owner PACCatalogdataV1
 */
typedef enum{
    /** The catalog data type is shopping. */
    PACCatalogdataTypeShopping = 1,
    /** The catalog data type is hospitality. */
    PACCatalogdataTypeHospitality
}PACCatalogdataType;

/**
 * This is the protocol that the request objects implement.
 */
@protocol PACCatalogdataV1Request <NSObject>

/**
 PACCatalogdataV1 completion block
 @param object The response object from the server. It can be either a NSDictionary, a NSArray, or an UIImage depending on the type of the request.
 @param error The response error in case an error occured while retreiving data.
 */

typedef void (^PACCatalogdataV1CompletionHandler)(id object, NSError *error);

/**
 Starts the request and returns a completion block when complete.
 @param completion The PACCatalogdataV1CompletionHandler block is executed after request job is finished.
 @return Returns PACCatalogdataV1RequestReturnCode. See PACCatalogdataV1RequestReturnCode for all possible results.
 */
- (PACCatalogdataV1RequestReturnCode)startWithCompletionHandler:(PACCatalogdataV1CompletionHandler)completion;

/**
 * Stops the request.
 */
- (void)stop;

/**
 * Sets the operation queue that will execute the completion block.
 *
 * If not set, the main queue will be used.
 * @param queue The operation queue that the callback will be called on.
 */
- (void)setOperationQueue:(NSOperationQueue *)queue;

/**
 * Gets the operation queue that will execute the completion block.
 * @return The operation queue object.
 */
- (NSOperationQueue *)operationQueue;

@end



/**
 PACCatalogdataV1 is a service class retrieves the metadata information for all shopping and hospitality items. Different service names are used for instantiating shopping and hospitality services, but they provide same public interfaces. PACCatalogdataV1 initializes request objects including catalogdata, categories, items, and image.
  
 [Download Sample Project](../../samples/PACCatalogBrowsing/SampleCatalogdataApplication.zip)
 
 ***Example***
 
        // Example for requesting all shopping catalogdata that belong to personal electronic device (PED) seat class
 
        // PACCatalogdataV1 service object
        PACCatalogdataV1 *_catalogdataV1 = nil;
        // Catalogdata request object that can start or stop
        id <CatalogdataV1Request> _catalogdataRequest;

        NSMutableArray *_catalogdataList = ...;
        UITableView *_tableView = ...;

        // To initialize a shopping catalogdata service
        - (void) initialize(){
            // For shopping catalogdata, use: PACCatalogdataTypeShopping
            // For hospitality catalogdata, use: PACCatalogdataTypeHospitality
            [PACCatalogdataV1 initServiceWithCatalogType:PACCatalogdataTypeShopping completionBlock:^(id object, NSError *error) {
                if (error != nil) {
                    NSLog(@"Failed to initialize service CatalogdataV1 of type shopping. Reason: %@",error);
                    return;
                }
                
                self.catalogdataV1 = object;
                [self refresh];
            }];
        }

        // Refreshs contents of a table view that displays English title of all categories
        - (void)refresh{
            if (!self.catalogdataRequest) {
                self.catalogdataRequest = [self.catalogdataV1 requestForCatalogdataWithSeatClass:PACCatalogdataSeatClassPED language:nil];
            }
            
            //
            // It is best practice to avoid strong reference to self in a block. If the request is cancelled and the retained instance object
            // self.catalogdataRequest was not cleared, there will be a circular reference.
            //
            __weak typeof(self) weakSelf = self;
            [self.catalogdataRequest startWithCompletionHandler:^(id object, NSError *error) {
                if (!error) {
                    // Update data model
                    weakSelf.catalogdataList = ((NSDictionary *)object)[@"data"];
                    
                    // Update GUI
                    [weakSelf.tableView reloadData];
                }
                else {
                    // Handle error.
                    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Request Failure"
                                                                    message:[NSString stringWithFormat:@"Error Code: %ld \nDescription: %@",
                                                                             (long)error.code, error.description]
                                                                   delegate:nil
                                                          cancelButtonTitle:@"OK"
                                                          otherButtonTitles:nil];
                    [alert show];
                }
            }];
        }

        // Cancels the request
        -(void)cancelRequest{
            [self.catalogdataRequest stop];
        }

 */
@interface PACCatalogdataV1 : InFlightService

/**
 * Initializes a service with a specific catalog type, such as shopping.
 * @param type The catalog data type. Please refer to PACCatalogdataType for more details.
 * @param error The pointer to an error object that is set when an error occurs.
 * @return The instance object.
 */
+ (instancetype)initServiceWithCatalogType:(PACCatalogdataType)type error:(NSError *__autoreleasing *)error;

/**
 * Asynchronously initializes a service with a specific catalog type, such as shopping.
 *
 * This function is an asynchronous call.
 * @param type The catalog data type. Please refer to PACCatalogdataType for more details.
 * @param completion The completion block that is executed when the service has finished initializing.
 *
 *  - *object* Service object.
 *  - *error* Pointer to an error object that is set when an error occurs.
 */
+ (void)initServiceWithCatalogType:(PACCatalogdataType)type completionBlock:(void (^)(id, NSError *))completion;

/**
 * Returns the type of the catalog data request.
 *
 * This is a helper function that will allow you to identify the types of various PACCatalogdataV1 objects.
 * Please refer to PACCatalogdataType for more details on different types.
 */
@property (readonly, assign) PACCatalogdataType catalogdataType;

/**
 Request for all catalogs that belong to the seat class. The default is personal electronic device (PED).
 
 This call initializes a request to retrieve catalogs from the server. The response is localized depending on the languageCode provied.
 On success, the request will return a NSDictionary object through the PACCatalogdataV1CompletionHandler block in the start call.
 
 Sample response object from PACCatalogdataV1CompletionHandler

    {
        "total":2,
        "data": [
            {
                "id":"xyz",
                "title": {
                    "eng": "title",
                    "fre" : "title",
                },
                "description": {
                    "eng": "description",
                    "fre" : "description",
                },
                "image": {
                    "default": [
                        {
                            "width":"200",
                            "height":"200",
                            "url":"<image_url>"
                        },
                        {
                            "width":"400",
                            "height":"400",
                            "url":"<image_url>"
                        },
                        .
                        .
                    ],         
                    "eng": [
                        {
                            "width":"200",
                            "height":"200",
                            "url":"<image_url>"
                        },
                        {
                            "width":"400",
                            "height":"400",
                            "url":"<image_url>"
                        },
                        .
                        .
                    ],
                    "fre": [
                        {
                            "width":"200",
                            "height":"200",
                            "url":"<image_url>"
                        },
                        {
                            "width":"400",
                            "height":"400",
                            "url":"<image_url>"
                        },
                        .
                        .
                    ]
                },
                "catalog_type": "SHOP" // can be BEV, or MEAL
            },
            .
            .
        ]
    }
 
 @param seatClass The seat class for the request. The default is personal electronic device (PED). The seatClass is optional. If nil, it will default to PACCatalogdataSeatClassPED. Refer to PACCatalogdataSeatClass for all values.
 @param languageCode The iso639-2 language 3-letter code. If nil, it will request data for all languages provided by the airline. This value determines the languages of the data within the response.
 @return The request object. Please refer to PACCatalogdataV1Request.
*/
- (id <PACCatalogdataV1Request>)requestForCatalogsWithSeatClass:(NSString *)seatClass language:(NSString *)languageCode;

/**
  Request for all categories and subcategories that belong to the catalogID.
 
 This call initializes a request to retrieve categories from the server. The response is localized depending on the languageCode provied. On success, the request will return a NSDictionary object through the PACCatalogdataV1CompletionHandler block in the start call. Categories and subcategories are associated using "parent_category_id" attribute. For root categories, "parent_category_id" will be "-1". Also, the categories response data are sorted by airline-specific default display order.
 
 Sample response object from PACCatalogdataV1CompletionHandler

    {
        "total":3,
        "data": [
            {
                "id":"xyz",
                "parent_category_id":"-1"
                "title": {
                    "eng": "title",
                    "fre" : "title",
                },
                "description": {
                    "eng": "description",
                    "fre" : "description",
                },
                "image": {
                    "default": [
                        {
                            "width":"200",
                            "height":"200",
                            "url":"<image_url>"
                        },
                        {
                            "width":"400",
                            "height":"400",
                            "url":"<image_url>"
                        }
                        .
                        .
                    ],         
                    "eng": [
                        {
                            "width":"200",
                            "height":"200",
                            "url":"<image_url>"
                        },
                        {
                            "width":"400",
                            "height":"400",
                            "url":"<image_url>"
                        }
                        .
                        .
                    ],
                    "fre": [ ],
                    .
                    .
                },
                "sub_category_ids":["cateID1","cateID2"], // Array defines GUI sequence for these categories. 
                                                          // Will be empty for categories with no sub categories.
            },
            .
            .
        ]
    }
 
  @param catalogID The catalog ID for the request. The catalogID is required.
  @param languageCode The iso639-2 language 3-letter code. If nil, it will request data for all languages provided by the airline. This value determines the languages of the data within the response.
  @return The request object. Please refer to PACCatalogdataV1Request.
 */
- (id <PACCatalogdataV1Request>)requestForCategoriesWithCatalogID:(NSString *)catalogID language:(NSString *)languageCode;

/**
  Request list of all the items that belongs to the category. Also, the response data are sorted by airline-specific default display order.
 
   This call initializes a request to retrieve items from the server. The response is localized depending on the languageCode provied.
 On success, the request will return a NSDictionary object through the PACCatalogdataV1CompletionHandler block in the start call.
 
 Sample response object from PACCatalogdataV1CompletionHandler


    {
        "total":5
        "data": [
            {
                "id":"xyz",
                "sku":"12345",
                "item_type":"simple",
                "category_ids":["cate1","cate2"],
                "title": {
                    "eng": "title",
                    "fre" : "title",
                },
                "description": {
                    "eng": "description",
                    "fre" : "description",
                },
                "price": {
                    "usd":{
                        "amount":10.00,
                        "discount_amount":null
                    },
                    "hkd":{
                        "amount":10.00,
                        "discount_amount":null
                    }
                },
                "image": {
                    "default": [
                        {
                            "width":"200",
                            "height":"200",
                            "url":"<image_url>"
                        },
                        {
                            "width":"400",
                            "height":"400",
                            "url":"<image_url>"
                        }
                        .
                        .
                     ],
                    .
                    .
                }
            }
        ]
    }
 
  @param categoryID The category ID for the request. The category ID is required.
  @param languageCode The iso639-2 language 3-letter code. If nil, it will request data for all languages provided by the airline. This value determines the languages of the data within the response.
  @return The request object. Please refer to PACCatalogdataV1Request.
 */
- (id <PACCatalogdataV1Request>)requestForItemsWithCategoryID:(NSString *)categoryID language:(NSString *)languageCode;

/**
 Request for list of all items identified by the item IDs.
 
 This call initializes a request to retrieve items from the server. The response is localized depending on the languageCode provided.
 On success, the request will return a NSDictionary object through the PACCatalogdataV1CompletionHandler block in the start call.
 
 Refer to requestForItemsWithCategoryID:language: API for sample response object from PACCatalogdataV1CompletionHandler
 
 @param itemIDs The item IDs for the request. The item IDs is required.
 @param languageCode The 3-letter ISO 639-2 language code. If nil, it will request data for all languages provided by the airline. This value determines the languages of the data within the response.
 @return The request object. Please refer to PACCatalogdataV1Request.
 */
- (id <PACCatalogdataV1Request>)requestForItemsWithItemIDs:(NSArray *)itemIDs language:(NSString *)languageCode;

/**
 Request for the image identified by the image URL.
 
 This call initializes a request to retrieve an image from the server.
 On success, the request will return a UIImage object through the PACCatalogdataV1CompletionHandler block in the start call.
 
 @param imageURL The URL of the image
 @return The request object. Please refer to PACCatalogdataV1Request.
 */
- (id <PACCatalogdataV1Request>)requestForImageWithImageURL:(NSString *)imageURL;

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

/**
 * @constantgroup PACCatalogdataSeatClass
 * The following represents the string constants defining the seat classes.
 * @owner PACCatalogdataV1
 */

/**
 * The catalog data for all seat classes.
 */
extern NSString *const PACCatalogdataSeatClassAll;

/**
 * PED (Personal Electronic Device) class.
 */
extern NSString *const PACCatalogdataSeatClassPED;

/**
 * First class.
 */
extern NSString *const PACCatalogdataSeatClassFirst;

/**
 * Business class.
 */
extern NSString *const PACCatalogdataSeatClassBusiness;

/**
 * Premium economy class.
 */
extern NSString *const PACCatalogdataSeatClassPremiumEconomy;

/**
 * Economy class.
 */
extern NSString *const PACCatalogdataSeatClassEconomy;

/**
 * @constantgroup PACCatalogdataItemType
 * The following represents the string constants defining the item types.
 * This can be used to identify the type of an item by matching it with the value of "item_type" attribute in the response object.
 * Item types, other than simple type, is to be added in future releases.
 * @owner PACCatalogdataV1
 */

/**
 * Simple type is an item whose price does NOT depend on any attributes of the item or other factors.
 */
extern NSString *const PACCatalogdataItemTypeSimple;

/**
 * Group type is an item whose price is dependent on attributes associated with the item.
 */
extern NSString *const PACCatalogdataItemTypeGroup;

/**
 *Bundle type is group of items with a single combined price.
 */
extern NSString *const PACCatalogdataItemTypeBundle;


