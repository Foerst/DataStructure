//
//  main.c
//  06_LinkStack
//
//  Created by chan on 15/10/21.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "LinkStack.h"

int main(int argc, const char * argv[]) {
    LinkStack *stack = NULL;
//    int  a[5], i = 0;
//    
//    for (i = 0; i < 5; i ++)
//    {
//        a[i] = i+1;
//    }
    int i;
    char a[5] = "1234";
    stack = LinkStack_Create();
    
    //向栈中添加元素
    for (i = 0; i < 4; i ++)
    {
//        char c = a[i];
        LinkStack_Push(stack, a+i);
    }
    
    //栈的属性
    printf("len:%d \n", LinkStack_Size(stack));
    printf("top:%c \n",  *((char *)LinkStack_Top(stack)));
    
    //元素出栈
    while (LinkStack_Size(stack) > 0)
    {
        char tmp = 0;
        tmp = *((char *)LinkStack_Pop(stack));
        printf("%c\n", tmp);
    }
    
    LinkStack_Destroy(stack);
    return 0;
}
