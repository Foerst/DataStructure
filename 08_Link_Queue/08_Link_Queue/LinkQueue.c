//
//  LinkQueue.c
//  08_Link_Queue
//
//  Created by chan on 15/11/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "LinkQueue.h"
#include "LinkList.h"
#include <stdlib.h>

typedef void LinkQueue;

typedef struct _t_linkQueue_node{
    LinkListNode node;
    void *val;
}TLinkQueueNode;

LinkQueue *LinkQueue_Create()
{
   return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue *queue)
{
    LinkQueue_Clear(queue);
    LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue *queue)
{
    while (LinkList_Length(queue)) {
        LinkQueue_Retrieve(queue);
    }
}

int LinkQueue_Append(LinkQueue *queue, void *item)
{
    TLinkQueueNode *node = malloc(sizeof(TLinkQueueNode));
    if (!node) {
        return -1;
    }
    node->val = item;
    return LinkList_Insert(queue, (LinkListNode *)node, LinkQueue_Length(queue));
}

void *LinkQueue_Retrieve(LinkQueue *queue)
{
    TLinkQueueNode *node = (TLinkQueueNode *)LinkList_Delete(queue, 0);
    void *item = node->val;
    free(node);
    node = NULL;
    return item;
}

void *LinkQueue_Header(LinkQueue *queue)
{
    TLinkQueueNode *node = (TLinkQueueNode *)LinkList_Get(queue, 0);
    return node->val;
}

int LinkQueue_Length(LinkQueue *queue)
{
    return LinkList_Length(queue);
}