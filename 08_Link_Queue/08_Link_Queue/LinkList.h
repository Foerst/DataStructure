//
//  LinkList.h
//  02_LinearList_Linked_Storage
//
//  Created by chan on 14/10/13.
//  Copyright © 2015年 chan. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

typedef void  LinkList;

typedef struct _t_LinkListNode{
    struct _t_LinkListNode *next;
}LinkListNode;

LinkList *LinkList_Create();

void LinkList_Destroy(LinkList *list);

void LinkList_Clear(LinkList *list);

int LinkList_Length(LinkList *list);

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos);

LinkListNode *LinkList_Get(LinkList *list, int pos);

LinkListNode *LinkList_Delete(LinkList *list, int pos);
#endif /* LinkList_h */
