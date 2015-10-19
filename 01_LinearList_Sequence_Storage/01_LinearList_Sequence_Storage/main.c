//
//  main.c
//  01_LinearList_Sequence_Storage
//
//  Created by chan on 14/10/12.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "SeqList.h"
#include "Structs.h"


int main(int argc, const char * argv[]) {
    Teacher teacher1 = {11, "Mr Wang", 'M'};
    Teacher teacher2 = {22, "Mr Jiang", 'M'};
    Teacher teacher3 = {33, "Mr Huang", 'M'};
    Teacher teacher4 = {44, "Mr Si", 'M'};
    Teacher teacher5 = {55, "Mr Wu", 'M'};
    
    SeqList *list = SeqList_Create(100);
    if (!list) return -1;
    //Insert
    SeqList_Insert(list, &teacher1, 0);
    SeqList_Insert(list, &teacher2, 0);
    SeqList_Insert(list, &teacher3, 0);
    SeqList_Insert(list, &teacher4, 0);
    SeqList_Insert(list, &teacher5, 0);
    //print
    for (int i = 0; i < SeqList_Length(list); i ++) {
        Teacher *teacher = (Teacher*)SeqList_Get(list, i);
        printf("ListNode %d name:%s\n", i, teacher->name);
    }
    //delete
    SeqList_Delete(list, 3);
    SeqList_Delete(list, 5);
    //print
    for (int i = 0; i < SeqList_Length(list); i ++) {
        Teacher *teacher = (Teacher*)SeqList_Get(list, i);
        printf("ListNode %d name:%s\n", i, teacher->name);
    }
    SeqList_Clear(list);
    SeqList_Destroy(list);
    return 0;
}
