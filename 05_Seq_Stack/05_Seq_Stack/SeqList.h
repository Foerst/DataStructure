//
//  SeqList.h
//  01_LinearList_Sequence_Storage
//
//  Created by chan on 14/10/12.
//  Copyright © 2015年 chan. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

#include <stdio.h>

typedef void SeqList;
typedef void SeqListNode;

//线性表创建
SeqList* SeqList_Create(int capacity);

//销毁
void SeqList_Destroy(SeqList* list);

//清空
void SeqList_Clear(SeqList* list);

//长度
int SeqList_Length(SeqList* list);

//容量
int SeqList_Capacity(SeqList* list);

//在某一个位置 插入元素
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//获取某一个位置的结点
SeqListNode* SeqList_Get(SeqList* list, int pos);

//删除某一个位置的结点
SeqListNode* SeqList_Delete(SeqList* list, int pos);

#endif /* SeqList_h */
