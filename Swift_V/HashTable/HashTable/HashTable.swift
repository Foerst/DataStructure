//
//  HashTable.swift
//  HashTable
//
//  Created by CXY on 2019/7/23.
//  Copyright © 2019 cxy. All rights reserved.
//

import Cocoa

struct HashTable {
    
    static private let maxSize = 20
    
    static private let nullKey = -32768
    
    private lazy var array = [Int](repeating: HashTable.nullKey, count: HashTable.maxSize)
    
    private func hash(_ key: Int) -> Int {
        return key % HashTable.maxSize
    }
    
    mutating func insert(_ key: Int) {
        var addr = hash(key)
        while array[addr] != HashTable.nullKey {
            addr = (addr + 1) % HashTable.maxSize // linear detec
        }
        array[addr] = key
    }
    
    mutating func search(_ key: Int) -> Int {
        var addr = hash(key)
        while array[addr] != key {
            addr = (addr + 1) % HashTable.maxSize // linear detec
            if array[addr] == HashTable.nullKey || addr == hash(key) {
                return -1 // not found
            }
        }
        return addr
    }
}
