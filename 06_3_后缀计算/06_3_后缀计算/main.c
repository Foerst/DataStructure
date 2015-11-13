//
//  main.c
//  06_3_后缀计算
//
//  Created by chan on 15/10/27.
//  Copyright © 2015年 jhon chan. All rights reserved.
//

#include <stdio.h>
#include "LinkStack.h"
#include <string.h>

int isNumber(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int isLeftSymbol(char c)
{
    if (c == '(') {
        return 1;
    }
    return 0;
}

int isRightSymbol(char c)
{
    if (c == ')') {
        return 1;
    }
    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

int charToInt(char c)
{
    return c - '0';
}

int isSymbolMatch(char l, char r)
{
    if (l == '(' && r == ')') {
        return 1;
    }
    return 0;
}

float calculateResultWithOperator(float op1, float op2, char operator)
{
    float ret = .0f;
    switch (operator) {
        case '+':
            ret = op1 + op2;
            break;
        case '-':
            ret = op1 - op2;
            break;
        case '*':
            ret = op1 * op2;
            break;
        case '/':
            ret = op1 / op2;
            break;
        default:
            break;
    }
    return ret;
}

float calculateStr(const char *s)
{
    if (!s) {
        return 0;
    }
    LinkStack *stack = LinkStack_Create();
    int i = 0;
    while (s[i] != '\0') {
        if (isNumber(s[i])) {
            int num = charToInt(s[i]);
            LinkStack_Push(stack, (void *)num);
        }
        if (isOperator(s[i])) {
            int rightNum = (int)LinkStack_Pop(stack);
            int leftNum = (int)LinkStack_Pop(stack);
            int result = calculateResultWithOperator(leftNum, rightNum, s[i]);
            LinkStack_Push(stack, (void *)result);
        }
        i ++;
    }
    if (s[i] == '\0' && LinkStack_Size(stack)) {
        int ret = (int)LinkStack_Pop(stack);
        return ret;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    char *s = "891-5*+";
    printf("8+(9-1)*5 = %.1f\n", calculateStr(s));
    return 0;
}
