//
//  Graph.swift
//  Graph
//
//  Created by CXY on 2019/4/26.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

private let vertexsCountLimit = 100
private let edgesCountLimit = 4950

fileprivate class EdgeNode {
    // 邻接点索引
    var adjvex = 0
    var weight = 0
    var next: EdgeNode?
    
    init(adjvex: Int, weight: Int = 0) {
        self.adjvex = adjvex
        self.weight = weight
    }
}

fileprivate struct VertexNode {
    var data: Character?
    var firstEdge: EdgeNode?
}

class Graph {
    /// 顶点数组
    private var vertexs = [Character]()
    
    /// 邻接矩阵
    private var adjMatrix: [[Int]]?
    
    private var adjList: [VertexNode]?
    
    /// 顶点数
    private var vertexsCount = 0
    
    /// 边数
    private var edgesCount = 0
    
    private lazy var visited = [Bool]()
    
    func createAdjMatrix() {
        print("please input number of vertexs(>0):")
        guard let str = readLine(), let vcount = Int(str), vcount > 0 else {
            fatalError("wrong data!")
        }
        vertexsCount = vcount
        
        adjMatrix = [[Int]](repeating: [Int](repeating: 0, count: vertexsCount), count: vertexsCount)
        visited = [Bool](repeating: false, count: vertexsCount)
        
        print("please input number of edges:")
        guard let _str = readLine(), let ecount = Int(_str) else {
            fatalError("Not a number!")
        }
        edgesCount = ecount
        
        print("input vertex, separated with ' '")
        guard let tmp = readLine(), !tmp.isEmpty, tmp.split(separator: " ").count == vertexsCount else {
            fatalError("wrong data!")
        }
        let vertexArray = tmp.split(separator: " ")
        vertexs = vertexArray.map({ (str) -> Character in
            return str.first!
        })
        
        for _ in 0..<edgesCount {
            print("input edge start index & end index & weight, separated with ' '")
            
            guard let inputString = readLine() else {
                fatalError("wrong data!")
            }
            let array = inputString.split(separator: " ")
    
            guard array.count >= 2 else {
                fatalError("wrong data!")
            }
            
            guard let startIdx = Int(array[0]), let endIdx = Int(array[1]) else {
                fatalError("wrong data!")
            }
            var weight = 1
            if array.count >= 3 {
                weight = Int(array[2]) ?? 1
            }
            
            adjMatrix?[startIdx][endIdx] = weight
            // 无向图邻接矩阵轴对称
            adjMatrix?[endIdx][startIdx] = weight
        }
        
    }
    
    
    func createAdjList() {
        print("please input number of vertexs(>0):")
        guard let str = readLine(), let vcount = Int(str), vcount > 0 else {
            fatalError("wrong data!")
        }
        vertexsCount = vcount
        
        adjList = [VertexNode]()
        visited = [Bool](repeating: false, count: vertexsCount)
        
        print("please input number of edges:")
        guard let _str = readLine(), let ecount = Int(_str) else {
            fatalError("Not a number!")
        }
        edgesCount = ecount
        
        print("input vertex, separated with ' '")
        guard let tmp = readLine(), !tmp.isEmpty, tmp.split(separator: " ").count == vertexsCount else {
            fatalError("wrong data!")
        }
        
        let vertexArray = tmp.split(separator: " ")
        let _ = vertexArray.map({ (str) -> Character in
            let char = str.first!
            adjList?.append(VertexNode(data: char, firstEdge: nil))
            return char
        })
        
        for _ in 0..<edgesCount {
            print("input edge start Vertext index & end vertext index, separated with ' '")
            guard let indexes = readLine(), !indexes.isEmpty, indexes.split(separator: " ").count == 2 else {
                fatalError("wrong data!")
            }
            
            let idArray = indexes.split(separator: " ").map { (substr) -> Int in
                return Int(substr)!
            }
            let start = Int(idArray.first!)
            let end = Int(idArray.last!)
            let node = EdgeNode(adjvex: end)
            node.next = adjList?[start].firstEdge
            adjList?[start].firstEdge = node
        }

    }
    
    private func visit(index: Int) {
        if index >= 0 && index < vertexsCount {
            print("node \(String(vertexs[index]))")
            visited[index] = true
        } else {
            print("visit index error!")
        }
    }
    
    func DFS_AdjMatrix() {
        print("\(#function)")
        for i in 0..<vertexsCount { // 非连通图
            if !visited[i] {
               _DFS_AdjMatrix(i)
            }
        }
    }
    
    private func _DFS_AdjMatrix(_ i: Int) {
        guard !vertexs.isEmpty, let matrix = adjMatrix, !matrix.isEmpty else {
            print("Data Error!")
            return
        }
        
        visit(index: i)
        for j in 0..<vertexsCount {
            if matrix[i][j] >= 1 && !visited[j] {
                _DFS_AdjMatrix(j)
            }
        }
    }
    
    func DFS_AdjList() {
        print("\(#function)")
        for i in 0..<vertexsCount { // 非连通图
            if !visited[i] {
                _DFS_AdjList(i)
            }
        }
    }
    
    private func _DFS_AdjList(_ i: Int) {
        print("node \(String((adjList?[i].data)!))")
        visited[i] = true
        var node = adjList?[i].firstEdge
        while node != nil {
            let j = (node?.adjvex)!
            if !visited[j] {
                _DFS_AdjList(j)
            }
            node = node?.next
        }
    }
    
    func BFS_AdjMatrix() {
        print("\(#function)")
        reset()
        guard !vertexs.isEmpty, let matrix = adjMatrix, !matrix.isEmpty else {
            print("Data Error!")
            return
        }
        let queue = Queue<Int>()
        
        for i in 0..<vertexsCount { // 非连通图
            if !visited[i] {
                queue.enqueue(i)
                visit(index: i)
                while !queue.isEmpty {
                    if let idx = queue.dequeue() {
                        
                        for j in 0..<vertexsCount {
                            if matrix[idx][j] >= 1 && !visited[j] {
                                queue.enqueue(j)
                                visit(index: j)
                            }
                        }
                    }
                }
            }
        }
    }
    
    private func reset() {
        for i in 0..<visited.count {
            visited[i] = false
        }
    }
    
    func BFS_AdjList() {
        print("\(#function)")
        reset()
        
        let queue = Queue<Int>()

        for i in 0..<vertexsCount {
            if !visited[i] {
                queue.enqueue(i)
                print("node \(String((adjList?[i].data)!))")
                visited[i] = true
                
                while !queue.isEmpty {
                    if let idx = queue.dequeue() {
                        
                        var node = adjList?[idx].firstEdge
                        while node != nil {
                            let j = (node?.adjvex)!
                            if !visited[j] {
                                queue.enqueue(j)
                                print("node \(String((adjList?[j].data)!))")
                                visited[j] = true
                            }
                            node = node?.next
                        }
                        
                    }
                }
            }
        }
    }
    
    // Minimum Cost Spanning Tree 最小生成树
    func mcst() -> Int {
        return 0
    }
    
    // Prim普里姆算法
    private func prim() {
        
    }
    
    // 克鲁斯卡尔算法
    private func kruskal() {
        
    }
}
