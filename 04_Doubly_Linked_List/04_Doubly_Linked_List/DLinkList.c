//
//  DLinkList.c
//  04_Doubly_Linked_List
//
//  Created by chan on 14/10/20.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "DLinkList.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    DLinkListNode header;
    DLinkListNode *slider;//游标
    int length;
}TDLinkList;


DLinkList *DLinkList_Create()
{
    TDLinkList *list = (TDLinkList *)malloc(sizeof(TDLinkList));
    if (!list) {
        return NULL;
    }
    memset(list, 0, sizeof(TDLinkList));
    return list;
}

void DLinkList_Destroy(DLinkList *list)
{
    TDLinkList *dlist = (TDLinkList *)list;
    free(dlist);
    dlist = NULL;
}

void DLinkList_Clear(DLinkList *list)
{
    TDLinkList *dlist = (TDLinkList *)list;
    if (!dlist) {
        return;
    }
//    dlist->header.next = NULL;
//    dlist->header.pre = NULL;
//    dlist->slider = NULL;
//    dlist->length = 0;
    memset(dlist, 0, sizeof(TDLinkList));
}

int DLinkList_Length(DLinkList *list)
{
    if (!list) {
        return -1;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    return dlist->length;
}

DLinkListNode *DLinkList_Get(DLinkList *list, int pos)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    if (pos < 0 || pos > dlist->length) {
        return NULL;
    }
    DLinkListNode *current = &dlist->header;
    int i;
    for (i = 0; i < pos; i ++) {
        current = current->next;
    }
    return current->next;
}

int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
    if (!list) {
        return -1;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    if (pos < 0 || pos > dlist->length) {
        return -2;
    }
    DLinkListNode *current = &dlist->header;//current
    int i;
    for (i = 0; i < pos; i ++) {
        current = current->next;
    }
    DLinkListNode *next = current->next;//next
    //一般插入
    node->next = next;
    node->pre = current;
    current->next = node;
    if (next) {
        next->pre = node;
    }
    //头部插入
    if (current == &dlist->header) {
        node->pre = NULL;
    }
    //尾部插入
    if (!next) {
        node->next = NULL;
    }
    if (!dlist->length) {//插入第一个时处理游标
        dlist->slider = node;
    }
    dlist->length++;
    return 0;//success
}

DLinkListNode *DLinkList_Delete(DLinkList *list, int pos)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    if (pos < 0 || pos >= dlist->length) {
        return NULL;
    }
    DLinkListNode *current = &dlist->header;
    for (int i = 0; i < pos; i ++) {
        current = current->next;
    }
    DLinkListNode *ret = current->next;
    DLinkListNode *next = ret->next;//next
    if (ret == dlist->slider) {
        dlist->slider = next;//游标下移
    }
    //1
    current->next = next;
    //2
    if (next) {
        next->pre = current;
        if (current == &dlist->header) {//删除头部
            next->pre = NULL;
        }
    }
    dlist->length--;
    return ret;
}

//add
DLinkListNode *DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *cList = (TDLinkList *)list;
    int i;
    DLinkListNode *current = &cList->header;
    for (i = 0 ; i < cList->length; i ++) {
        current = current->next;
        if (node == current) {
            break;
        }
    }
    return DLinkList_Delete(cList, i);
}

DLinkListNode *DLinkList_Reset(DLinkList *list)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    dlist->slider = dlist->header.next;
    return dlist->slider;
}

DLinkListNode *DLinkList_Current(DLinkList *list)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    return dlist->slider;
}

DLinkListNode *DLinkList_Next(DLinkList *list)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    DLinkListNode *current = dlist->slider;
    dlist->slider = current->next;
    return current;
}

DLinkListNode *DLinkList_Pre(DLinkList *list)
{
    if (!list) {
        return NULL;
    }
    TDLinkList *dlist = (TDLinkList *)list;
    DLinkListNode *cur = dlist->slider;
    dlist->slider = cur->pre;
    return cur;
}

