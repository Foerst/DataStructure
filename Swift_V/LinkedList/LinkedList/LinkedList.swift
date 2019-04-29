//
//  LinkedList.swift
//  LinkedList
//
//  Created by CXY on 2019/4/29.
//  Copyright © 2019 cxy. All rights reserved.
//

import Cocoa

class Node {
    var data: String?
    var next: Node?
    
    init(data: String? = nil) {
        self.data = data
    }
}

class LinkedList {
    
    private var header = Node()
    
    func create(input: String) {
        let array = input.split(separator: " ")
        
        var pre: Node? = header
        for str in array {
            let node = Node(data: String(str))
            pre?.next = node
            pre = node
        }
    }
    
    func traverse() {
        print("\(#function)")
        var p = header.next
        while p != nil {
            print("\(p?.data ?? "") ")
            p = p?.next
        }
    }
    
    // 单链表翻转
    func reverse() {
        print("\(#function)")
        var cur = header.next
        header.next = nil
        
        while cur != nil {
            let next = cur?.next
            cur?.next = header.next
            header.next = cur
            cur = next
        }
    }
    
    // 单链表判断是否有环
    func hasCycle() -> Bool {
        print("\(#function)")
        var slow = header.next
        var fast = header.next
        while fast != nil {
            slow = slow?.next
            fast = fast?.next?.next
            if fast != nil && fast === slow {
                return true
            }
        }
        return false
    }
    
    // 求单链表找环入口, l+2a+b = 2(l+b) ==> l = b
    func detectCycle() -> Node? {
        print("\(#function)")
        var node: Node?
        var slow = header.next
        var fast = header.next
        while fast != nil {
            slow = slow?.next
            fast = fast?.next?.next
            if fast === slow {
                var first: Node? = header.next
                while first !== slow {
                    first = first?.next
                    slow = slow?.next
                }
                node = slow
                break
            }
        }
        return node
    }
    
    // 判断2个单链表是否有交点, 比较最后一个结点即可
    func intersectWith(list: LinkedList) ->Bool {
        var last: Node? = header.next
        var otherLast: Node? = list.header.next
        
        while last?.next != nil {
            last = last?.next
        }
        
        while otherLast?.next != nil {
            otherLast = otherLast?.next
        }
        return last === otherLast
    }
    
    private func listLength() -> Int {
        var p = header.next
        var length = 0
        while p != nil {
            length += 1
            p = p?.next
        }
        return length
    }
    
    // 求2个单链表的交点
    func commonNode(list: LinkedList) -> Node? {
        guard intersectWith(list: list) else {
            return nil
        }
        
        let length = listLength()
        let otherLength = list.listLength()
        var distance = abs(length-otherLength)
        var p1: Node? = header.next
        var p2: Node? = list.header.next

        while distance != 0 {
            p2 = p2?.next
            distance -= 1
        }
        
        while p1 != nil && p2 != nil {
            if p1 === p2 {
                return p1
            }
            p1 = p1?.next
            p2 = p2?.next
        }
        return nil
    }
    
    // 求2个单链表的交点, 将尾部指向头构成环，求环入口
    func commonNode2(list: LinkedList) -> Node? {
        guard intersectWith(list: list) else {
            return nil
        }
        
        var p2 = list.header.next
        while p2 != nil && p2?.next != nil {
            p2 = p2?.next
        }
        p2?.next = list.header.next
        
        return detectCycle()
    }
    
    // 单链表找中间节点
    func middleNode() -> Node? {
        var slow = header.next
        var fast = header.next
        while fast != nil && fast?.next != nil {
            slow = slow?.next
            fast = fast?.next?.next
        }
        return slow
    }
    
    // mergeTwoLists ordered
    func mergeTwoLists(_ list: LinkedList) {
        var p1 = header.next
        var pre1: Node? = header
        var p2 = list.header.next
        
        while p1 != nil && p2 != nil {
            let num1 = Int(p1?.data ?? "")!
            let num2 = Int(p2?.data ?? "")!
            if num1 < num2 {
                pre1 = p1
                p1 = p1?.next
            } else {
                let node = Node(data: p2?.data)
                node.next = pre1?.next
                pre1?.next = node
                p2 = p2?.next
                pre1 = pre1?.next
            }
        }
        
        if p2 != nil {
            pre1?.next = p2
        }
    }
    
    
    func mergeList(_ list: LinkedList) -> LinkedList {
        var p: Node? = Node()
        let t = p!
        var p1 = header.next
        var p2 = list.header.next
        
        while p1 != nil && p2 != nil {
            let num1 = Int(p1?.data ?? "")!
            let num2 = Int(p2?.data ?? "")!
            if num1 < num2 {
                p?.next = p1
                p1 = p1?.next
            } else {
                p?.next = p2
                p2 = p2?.next
            }
            p = p?.next
        }
        
        if p1 != nil {
            p?.next = p1
        }
        
        if p2 != nil {
            p?.next = p2
        }
        let ret = LinkedList()
        ret.header = t
        return ret
    }
}



