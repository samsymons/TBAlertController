//
//  TBAlertController.h
//  TBAlertController
//
//  Created by Tanner on 9/22/14.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TBAlertAction.h"

typedef void (^TBAlertControllerBlock)();

typedef NS_ENUM(NSInteger, TBAlertControllerStyle) {
    TBAlertControllerStyleActionSheet = 0,
    TBAlertControllerStyleAlert
};


@interface TBAlertController : NSObject

#pragma mark Properties

@property (nonatomic      ) TBAlertControllerStyle style;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *message;
// destructiveButtonIndex defaults to NSNotFound.
// Indexes greater than the number of buttons will be ignored.
@property (nonatomic) NSInteger destructiveButtonIndex;

- (NSUInteger)numberOfButtons;

#pragma mark init

- (instancetype)initWithStyle:(TBAlertControllerStyle)style;
- (instancetype)initWithTitle:(NSString *)title message:(NSString *)message style:(TBAlertControllerStyle)style;

#pragma mark Cancel button

- (void)setCancelButton:(TBAlertAction *)button;
- (void)setCancelButtonWithTitle:(NSString *)title;
- (void)setCancelButtonWithTitle:(NSString *)title buttonAction:(void(^)())buttonBlock;
- (void)setCancelButtonWithTitle:(NSString *)title target:(id)target action:(SEL)action;
- (void)setCancelButtonWithTitle:(NSString *)title target:(id)target action:(SEL)action withObject:(id)object;
- (void)setCancelButtonEnabled:(BOOL)enabled;
- (void)removeCancelButton;

#pragma mark Other buttons

- (void)addOtherButton:(TBAlertAction *)button;
- (void)addOtherButtonWithTitle:(NSString *)title;
- (void)addOtherButtonWithTitle:(NSString *)title buttonAction:(void(^)())buttonBlock;
- (void)addOtherButtonWithTitle:(NSString *)title target:(id)target action:(SEL)action;
- (void)addOtherButtonWithTitle:(NSString *)title target:(id)target action:(SEL)action withObject:(id)object;
- (void)setButtonEnabled:(BOOL)enabled atIndex:(NSUInteger)buttonIndex;
- (void)removeButtonAtIndex:(NSUInteger)buttonIndex;

#pragma mark Displaying alert

// "animated" only applies to iOS 8
- (void)showFromViewController:(UIViewController *)viewController;
- (void)showFromViewController:(UIViewController *)viewController animated:(BOOL)animated completion:(void(^)())completion;

@end
