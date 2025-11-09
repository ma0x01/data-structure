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

//单链表相关算法

Node *FindNodeFS(Node *head, int k); //1. 倒数第k个结点 - 双指针法

Node *ReverseList(Node *head); //2. 反转链表

void delMiddleNode(Node *head); //3. 删除中间结点

int haveCircle(Node *head); //4. 判断链表是否有环-快慢指针（走到同一位置就证明有）

Node *findCircle(Node *head); //5. 寻找链表中环的位置

#endif //DATA_STRUCTURE_SINGLY_LINKED_LIST_H
