//
// Created by tube on 2025/11/8.
//

#ifndef DATA_STRUCTURE_SINGLY_LINKED_LIST_H
#define DATA_STRUCTURE_SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;

typedef struct node //单向链表定义
{
	ElementType data;
	struct node *next;
} Node;

Node *InitLinkedList(); //初始化链表

void InsertHead(Node *head, ElementType e); //头插法

Node *GetTail(Node *head); //获取尾结点

Node *InsertTail(Node *head, ElementType e); //尾插法

void InsertAtIndex(Node *head, int index, ElementType e); //插入结点

int GetLength(Node *head); //获取链表长度

void DisplayList(Node *head); //遍历输出链表

void DeleteNode(Node *head, int index); //删除某结点

void DeleteLinkedList(Node *head); //释放链表


#endif //DATA_STRUCTURE_SINGLY_LINKED_LIST_H
