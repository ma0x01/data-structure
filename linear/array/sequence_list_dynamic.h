//
// Created by tube on 2025/11/8.
//

#ifndef DATA_STRUCTURE_SEQUENCE_LIST_DYNAMIC_H
#define DATA_STRUCTURE_SEQUENCE_LIST_DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MAX_SIZE 100

typedef struct //动态内存顺序表定义
{
	ElementType *data;
	int length;
} SeqList;

SeqList *InitDynamicSeqList(); //初始化顺序表

#endif //DATA_STRUCTURE_SEQUENCE_LIST_DYNAMIC_H
