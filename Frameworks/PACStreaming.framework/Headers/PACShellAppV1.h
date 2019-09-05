/** @module PACStreaming.framework *///
//  PACShellAppV1.h
//  InFlight iOS SDK
//  Copyright (c) 2014-2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIScrollView.h>
#import <PACCoreKit/PACCoreKit.h>

/**
 * ShellApp is a service that loads a portal website that is using the In-Flight engine. It allows portal developers to communicate with the SDK via the JS bridge.
 */

@interface PACShellAppV1 : InFlightService <UIScrollViewDelegate>
/**
 * @name Webview Methods
 */

/**
 * Set whether the service object should use the legacy web engine.
 *
 * Setting the value to true will force the use of UIWebView instead of the new WebKit engine WKWebView. The default value is NO.
 *
 */
@property (nonatomic,assign) BOOL legacyMode;

/**
 * A Boolean value that controls whether the webview view bounces past the edge of content and back again.
 *
 * If the value of this property is YES, the web view bounces when it encounters a boundary of the content. Bouncing visually indicates that scrolling has reached an edge of the content. If the value is NO, scrolling stops immediately at the content boundary without bouncing. The default value is YES.
 */
@property (nonatomic,assign) BOOL bounces;

/**
 * Loads given URL on a webview and puts it on the superview, matching its viewport
 * @param url URL to load
 * @param superview View where the webpage is going to load.
 */

- (void) load:(NSString *)url withSuperview:(UIView *)superview;

/**
 * Clears the webview and objects created through the service
 */

- (void) clear;

/**
 * Shows the webview
 */

- (void) show;

/**
 * Hide the webview
 */

- (void) hide;

/**
 * Reloads the webview
 */

- (void) reload;

/**
 * Stops the webview
 */

- (void) stop;

/**
 * Stops retry timer for loading URL and removes all loading screens
 */

- (void) stopTimer;

@end

@interface PACShellAppV1 (loadingScreen)
/**
 * @name LoadingScreens
 */
/**
 * Sets the loading screen on superview for all orientations. Loading screens only display while trying to load.
 * @param portraitImage Portrait image.
 * @param landscapeImage Landscape image.
 */

- (void) setLoadingScreen:(UIImage *)portraitImage withLandscapeScreen:(UIImage *)landscapeImage;

/**
 * Sets the error screen on superview for all orientations. They only display while waiting to retry loading.
 * @param portraitImage Portrait error image.
 * @param landscapeImage Landscape error image.
 */

- (void) setErrorScreen:(UIImage *)portraitImage withLandscapeScreen:(UIImage *)landscapeImage;

/**
 * Sets the loading screen on superview for all orientations. Loading screens only display while trying to load.
 * @param filePath File path of the portrait image to load.
 * @param landscapeFilePath File path of the landscape image to load.
 * @param superview View where the webpage is going to load.
 * @deprecated First deprecated in InFlight iOS SDK 02.04.00.00. Use the setLoadingScreen:withLandscapeScreen: instead.
 */

- (void) setLoadingScreen:(NSString *)filePath withLandscapeScreen:(NSString *)landscapeFilePath withSuperview:(UIView *)superview __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 02.04.00.00. Use the setLoadingScreen:withLandscapeScreen: instead.")));

/**
 * Sets the error screen on superview for all orientations. They only display while waiting to retry loading.
 * @param filePath File path of the error portrait image to load.
 * @param landscapeFilePath File path of the error landscape image to load.
 * @param superview View where the webpage is going to load.
 * @deprecated First deprecated in InFlight iOS SDK 02.04.00.00. Use the setErrorScreen:withLandscapeScreen: instead.
 */

- (void) setErrorScreen:(NSString *)filePath withLandscapeScreen:(NSString *)landscapeFilePath withSuperview:(UIView *)superview __attribute__ ((deprecated("first deprecated in InFlight iOS SDK 02.04.00.00. Use the setErrorScreen:withLandscapeScreen: instead.")));

/**
 * Sets app and lib versions to display on loading screen
 * @param appVersion App version.
 * @param libVersion Library version.
 */

- (void) setVersion:(NSString *)appVersion withLibVersion:(NSString *)libVersion;

@end


/**
 * PACShellAppV1 category to handle remote events.
 */
@interface PACShellAppV1 (remoteevents)

/**
 * Remove loading screen only when portal sends in a version acknowledgement.
 * If set to false, the loading screen will be removed as soon as the page loads.
 * If set to true, the loading screen will be removed only after a version ACK from the portal is received.
 * @param boolean The value stating whether to wait for portal ACK or not.
 */
- (void)setWaitForPortalACK:(BOOL)boolean;

/**
 * Sent to the receiver when a remote-control event is received.
 * Remote-control events originate as commands from external accessories, including headsets. An application responds to these commands by controlling the audio or video media presented to the user. The ViewController that is the first responder needs to implement this function on their ViewController class and call this API to handle it.
 * @param event An event object encapsulating a remote-control command. Remote-control events have a type of UIEventTypeRemoteControl.
 */
- (void)remoteControlReceivedWithEvent:(UIEvent *)event;

@end

#pragma mark - Error codes

/**
 * PACShellApp load error codes.
 * @owner PACShellAppV1
 */
typedef enum {
    /** Unknown error. */
    PACShellAppLoadErrorUnknown                    =    4000,
    /** The host is not reachable. */
    PACShellAppLoadErrorHostNotReachable           =    4001,
    /** Timedout while trying to load initial page. */
    PACShellAppLoadErrorTimedout                   =    4002,
    /** A webview error occurred while loading initial page. */
    PACShellAppLoadErrorWebView                    =    4003,
}PACShellAppLoadErrorCode;


#pragma mark - Notifications
/**
 * Dispatched when the shell app starts loading the webpage.
 * @owner PACShellAppV1
 */

extern NSString *const PACShellAppLoadDidStartNotification;

/**
 * Dispatched when the shell app finishes loading the webpage.
 *
 * Please note if setWaitForPortalACK is set to a true value,
 * then PACShellAppLoadDidFinishNotification is dispatched only
 * after the portal acknowledgement is received from the portal.
 *
 * @owner PACShellAppV1
 */

extern NSString *const PACShellAppLoadDidFinishNotification;

/**
 * Dispatched when the shell app fails to load the webpage.
 *
 * Please note that ShellApp will retry after 5 seconds. At that
 * point, PACShellAppLoadDidStartNotification is called again.
 *
 *
 * userInfo Contains error object
 *
 * - *error* Error object. See PACShellAppLoadErrorCode.
 *
 * @owner PACShellAppV1
 */

extern NSString *const PACShellAppLoadDidFailNotification;

/**
 Dispatched when the portal sends a message to the app

 - *userInfo* Contains message and value

  - *message* Portal message to app.
  - *value* Optional value associated with the message

 Example
 
        - (void) webPortalMessageNotification:(NSNotification*)notification
        {
           NSDictionary *userInfo = [notification userInfo];
           if ([userInfo[PACWebPortalMessageKey] isEqualToString:PACWebPortalExitMessage])
           {
               // exit message from portal clears the bridge
           }
           else if ([userInfo[PACWebPortalMessageKey] isEqualToString:PACWebPortalVersionMessage])
           {
               NSString *portalVersion = userInfo[PACWebPortalValueKey];
               ...
           }
        }

  @owner PACShellAppV1
 */

extern NSString *const PACWebPortalMessageNotification;

#pragma mark - Web Portal IFAPI Keys
/**
 * @constantgroup PACWebPortalKeys
 * These are the keys associated with the userInfo of the PACWebPortalMessageNotification.
 * @owner PACShellAppV1
 */

/**
 * The key for obtaining the portal message from the userInfo
 * of the PACWebPortalMessageNotification.
 */
extern NSString *const PACWebPortalMessageKey;

/**
 * The key for obtaining the portal message value from the userInfo
 * of the PACWebPortalMessageNotification.
 */
extern NSString *const PACWebPortalValueKey;

#pragma mark - Web Portal IFAPI Messages
/**
 * @constantgroup PACWebPortalMessages
 * These are the some of the InFlight web messages.
 * @owner PACShellAppV1
 */
/**
 * The content of the PACWebPortalMessageNotification message key that is sent when
 * portal requests exit.
 */
extern NSString *const PACWebPortalExitMessage;

/**
 * The content of the PACWebPortalMessageNotification message key that is sent when
 * the portal sends the portal version. You can find the portal version
 * by getting the value from the PACWebPortalValueKey of the notification's userInfo.
 */
extern NSString *const PACWebPortalVersionMessage;
