//
//  SeqQueue.h
//  07_Seq_Queue
//
//  Created by chan on 15/11/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#ifndef SeqQueue_h
#define SeqQueue_h

#include <stdio.h>

typedef void SeqQueue;

SeqQueue *SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue *queue);

void SeqQueue_Clear(SeqQueue *queue);

//append
int SeqQueue_Append(SeqQueue *queue, void *item);

//retrieve
void *SeqQueue_Retrieve(SeqQueue *queue);

//header
void *SeqQueue_Header(SeqQueue *queue);

int SeqQueue_Length(SeqQueue *queue);

int SeqQueue_Capacity(SeqQueue *queue);
#endif /* SeqQueue_h */
