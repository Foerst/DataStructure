//
//  Queue.swift
//  LinkedQueue
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

private class Node<T: Equatable>: Equatable {
    
    var data: T?
    
    var next: Node<T>?
    
    init(data: T?) {
        self.data = data
    }
    
    static func == (lhs: Node<T>, rhs: Node<T>) -> Bool {
        return lhs.data == rhs.data && lhs.next == rhs.next
    }
}


struct LinkedQueue<T: Equatable> {
    
    private var front: Node<T>?
    
    private var rear: Node<T>?
    
    init() {
        let headerNode = Node<T>(data: nil)
        front = headerNode
        rear = front
    }
    
    var isEmpty: Bool {
        return front == rear
    }
    
    var count: UInt {
        var p = front?.next
        var count: UInt = 0
        while p != nil {
            count += 1
            p = p?.next
        }
        return count
    }
    
    mutating func enqueue(element: T) {
        let node = Node(data: element)
        rear?.next = node
        rear = node
    }
    
    mutating func dequeue() -> T? {
        if isEmpty {
            return nil
        }
        let p = front?.next
        front?.next = p?.next
        if rear == p {
            rear = front
        }
        return p?.data
    }
    
}
