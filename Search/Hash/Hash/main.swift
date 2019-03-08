//
//  main.swift
//  Hash
//
//  Created by CXY on 2019/1/8.
//  Copyright © 2019年 ubtechinc. All rights reserved.
//

import Foundation

var hash = Hash(size: 3)

hash.setObject("sjdjk", forKey: "1")
hash.setObject("32423", forKey: "2")
hash.setObject("xxxxxx", forKey: "3")

print(hash.objectForKey("1")!)
print(hash.objectForKey("2")!)
print(hash.objectForKey("3")!)

hash.setObject("fuck1", forKey: "1")
hash.setObject("fuck2", forKey: "2")
hash.setObject("fuck3", forKey: "3")

print(hash.objectForKey("1")!)
print(hash.objectForKey("2")!)
print(hash.objectForKey("3")!)


