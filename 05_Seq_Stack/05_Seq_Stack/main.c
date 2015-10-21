//
//  main.c
//  05_Seq_Stack
//
//  Created by chan on 15/10/20.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "SeqStack.h"

int main(int argc, const char * argv[]) {
    SeqStack *stack = NULL;
    int a[3] = {1, 2, 3};
    
    stack = SeqStack_Create();
    for (int i = 0; i < 3; i ++) {
        SeqStack_Push(stack, &a[i]);
    }
    while (SeqStack_Size(stack)) {
        int *p = SeqStack_Pop(stack);
        printf("-->%d", *p);
    }
    SeqStack_Destroy(stack);
    return 0;
}
