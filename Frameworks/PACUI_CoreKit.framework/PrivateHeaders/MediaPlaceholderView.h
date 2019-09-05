//
//  MediaPlaceholderView.h
//  PanaSkyKit-iOS
//
//  Created by Russell Cook on 10/7/15.
//  Copyright © 2015 Mercury. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MediaPlaceholderView : UIView

- (void)setupWithMediaTemplateID:(NSString *)mediaTemplateID;
- (void)setupWithMediaTemplateID:(NSString *)mediaTemplateID withLocalizedTitle:(NSString *)localizedTitle;

@end
