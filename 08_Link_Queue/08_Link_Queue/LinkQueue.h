//
//  LinkQueue.h
//  08_Link_Queue
//
//  Created by chan on 15/11/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>

typedef void LinkQueue;

LinkQueue *LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue *queue);

void LinkQueue_Clear(LinkQueue *queue);

int LinkQueue_Append(LinkQueue *queue, void *item);

void *LinkQueue_Retrieve(LinkQueue *queue);

void *LinkQueue_Header(LinkQueue *queue);

int LinkQueue_Length(LinkQueue *queue);
#endif /* LinkQueue_h */
