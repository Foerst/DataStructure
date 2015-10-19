//
//  main.c
//  FindMostAppearTime
//
//  Created by chan on 14/10/12.
//  Copyright © 2015年 chan. All rights reserved.
//

//练习2：时间换空间
/*
 问题：
 在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
 设计一个算法，找出出现次数最多的数字。
 */

#include <stdio.h>

void search(int a[], int len)
{
    int sp[1000] = {0};
    int i = 0;
    int max = 0;
    
    for(i=0; i<len; i++)
    {
        int index = a[i] - 1;
        
        sp[index]++;
    }
    
    for(i=0; i<1000; i++)
    {
        if( max < sp[i] )
        {
            max = sp[i];
        }
    }
    
    for(i=0; i<1000; i++)
    {
        if( max == sp[i] )
        {
            printf("%d\n", i+1);
        }
    }
}

int main()
{
    int array[] = {1, 1, 3, 4, 5, 6, 6, 6, 2, 3};
    
    search(array, sizeof(array)/sizeof(*array));
    
    return 0;
}
