//
// Created by tube on 2025/11/9.
//

#include "seq_stack.h"

bool InitStack(Stack *st, int initSize) //初始化
{
	st->data = (ElementType *) malloc(sizeof(ElementType) * initSize);
	if (st->data == NULL)
	{
		printf("内存分配失败！\n");
		return false;
	}
	st->top = -1;
	st->capacity = initSize;
	return true;
}

bool IsEmptyStack(Stack *st) //判断栈是否为空
{
	if (st->top == -1)
	{
		return true;
	}

	return false;
}

bool ExpandStack(Stack *st) //扩容
{
	int newCapacity = st->capacity * 2;
	ElementType *newData = (ElementType *) realloc(st->data, sizeof(ElementType) * newCapacity);

	if (newData == NULL)
	{
		printf("扩容失败！\n");
		return false;
	}

	st->data = newData;
	st->capacity = newCapacity;

	return true;
}

bool PushStack(Stack *st, ElementType e) //进栈/压栈
{
	if (st->top >= st->capacity - 1)
	{
		if (!ExpandStack(st))
		{
			printf("扩容失败，无法入栈 %d\n", e);
			return false;
		}
	}

	st->data[++st->top] = e;
	return true;
}

bool PopStack(Stack *st, ElementType *e) //出栈
{
	if (IsEmptyStack(st))
	{
		printf("栈为空！\n");
		return false;
	}

	*e = st->data[st->top];
	st->top--;
	return true;
}

bool GetStackTop(Stack *st, ElementType *e) //获取栈顶元素
{
	if (IsEmptyStack(st))
	{
		printf("栈为空！\n");
		return false;
	}

	*e = st->data[st->top];
	return true;
}

void PrintStack(Stack *st) //输出栈元素
{
	if (st == NULL)
	{
		return;
	}
	for (int i = st->top; i > -1; i--)
	{
		printf("%d ", st->data[i]);
	}
	printf("\n");
}

void ClearStack(Stack *st) //清空栈
{
	if (st != NULL)
	{
		st->top = -1;
	}
}

void DestroyStack(Stack *st) //销毁栈
{
	if (st->data != NULL)
	{
		free(st->data);
		st->data = NULL;
	}

	st->top = -1;
	st->capacity = 0;
}
