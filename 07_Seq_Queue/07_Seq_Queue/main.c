//
//  main.c
//  07_Seq_Queue
//
//  Created by chan on 15/11/16.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "SeqQueue.h"

int main(int argc, const char * argv[]) {
    int  i = 0, a[10];
    
    SeqQueue *queue = NULL;
    
    for (i=0; i<10; i++)
    {
        a[i] = i + 1;
    }
    
    queue = SeqQueue_Create(10);
    
    //add
    for (i=0; i<10; i++)
    {
        SeqQueue_Append(queue, a+i);
    }
    
    //property
    printf("capacity:%d \n", SeqQueue_Capacity(queue));
    printf("length:%d \n", SeqQueue_Length(queue));
    printf("header: %d \n", *( (int *)SeqQueue_Header(queue)));
    
    //delete
    while (SeqQueue_Length(queue))
    {
        int tmp;
        tmp =  *((int *)SeqQueue_Retrieve(queue));
        printf("%d ", tmp);
    }
    putchar('\n');
    SeqQueue_Destroy(queue);

    return 0;
}
