//
// Created by tube on 2025/11/9.
//

#ifndef DATA_STRUCTURE_SEQ_STACK_H
#define DATA_STRUCTURE_SEQ_STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElementType;

typedef struct //栈
{
	ElementType *data;
	int top;
	int capacity;
} Stack;

bool InitStack(Stack *st, int initSize); //初始化

bool IsEmptyStack(Stack *st); //判断栈是否为空

bool ExpandStack(Stack *st); //扩容

bool PushStack(Stack *st, ElementType e); //进栈/压栈

bool PopStack(Stack *st, ElementType *e); //出栈

bool GetStackTop(Stack *st, ElementType *e); //获取栈顶元素

void PrintStack(Stack *st); //输出栈元素

void ClearStack(Stack *st); //清空栈

void DestroyStack(Stack *st); //销毁栈

#endif //DATA_STRUCTURE_SEQ_STACK_H
