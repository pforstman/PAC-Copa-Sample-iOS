/** @module PACMaps.framework *///
//  PACBroadcastMapsV1.h
//  InFlight iOS SDK
//
//  Copyright (c) 2014 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PACCoreKit/PACCoreKit.h>

@class PACBroadcastMapsResolution;

/**
  PACBroadcastMapsV1 is a class used to receive broadcasted maps images relative to flight path.

  Example:
 
        PACBroadcastMapsV1 maps;
     
        - (void)viewDidLoad{
            [super viewDidLoad];
     
            // Initialize the service.
            [PACBroadcastMapsV1 initServiceWithCompletionBlock:^(id object, NSError *error) {
                if (error != nil) {
                    NSLog(@"Failed to initialize service BroadcastMapsV1. Reason: %@",error);
                    return;
                }
                
                // Get service object
                self.maps = object;
                // Add notification observers
                [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(availableResolutionsChanged:)
                                                             name:PACBroadcastMapsAvailableResolutionsDidChangeNotification object:self.maps];
                [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(mapsChanged:)
                                                             name:PACBroadcastMapsImageDidChangeNotification object:self.maps];
                
                // Start
                [self.maps start];
            }];
        }
     
        - (void)availableResolutionsChanged:(NSNotification *)sender{
            NSArray *resolutions = [self.maps availableResolutions];
            if (resolutions && resolutions.count>0){
                // Select first resolution
                [self.maps setCurrentResolution:resolutions[0]];
            }
        }
     
        - (void)mapsChanged:(NSNotification *)sender{
            // Update image view.
            [self.imageView setImage:[self.maps mapImage]];
        }
 
 */

@interface PACBroadcastMapsV1 : InFlightService

/**
 * Return an array of all resolutions for the map image.
 * @return Array of PACBroadcastMapsResolution
 */
- (NSArray *)availableResolutions;

/**
 * Set the resolution for the map image.
 * @param resolution The resolution used to populate mapImage. See availableResolutions.
 */
- (void)setCurrentResolution:(PACBroadcastMapsResolution *)resolution;

/**
 * Set the CGS size resolution for the map image.
 * @param resolution The resolution that will be used to populate mapImage. See availableCGSizeResolutions.
 */
- (void)setCurrentResolutionWithCGSize:(CGSize)resolution;

/**
 * Get the specific resolution for the map image.
 * @return The resolution that is used to populate mapImage.
 */
- (PACBroadcastMapsResolution *)currentResolution;

/**
 * Get the current map image. This will be changed as new maps come in.
 * See PACBroadcastMapsImageDidChangeNotification.
 * @return The current map image.
 */
- (UIImage *)mapImage;

/**
 * Start receiving map images. This needs to be called in order to receive PACBroadcastMapsImageDidChangeNotification.
 * In case there are multiple PACBroadcastMapsV1s, only one instance can receive map images.
 * When start is called on an instance of PACBroadcastMapsV1, other instances will automatically be stopped and will stop receiving map images.
 * As a result, PACBroadcastMapsImageDidStopReceivingImageNotification will be dispatched on all other instances of PACBroadcastMapsV1.
 */
- (void)start;

/**
 * Stop receiving map images.
 * Calling stop will not dispatch the PACBroadcastMapsImageDidStopReceivingImageNotification.
 */
- (void)stop;

@end

/**
 * PACBroadcastMapsResolution is a class used to represent map resolutions by width and height.
 */
@interface PACBroadcastMapsResolution : NSObject

/**
 * The width value in map resolution
 */
@property (nonatomic) CGFloat width;

/**
 * The height value in map resolution
 */
@property (nonatomic) CGFloat height;

/**
 * Return the size of map resolution. CGSize representation of width and height.
 * @return The size of map resolution.
 */
- (CGSize)CGSize;

@end


/**
 * Event dispatched when error occurs while fetching map information. The service object will recover
 * when it reconnects to the server.
 *
 * @owner PACBroadcastMapsV1
 */
extern NSString *const PACBroadcastMapsErrorNotification;

/**
 * Event dispatched when the available resolutions changed.
 *
 * @owner PACBroadcastMapsV1
 */
extern NSString *const PACBroadcastMapsAvailableResolutionsDidChangeNotification;

/**
 * Event dispatched when the map data has changed. This is dispatched only if start is called.
 *
 * @owner PACBroadcastMapsV1
 */
extern NSString *const PACBroadcastMapsImageDidChangeNotification;

/**
 * Event dispatched when map stops receiving data. This is dispatched only if current instance is automatically stopped by another instance starting. Calling stop will not dispatch this notification.
 *
 * @owner PACBroadcastMapsV1
 */
extern NSString *const PACBroadcastMapsImageDidStopReceivingImageNotification;
