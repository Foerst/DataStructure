//
//  Hash.h
//  HashTable
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#ifndef Hash_h
#define Hash_h

#include <stdio.h>

typedef struct _t_hash_map{
    int *table;
    int size;
}HashMap;

void hash_map_create(HashMap **map, int capacity);
void hash_map_set(HashMap *map, int key, int value);
int hash_map_get(HashMap *map, int key);

#endif /* Hash_h */
