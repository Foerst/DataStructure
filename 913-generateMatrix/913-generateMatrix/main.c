//
//  main.c
//  913-generateMatrix
//
//  Created by CXY on 2018/9/5.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generateMatrix(int n) {
    int **result=malloc(sizeof(int *)*n);
    for (int i=0; i<n; i++) {
        result[i]=malloc(sizeof(int)*n);
        memset(result[i], 0, sizeof(int)*n);
    }

    int num = 1;
    int sum = n * n;
    int x = 0,y = 0;
    while(num <= sum){
        while(y < n && result[x][y] == 0)//向右
            result[x][y++] = num++;
        x++;y--;//向下移一位,y已经变成了n
        while(x < n && result[x][y] == 0)//向下
            result[x++][y] = num++;
        y--;x--;
        while(y >= 0 && result[x][y] == 0)//向左
            result[x][y--] = num++;
        x--;y++;
        while(x >= 0 && result[x][y] == 0)//向上
            result[x--][y] = num++;
        y++;x++;
        n--;
    }

    return result;
}

int main(int argc, const char * argv[]) {
    int n = 10;
    int **ret = generateMatrix(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf(" %6d", ret[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
