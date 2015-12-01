//
//  main.c
//  08_Link_Queue
//
//  Created by chan on 15/11/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "LinkQueue.h"
#include <stdlib.h>

//添加注释
int main(int argc, const char * argv[]) {
    int  i = 0, a[10];
    
    LinkQueue *queue = NULL;
    
    for (i=0; i<10; i++)
    {
        a[i] = i + 1;
    }
    
    queue = LinkQueue_Create(10);
    
    //add
    for (i=0; i<10; i++)
    {
        LinkQueue_Append(queue, a+i);
    }
    
    //property
    printf("length:%d \n", LinkQueue_Length(queue));
    printf("header: %d \n", *((int *)LinkQueue_Header(queue)));
    
    //delete
    while (LinkQueue_Length(queue))
    {
        int tmp;
        tmp =  *((int *)LinkQueue_Retrieve(queue));
        printf("%d ", tmp);
    }
    putchar('\n');
    LinkQueue_Destroy(queue);
    return 0;
}
