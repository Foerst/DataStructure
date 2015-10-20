//
//  main.c
//  04_Doubly_Linked_List
//
//  Created by chan on 14/10/20.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "DLinkList.h"

struct Value
{
    DLinkListNode node;
    int v;
};

int main()
{
    int i = 0;
    DLinkList* list = DLinkList_Create();
    struct Value* pv = NULL;
    struct Value v1, v2, v3, v4, v5;
    
    v1.v = 1;	v2.v = 2;	v3.v = 3;	v4.v = 4;
    v5.v = 5;
    
    DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));
    
    for(i=0; i<DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    DLinkList_Delete(list, DLinkList_Length(list)-1);
    DLinkList_Delete(list, 0);
    //DLinkList_Delete(list, 3);
    
    
    for(i=0; i<DLinkList_Length(list); i++)
    {
        pv = (struct Value*)DLinkList_Next(list);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    DLinkList_Reset(list);
    DLinkList_Next(list);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    DLinkList_DeleteNode(list, (DLinkListNode*)pv);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    DLinkList_Pre(list);
    
    pv = (struct Value*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    printf("Length: %d\n", DLinkList_Length(list));
    
    DLinkList_Destroy(list);
    system("pause");
    return 0;
}
