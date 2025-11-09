//
// Created by tube on 2025/11/8.
//

#ifndef DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node //双向链表
{
	ElemType data;
	struct node *prev;
	struct node *next;
} Node;

Node *InitList_D(); //初始化链表

void InsertHead_D(Node *head, ElemType e); //头插法

Node *InsertTail_D(Node *tail, ElemType e); //尾插法

void InsertAtIndex_D(Node *head, int index, ElemType e); //插入

void PrintList_D(Node *head); //遍历链表

void DeleteNode_D(Node *head, int pos); //删除结点

void DeleteList_D(Node *head); //释放链表

#endif //DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
