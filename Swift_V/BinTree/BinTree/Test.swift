//
//  Test.swift
//  BinTree
//
//  Created by CXY on 2019/4/23.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

func testBinTree() {
    var binTree = BinTree<String>()
    
    func createTree(_ tree: inout BinTreeNode<String>?) {
        if let data = readLine(strippingNewline: true) {
            if data.elementsEqual("#") {
                tree = nil
            } else {
                tree = BinTreeNode<String>(data: data)
                createTree(&tree!.lchild)
                createTree(&tree!.rchild)
            }
        }
    }
    
    func createBinTree() -> BinTreeNode<String>? {
        var root: BinTreeNode<String>?
        if let data = readLine(strippingNewline: true) {
            if data.elementsEqual("#") {
                root = nil
            } else {
                root = BinTreeNode<String>(data: data)
                root?.lchild = createBinTree()
                root?.rchild = createBinTree()
            }
        }
        return root
    }
    
    //binTree.createBinTree { () -> BinTreeNode<String>? in
    //    print("please input pre order bin tree node, seprated by '#':")
    //    return createBinTree()
    //}
    
    binTree.createBinTree { (root) in
        print("please input pre order bin tree node, seprated by '#':")
        createTree(&root)
    }
    
    print("\npreOrderTraverse:")
    
    binTree.preOrderTraverse()
    
    print("\ninOrderTraverse:")
    
    binTree.inOrderTraverse()
    
    print("\npostOrderTraverse:")
    
    binTree.postOrderTraverse()
    
    print("\n")
    
}



func testThreadBinaryTree() {
    func createBinTree() -> ThreadBinTreeNode<String>? {
        var root: ThreadBinTreeNode<String>?
        if let data = readLine(strippingNewline: true) {
            if data.elementsEqual("#") {
                root = nil
            } else {
                root = ThreadBinTreeNode<String>(data: data)
                root?.lchild = createBinTree()
                root?.rchild = createBinTree()
            }
        }
        return root
    }
    
    let tree = ThreadBinTree<String>(headerData: "")
    tree.createTree { () -> ThreadBinTreeNode<String>? in
        print("input string ended with enter, separated with #")
        return createBinTree()
    }
    
    print("\nPreOrderTraverse:")
    
    tree.preOrderTraverse()
    
    tree.inThreading()
    
    print("\ninOrderThreadTraverse:")
    
    tree.inOrderThreadTraverse { (node) in
        print(node?.data ?? "", separator: " ", terminator: " ")
    }
    
    print("\n")
}
