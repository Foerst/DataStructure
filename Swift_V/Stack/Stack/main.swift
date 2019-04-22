//
//  main.swift
//  Stack
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

var stack = Stack<Int>()

for i in 1...10 {
    stack.push(i)
}

while !stack.isEmpty {
    if let item = stack.pop() {
        print("pop \(item)")
    }
}

