//
//  SelectSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "SelectSort.h"
#include "swap.h"

void SelectSort(int a[], int n) {
    for (int i=0; i<n; i++) {
        int min = i;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[min]) {
                min = j;
            }
        }
        swap(a+i, a+min);
    }
}
