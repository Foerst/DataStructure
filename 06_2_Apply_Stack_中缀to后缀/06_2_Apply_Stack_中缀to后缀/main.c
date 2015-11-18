//
//  main.c
//  06_2_Apply_Stack_中缀to后缀
//
//  Created by chan on 15/10/26.
//  Copyright © 2015年 chan. All rights reserved.
//

#include <stdio.h>
#include "LinkStack.h"
#include <string.h>



/*
 中缀转后缀算法：
 遍历中缀表达式中的数字和符号
 对于数字：直接输出
 对于符号：
 左括号：进栈
 运算符号：与栈顶符号进行优先级比较
     若栈顶符号优先级低：此符号进栈  （默认栈顶若是左括号，左括号优先级最低）
     若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
 右括号：将栈顶符号弹出并输出，直到匹配左括号
 遍历结束：将栈中的所有符号弹出并输出
 
 */


int isLeftSymbol(char c)
{
    return c == '(';
}

int isRightSymbol(char c)
{
    return c == ')';
}

int isOperator(char c)
{
    return (c == '+'||c == '-'||c == '*'||c == '/');
}

int isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

int isMatch(char l, char r)
{
    if ((isLeftSymbol(l)&&isRightSymbol(r)) || (isLeftSymbol(r)&&isRightSymbol(l))) {
        return 1;
    }
    return 0;
}

//优先级
int isPriorityHigh(char c, char top)
{
    if (isLeftSymbol(top)) {
        return 1;
    }
    if ((c == '*' || c == '/')&&(top == '+' || top == '-')) {
        return 1;
    }
    return 0;
}

void output(char c)
{
    putchar(c);
}

void transferString(char *inStr)
{
    int i = 0;
    LinkStack *stack = LinkStack_Create();
    
    while (inStr[i]) {
        char c = inStr[i];
        if (isNumber(c)) {
            output(c);
        }else if (isLeftSymbol(c)) {
            LinkStack_Push(stack, inStr+i);
        }
        else if (isOperator(c)) {
            if (LinkStack_Size(stack)) {
                char *top = (char *)LinkStack_Top(stack);
                if (isPriorityHigh(c, *top)) {
                    LinkStack_Push(stack, inStr+i);
                }else {
                    char *tp = (char *)LinkStack_Pop(stack);
                    output(*tp);
                    LinkStack_Push(stack, inStr+i);
                }
            }else {
                LinkStack_Push(stack, inStr+i);
            }
        }
        else if (isRightSymbol(c)) {
            char *top = NULL;
            do {
                top = (char *)LinkStack_Pop(stack);
                if (!isLeftSymbol(*top)) {
                    output(*top);
                }
            } while (!isMatch(c, *top));
        }
        i ++;
    }
    if (i >= strlen(inStr)) {
        while (LinkStack_Size(stack)) {
            char *top = (char *)LinkStack_Pop(stack);
            output(*top);
        }
    }
}

int main(int argc, const char * argv[]) {
    char *s = "8+5*(9-1)";
    printf("8+5*(9-1)-------->");
    transferString(s);
    putchar('\n');
    return 0;
}
