//
//  QuickSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/30.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "QuickSort.h"
#include "swap.h"

static void quick_sort(int a[], int m, int n){
    int low = m;
    int heigh= n;
    if(low>=heigh) return;
    int pivot = a[low]; // 枢轴
    while (low<heigh) {
        while (a[heigh]>pivot && low<heigh) heigh--;
        swap(&pivot, a+heigh);
        while (a[low]<pivot && low<heigh) low++;
        swap(&pivot, a+low);
    }
    quick_sort(a, m, low-1);
    quick_sort(a, low+1, n);
}

void QuickSort(int a[], int n){
    quick_sort(a, 0, n-1);
}
