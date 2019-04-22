//
//  main.swift
//  CircleQueue
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

var cq = CircleQueue<Int>(size: 10)

// only size-1
for i in 1..<10 {
    cq.enqueue(element: i)
}

while !cq.isEmpty {
    if let element = cq.dequeue() {
        print("dequeue \(element)")
    }
}



