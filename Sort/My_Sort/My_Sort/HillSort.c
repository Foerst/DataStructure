//
//  HillSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "HillSort.h"


void HillSort(int a[], int n){
    if (n<=0) return;
    int increment = n;
    do {
        increment = increment/3+1;
        for (int i=0; i<n; i++) {
            for (int j=i+increment; j<n; j+=increment) {
                int tmp = a[j];
                int n = j-increment;
                while (a[n]>tmp && n>=i) {
                    a[n+increment] = a[n];
                    n -= increment;
                }
                a[n+increment] = tmp;
            }
        }
        
    } while (increment>1);
}
