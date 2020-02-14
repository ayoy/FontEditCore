//
//  Format.swift
//  FontEditCore
//
//  Created by Dominik Kapusta on 14/02/2020.
//  Copyright © 2020 The Fat Cat. All rights reserved.
//

import Foundation
import FontEditCore_objc

public enum Format {
    case c, arduino, pythonList, pythonBytes
    
    public var identifier: String {
        switch self {
        case .c:
            return FormatIdentifierC
        case .arduino:
            return FormatIdentifierArduino
        case .pythonList:
            return FormatIdentifierPythonList
        case .pythonBytes:
            return FormatIdentifierPythonBytes
        }
    }
}
