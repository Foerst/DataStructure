//
//  Stack.swift
//  Stack
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

struct Stack<T> {
    
    private var data = [T]()
    
    var isEmpty: Bool {
        return data.isEmpty
    }
    
    mutating func push(_ element: T) {
        data.append(element)
    }
    
    mutating func pop() -> T? {
        return data.popLast()
    }
    
}
