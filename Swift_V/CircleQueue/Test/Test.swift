//
//  Test.swift
//  Test
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import XCTest

class Test: XCTestCase {

    func testCircleQueue() {
        var cq = CircleQueue<Int>(size: 10)

        XCTAssertTrue(cq.isEmpty)
        
        XCTAssertEqual(cq.dequeue(), nil)
        
        for i in 1..<10 {
            cq.enqueue(element: i)
        }
        
        XCTAssertTrue(cq.isFull)
        
        XCTAssertEqual(cq.count, 9)
        
        XCTAssertNotNil(cq.dequeue())
        
//        XCTAssertTrue(cq.isFull)
        
        XCTAssertEqual(cq.count, 8)
        
        XCTAssertGreaterThan(cq.count, 7)
        
        while !cq.isEmpty {
            if let element = cq.dequeue() {
                print("dequeue \(element)")
            }
        }
        
        XCTAssertEqual(cq.count, 0)
        
        XCTAssertEqual(cq.dequeue(), nil)
    }

}
