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

//单链表相关算法
Node *FindNodeFS(Node *head, int k) //1. 倒数第k个结点 - 双指针法
{
	if (head == NULL || head->next == NULL || k <= 0)
	{
		return NULL;
	}

	Node *fast = head->next;
	Node *slow = head->next;
	for (int i = 0; i < k; i++)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}

	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

Node *ReverseList(Node *head) //2. 反转链表
{
	Node *first = NULL;
	Node *second = head->next;
	Node *third;

	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}

	head->next = first;
	return head;
}

void delMiddleNode(Node *head) //3. 删除中间结点
{
	//找到中间结点
	Node *fast = head->next;
	Node *slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	Node *temp = slow->next;
	slow->next = temp->next;
	free(temp);
}

int haveCircle(Node *head) //4. 判断链表是否有环-快慢指针（走到同一位置就证明有）
{
	Node *fast = head;
	Node *slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return 1;
		}
	}

	return 0;
}

Node *findCircle(Node *head) //5. 寻找链表中环的位置
{
	Node *fast = head;
	Node *slow = head;
	int circleLength = 1;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			Node *p = fast->next;
			while (p != fast)
			{
				circleLength++;
				p = p->next;
			}
			fast = head;
			slow = head;

			for (int i = 0; i < circleLength; i++)
			{
				fast = fast->next;
			}
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}

			return slow;
		}
	}
	return NULL;
}
