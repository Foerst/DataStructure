//
//  SeqStack.h
//  05_Seq_Stack
//  用顺序表模拟栈
//  Created by chan on 15/10/21.
//  Copyright © 2015年 chan. All rights reserved.
//

#ifndef SeqStack_h
#define SeqStack_h

#include <stdio.h>
typedef void SeqStack;

//创建栈
SeqStack *SeqStack_Create();
//销毁栈
void SeqStack_Destroy(SeqStack *stack);
//清空
void SeqStack_Clear(SeqStack *stack);
//压栈
int SeqStack_Push(SeqStack *stack, void *item);
//出栈
void *SeqStack_Pop(SeqStack *stack);
//获取顶部元素
void *SeqStack_Top(SeqStack *stack);
//栈大小
int SeqStack_Size(SeqStack *stack);

#endif /* SeqStack_h */
