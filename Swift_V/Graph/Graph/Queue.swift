//
//  Queue.swift
//  Graph
//
//  Created by CXY on 2019/4/26.
//  Copyright © 2019 cxy. All rights reserved.
//

import Cocoa

class Queue<T> {
    private lazy var data = [T]()
    
    var count: Int {
        return data.count
    }
    
    var isEmpty: Bool {
        return data.isEmpty
    }
    
    func enqueue(_ element: T) {
        data.append(element)
    }

    func dequeue() -> T? {
        if data.isEmpty {
            return nil
        }
        return data.remove(at: 0)
    }
}
