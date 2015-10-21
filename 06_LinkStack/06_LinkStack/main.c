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
    int  a[5], i = 0;
    
    for (i=0; i<5; i++)
    {
        a[i] = i+1;
    }
    
    stack = LinkStack_Create();
    
    //向栈中 添加 元素
    for (i=0; i<5; i++)
    {
        LinkStack_Push(stack, &a[i]); //抛砖: 栈的结点a[i]==>转换成(适配成) 链表结点 ===>插入到链表库
    }
    
    //栈的属性
    printf("len:%d \n", LinkStack_Size(stack));
    printf("top:%d \n",  *( (int *)LinkStack_Top(stack) )  );
    
    /*
     //元素 出栈
     while (LinkStack_Size(stack) > 0 )
     {
     int tmp = 0;
     tmp = *( (int *)LinkStack_Pop(stack) );
     printf("%d ", tmp);
     }
     */
    
    LinkStack_Destroy(stack);
    return 0;
}
