//
//  BinTree.swift
//  BinTree
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

class BinTreeNode<T> {
    var data: T?
    var lchild: BinTreeNode<T>?
    var rchild: BinTreeNode<T>?
    
    init(data: T?) {
        self.data = data
    }
}

struct BinTree<T> {
    
    var root: BinTreeNode<T>?
    
    init() {
        root = BinTreeNode<T>(data: nil)
    }
    
    private func visit(_ node: BinTreeNode<T>) {
        print(node.data!)
    }
    
    func preOrderTraverse(_ root: BinTreeNode<T>?) {
        if root != nil {
            visit(root!)
            preOrderTraverse(root?.lchild)
            preOrderTraverse(root?.rchild)
        }
    }
    
    func inOrderTraverse(_ root: BinTreeNode<T>?) {
        if root != nil {
            inOrderTraverse(root?.lchild)
            visit(root!)
            inOrderTraverse(root?.rchild)
        }
    }
    
    func postOrderTraverse(_ root: BinTreeNode<T>?) {
        if root != nil {
            postOrderTraverse(root?.lchild)
            postOrderTraverse(root?.rchild)
            visit(root!)
        }
    }
}
