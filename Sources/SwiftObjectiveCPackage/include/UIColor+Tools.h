//
//  UIColor+Tools.h
//  Shopsterhood
//
//  Created by Vlas Voloshin on 4/3/13.
//  Copyright (c) 2013 Lodoss. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Tools)

@property (nonatomic, readonly, assign) CGFloat alpha;
@property (nonatomic, readonly, assign) CGFloat luminance;

+ (UIColor *)colorWithByteRed:(unsigned char)red green:(unsigned char)green blue:(unsigned char)blue alpha:(unsigned char)alpha;
+ (UIColor *)colorWithHexString:(NSString *)hexColorString;

- (NSString *)hexStringValueRGBA;
- (NSString *)hexStringValueRGB;
- (BOOL)getEffectiveRed:(CGFloat *)red green:(CGFloat *)green blue:(CGFloat *)blue alpha:(CGFloat *)alpha;
- (BOOL)getEffectiveHue:(CGFloat *)hue saturation:(CGFloat *)saturation brightness:(CGFloat *)brightness alpha:(CGFloat *)alpha;
- (UIColor *)colorWithDeltaHue:(CGFloat)deltaHue saturation:(CGFloat)deltaSaturation andBrightness:(CGFloat)deltaBrightness;
- (UIColor *)colorWithMultipliedHue:(CGFloat)hueFactor saturation:(CGFloat)saturationFactor andBrightness:(CGFloat)brightnessFactor;

@end
