//
//  main.c
//  My_Sort
//
//  Created by CXY on 2018/8/30.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "HillSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

void printArray(int a[], int n){
    for (int i=0; i<n; i++) {
        printf("%d  ", a[i]);
    }
}

int main(int argc, const char * argv[]) {
    int n = 11;
    int a[11] = {100, 90, 8, 7, 66, 5, 4, -3, 20, 1, -2};
    
    printf("before sort:\n");
    printArray(a, n);
    
//    BubbleSort(a, n);
    
    QuickSort(a, n);
    
//    InsertSort(a, n);
    
//    SelectSort(a, n);
    
//    HillSort(a, n);
    
//    MergeSort(a, n);
    
//    HeapSort(a, n);
    
    printf("\nafter sort:\n");
    printArray(a, n);
    putchar('\n');
    return 0;
}
