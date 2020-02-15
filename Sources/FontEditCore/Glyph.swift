//
//  Glyph.swift
//  FontEditCore
//
//  Created by Dominik Kapusta on 14/02/2020.
//  Copyright © 2020 The Fat Cat. All rights reserved.
//

import Foundation
import FontEditCore_objc

public struct Size: Hashable {
    public var width: UInt
    public var height: UInt
    
    public init(width: UInt, height: UInt) {
        self.width = width
        self.height = height
    }
}

public struct Point: Hashable {
    public var x: UInt
    public var y: UInt
    
    public init(x: UInt, y: UInt) {
        self.x = x
        self.y = y
    }

    public func offsetInArray(forGlyphSize size: Size) -> UInt {
        return FECPointOffset(fecPoint, size.fecSize)
    }
}

open class Glyph {

    open var size: Size

    open var pixels: [Bool] {
        return fecGlyph.pixels.map { $0.boolValue }
    }
    
    public init(size: Size, pixels: [Bool] = []) {
        self.size = size
        let pixelNumbers = pixels.map { NSNumber(value: $0) }
        fecGlyph = FECGlyph(size: size.fecSize, pixels: pixelNumbers)
    }
    
    open func isPixelSet(_ point: Point) -> Bool {
        return fecGlyph.isPixelSet(point.fecPoint)
    }
    
    open func setPixelSet(_ point: Point) {
        fecGlyph.setPixelSet(point.fecPoint)
    }
    
    init(fecGlyph: FECGlyph) {
        self.size = fecGlyph.size.size
        self.fecGlyph = fecGlyph
    }

    let fecGlyph: FECGlyph
}

extension Size {
    var fecSize: FECSize {
        return FECSizeMake(width, height)
    }
}

extension FECSize {
    var size: Size {
        return Size(width: width, height: height)
    }
}

extension Point {
    var fecPoint: FECPoint {
        return FECPointMake(x, y)
    }
}

extension FECPoint {
    var point: Point {
        return Point(x: x, y: y)
    }
}
