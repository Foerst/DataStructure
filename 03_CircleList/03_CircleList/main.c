//
//  main.c
//  03_CircleList
//
//  Created by chan on 14/10/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "CircleList.h"
#define STEP  3

/*问题1：证明循环链表*/
//可打印两倍长度结点看输出
/*问题2：用循环链表解决约瑟夫问题：
n 个人围成一个圆圈，首先第 1 个人从 1 开始一个人一个人顺时针报数，报到第 m 个人，令其出列。然后再从下一 个人开始从 1 顺时针报数，报到第 m 个人，再令其出列，…，如此下去，求出列顺序。*/

typedef struct _t_Student{
    CircleListNode node;
    int id;
}Student;


int main(int argc, const char * argv[]) {
    CircleList *list = CircleList_Create();
    Student stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8;
    stu1.id = 1;
    stu2.id = 2;
    stu3.id = 3;
    stu4.id = 4;
    stu5.id = 5;
    stu6.id = 6;
    stu7.id = 7;
    stu8.id = 8;
    CircleList_Insert(list, (CircleListNode *)&stu1, 0);
    CircleList_Insert(list, (CircleListNode *)&stu2, 1);
    CircleList_Insert(list, (CircleListNode *)&stu3, 2);
    CircleList_Insert(list, (CircleListNode *)&stu4, 3);
    CircleList_Insert(list, (CircleListNode *)&stu5, 4);
    CircleList_Insert(list, (CircleListNode *)&stu6, 5);
    CircleList_Insert(list, (CircleListNode *)&stu7, 6);
    CircleList_Insert(list, (CircleListNode *)&stu8, 7);
    printf("start:\n");
    for (int i = 0; i < CircleList_Length(list); i++) {
//        CircleListNode *node = CircleList_Get(list, i);
        Student *stu = (Student *)CircleList_Next(list);
        printf("--->%d",stu->id);
    }
    //重置游标
    CircleList_Reset(list);
    printf("\nend:\n");
    while (CircleList_Length(list)) {
        Student *node = NULL;
        for (int j = 1; j < STEP; j ++) {
           CircleList_Next(list);
        }
        node = (Student *)CircleList_Current(list);
        printf("--->%d",node->id);
        CircleList_DeleteNode(list, (CircleListNode *)node);
    }
    putchar('\n');
    CircleList_Destroy(list);
    return 0;
}
