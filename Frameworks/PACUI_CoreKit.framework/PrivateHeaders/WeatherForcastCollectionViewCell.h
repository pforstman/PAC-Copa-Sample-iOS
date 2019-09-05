//
//  WeatherForcastCollectionViewCell.h
//  PanaSkyKit-iOS
//
//  Created by Ian Blue on 9/12/16.
//  Copyright © 2016 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PACWeather/PACWeatherV1.h>

@interface WeatherForcastCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) PACWeatherV1WeatherForecastItem *forcastItem;

@end
