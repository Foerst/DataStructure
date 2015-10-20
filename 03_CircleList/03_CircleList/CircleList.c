//
//  CircleList.c
//  03_CircleList
//
//  Created by chan on 14/10/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "CircleList.h"
#include <stdlib.h>
#include <string.h>

typedef struct _t_CircleList{
    CircleListNode header;
    CircleListNode *slider;//游标
    int length;
}TCircleList;

CircleList *CircleList_Create()
{
    TCircleList *list = NULL;
    list = (TCircleList *)malloc(sizeof(TCircleList));
    if (!list) {
        return NULL;
    }
    memset(list, 0, sizeof(TCircleList));
    return list;
}

void CircleList_Destroy(CircleList *list)
{
    if (!list) {
        return;
    }
    TCircleList *cList = (TCircleList *)list;
    free(cList);
    cList = NULL;
}


void CircleList_Clear(CircleList *list)
{
    if (!list) {
        return;
    }
    TCircleList *cList = (TCircleList *)list;
    cList->header.next = NULL;
    cList->slider = NULL;
    cList->length = 0;
}


int CircleList_Length(CircleList *list)
{
    if (!list) {
        return -1;
    }
    TCircleList *cList = (TCircleList *)list;
    return cList->length;
}

int CircleList_Insert(CircleList *list, CircleListNode *node, int pos)
{
    if (!list) {
        return -1;
    }
    TCircleList *cList = (TCircleList *)list;
    if (pos < 0 || pos > cList->length) {
        return -2;
    }
    CircleListNode *current = &cList->header;
    int i;
    CircleListNode *lastnode = NULL;
   
    for (i = 0 ; i < pos; i ++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    if (0 == cList->length) {//第一次插入时，游标指向第一个结点
        cList->slider = node;
    }
    cList->length++;
    if (0 == pos) {
        //头部插入需要求出尾结点
        lastnode = CircleList_Get(cList, cList->length-1);
    }
    if (lastnode) {//头部插入时尾结点next域要指向头结点
        lastnode->next = current->next;
    }
    
    return 0;//success
}

CircleListNode *CircleList_Get(CircleList *list, int pos)
{
    if (!list) {
        return NULL;
    }
    TCircleList *cList = (TCircleList *)list;
    if (pos < 0 || pos > cList->length) {
        return NULL;
    }
    int i;
    CircleListNode *current = &cList->header;
    for (i = 0 ; i < pos; i ++) {
        current = current->next;
    }
    return current->next;
}

#pragma mark - 删除循环链表某个位置处的结点
CircleListNode *CircleList_Delete(CircleList *list, int pos)
{
    if (!list) {
        return NULL;
    }
    TCircleList *cList = (TCircleList *)list;
    if (pos < 0 || pos >= cList->length) {
        return NULL;
    }
    CircleListNode *current = &cList->header;
    if (cList->length > 1) {
        int i;
        for (i = 0 ; i < pos; i ++) {
            current = current->next;
        }
        CircleListNode *lastnode = NULL;
        if (current == &cList->header) {//pos=0删除头结点时
            //头部插入需要求出尾结点
            lastnode = CircleList_Get(cList, cList->length-1);
        }
        CircleListNode *deleteNode = current->next;
        current->next = deleteNode->next;
        if (lastnode) {
            lastnode->next = deleteNode->next;
        }
        if (deleteNode == cList->slider) {//若删除的为游标所指向结点，则游标下移
            CircleList_Next(cList);
        }
        cList->length--;
        return deleteNode;
    }else {
        CircleListNode *deleteNode = current->next;
        cList->slider = NULL;
        current->next = NULL;
        cList->length--;
        return deleteNode;
    }
}

CircleListNode *CircleList_Reset(CircleList *list)
{
    if (!list) {
        return NULL;
    }
    TCircleList *cList = (TCircleList *)list;
    if (cList->header.next) {
        cList->slider = cList->header.next;
    }
    return cList->slider;
}

CircleListNode *CircleList_Current(CircleList *list)
{
    if (!list) {
        return NULL;
    }
    TCircleList *cList = (TCircleList *)list;
    return cList->slider;
}


CircleListNode *CircleList_Next(CircleList *list)
{
    if (!list) {
        return NULL;
    }
    TCircleList *cList = (TCircleList *)list;
    CircleListNode *ret = cList->slider;
    cList->slider = ret->next;
    return ret;
}

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node)
{
    if (!list) {
        return NULL;
    }
    TCircleList *cList = (TCircleList *)list;
    int i;
    CircleListNode *current = &cList->header;
    for (i = 0 ; i < cList->length; i ++) {
        current = current->next;
        if (node == current) {
            break;
        }
    }
    return CircleList_Delete(cList, i);
}