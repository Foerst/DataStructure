//
//  DLinkList.h
//  04_Doubly_Linked_List双向链表
//
//  Created by chan on 14/10/20.
//  Copyright © 2015年 chan. All rights reserved.
//

#ifndef DLinkList_h
#define DLinkList_h

#include <stdio.h>

typedef void DLinkList;

typedef struct _t_DLinkListNode
{
    struct _t_DLinkListNode *next;
    struct _t_DLinkListNode *pre;
}DLinkListNode;

DLinkList *DLinkList_Create();

void DLinkList_Destroy(DLinkList *list);

void DLinkList_Clear(DLinkList *list);

int DLinkList_Length(DLinkList *list);

int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);

DLinkListNode *DLinkList_Get(DLinkList *list, int pos);

DLinkListNode *DLinkList_Delete(DLinkList *list, int pos);

//add
DLinkListNode *DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node);
//将游标重置指向链表中的第一个数据元素
DLinkListNode *DLinkList_Reset(DLinkList *list);

DLinkListNode *DLinkList_Current(DLinkList *list);

DLinkListNode *DLinkList_Next(DLinkList *list);

DLinkListNode *DLinkList_Pre(DLinkList *list);
#endif /* DLinkList_h */
