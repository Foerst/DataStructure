//
//  LinkStack.c
//  06_LinkStack
//
//  Created by chan on 15/10/21.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "LinkStack.h"
#include "LinkList.h"
#include <stdlib.h>

typedef struct _t_LinkStack_Node{
    LinkListNode node;
    void *val;
}LinkStackNode;

LinkStack *LinkStack_Create()
{
    return LinkList_Create();
}

void LinkStack_Destroy(LinkStack *stack)
{
    //clear first
    LinkStack_Clear(stack);
    free(stack);
    stack = NULL;
}

void LinkStack_Clear(LinkStack *stack)
{
    while (LinkStack_Size(stack)) {
        LinkStack_Pop(stack);
    }
}

int LinkStack_Push(LinkStack *stack, void *item)
{
    //item 与linklist的结点结构不一样，需要包装一下
    LinkStackNode *nod = (LinkStackNode *)malloc(sizeof(LinkStackNode));//alloc
    if (!nod) {
        return -1;
    }
    nod->val = item;
    return LinkList_Insert(stack, (LinkListNode *)nod, 0);
}

void *LinkStack_Pop(LinkStack *stack)
{
    LinkStackNode *nod = (LinkStackNode *)LinkList_Delete(stack, 0);
    void *item = nod->val;
    free(nod); //free
    nod = NULL;
    return item;
}

void *LinkStack_Top(LinkStack *stack)
{
    LinkStackNode *nod = (LinkStackNode *)LinkList_Get(stack, 0);
    return nod->val;
}

int LinkStack_Size(LinkStack *stack)
{
    return LinkList_Length(stack);
}