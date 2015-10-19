//
//  Structs.h
//  01_LinearList_Sequence_Storage
//
//  Created by chan on 14/10/13.
//  Copyright © 2015年 Jhon Chan. All rights reserved.
//

#ifndef Structs_h
#define Structs_h

#include <stdio.h>

typedef struct{
    long tID;
    char *name;
    char sex;
} Teacher;

typedef struct{
    long sID;
    char *name;
    char sex;
    char *major;
} Student;
#endif /* Structs_h */
