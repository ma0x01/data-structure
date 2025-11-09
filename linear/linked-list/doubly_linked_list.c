//
// Created by tube on 2025/11/8.
//

#include "doubly_linked_list.h"

Node *InitList_D() //初始化链表
{
	Node *head = (Node *) malloc(sizeof(Node));
	if (!head)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	head->data = 0;
	head->prev = NULL;
	head->next = NULL;

	return head;
}

void InsertHead_D(Node *head, ElemType e) //头插法
{
	Node *n = (Node *) malloc(sizeof(Node));
	if (!n)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	n->data = e;
	n->prev = head;
	n->next = head->next;
	if (head->next != NULL)
	{
		head->next->prev = n;
	}
	head->next = n;
}

Node *InsertTail_D(Node *tail, ElemType e) //尾插法
{
	Node *n = (Node *) malloc(sizeof(Node));
	if (!n)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}

	n->data = e;
	n->prev = tail;
	n->next = NULL;
	tail->next = n;

	return n;
}

void InsertAtIndex_D(Node *head, int index, ElemType e) //插入
{
	Node *n = (Node *) malloc(sizeof(Node));
	if (!n)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	n->data = e;

	Node *p = head;
	for (int i = 0; i < index; i++)
	{
		if (p->next == NULL)
		{
			free(n);
			printf("插入位置有误！\n");
			return;
		}
		p = p->next;
	}
	n->next = p->next;
	n->prev = p;
	if (p->next != NULL)
	{
		p->next->prev = n;
	}
	p->next = n;
}

void PrintList_D(Node *head) //遍历链表
{
	Node *p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void DeleteNode_D(Node *head, int pos) //删除结点
{
	Node *p = head;
	for (int i = 0; i < pos; i++)
	{
		if (p->next == NULL)
		{
			printf("删除位置有误！\n");
			return;
		}
		p = p->next;
	}

	Node *temp = p->next;
	if (temp == NULL)
	{
		printf("删除位置有误！\n");
		return;
	}
	p->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = p;
	}

	free(temp);
}

void DeleteList_D(Node *head) //释放链表
{
	Node *p = head;
	while (p != NULL)
	{
		Node *temp = p;
		p = p->next;
		free(temp);
	}
}
