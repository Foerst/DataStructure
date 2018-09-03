//
//  HashTable.h
//  HashTable
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>



typedef struct _t_hash_table HashTable;

void hash_table_create(HashTable **table, int capacity);

void hash_table_set(HashTable *table, int key, void *value);

void *hash_table_get(HashTable *table, int key);

void hash_table_free(HashTable *table);

#endif /* HashTable_h */
