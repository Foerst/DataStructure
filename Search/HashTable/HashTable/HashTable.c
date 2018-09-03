//
//  HashTable.c
//  HashTable
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "HashTable.h"
#include <stdlib.h>
#include <string.h>

typedef struct _t_node{
    int key;
    void *value;
    struct _t_node *next;
} Node;


struct _t_hash_table{
    Node **list;
    int size;
};

static int hash(HashTable *table, int key){
    return key%table->size;
}

static Node *find(HashTable *table, int key){
    int index = hash(table, key);
    Node *node = table->list[index];
    Node *p = node;
    while (p) {
        if (p->key == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void hash_table_create(HashTable **table, int capacity){
    if (capacity<0) {
        return;
    }
    *table = (HashTable *)malloc(sizeof(HashTable));
    HashTable *tmp = *table;
    memset(tmp, 0, sizeof(HashTable));
    tmp->size = capacity;
    tmp->list = (Node **)malloc(sizeof(Node*)*capacity);
    memset(tmp->list, 0, sizeof(Node *)*capacity);
}

void hash_table_set(HashTable *table,int key, void *value){
    Node *cur = find(table, key);
    if (cur) {
        cur->value = value;
        return;
    }
    // 链地址法处理冲突
    int index = hash(table, key);
    Node *node = table->list[index];
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->key = key;
    tmp->value = value;
    tmp->next = NULL;
    if (node) {
        tmp->next = node;
    }
    table->list[index] = tmp;
}

void *hash_table_get(HashTable *table,int key){
    Node *p = find(table, key);
    if (p) {
        return p->value;
    }
    return NULL;
}


void hash_table_free(HashTable *t){
    if (!t) return;
    for (int i=0; i<t->size; i++) {
        Node *node = t->list[i];
        if (node) {
            Node *cur = node;
            Node *next = cur->next;
            while (cur) {
                free(cur);
                cur = next;
                if (next) {
                    next = next->next;
                }
            }
        }
    }
    free(t->list);
    free(t);
}
