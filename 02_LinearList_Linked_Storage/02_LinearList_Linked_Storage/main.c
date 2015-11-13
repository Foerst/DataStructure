//
//  main.c
//  02_LinearList_Linked_Storage
//
//  Created by chan on 14/10/13.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"

//typedef struct _t_Teacher{
//    LinkListNode node;
//    int age;
//    char *name;
//    char sex;
//} Teacher;

typedef struct _t_Teacher{
    LinkListNode node;
    void *val;
} Teacher;

int main(int argc, const char * argv[]) {
    Teacher teacher1, teacher2, teacher3, teacher4, teacher5;
    char *v1= "11", *v2 = "22", *v3 = "33", *v4 = "44", *v5 = "55";
//    teacher1.age = 41;
//    teacher2.age = 42;
//    teacher3.age = 43;
//    teacher4.age = 44;
//    teacher5.age = 45;
    teacher1.val = &v1;
    teacher2.val = &v2;
    teacher3.val = &v3;
    teacher4.val = &v4;
    teacher5.val = &v5;
    
    LinkList *list = LinkList_Create(10);
    if (!list) return -1;
    //Insert
    LinkList_Insert(list, (LinkListNode *)&teacher1, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&teacher2, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&teacher3, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&teacher4, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode *)&teacher5, LinkList_Length(list));
    //print
    for (int i = 0; i <  LinkList_Length(list); i ++) {
        Teacher *teacher = (Teacher*) LinkList_Get(list, i);
        printf("ListNode %d age:%s\n", i, *((char **)teacher->val));
    }
    //delete
    LinkList_Delete(list, 2);
    LinkList_Delete(list, 0);
    LinkList_Delete(list, 0);
    //print
    for (int i = 0; i < LinkList_Length(list); i ++) {
        Teacher *teacher = (Teacher*)LinkList_Get(list, i);
        printf("ListNode %d name:%s\n", i, *((char **)teacher->val));
    }
    LinkList_Clear(list);
    LinkList_Destroy(list);
    return 0;
}
