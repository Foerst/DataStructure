//
//  main.c
//  58-ShuffleAnArray
//
//  Created by CXY on 2018/8/7.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%i  ", arr[i]);
    }
    putchar('\n');
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef struct {
    int *nums;
    int size;
    int *rand;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution *sln = (Solution *)malloc(sizeof(Solution));
    sln->nums = nums;
    sln->size = size;
    sln->rand = (int *)malloc(sizeof(int)*size);
    for (int i=0; i < size; i++) {
        sln->rand[i] = sln->nums[i];
    }
    return sln;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
    *returnSize = obj->size;
    for (int i=0; i < obj->size; i++) {
        obj->rand[i] = obj->nums[i];
    }
    return obj->nums;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    int size = obj->size;
    *returnSize = size;
    
    for (int i = 0; i < size; ++i) {
        int t = i + rand() % (size - i);
        swap(&obj->rand[i], &obj->rand[t]);
    }
    return obj->rand;
}

void solutionFree(Solution* obj) {
    free(obj->rand);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, size);
 * int* param_1 = solutionReset(obj);
 * int* param_2 = solutionShuffle(obj);
 * solutionFree(obj);
 */

int main(int argc, const char * argv[]) {
    int nums[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int returnSize = 0;
    Solution* obj = solutionCreate(nums, size);
    
    int *param_2 = solutionShuffle(obj, &returnSize);
    printArray(param_2, size);
    
    param_2 = solutionShuffle(obj, &returnSize);
    printArray(param_2, size);
    
    param_2 = solutionShuffle(obj, &returnSize);
    printArray(param_2, size);
    
    param_2 = solutionShuffle(obj, &returnSize);
    printArray(param_2, size);
    
    int *param_1 = solutionReset(obj, &returnSize);
    printArray(param_1, size);
    
    solutionFree(obj);
    return 0;
}
