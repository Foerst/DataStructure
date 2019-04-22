//
//  main.swift
//  LinkedQueue
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

var lq = LinkedQueue<Int>()

for i in 1...10 {
    lq.enqueue(element: i)
}

print("count = \(lq.count)")

while !lq.isEmpty {
    if let item = lq.dequeue() {
        print("dequeue \(item)")
    }
}

