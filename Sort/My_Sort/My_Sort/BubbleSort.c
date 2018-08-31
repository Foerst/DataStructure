//
//  BubbleSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/30.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "BubbleSort.h"
#include "swap.h"

void BubbleSort(int a[], int n){
    int swaped = 1;
    for (int i=0; i<n&&swaped; i++) {
        swaped = 0;
        for (int j=0; j<n-i-1; j++) {
            if (a[j]>a[j+1]) {
                swap(a+j, a+j+1);
                swaped = 1;
            }
        }
    }
}
