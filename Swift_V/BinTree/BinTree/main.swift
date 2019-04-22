//
//  main.swift
//  BinTree
//
//  Created by CXY on 2019/4/22.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

var binTree = BinTree<String>()

func createTree(_ tree: inout BinTreeNode<String>?) {
    if let data = readLine(strippingNewline: true) {
        if data.elementsEqual("#") {
            tree = nil
        } else {
            tree = BinTreeNode<String>(data: data)
            tree!.data = data
            createTree(&tree!.lchild)
            createTree(&tree!.rchild)
        }
    }
}

print("please input pre order bin tree node, seprated by '#':")

createTree(&binTree.root)

print("preOrderTraverse:")

binTree.preOrderTraverse(binTree.root)

print("inOrderTraverse:")

binTree.inOrderTraverse(binTree.root)

print("postOrderTraverse:")

binTree.postOrderTraverse(binTree.root)
