//
//  FECSize.h
//  FontEditCore
//
//  Created by Dominik Kapusta on 13/02/2020.
//  Copyright © 2020 The Fat Cat. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct FECSize {
    NSUInteger width;
    NSUInteger height;
};
typedef struct __attribute__((objc_boxable)) FECSize FECSize;

static inline FECSize
FECSizeMake(NSUInteger width, NSUInteger height)
{
    FECSize sz; sz.width = width; sz.height = height; return sz;
}


struct FECPoint {
    NSUInteger x;
    NSUInteger y;
};
typedef struct __attribute__((objc_boxable)) FECPoint FECPoint;

static inline FECPoint
FECPointMake(NSUInteger x, NSUInteger y)
{
    FECPoint p; p.x = x; p.y = y; return p;
}

static inline NSUInteger
FECPointOffset(struct FECPoint p, struct FECSize sz)
{
    return p.y * sz.width + p.x;
}


struct FECMargins {
    NSUInteger top;
    NSUInteger bottom;
};
typedef struct __attribute__((objc_boxable)) FECMargins FECMargins;

static inline FECMargins
FECMarginsMake(NSUInteger top, NSUInteger bottom)
{
    FECMargins m; m.top = top; m.bottom = bottom; return m;
}


@interface FECGlyph : NSObject

- (instancetype)initWithSize:(FECSize)size;
- (instancetype)initWithSize:(FECSize)size pixels:(nullable NSArray<NSNumber *> *)pixels;

- (BOOL)isPixelSet:(FECPoint)point;
- (void)setPixelSet:(FECPoint)point value:(BOOL)value;

- (NSUInteger)topMargin;
- (NSUInteger)bottomMargin;

@property (nonatomic, assign, readonly) FECSize size;
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *pixels;
@end


@protocol FECFaceReader <NSObject>

- (BOOL)isPixelSetAtPoint:(FECPoint)point forGlyphWithID:(NSUInteger)glyphID;

@property (nonatomic, assign, readonly) FECSize fontSize;
@property (nonatomic, assign, readonly) NSUInteger numberOfGlyphs;
@end


@interface FECFace : NSObject

- (instancetype)initWithFaceReader:(id<FECFaceReader>)faceReader;

- (FECGlyph *)glyphAtIndex:(NSUInteger)index;
- (void)setGlyph:(FECGlyph *)glyph atIndex:(NSUInteger)index;

- (FECGlyph *)objectAtIndexedSubscript:(NSUInteger)index;
- (void)setObject:(FECGlyph *)newValue atIndexedSubscript:(NSUInteger)index;

- (FECMargins)calculateMargins;

@property (nonatomic, assign, readonly) FECSize glyphSize;
@property (nonatomic, assign, readonly) NSUInteger numberOfGlyphs;
@property (nonatomic, copy, readonly) NSArray<FECGlyph *> *glyphs;
@end

NS_ASSUME_NONNULL_END
