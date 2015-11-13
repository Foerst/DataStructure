//
//  main.c
//  05_Seq_Stack
//
//  Created by chan on 15/10/20.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "SeqStack.h"
//#include "SeqList.h"

int main(int argc, const char * argv[]) {
    SeqStack *stack = NULL;
//    int a[3] = {1, 2, 3};
    char *a = "123";
//    SeqList *list = SeqList_Create(100);
    stack = SeqStack_Create();
    
    for (int i = 0; i < 3; i ++) {
//        char c = a[i]; 变量c地址不变,错误的写法
//        SeqList_Insert(list, a+i, SeqList_Length(list));
        SeqStack_Push(stack, a+i);
    }
    while (SeqStack_Size(stack)) {
        char *p = (char *)SeqStack_Pop(stack);
        printf("-->%c", *p);
    }
//    for (int i = 0; i < SeqList_Length(list); i++) {
//        char *p = (char *)SeqList_Get(list, i);
//        printf("-->%c", *p);
//    }
//    while (SeqList_Length(list)) {
//        char *p = (char *)SeqList_Delete(list, SeqList_Length(list)-1);
//        printf("-->%c", *p);
//    }
    putchar('\n');
    SeqStack_Destroy(stack);
    return 0;
}
