//
//  ThreadBinTree.swift
//  BinTree
//
//  Created by CXY on 2019/4/23.
//  Copyright © 2019 cxy. All rights reserved.
//


fileprivate enum Tag {
    case link
    case thread
}

class ThreadBinTreeNode<T: Equatable>: Equatable {
    
    static func == (lhs: ThreadBinTreeNode<T>, rhs: ThreadBinTreeNode<T>) -> Bool {
        return lhs.lchild == rhs.lchild && lhs.ltag == rhs.ltag && lhs.data == rhs.data && lhs.rtag == rhs.rtag && lhs.rchild == rhs.rchild
    }
    
    var lchild: ThreadBinTreeNode<T>?
    
    fileprivate var ltag = Tag.link
    
    var data: T?
    
    var rchild: ThreadBinTreeNode<T>?
    
    fileprivate var rtag = Tag.link
    
    init(data: T?) {
        self.data = data
    }

}

/// 线索二叉树
class ThreadBinTree<T: Equatable> {
    
    // "双向链表"头结点
    private var header: ThreadBinTreeNode<T>?
    
    private var root: ThreadBinTreeNode<T>?
    
    private var pre: ThreadBinTreeNode<T>?

    init(headerData: T) {
        pre = ThreadBinTreeNode<T>(data: headerData)
    }
    
    func createTree(_ fun: (inout ThreadBinTreeNode<T>?)->Void) {
        fun(&root)
    }
    
    func createTree(_ fun: ()->ThreadBinTreeNode<T>?) {
        root = fun()
        header?.lchild = root
    }
    
    func inThreading() {
        guard let _root = root else { return }
        
        header?.lchild = _root
        
        _inThreading(_root)
        
        // pre指向中序遍历最后一个结点，即右子树右侧叶子结点
        pre?.rtag = .thread
        pre?.rchild = header
        header?.rtag = .thread
        header?.rchild = pre
    }
    
    // 线索化 类似中序遍历
    private func _inThreading(_ p: ThreadBinTreeNode<T>?) {
        if p != nil {
            _inThreading(p?.lchild)
            
            if p?.lchild == nil {
                p?.ltag = .thread
                p?.lchild = pre
            }
            
            if pre?.rchild == nil {
                pre?.rtag = .thread
                pre?.rchild = p
            }
            
            pre = p
            
            _inThreading(p?.rchild)
        }
    }
    
    func inOrderThreadTraverse(process: ((ThreadBinTreeNode<T>?)->Void)) {
        var p = root
        
        while p != header {
            
            while p?.ltag == .link {
                p = p?.lchild
            }
            
            process(p)
            
            while p?.rtag == .thread && p?.rchild != header {
                p = p?.rchild
                process(p)
            }
            
            p = p?.rchild
        }
    }
    
    private func visit(_ node: ThreadBinTreeNode<T>) {
        print(node.data!, separator: " ", terminator: " ")
    }
    
    func preOrderTraverse() {
        _preOrderTraverse(root)
    }
    
    private func _preOrderTraverse(_ root: ThreadBinTreeNode<T>?) {
        if root != nil {
            visit(root!)
            _preOrderTraverse(root?.lchild)
            _preOrderTraverse(root?.rchild)
        }
    }
    
}
