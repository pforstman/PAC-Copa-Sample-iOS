//
//  DrawView.h
//  PanaSkyKit
//
//  Created by Paul Forstman on 9/16/14.
//  Copyright (c) 2014 Mercury. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^DrawView_DrawBlock)(UIView* v,CGContextRef context);

@interface DrawView : UIView

@property (nonatomic,copy) DrawView_DrawBlock drawBlock;

@end

@interface UIView (DrawView)

- (void)addDrawBlock:(DrawView_DrawBlock)drawBlock;

@end

/// Stroke Methods

/** Draws a stroke that takes up 1 physical pixel. The start and end points should be whole numbers for
 rendering to occur correctly.
 */
void draw1PxStroke(CGContextRef context, CGPoint startPoint, CGPoint endPoint, UIColor* color);
void draw2PxStroke(CGContextRef context, CGPoint startPoint, CGPoint endPoint, UIColor* color);
void drawStroke(CGContextRef context, CGPoint startPoint, CGPoint endPoint, UIColor* color, CGFloat lineOffset, CGFloat lineWidth);
void drawLinearGradient(CGContextRef context, CGRect rect, UIColor* startColor, UIColor*  endColor);
void drawGradient(CGContextRef context, CGRect rect, NSArray *colors, CGFloat *locations);
void drawCircle(CGContextRef context, CGRect rect, UIColor *color);
void drawRoundedRect(CGContextRef context, CGRect rect, CGFloat radius, UIColor *color);
UIImage* createMaskImageFromPathInRect(UIBezierPath *path, CGRect rect);
