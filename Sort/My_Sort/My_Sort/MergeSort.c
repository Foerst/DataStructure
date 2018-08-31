//
//  MergeSort.c
//  My_Sort
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "MergeSort.h"
#include <stdlib.h>

static void merge(int a[], int low, int mid, int high, int tmp[]){
    int i = low;
    int j = mid+1;
    int k = 0;
    while (i<=mid && j<=high) {
        if (a[i]<a[j]) {
            tmp[k++]=a[i++];
        } else {
            tmp[k++]=a[j++];
        }
    }
    while (i<=mid) {
        tmp[k++]=a[i++];
    }
    while (j<=high) {
        tmp[k++]=a[j++];
    }
    
    k=0;
    i=low;
    while (k<=high-low) {
        a[i++]=tmp[k++];
    }
}

static void mergeSort(int a[], int low, int high, int tmp[]){
    if (low<high) {
        int mid = (low+high)/2;
        mergeSort(a, low, mid, tmp);
        mergeSort(a, mid+1, high, tmp);
        merge(a, low, mid, high, tmp);
    }
}


void MergeSort(int a[], int n){
    if (n < 1) return;
    int *arr = (int *)malloc(sizeof(int)*n);
    mergeSort(a, 0, n-1, arr);
    free(arr);
}


