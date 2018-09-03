//
//  main.c
//  HashTable
//
//  Created by CXY on 2018/8/31.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include "HashTable.h"
#include "Hash.h"

int main(int argc, const char * argv[]) {
    
    HashTable *t;
    
    hash_table_create(&t, 3);


    hash_table_set(t, 0, "hi0");
    hash_table_set(t, 10, "hi10");
    hash_table_set(t, 5, "hi5");
    hash_table_set(t, 7, "hi7");
    hash_table_set(t, 7, "修改的7");
    hash_table_set(t, 19, "hi19");
    hash_table_set(t, 100, "hi100");
    hash_table_set(t, 63, "hi63");
    
    char *value = (char *)hash_table_get(t, 0);
    printf("0 === %s\n", value);
    
    value = (char *)hash_table_get(t, 10);
    printf("10 === %s\n", value);
    
    value = (char *)hash_table_get(t, 5);
    printf("5 === %s\n", value);
    
    value = (char *)hash_table_get(t, 7);
    printf("7 === %s\n", value);
    
    value = (char *)hash_table_get(t, 19);
    printf("19 === %s\n", value);
    
    value = (char *)hash_table_get(t, 100);
    printf("100 === %s\n", value);
    
    value = (char *)hash_table_get(t, 63);
    printf("63 === %s\n", value);
    
    
    hash_table_free(t);
    
    return 0;
}
