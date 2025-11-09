//
// Created by tube on 2025/11/9.
//

#include"doubly_linked_list.h"

// int main()
// {
// 	//以下测试代码由ChatGpt生成，均测试通过
//
// 	// 1. 初始化链表
// 	Node *head = InitList_D();
// 	printf("初始化链表: ");
// 	PrintList_D(head);
//
// 	// 2. 头插法
// 	InsertHead_D(head, 10);
// 	InsertHead_D(head, 20);
// 	InsertHead_D(head, 30);
// 	printf("头插法后: ");
// 	PrintList_D(head); // 30 20 10
//
// 	// 3. 尾插法
// 	Node *tail = head;
// 	while (tail->next != NULL)
// 		tail = tail->next; // 找到尾结点
// 	tail = InsertTail_D(tail, 40);
// 	tail = InsertTail_D(tail, 50);
// 	printf("尾插法后: ");
// 	PrintList_D(head); // 30 20 10 40 50
//
// 	// 4. 按索引插入
// 	InsertAtIndex_D(head, 2, 25); // 在索引2后插入25
// 	printf("按索引插入25后: ");
// 	PrintList_D(head); // 30 20 25 10 40 50
//
// 	// 5. 删除指定位置结点
// 	DeleteNode_D(head, 3); // 删除索引3后的结点（原本是10）
// 	printf("删除索引3的结点后: ");
// 	PrintList_D(head); // 30 20 25 40 50
//
// 	// 6. 释放链表
// 	DeleteList_D(head);
// 	head = NULL;
// 	printf("链表已释放。\n");
//
// 	return 0;
// }
