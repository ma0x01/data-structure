//
// Created by tube on 2025/11/8.
//

#ifndef DATA_STRUCTURE_SEQUENCE_LIST_H
#define DATA_STRUCTURE_SEQUENCE_LIST_H

#include <stdio.h>

typedef int ElementType;
#define MAX_SIZE 100

typedef struct //顺序表定义
{
	ElementType data[MAX_SIZE];
	int length;
} SeqList;

void InitSeqList(SeqList *p); //初始化顺序表

void AppendSeqList(SeqList *p, ElementType e); //尾插顺序表

void DisplaySeqList(SeqList *p); //遍历顺序表

void InsertSeqList(SeqList *p, int pos, ElementType e); //插入顺序表

int DeleteSeqListELem(SeqList *p, int pos, ElementType *e); //删除顺序表中的某个元素

int FindSeqListIndex(SeqList *p, ElementType e); //查找顺序表中的元素位置

#endif //DATA_STRUCTURE_SEQUENCE_LIST_H
