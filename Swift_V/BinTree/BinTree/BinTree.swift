//
//  BinTree.swift
//  BinTree
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//


class BinTreeNode<T: Equatable>: Equatable {
    static func == (lhs: BinTreeNode<T>, rhs: BinTreeNode<T>) -> Bool {
        return lhs.value == rhs.value && lhs.lchild == rhs.lchild && lhs.rchild == rhs.rchild
    }
    
    var value: T?
    
    var lchild: BinTreeNode<T>?
    
    var rchild: BinTreeNode<T>?
    
    init(value: T?) {
        self.value = value
    }
}

struct BinTree<T: Equatable> {
    
    var root: BinTreeNode<T>?
    
    init() {
    }
    
    
    private func visit(_ node: BinTreeNode<T>) {
        print(node.value!, separator: " ", terminator: " ")
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
