//
//  swap.c
//  My_Sort
//
//  Created by CXY on 2018/8/30.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
