//
//  InsertSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "InsertSort.h"


void InsertSort(int a[], int n){
    if (n<=1) return;
    for (int i=1; i<n; i++) {
        int tmp = a[i];
        int k = i-1;
        while (a[k]>tmp && k>0) {
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = tmp;
    }
}
