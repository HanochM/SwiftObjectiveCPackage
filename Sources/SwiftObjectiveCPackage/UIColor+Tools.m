//
//  UIColor+Tools.m
//  Shopsterhood
//
//  Created by Vlas Voloshin on 4/3/13.
//  Copyright (c) 2013 Lodoss. All rights reserved.
//

#import "UIColor+Tools.h"

#if !defined(CLAMP)
#define CLAMP(x, min, max)  ({ \
__typeof__(x) __x = (x); \
__typeof__(min) __min = (min); \
__typeof__(max) __max = (max); \
__x > __max ? __max : (__x < __min ? __min : __x); \
})
#endif

@implementation UIColor (Tools)

- (CGFloat)alpha
{
    CGFloat alpha;
    BOOL success = [self getEffectiveRed:NULL green:NULL blue:NULL alpha:&alpha];
    
    return success ? alpha : 1.0f;
}

- (CGFloat)luminance
{
    if (self.colorSpaceModel == kCGColorSpaceModelMonochrome) {
        CGFloat white;
        BOOL success = [self getWhite:&white alpha:NULL];
        if (success) {
            return white;
        }
        
        NSAssert(NO, @"Failed to get color white value. Did you specify an incompatible color?");
    } else {
        CGFloat red, green, blue;
        BOOL success = [self getEffectiveRed:&red green:&green blue:&blue alpha:NULL];
        if (success) {
            return 0.2126f * red + 0.7152f * green + 0.0722f * blue;
        }
        
        NSAssert(NO, @"Failed to get color RGB values. Did you specify an incompatible color?");
    }
    
    return -1.0f;
}

+ (UIColor *)colorWithByteRed:(unsigned char)red green:(unsigned char)green blue:(unsigned char)blue alpha:(unsigned char)alpha
{
    return [self colorWithRed:red / 255.0f green:green / 255.0f blue:blue / 255.0f alpha:alpha / 255.0f];
}

+ (UIColor *)colorWithHexString:(NSString *)hexColorString
{
    if (hexColorString == nil) {
        return nil;
    }
    
    NSString *cleanString = [hexColorString stringByReplacingOccurrencesOfString:@"#" withString:@""];
    if ([cleanString length] == 3) {
        // to convert #RGB format to #RRGGBB format
        cleanString = [NSString stringWithFormat:@"%@%@%@%@%@%@",
                       [cleanString substringWithRange:NSMakeRange(0, 1)], [cleanString substringWithRange:NSMakeRange(0, 1)],
                       [cleanString substringWithRange:NSMakeRange(1, 1)], [cleanString substringWithRange:NSMakeRange(1, 1)],
                       [cleanString substringWithRange:NSMakeRange(2, 1)], [cleanString substringWithRange:NSMakeRange(2, 1)]];
    }
    if ([cleanString length] == 6) {
        // to convert #RRGGBB format to #RRGGBBAA format
        cleanString = [cleanString stringByAppendingString:@"ff"];
    }
    
    unsigned int baseValue;
    [[NSScanner scannerWithString:cleanString] scanHexInt:&baseValue];
    
    float red = ((baseValue >> 24) & 0xFF) / 255.0f;
    float green = ((baseValue >> 16) & 0xFF) / 255.0f;
    float blue = ((baseValue >> 8) & 0xFF) / 255.0f;
    float alpha = ((baseValue >> 0) & 0xFF) / 255.0f;
    
    return [UIColor colorWithRed:red green:green blue:blue alpha:alpha];
}

- (CGColorSpaceModel)colorSpaceModel
{
    return CGColorSpaceGetModel(CGColorGetColorSpace(self.CGColor));
}

- (NSString *)hexStringValueRGBA
{
    NSString *rgbHexString = [self hexStringValueRGB];
    if (rgbHexString == nil) {
        return nil;
    }
    
    CGFloat alpha = CGColorGetAlpha(self.CGColor);
    
    return [rgbHexString stringByAppendingFormat:@"%02X", (int)(alpha * 0xFF)];
}

- (NSString *)hexStringValueRGB
{
    CGFloat red, green, blue;
    if (self.colorSpaceModel == kCGColorSpaceModelMonochrome) {
        BOOL successful = [self getWhite:&red alpha:NULL];
        if (!successful) {
            NSAssert(NO, @"Failed to get color white value. Did you specify an incompatible color?");
            return nil;
        }
        
        blue = green = red;
    } else {
        BOOL successful = [self getRed:&red green:&green blue:&blue alpha:NULL];
        if (!successful) {
            NSAssert(NO, @"Failed to get color RGBA values. Did you specify an incompatible color?");
            return nil;
        }
    }
    
    return [NSString stringWithFormat:@"#%02X%02X%02X", (int)(red * 0xFF), (int)(green * 0xFF), (int)(blue * 0xFF)];
}

- (BOOL)getEffectiveRed:(CGFloat *)red green:(CGFloat *)green blue:(CGFloat *)blue alpha:(CGFloat *)alpha
{
    if ([self colorSpaceModel] == kCGColorSpaceModelMonochrome) {
        CGFloat white;
        BOOL success = [self getWhite:&white alpha:alpha];
        if (red) {
            *red = white;
        }
        if (green) {
            *green = white;
        }
        if (blue) {
            *blue = white;
        }
        
        return success;
    } else {
        return [self getRed:red green:green blue:blue alpha:alpha];
    }
}

- (BOOL)getEffectiveHue:(CGFloat *)hue saturation:(CGFloat *)saturation brightness:(CGFloat *)brightness alpha:(CGFloat *)alpha
{
    if ([self colorSpaceModel] == kCGColorSpaceModelMonochrome) {
        CGFloat white;
        BOOL success = [self getWhite:&white alpha:alpha];
        if (hue) {
            *hue = 0.0f;
        }
        if (saturation) {
            *saturation = 0.0f;
        }
        if (brightness) {
            *brightness = white;
        }
        
        return success;
    } else {
        return [self getHue:hue saturation:saturation brightness:brightness alpha:alpha];
    }
}

- (UIColor *)colorWithDeltaHue:(CGFloat)deltaHue saturation:(CGFloat)deltaSaturation andBrightness:(CGFloat)deltaBrightness
{
    CGFloat hue, saturation, brightness, alpha;
    BOOL success = [self getEffectiveHue:&hue saturation:&saturation brightness:&brightness alpha:&alpha];
    if (success) {
        hue = CLAMP(hue + deltaHue, 0, 1);
        saturation = CLAMP(saturation + deltaSaturation, 0, 1);
        brightness = CLAMP(brightness + deltaBrightness, 0, 1);

        return [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
    } else {
        NSAssert(NO, @"Failed to get color HSBA values. Did you specify an incompatible color?");
        
        return self;
    }
}

- (UIColor *)colorWithMultipliedHue:(CGFloat)hueFactor saturation:(CGFloat)saturationFactor andBrightness:(CGFloat)brightnessFactor
{
    CGFloat hue, saturation, brightness, alpha;
    BOOL success = [self getEffectiveHue:&hue saturation:&saturation brightness:&brightness alpha:&alpha];
    if (success) {
        hue = CLAMP(hue * hueFactor, 0, 1);
        saturation = CLAMP(saturation * saturationFactor, 0, 1);
        brightness = CLAMP(brightness * brightnessFactor, 0, 1);
        
        return [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
    } else {
        NSAssert(NO, @"Failed to get color HSBA values. Did you specify an incompatible color?");

        return self;
    }
}

@end
