//
//  SeqStack.c
//  05_Seq_Stack
//
//  Created by chan on 15/10/21.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "SeqStack.h"
#include "SeqList.h"
#define STACK_MAX_SIZE (100)

#pragma mark -创建栈
SeqStack *SeqStack_Create()
{
    return SeqList_Create(STACK_MAX_SIZE);
}

#pragma mark -销毁栈
void SeqStack_Destroy(SeqStack *stack)
{
    SeqList_Destroy(stack);
}

#pragma mark -清空
void SeqStack_Clear(SeqStack *stack)
{
    SeqList_Clear(stack);
}

#pragma mark -压栈
int SeqStack_Push(SeqStack *stack, void *item)
{
    return SeqList_Insert(stack, item, SeqList_Length(stack));
}

#pragma mark -出栈
void *SeqStack_Pop(SeqStack *stack)
{
    return SeqList_Delete(stack, SeqList_Length(stack)-1);
}

#pragma mark -获取顶部元素
void *SeqStack_Top(SeqStack *stack)
{
    return SeqList_Get(stack, SeqList_Length(stack)-1);
}

#pragma mark -栈大小
int SeqStack_Size(SeqStack *stack)
{
    return SeqList_Length(stack);
}