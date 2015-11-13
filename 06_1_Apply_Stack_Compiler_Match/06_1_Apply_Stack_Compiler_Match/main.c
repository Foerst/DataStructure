//
//  main.c
//  06_1_Apply_Stack_Compiler_Match
//
//  Created by chan on 14/10/22.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "LinkStack.h"
#include <string.h>
#include "LinkList.h"


/*
 应用1：就近匹配
 如何实现编译器中的符号成对检测
 
 算法思路
 从第一个字符开始扫描
 当遇见普通字符时忽略，
 当遇见左符号时压入栈中
 当遇见右符号时从栈中弹出栈顶符号，并进行匹配
 匹配成功：继续读入下一个字符
 匹配失败：立即停止，并报错
 结束：
 成功: 所有字符扫描完毕，且栈为空
 失败：匹配失败或所有字符扫描完毕但栈非空
 */


int isLeftSymbol(char c);
int isRightSymbol(char c);
int isMatch(char lchar, char rchar);
void doCheck(const char *str);

int main(int argc, const char * argv[]) {
    char *codes = "#include <stdio.h> int main() { int a[4]]][4]; int (*p)[4]; p = a[0]; return 0;";
//    char *codes = "[]]";
    doCheck(codes);
    return 0;
}

int isLeftSymbol(char c)
{
    if (c == '[' || c == '{' || c == '<' || c == '(' || c == '\"' || c == '\'') {
        return 1;
    }
    return 0;
}

int isRightSymbol(char c)
{
    if (c == ']' || c == '}' || c == '>' || c == ')' || c == '\"' || c == '\'') {
        return 1;
    }
    return 0;
}

int isMatch(char lchar, char rchar)
{
    int ret;
    switch (lchar) {
        case '[':
            ret = (rchar == ']');
            break;
        case '{':
            ret = (rchar == '}');
            break;
        case '<':
            ret = (rchar == '>');
            break;
        case '(':
            ret = (rchar == ')');
            break;
        case '\"':
            ret = (rchar == '\"');
            break;
        case '\'':
            ret = (rchar == '\'');
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

void doCheck(const char *codes)
{
    int i = 0;
    LinkStack *stack = LinkStack_Create();
    while (codes[i] != '\0') {
        if (isLeftSymbol(codes[i])) {
            LinkStack_Push(stack, (void *)&codes[i]);
        }
        if (isRightSymbol(codes[i])) {
            if (LinkStack_Size(stack)) {
                char *top = (char *)LinkStack_Pop(stack);
                printf("pop %c\n", *top);
                if (!isMatch(*top, codes[i])) {
                    printf("No match %c at char %d\n", codes[i], i);
                    return;
                }
            }else {
                printf("No match %c at char %d\n", codes[i], i);
                return;
            }
        }
        i ++;
    }
//    while (codes[i] != '\0') {
//        char c = codes[i];
//        if (isLeftSymbol(c)) {
//            LinkStack_Push(stack, &c);
//        }
//        if (isRightSymbol(c)) {
//            if (LinkStack_Size(stack)) {
//                char *top = NULL;
//                top = (char *)LinkStack_Pop(stack);
//                printf("pop %c\n", *top);
//                if (!isMatch(*top, c)) {
//                    printf("No match %c at char %d\n", c, i);
//                    return;
//                }
//            }else {
//                printf("No match %c at char %d\n", c, i);
//                return;
//            }
//        }
//        i ++;
//    }
    if (!LinkStack_Size(stack) && codes[i] == '\0') {
        printf("Match success!\n");
    }else {
        printf("Match failed!\n");
    }
}