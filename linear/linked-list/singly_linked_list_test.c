//
// Created by tube on 2025/11/8.
//

#include "singly_linked_list.h"

int main()
{
	//以下测试内容由ChatGPT生成，均测试通过
	printf("==== 链表测试开始 ====\n");

	// 初始化链表
	Node *head = InitLinkedList();
	printf("初始化链表成功。\n");

	// 测试头插法
	printf("测试头插法：插入 10, 20, 30\n");
	InsertHead(head, 10);
	InsertHead(head, 20);
	InsertHead(head, 30);
	DisplayList(head); // 预期：30 20 10

	// 测试尾插法
	printf("测试尾插法：在尾部插入 40, 50\n");
	Node *tail = GetTail(head);
	tail = InsertTail(tail, 40);
	tail = InsertTail(tail, 50);
	DisplayList(head); // 预期：30 20 10 40 50

	// 测试按位置插入
	printf("测试按位置插入：在第3个位置插入 99\n");
	InsertAtIndex(head, 3, 99);
	DisplayList(head); // 预期：30 20 99 10 40 50

	// 测试获取长度
	int len = GetLength(head);
	printf("链表长度：%d（预期6）\n", len);

	// 测试删除结点
	printf("测试删除第4个结点（值10）\n");
	DeleteNode(head, 4);
	DisplayList(head); // 预期：30 20 99 40 50

	printf("测试删除第1个结点（值30）\n");
	DeleteNode(head, 1);
	DisplayList(head); // 预期：20 99 40 50

	// 测试尾结点删除
	printf("测试删除最后一个结点（值50）\n");
	DeleteNode(head, GetLength(head));
	DisplayList(head); // 预期：20 99 40

	// 测试链表释放
	printf("释放整个链表...\n");
	DeleteLinkedList(head);
	printf("==== 所有测试完成 ====\n");

	return 0;
}
