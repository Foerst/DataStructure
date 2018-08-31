//
//  HeapSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "HeapSort.h"
#include "swap.h"


static void build_heap(int a[], int i, int limit){
    for (int j=2*i+1; j<limit; j=2*j+1) {
        int max = j;
        if (j+1<limit && a[j]<a[j+1]) {
            max = j+1;
        }
        if (a[i]<a[max]) {
            swap(a+i, a+max);
        }
    }
}

void HeapSort(int a[], int n){
    // 建堆
    for (int i=n/2-1; i>=0; i--) {
        build_heap(a, i, n);
    }
    for (int i=n-1; i>0; i--) {
        // 将堆顶记录和当前未经排序子序列的最后一个记录交换
        swap(a, a+i);
        // 重新调整为大顶堆
        build_heap(a, 0, i);
    }
}


