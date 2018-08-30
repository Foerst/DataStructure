//
//  main.c
//  36-isPalindrome
//
//  Created by CXY on 2018/8/6.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define bool int
#define true 1
#define false 0


bool isPalindrome(char* s) {
    int length=(int)strlen(s);
    if(0==length) return true;
    int i=0,j=length-1;
    while(i<j){
        while(!isalpha(s[i])&&!isdigit(s[i])){
            i++;
            if(i>=j) return true;
        }
        
        while(!isalpha(s[j])&&!isdigit(s[j])){
            j--;
            if(i>=j) return true;
        }
        char start=tolower(s[i]);
        char end=tolower(s[j]);
        if(start!=end){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    char *s="A man, a plan, a canal: Panala";
    int ret=isPalindrome(s);
    printf("ret===%d\n", ret);
    return 0;
}
