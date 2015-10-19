//
//  main.c
//  02_LinearList_Linked_Storage
//
//  Created by chan on 14/10/13.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"

typedef struct _t_Teacher{
    LinkListNode node;
    int age;
    char *name;
    char sex;
} Teacher;


int main(int argc, const char * argv[]) {
    Teacher teacher1, teacher2, teacher3, teacher4, teacher5;
    teacher1.age = 41;
    teacher2.age = 42;
    teacher3.age = 43;
    teacher4.age = 44;
    teacher5.age = 45;
    
    LinkList *list = LinkList_Create(100);
    if (!list) return -1;
    //Insert
    LinkList_Insert(list, (LinkListNode *)&teacher1, 0);
    LinkList_Insert(list, (LinkListNode *)&teacher2, 0);
    LinkList_Insert(list, (LinkListNode *)&teacher3, 0);
    LinkList_Insert(list, (LinkListNode *)&teacher4, 0);
    LinkList_Insert(list, (LinkListNode *)&teacher5, 0);
    //print
    for (int i = 0; i <  LinkList_Length(list); i ++) {
        Teacher *teacher = (Teacher*) LinkList_Get(list, i);
        printf("ListNode %d name:%d\n", i, teacher->age);
    }
    //delete
    LinkList_Delete(list, 3);
    LinkList_Delete(list, 5);
    //print
    for (int i = 0; i < LinkList_Length(list); i ++) {
        Teacher *teacher = (Teacher*)LinkList_Get(list, i);
        printf("ListNode %d name:%d\n", i, teacher->age);
    }
    LinkList_Clear(list);
    LinkList_Destroy(list);
    return 0;
}
