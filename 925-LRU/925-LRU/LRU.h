//
//  LRU.h
//  925-LRU
//
//  Created by CXY on 2018/9/5.
//  Copyright © 2018年 CXY. All rights reserved.
//

#ifndef LRU_h
#define LRU_h

// LRU == Least Recently Use

#include <stdio.h>

typedef struct {
    int capacity;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) ;

int lRUCacheGet(LRUCache* obj, int key) ;

void lRUCachePut(LRUCache* obj, int key, int value);

void lRUCacheFree(LRUCache* obj);

#endif /* LRU_h */
