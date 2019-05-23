//
//  main.c
//  Hanoi
//
//  Created by CXY on 2019/3/29.
//  Copyright © 2019年 CXY. All rights reserved.
//

#include <stdio.h>

static int count = 0;

// 从x 移动到 z 借助 y
void hanoi(int n, char x, char y, char z) {
    if (1==n) {
//        printf("第1个 从 %c --到---> %c\n", x, z);
        printf("第%d个 从 %c --到---> %c\n", n, x, z);
        count ++;
    } else {
        hanoi(n-1, x, z, y);
        printf("第%d个 从 %c --到---> %c\n", n, x, z);
        count ++;
        hanoi(n-1, y, x, z);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while (1) {
        printf("请输入汉诺塔层数：\n");
        scanf("%d", &n);
        printf("开始计算");
        
        hanoi(n, 'X', 'Y', 'Z');
        
        printf("一共移动%d步。\n", count);
    }
    
    return 0;
}
