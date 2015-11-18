//
//  LinkList.c
//  02_LinearList_Linked_Storage
//
//  Created by chan on 14/10/13.
//  Copyright © 2015年 chan. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>
#include <string.h>

typedef struct _t_LinkList{
    LinkListNode header;
    int length;
}TLinkList;

LinkList *LinkList_Create()
{
    TLinkList *list = NULL;
    list = (TLinkList *)malloc(sizeof(TLinkList));
    if (!list) return NULL;
    memset(list, 0, sizeof(TLinkList));
    return list;
}

void LinkList_Destroy(LinkList *list)
{
    if (!list) return;
    TLinkList *tmp = (TLinkList *)list;
    free(tmp);
    tmp = NULL;
}

void LinkList_Clear(LinkList *list)
{
    if (!list) return;
    TLinkList *tmp = (TLinkList *)list;
    tmp->header.next = NULL;
    tmp->length = 0;
}

int LinkList_Length(LinkList *list)
{
    if (!list) return -1;
    TLinkList *tmp = (TLinkList *)list;
    return tmp->length;
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
    if (!list) return -1;
    TLinkList *tmp = (TLinkList *)list;
    int length = LinkList_Length(tmp);
    if (pos < 0 || pos > length) {
        return -2;
    }
    int index = 0;
    LinkListNode *current = &tmp->header;
    while (current && index < pos) {
        current = current->next;
        index++;
    }
    node->next = current->next;
    current->next = node;
    tmp->length++;
    return 0;//success
}

LinkListNode *LinkList_Get(LinkList *list, int pos)
{
    if (!list) return NULL;
    TLinkList *tmp = (TLinkList *)list;
    int length = LinkList_Length(tmp);
    if (pos < 0 || pos > length) {
        return NULL;
    }
    int index = 0;
    LinkListNode *nd = &tmp->header;
    while (nd && index < pos) {
        nd = nd->next;
        index++;
    }
    return nd->next;
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
    if (!list) return NULL;
    TLinkList *tmp = (TLinkList *)list;
    int length = LinkList_Length(tmp);
    if (pos < 0 || pos >= length) {
        return NULL;
    }
    int index = 0;
    LinkListNode *current = &tmp->header;
    while (index < pos) {
        current = current->next;
        index++;
    }
    LinkListNode *deleteNode = current->next;
    current->next = deleteNode->next;
    tmp->length--;
    return deleteNode;
}