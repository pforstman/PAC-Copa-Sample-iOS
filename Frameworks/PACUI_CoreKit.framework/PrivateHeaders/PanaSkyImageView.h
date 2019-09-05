//
//  PanaSkyImageView.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 6/5/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

@class PanaSkyImageLoader;
@class PSMedia;
@class PSMediaCategory;
@class PSSearchResult;

/*
 ImageView wrapper around the PanaSkyImage library.
 
 To use, just pass a source URL to the imageView's property.
 The imageView will handle calling the library to load our image.
 */

typedef enum {
    PanaImageTypeAudio  = 1 << 0,
    PanaImageTypeVideo  = 1 << 1, 
    PanaImageTypeSearch = 1 << 2
} PanaImageType;

typedef enum {
    PanaSizeTypePoster   = 1 << 0,
    PanaSizeTypeSynopsis = 1 << 1
} PanaSizeType;

@interface PanaSkyImageView : UIImageView

@property(nonatomic, strong) UIImage *placeholder;
@property(nonatomic, strong) NSString *sourceURLString;
@property(nonatomic, assign) BOOL syncrounous;
@property(nonatomic, assign) UIViewContentMode preferredContentMode;
@property(nonatomic, assign) BOOL animateImageTransitions;
@property (nonatomic, assign) BOOL disableCache;

- (id)initWithFrame:(CGRect)frame placeholderImage:(UIImage *)placeholderImage;
- (NSString *)posterURLForMedia:(PSMedia *)media withSize:(CGSize)size;
- (NSString *)posterURLForMediaCategory:(PSMediaCategory *)media withSize:(CGSize)size;
- (NSString *)posterURLForSearchResult:(PSSearchResult *)searchResult withSize:(CGSize)size;
- (void)setSourceURLString:(NSString *)sourceURLString;
- (void)setSourceURLString:(NSString *)sourceURLString withCompletion:(void(^)(BOOL success, NSError *error))completion;

/**
 Finds the closest image size greater than or equal to the provided input size in the corresponding image dictionaries

 @param size      Base input size
 @param imageType Either Audio or Video. See PanaImageType.
 @param sizeType  Either Poster or Synopsis. Synopsis being 1:1 aspect ratio. See PanaSizeType.

 @return Returns the closest CGSize greater than or equal to the input image size (based on width). If no size is found, returns largest available size.
 */
- (CGSize)closestSizeTo:(CGSize)size withImageType:(PanaImageType)imageType sizeType:(PanaSizeType)sizeType;

@end
