//
//  SeqList.c
//  01_LinearList_Sequence_Storage
//
//  Created by chan on 14/10/12.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "SeqList.h"
#include <stdlib.h>
#include <string.h>

typedef struct _t_SeqList{
    int capacity;
    int length;
    int **node;
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
    int ret;
    TSeqList *list = NULL;
    list = (TSeqList *)malloc(sizeof(TSeqList));
    if (list == NULL) {
        ret = 1;
        printf("func SeqList_Create() err :%d \n", ret);
        return NULL;
    }
    memset(list, 0, sizeof(TSeqList));
    list->length = 0;
    list->capacity = capacity;
    list->node = (int **)malloc(sizeof(int *)*capacity);
    if (list->node == NULL) {
        ret = 2;
        printf("func SeqList_Create() create node err :%d \n", ret);
        return NULL;
    }
    memset(list->node, 0, sizeof(int *)*capacity); //memory set zero
    return list;
}

void SeqList_Destroy(SeqList* list)
{
    if (list == NULL) return;
    TSeqList *tmp = (TSeqList *)list;
    if (tmp->node) {
        free(tmp->node);
        tmp->node = NULL;
    }
    free(tmp);
    tmp = NULL;
}

void SeqList_Clear(SeqList* list)
{
    if (list == NULL) return;
    TSeqList *tmp = (TSeqList *)list;
    tmp->length = 0;
    if (tmp->node) {
        memset(tmp->node, 0, sizeof(int *)*tmp->capacity);
    }
}

int SeqList_Length(SeqList* list)
{
    if (list == NULL) return -1;
    TSeqList *tmp = (TSeqList *)list;
    return tmp->length;
}

int SeqList_Capacity(SeqList* list)
{
    if (list == NULL) return -1;
    TSeqList *tmp = (TSeqList *)list;
    return tmp->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
    if (list == NULL||node == NULL) return -1;
    TSeqList *tmp = (TSeqList *)list;
    if (pos < 0 || pos > SeqList_Length(tmp) || SeqList_Length(tmp) >= SeqList_Capacity(tmp)) return -2;
    int i;
    for (i = SeqList_Length(tmp); i > pos; i --) {
        tmp->node[i] = tmp->node[i-1];
    }
    tmp->node[i] = (int *)node;
    tmp->length++;
    return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
    if (list == NULL) return NULL;
    TSeqList *tmp = (TSeqList *)list;
    if (pos < 0 || pos > SeqList_Length(tmp)) return NULL;
    SeqListNode *node = (SeqListNode *)tmp->node[pos];
    return node;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
    if (list == NULL) return NULL;
    TSeqList *tmp = (TSeqList *)list;
    if (pos < 0 || pos > SeqList_Length(tmp)) return NULL;
    SeqListNode *node = (SeqListNode *)tmp->node[pos];
    int i;
    for (i = pos; i < SeqList_Length(tmp)-1; i ++) {
        tmp->node[i] = tmp->node[i+1];
    }
    tmp->length--;
    return node;
}