//
//  Queue.c
//  50- level order traversa
//
//  Created by CXY on 2018/8/6.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>
#include <string.h>

typedef struct _t_queue_node {
    void *val;
    void *next;
}QueueNode, *QueueNodeRef;

int createQueue(QueueRef *q) {
    *q = (QueueRef)malloc(sizeof(Queue));
    memset(*q, 0, sizeof(Queue));
    return 0;
}

void enqueue(QueueRef q, void *val){
    QueueNodeRef node = (QueueNodeRef)malloc(sizeof(QueueNode));
    memset(node, 0, sizeof(QueueNode));
    node->val = val;
    if (q->tail==NULL) {
        q->tail = node;
        q->rail = node;
    } else {
        QueueNodeRef tmp = (QueueNodeRef)q->tail;
        tmp->next = node;
        q->tail = node;
    }
    q->size++;
}

void *dequeue(QueueRef q) {
    if (q->size==0) {
        return NULL;
    }
    QueueNodeRef tmp = (QueueNodeRef)q->rail;
    q->rail = tmp->next;
    q->size--;
    if (q->rail==NULL) {
        q->tail=NULL;
    }
    return tmp->val;
}

void destroyQueue(QueueRef q) {
    // no imp
}

void clearQueue(QueueRef q) {
    // no imp
}



