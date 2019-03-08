//
//  Hash.swift
//  Hash
//
//  Created by CXY on 2019/1/8.
//  Copyright © 2019年 ubtechinc. All rights reserved.
//

import Foundation


struct Hash {
    var list: [Array<(String, String)>]!
    
    var size = 0
    
    init(size: Int) {
        self.size = size
        list = Array(repeating: [(String, String)](), count: size)
    }
    
    private func hashValue(key: String) -> Int {
        let t = key.hashValue % size
        return t > 0 ? t : -t
    }
    
    func objectForKey(_ key: String) -> String? {
        let index = hashValue(key: key)
        return list[index].filter({ (ky, value) -> Bool in
            return ky.elementsEqual(key)
        }).first?.1
    }
    
    mutating func setObject(_ obj: String, forKey key: String) {
        let index = hashValue(key: key)
        if var item = list?[index].filter({ (ky, value) -> Bool in
            return ky.elementsEqual(key)
        }).first {
            var idx = 0
            for (i, item) in list[index].enumerated() {
                if item.0.elementsEqual(key) {
                    idx = i
                    break
                }
            }
            item.1 = obj
            list[index][idx] = item
        } else {
            list[index].append((key, obj))
        }
    }
    
    
}
