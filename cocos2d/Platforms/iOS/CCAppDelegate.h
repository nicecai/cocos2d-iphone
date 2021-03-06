//
//  CCAppDelegate.h
//  cocos2d-ios
//
//  Created by Viktor on 12/6/13.
//
//

#import "../../ccMacros.h"
#ifdef __CC_PLATFORM_IOS

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CCDirectorIOS.h"

/**
 *  The screen mode defines how different types of screens and resolutions are handled.
 */
typedef NS_ENUM(unsigned char, CCScreenMode)
{
    /// The flexible screen mode is Cocos2d's default. It will give you an area that can vary slightly in size. In landscape mode the height will be 320 points for mobiles and 384 points for tablets. The width of the area can vary from 480 to 568 points.
    CCScreenModeFlexible,
    
    /// The fixed screen mode will setup the working area to be 568 x 384 points. Depending on the device, the outer edges may be cropped. The safe area, that will be displayed on all sorts of devices, is 480 x 320 points and placed in the center of the working area.
    CCScreenModeFixed,
};

NSString* const CCConfigPixelFormat;
NSString* const CCConfigScreenMode;
NSString* const CCConfigAnimationInterval;


@class CCAppDelegate;
@class CCScene;

@interface CCNavigationController : UINavigationController <CCDirectorDelegate>
{
}
@end

/**
 *  Most Cocos2d apps should override the CCAppDelegate, it serves as the apps starting point. By the very least, the startScene method should be overridden to return the first scene the app should display. To further customize the behavior of Cocos2d, such as the screen mode of pixel format, override the applicaton:didFinishLaunchingWithOptions: method.
 */
@interface CCAppDelegate : NSObject <UIApplicationDelegate>
{
    UIWindow *window_;
	CCNavigationController *navController_;
    
}

// -----------------------------------------------------------------------
/** @name Accessing Window and Navigation Controller */
// -----------------------------------------------------------------------

/**
 *  The window used to display the Cocos2d content.
 */
@property (nonatomic, strong) UIWindow *window;

/**
 *  The navigation controller that Cocos2d is using.
 */
@property (atomic, readonly) CCNavigationController *navController;

// -----------------------------------------------------------------------
/** @name Setting Up the Start Scene */
// -----------------------------------------------------------------------

/**
 *  Override this method to return the first scene that Cocos2d should display.
 *
 *  @return Starting scene for your app.
 */
- (CCScene*) startScene;

// -----------------------------------------------------------------------
/** @name Cocos2d Configuration */
// -----------------------------------------------------------------------

/**
 *  This method is normally called from the applicaton:didFinishLaunchingWithOptions: method. It will configure Cocos2d with the options that you provide. You can leave out any of the options and Cocos2d will use the default values.
 *
 *  Currently supported keys for the configuration dictionary are:
 *
 *  - CCConfigPixelFormat NSString with the pixel format, normally kEAGLColorFormatRGBA8 or kEAGLColorFormatRGB565. The RGB565 option is faster, but will allow less colors.
 *  - CCConfigScreenMode NSNumber with int specifying which CCScreenMode to use, CCScreenModeFlexible is the default option.
 *  - CCConfigAnimationInterval NSNumber with double. Specifies the interval between animation frames. Supported values are 1.0/60 and 1.0/30.
 *
 *  @param config Dictionary with options for configuring Cocos2d.
 */
- (void) setupCocos2dWithOptions:(NSDictionary*)config;

@end

#endif
