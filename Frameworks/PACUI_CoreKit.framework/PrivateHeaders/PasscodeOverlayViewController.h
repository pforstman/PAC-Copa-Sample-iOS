//
//  PasscodeOverlayViewController.h
//  PanaSky-iOS
//
//  Created by Paul Forstman on 11/5/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import "BaseOverlayViewController.h"
#import "PasscodeEntryView.h"
#import "PSMedia.h"

@class PasscodeOverlayViewController;

typedef void(^PasscodeOverlayDismissBlock)(BOOL canceled);

typedef NS_ENUM(NSUInteger, PasscodeOverlayClearAnimationType) {
    PasscodeOverlayClearAnimationType_Incorrect,
    PasscodeOverlayClearAnimationType_Slide,
    PasscodeOverlayClearAnimationType_None,
};

typedef NS_ENUM(NSUInteger, PasscodeOverlayInputMode) {
    PasscodeOverlayInputMode_Normal,
    PasscodeOverlayInputMode_Admin,
};



@protocol PasscodeOverlayEntryDelegate <NSObject>
@required
// Return YES if the controller should dismiss after entry
- (BOOL)passcodeEntryCompleted:(NSString *)passcode withController:(PasscodeOverlayViewController *)controller;
@end



@interface PasscodeOverlayViewController : BaseOverlayViewController

@property (nonatomic, weak) IBOutlet UIButton *cancelButton;
@property (nonatomic, weak) IBOutlet UIView *buttonPanelView;
@property (nonatomic, weak) IBOutlet PasscodeEntryView *passcodeEntryView;
@property (nonatomic, weak) id<PasscodeOverlayEntryDelegate> entryDelegate;
@property (nonatomic, copy) PasscodeOverlayDismissBlock dismissBlock;
@property (nonatomic, assign) PasscodeOverlayInputMode inputMode;   // Defaults to 'Normal'

- (void)clearPasscodeWithAnimationType:(PasscodeOverlayClearAnimationType)type;

@end
