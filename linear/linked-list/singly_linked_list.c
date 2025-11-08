//
// Created by tube on 2025/11/8.
//

#include "singly_linked_list.h"

Node *InitLinkedList() //初始化链表
{
	Node *head = (Node *) malloc(sizeof(Node));
	if (!head) //内存分配安全检查
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	head->data = 0;
	head->next = NULL;

	return head;
}

void InsertHead(Node *head, ElementType e) //头插法
{
	Node *p = (Node *) malloc(sizeof(Node));
	if (!p) //内存分配安全检查
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	p->data = e;
	p->next = head->next;
	head->next = p;
}

Node *GetTail(Node *head) //获取尾结点
{
	Node *p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

Node *InsertTail(Node *tail, ElementType e) //尾插法
{
	assert(tail->next == NULL); //确保tail是尾结点

	Node *p = (Node *) malloc(sizeof(Node));
	if (!p) //内存分配安全检查
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}

void InsertAtIndex(Node *head, int index, ElementType e) //插入结点 index必须>=1
{
	Node *pre = head;
	for (int i = 0; i < index - 1; i++)
	{
		pre = pre->next;
		if (pre == NULL)
		{
			printf("插入位置出错！\n");
			return;
		}
	}

	Node *p = (Node *) malloc(sizeof(Node));
	if (!p) //内存分配安全检查
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	p->data = e;
	p->next = pre->next;
	pre->next = p;
}


int GetLength(Node *head) //获取链表长度
{
	int length = 0;

	Node *p = head->next;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}

	return length;
}

void DisplayList(Node *head) //遍历输出链表
{
	Node *p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void DeleteNode(Node *head, int index) //删除某结点
{
	if (index <= 0)
	{
		printf("删除结点出错！\n");
		return;
	}

	Node *pre = head;
	for (int i = 0; i < index - 1; i++)
	{
		pre = pre->next;
		if (pre == NULL)
		{
			return;
		}
	}

	if (pre->next == NULL)
	{
		printf("删除结点出错！\n");
		return;
	}

	Node *p = pre->next;
	pre->next = p->next;
	free(p);
}

void DeleteLinkedList(Node *head) //释放链表
{
	Node *p = head->next;
	while (p != NULL)
	{
		Node *temp = p;
		p = p->next;
		free(temp);
	}
	free(head);
}
