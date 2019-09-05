//
//  MetadataManager.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 05/27/16.
//  Copyright (c) 2016 Mercury. All rights reserved.
//

@interface MetadataManager : NSObject

+ (MetadataManager *)sharedMetadataManager;

@property (atomic, assign) BOOL isRetrying;
@property (nonatomic, strong) UIViewController *hostViewController;
@property (nonatomic, strong) NSMutableArray *modules;
@property (nonatomic, assign) NSString *default_route_class;
@property (nonatomic, assign) NSString *default_route_destination;
@property (nonatomic, assign) NSString *default_route_flightnumber;
@property (nonatomic, assign) NSString *default_route_origin;

- (void)setupCategoriesWithCompletion:(void(^)(NSError *error))completion;
- (void)setupCategories:(BOOL)isServerAvailable withCompletion:(void(^)(NSError *error))completion;
- (NSNumber *)categoryIDWithRootType:(NSString *)rootType;
- (NSNumber *)categoryIDWithParentRootType:(NSString *)parentRootType index:(NSInteger)parentCategoryIndex;
- (NSInteger)subcategoryCountForRootType:(NSString *)rootType;
- (NSInteger)subcategoryCountForCategoryID:(NSNumber *)categoryID;
- (NSInteger)itemCountForCategoryID:(NSNumber *)categoryID;
- (NSString *)firstMediaURIForCategoryID:(NSNumber *)categoryID;
- (NSInteger)subcategoryItemCountForCategoryID:(NSNumber *)categoryID;
- (NSString *)firstSubcategoryURIForCategoryID:(NSNumber *)categoryID;
- (NSString *)omZonePathForCategoryID:(NSNumber *)categoryID;
- (NSString *)omZonePathIndexForCategoryID:(NSNumber *)categoryID;

@end
