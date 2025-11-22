//
// Created by tube on 2025/11/9.
//

#include "seq_stack.h"

#include <math.h>

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

int GetPriority(char c)
{
	switch (c)
	{
		case '^':
			return 5;
		case '*':
			return 4;
		case'/':
			return 3;
		case'+':
			return 2;
		case'-':
			return 1;
		default:
			return 0;
	}
}

char *InfixToPostfix(const char *expression) //中缀表达式转后缀
{
	int len = strlen(expression);
	char *new = (char *) malloc((len + 1) * sizeof(char));
	int index = 0;
	char *stack = (char *) malloc((len + 1) * sizeof(char));
	int top = -1; //栈顶指针

	for (int i = 0; i < len; i++)
	{
		char c = expression[i];

		if (c >= '0' && c <= '9') //数字直接输出
		{
			new[index++] = c;
		}
		else if (expression[i] == '(') //左括号栈外优先级最高
		{
			stack[++top] = c;
		}
		else if (c == ')') //右括号持续出栈到左括号出栈为止
		{
			while (top >= 0 && stack[top] != '(')
			{
				new[index++] = stack[top--];
			}
			if (top >= 0 && stack[top] == '(')
			{
				top--; //弹掉左括号
			}
		}
		else
		{
			// 栈顶优先级 >= 当前运算符时，不断弹栈
			while (top >= 0 && stack[top] != '(' && GetPriority(stack[top]) >= GetPriority(c))
			{
				new[index++] = stack[top--];
			}

			stack[++top] = c; // 当前符号入栈
		}
	}

	while (top >= 0)
	{
		if (stack[top] != '(')
		{
			new[index++] = stack[top];
		}
		top--;
	}

	new[index] = '\0'; // 结束符

	free(stack);
	return new;
}

int Evaluate(int left, int right, char c) //计算
{
	switch (c)
	{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			return left / right;
		case '^':
			return pow(left, right);
		default:
			return 0;
	}
}

int EvaluatePostfix(const char *expression) //计算后缀表达式
{
	int len = strlen(expression);
	int *stack = (int *) malloc((len + 1) * sizeof(int));
	int top = -1; //栈顶指针

	for (int i = 0; i < len; i++)
	{
		char c = expression[i];
		if (c >= '0' && c <= '9') //数字入栈
		{
			stack[++top] = c - '0';
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		{
			int second = stack[top--];
			int first = stack[top--];

			stack[++top] = Evaluate(first, second, c);
		}
	}

	int result = stack[top];
	free(stack);
	return result;
}
