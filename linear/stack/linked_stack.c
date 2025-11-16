//
// Created by tube on 2025/11/9.
//

#include "linked_stack.h"

Stack *InitStack_L() //初始化栈
{
	return NULL;
}

bool IsEmptyStack_L(Stack *st) //判断栈是否为空
{
	return st == NULL;
}

void PushStack_L(Stack **st, ElementType e) //进栈/压栈
{
	Stack *n = (Stack *) malloc(sizeof(Stack));
	if (!n)
	{
		perror("内存分配失败");
		exit(EXIT_FAILURE);
	}
	n->data = e;
	n->next = *st;
	*st = n;
}

bool PopStack_L(Stack **st, ElementType *e) //出栈
{
	if (IsEmptyStack_L(*st)) //空栈
	{
		return false;
	}

	Stack *temp = *st;
	*e = temp->data;
	*st = temp->next;
	free(temp);
	return true;
}
