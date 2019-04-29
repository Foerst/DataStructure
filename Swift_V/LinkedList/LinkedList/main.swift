//
//  main.swift
//  LinkedList
//
//  Created by CXY on 2019/4/29.
//  Copyright © 2019 cxy. All rights reserved.
//

import Foundation

let list = LinkedList()

let list2 = LinkedList()
//
//let list3 = list
//
//print("\(list === list2)")
//list.traverse()
//
//list.reverse()
//
//list.traverse()

list.create(input: "-1 1 4 7 10 11 12")


list2.create(input: "1 2 9")

let list3 = list.mergeList(list2)

list3.traverse()
