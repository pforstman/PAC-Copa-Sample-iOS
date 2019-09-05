//
//  SampleViewController.m
//  PAC-PanaSky-CA-iOS
//
//  Created by Paul Forstman on 3/1/17.
//  Copyright © 2017 Panasonic Avionics Corporation. All rights reserved.
//

#import "SampleViewController.h"

// Import PACUI_CoreKit module
@import PACUI_CoreKit;

@interface SampleViewController ()

@end

@implementation SampleViewController

#pragma mark - Life Cycle

- (id)init
{
    if ((self = [super init])) {
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleMiniPlayerVisibilityDidChange:) name:PACUIMiniPlayerVisibilityDidChangeNotification object:nil];
    }
    return self;
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad
{
    [super viewDidLoad];

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)handleFullButtonPress:(id)sender
{
    NSURL *url = [PACUI_MiniApp urlForModule:PACUI_MiniAppModuleFull];
    [[UIApplication sharedApplication] openURL:url];
}

- (IBAction)handleStopPlaybackButtonPress:(id)sender
{
    [PACUI_MiniApp stopPlayback];
}

#pragma mark - Notifications

- (void)handleMiniPlayerVisibilityDidChange:(NSNotification *)notification
{
    CGFloat miniPlayerHeight = 0.0;
    
    if ([PACUI_MiniApp isMiniPlayerVisible])
    {
        miniPlayerHeight = [PACUI_MiniApp miniPlayerHeight];
    }
    
    // TODO: Use value of miniPlayerHeight to manage content offset at bottom of display
    
    NSLog(@"MiniPlayerVisibilityDidChange: isMiniPlayerVisible = %@ miniPlayerHeight = %f", [PACUI_MiniApp isMiniPlayerVisible] ? @"YES" : @"NO", miniPlayerHeight);
}

- (BOOL)shouldAutorotate
{
    return YES;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskAll;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
{
    return [UIApplication sharedApplication].statusBarOrientation;
}

@end
