//
//  BinTree.swift
//  BinTree
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//


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
    }
    
    
    private func visit(_ node: BinTreeNode<T>) {
        print(node.data!, separator: " ", terminator: " ")
//        print(node.data!)
    }
    
    mutating func createBinTree(_ fun: (inout BinTreeNode<T>?)->Void) {
        fun(&root)
    }
    
    mutating func createBinTree(_ fun: ()->BinTreeNode<T>?) {
        root = fun()
    }
    
    func preOrderTraverse() {
        _preOrderTraverse(root)
    }
    
    private func _preOrderTraverse(_ root: BinTreeNode<T>?) {
        if root != nil {
            visit(root!)
            _preOrderTraverse(root?.lchild)
            _preOrderTraverse(root?.rchild)
        }
    }
    
    func inOrderTraverse() {
        _inOrderTraverse(root)
    }
    
    func _inOrderTraverse(_ root: BinTreeNode<T>?) {
        if root != nil {
            _inOrderTraverse(root?.lchild)
            visit(root!)
            _inOrderTraverse(root?.rchild)
        }
    }
    
    func postOrderTraverse() {
        _postOrderTraverse(root)
    }
    
    func _postOrderTraverse(_ root: BinTreeNode<T>?) {
        if root != nil {
            _postOrderTraverse(root?.lchild)
            _postOrderTraverse(root?.rchild)
            visit(root!)
        }
    }
}
