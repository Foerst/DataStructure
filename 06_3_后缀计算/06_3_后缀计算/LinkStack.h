//
//  LinkStack.h
//  06_LinkStack
//
//  Created by jhon chan on 15/10/21.
//  Copyright © 2015年 jhon chan. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>

typedef void LinkStack;

LinkStack *LinkStack_Create();

void LinkStack_Destroy(LinkStack *stack);

void LinkStack_Clear(LinkStack *stack);

int LinkStack_Push(LinkStack *stack, void *item);

void *LinkStack_Pop(LinkStack *stack);

void *LinkStack_Top(LinkStack *stack);

int LinkStack_Size(LinkStack *stack);

#endif /* LinkStack_h */
