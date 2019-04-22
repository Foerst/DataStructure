//
//  CircleQueue.swift
//  CircleQueue
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Cocoa


/// 循环队列
struct CircleQueue<T> {
    
    private var data = [T?]()
    
    /// 头索引
    var front = 0
    
    /// 尾索引, 预留一个空位, 只剩一个位置时即为满
    var rear = 0
    
    /// 最大容量
    private let maxSize: Int
    
    init(size: Int) {
        maxSize = size
        data = [T?](repeating: nil, count: size)
    }
    
    var count: Int {
        return (rear - front + maxSize ) % maxSize
    }
    
    var isFull: Bool {
        return (rear + 1) % maxSize == front
    }
    
    var isEmpty: Bool {
        return rear == front
    }
    
    mutating func enqueue(element: T) {
        if isFull {
            return
        }
        data[rear] = element
        rear = (rear + 1) % maxSize
    }
    
    mutating func dequeue() -> T? {
        if isEmpty {
            return nil
        }
        let item = data[front]
        data[front] = nil
        front = (front + 1) % maxSize
        return item
    }
}
