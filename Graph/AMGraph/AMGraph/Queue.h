//
//  Queue.h
//  50- level order traversa
//
//  Created by CXY on 2018/8/6.
//  Copyright © 2018年 CXY. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef struct _t_queue {
    int size;
    void *tail;
    void *rail;
}Queue, *QueueRef;

int createQueue(QueueRef *q);
void enqueue(QueueRef q, void *val);
void *dequeue(QueueRef q);
void destroyQueue(QueueRef q);
void clearQueue(QueueRef q);

#endif /* Queue_h */
