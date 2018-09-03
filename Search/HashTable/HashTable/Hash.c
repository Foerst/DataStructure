//
//  Hash.c
//  HashTable
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "Hash.h"
#include <stdlib.h>
#include <string.h>

#define NULLKEY -32768

static int hash(HashMap *map, int key){
    return key%map->size;
}

void hash_map_create(HashMap **map, int capacity){
    *map = (HashMap *)malloc(sizeof(HashMap));
    (*map)->size = capacity;
    (*map)->table = (int *)malloc(sizeof(int)*capacity);
    memset((*map)->table, NULLKEY, sizeof(int)*capacity);
}

void hash_map_set(HashMap *map, int key, int value){
    int loc = hash(map, key);
    while (map->table[loc] != NULLKEY) {
        //开放定址法
        loc = hash(map, key+1);
    }
    map->table[loc] = value;
}

int hash_map_search(HashMap *map, int key){
    return -1;
//    int loc = hash(map, key);
//    while (map->table[loc] != NULLKEY) {
//        loc = hash(map, key+1);
//    }
//    return map->table[loc];
}
