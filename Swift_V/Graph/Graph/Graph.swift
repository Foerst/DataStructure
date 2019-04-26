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

struct Graph {
    /// 顶点数组
    private var vertexs = [Character]()
    
    /// 邻接矩阵
    private var adjMatrix: [[Int]]?
    
    /// 顶点数
    private var vertexsCount = 0
    
    /// 边数
    private var edgesCount = 0
    
    private lazy var visited = [Bool]()
    
    mutating func createAdjMatrix() {
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
    
    
    private mutating func visit(index: Int) {
        if index >= 0 && index < vertexsCount {
            print("node \(String(vertexs[index]))")
            visited[index] = true
        } else {
            print("visit index error!")
        }
        
    }
    
    mutating func DFS_AdjMatrix() {
        print("\(#function)")
        for i in 0..<vertexsCount { // 非连通图
            if !visited[i] {
               _DFS_AdjMatrix(i)
            }
        }
    }
    
    private mutating func _DFS_AdjMatrix(_ i: Int) {
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
        
    }
    
    mutating func BFS_AdjMatrix() {
        print("\(#function)")
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
    
    func BFS_AdjList() {
        
    }
}
