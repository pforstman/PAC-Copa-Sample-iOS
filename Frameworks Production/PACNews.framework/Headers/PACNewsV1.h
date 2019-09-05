/** @module PACNews.framework *///
//  PACNewsV1_2.h
//  News
//
//  Created by Rawad Hilal on 2/29/16.
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import <PACNews/PACNewsV1Provider.h>
#import <PACNews/PACNewsV1Category.h>
#import <PACNews/PACNewsV1Article.h>


/**
 This class is responsible for retrieving news service from the server. The news can contain images or videos.
 
 [Download Sample Project](../../samples/PACNews/SampleNewsApplication.zip)
 
 ***Example***
 
        ...
        @property (nonatomic,retain) PACNewsV1 *liveTextNews;
        ...
 
         - (void)viewDidLoad
         {
            // 1.inialize news object
            self.liveTextNews = [PACNewsV1 initService:nil];
 
            // 2. retrieves news
            [self.liveTextNews sendProvidersRequestWithQueue:[NSOperationQueue mainQueue]
                                                  completion:^(NSArray<PACNewsV1Provider *> * _Nullable providers, NSError * _Nullable error)
                    {
                        if (error)
                        {
                          NSLog(@"Error loading providers list.");
                          return;
                        }
 
 
                      [self.liveTextNews sendCategoriesRequestUsingProvider:providers[0].id
                                                              withImageType:PACNewsV1LTNImageTypeThumbnail
                                                                      queue:[NSOperationQueue mainQueue]
                                                                 completion:^(NSArray<PACNewsV1Category *> * _Nullable categories, NSError * _Nullable error)
                        {
                            // save articles into another array
                            NSMutableArray <PACNewsV1ArticleSummary *> *array = [[NSMutableArray alloc] init];
                            for (PACNewsV1Category *category in categories)
                            {
                                [array addObjectsFromArray:category.articles];
                            }

                            // sorting the article array
                            [array sortUsingComparator:^NSComparisonResult(PACNewsV1ArticleSummary *  _Nonnull obj1, PACNewsV1ArticleSummary *  _Nonnull obj2)
                            {
                                NSDate *d1 = [NSDate dateFromRFC2822:obj1.timestamp];
                                NSDate *d2 = [NSDate dateFromRFC2822:obj2.timestamp];
                                if ([d1 timeIntervalSinceDate:d2]>0)
                                {
                                    return NSOrderedAscending;
                                }
                                 else
                                {
                                    return NSOrderedDescending;
                                }
                            }];
 
                            // show in another UI
                            ArticlesFeedViewController *vc = [[ArticlesFeedViewController alloc] initWithArticlesSummary:array];
                            [self presentViewController:vc animated:YES completion:nil];
                        }];
                    }];
 
        }
 
 */
@interface PACNewsV1 : InFlightService


/**
 * @constantgroup PACNewsErrorDomains
 * The error domains associated to the PACNewsV1 class.
 */

/**
 * The generic error associated with the PACNewsV1 class.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACNewsErrorDomain;


/**
 * The news request error codes.
 *
 * @owner PACNewsV1
 */
typedef enum {
    /** The request has failed due to an unknown error. */
    PACNewsErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACNewsErrorBadRequest = 1001,
    /** The request has failed due the service being unavailable. */
    PACNewsErrorServiceNotFound = 1002,
    /** The request has failed due to the unexpected internal error. */
    PACNewsErrorInternalError = 1003,
    /** The request has failed due to the server returning an unexpected response. */
    PACNewsErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACNewsErrorConnectionError = 1005
}PACNewsErrorCode;

/**
 The completion block that is called by sendProvidersRequestWithQueue:completion: function.
 @param providers The array of news provider objects. Please refer to PACNewsV1Provider for more information.
 @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACNewsV1ProvidersCompletionBlock)(NSArray<PACNewsV1Provider *> * _Nullable providers, NSError * _Nullable error);

/**
 The completion block that is called by sendCategoriesRequestUsingProvider:withImageType:queue:completion: function.
 @param providers The array of news category objects. Please refer to PACNewsV1Category for more information.
 @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACNewsV1CategoriesCompletionBlock)(NSArray<PACNewsV1Category *> * _Nullable categories, NSError * _Nullable error);

/**
 The completion block that is called by sendArticleRequestWithArticleId:queue:completion: function.
 @param providers The article object. Please refer to PACNewsV1Article for more information.
 @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACNewsV1ArticleCompletionBlock)(PACNewsV1Article * _Nullable article, NSError * _Nullable error);

/**
 The completion block that is called by sendImageRequestWithUrl:queue:completion: function.
 @param image The image object.
 @param error The response error in case an error occured while retreiving data.
 */
typedef void (^PACNewsV1ImageCompletionBlock)(UIImage * _Nullable image, NSError * _Nullable error);

/**
 * Initialize a request for the list of news providers.
 *
 * @param queue The queue in which the completion block is going to be called.
 * @param completionHandler The completion block that will be executed on error or completion of the request. Please refer to PACNewsV1ProvidersCompletionBlock for more information.
 */
- (void)sendProvidersRequestWithQueue:(NSOperationQueue * _Nonnull)queue
                           completion:(PACNewsV1ProvidersCompletionBlock _Nonnull)completionHandler;


/**
 * Initialize a request for the list of categories, such as business, sports and arts, for a specific news provider.
 *
 * @param providerId The news provider id.
 * @param LTNImageType The image type. Please refer to PACNewsV1ImageType for values.
 * @param queue The queue in which the completion block is going to be called.
 * @param completionHandler The completion block that will be executed on error or completion of the request. Please refer to PACNewsV1CategoriesCompletionBlock for more information.
 */
- (void)sendCategoriesRequestUsingProvider:(NSString * _Nonnull)providerId
                            withImageType:(NSString * _Nullable)LTNImageType
                                    queue:(NSOperationQueue * _Nonnull)queue
                               completion:(PACNewsV1CategoriesCompletionBlock _Nonnull)completionHandler;

/**
 * Initialize a request for an article.
 *
 * @param articleId The article id.
 * @param queue The queue in which the completion block is going to be called.
 * @param completionHandler The completion block that will be executed upon error or completion of the request. Please refer to PACNewsV1ArticleCompletionBlock for more information.
 */
- (void)sendArticleRequestWithArticleId:(NSString * _Nonnull)articleId
                                  queue:(NSOperationQueue * _Nonnull)queue
                             completion:(PACNewsV1ArticleCompletionBlock _Nonnull)completionHandler;

/**
 * Initialize a request to get an image at a specific url.
 *
 * @param url The image url.
 * @param queue The queue in which the completion block is going to be called.
 * @param completionHandler The completion block that will be executed upon error or completion of the request. Please refer to PACNewsV1ImageCompletionBlock for more information.
 */
- (void)sendImageRequestWithUrl:(NSString * _Nonnull)url
                          queue:(NSOperationQueue * _Nonnull)queue
                     completion:(PACNewsV1ImageCompletionBlock _Nonnull)completionHandler;

/**
 * @constantgroup PACNewsV1ImageType
 * The image type for the category images, such as Business, Sports or Culture.
 *
 * @owner PACNewsV1
 */

/**
 * The image type is thumbnail image.
 */
FOUNDATION_EXPORT NSString* _Nonnull const PACNewsV1LTNImageTypeThumbnail;

/**
 * The image type is quick look image.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACNewsV1LTNImageTypeQuicklook;

/**
 * The image type is preview image.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACNewsV1LTNImageTypePreview;


@end
