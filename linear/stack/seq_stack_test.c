//
// Created by tube on 2025/11/9.
//

#include"seq_stack.h"

int main()
{
	Stack st;
	InitStack(&st, 4);

	printf("入栈：\n");
	for (int i = 1; i <= 10; i++)
	{
		PushStack(&st, i);
	}
	PrintStack(&st);

	ElementType e;
	GetStackTop(&st, &e); //获取栈顶元素
	printf("栈顶元素为：%d\n", e);

	printf("清空栈：\n");
	ClearStack(&st);
	if (IsEmptyStack(&st))
	{
		printf("栈为空\n");
	}

	printf("入栈：\n");
	PushStack(&st, 100);
	PushStack(&st, 200);
	PrintStack(&st);

	printf("销毁栈\n");
	DestroyStack(&st);

	return 0;
}
