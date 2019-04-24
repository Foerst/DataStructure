//
//  Problems.swift
//  BinTree
//
//  Created by CXY on 2019/4/24.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation


// 1.count the leaf node

var leafNum = 0

func countLeafNum(_ root: BinTreeNode<String>?) {
    if root != nil {
        if root?.lchild == nil && root?.rchild == nil {
            leafNum += 1
            print("leaf \(String(describing: root!.data!))")
        }
        countLeafNum(root?.lchild)
        countLeafNum(root?.rchild)
    }
}

// 2.reverse binary tree

func reverseBinTree(_ root: BinTreeNode<String>?) {
    if root != nil {
        let tmp = root?.rchild
        root?.rchild = root?.lchild
        root?.lchild = tmp
        reverseBinTree(root?.lchild)
        reverseBinTree(root?.rchild)
    }
}


// 3. calculate binary tree deep

func binTreeDeep(_ root: BinTreeNode<String>?) -> UInt {
    if root != nil {
        let left = binTreeDeep(root?.lchild)
        let right = binTreeDeep(root?.rchild)
        return max(left, right) + 1
    }
    return 0
}

// 4. print every node deep

func printNodeDeep(_ root: BinTreeNode<String>?, deep: UInt = 1) {
    if root != nil {
        print("node: \(String(describing: root!.data!)) ,deep: \(deep)")
        printNodeDeep(root?.lchild, deep: deep + 1)
        printNodeDeep(root?.rchild, deep: deep + 1)
    }
}

// 5. level Traverse

func levelTraverse(_ root: BinTreeNode<String>?) {
    if root != nil {
        var queue = LinkedQueue<BinTreeNode<String>>()
        queue.enqueue(element: root!)
        var level = 0
        while !queue.isEmpty {
            let count = queue.count
            level += 1
            for _ in 0..<count {
                if let node = queue.dequeue() {
                    print("node: \(String(describing: node.data!)) level: \(level)")
                    if node.lchild != nil {
                        queue.enqueue(element: node.lchild!)
                    }
                    if node.rchild != nil {
                        queue.enqueue(element: node.rchild!)
                    }
                }
            }
            
        }
    }
}

// 6. copy tree

func copyBinTree(_ root: BinTreeNode<String>?) {
    
}
