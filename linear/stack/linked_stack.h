//
// Created by tube on 2025/11/9.
//

#ifndef DATA_STRUCTURE_LINKED_STACK_H
#define DATA_STRUCTURE_LINKED_STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int ElementType;

typedef struct stack //栈
{
	ElementType data;
	struct stack *next;
} Stack;

Stack *InitStack_L(); //初始化栈

bool IsEmptyStack_L(Stack *st); //判断栈是否为空

void PushStack_L(Stack **st, ElementType e); //进栈/压栈

bool PopStack_L(Stack **st, ElementType *e); //出栈

#endif //DATA_STRUCTURE_LINKED_STACK_H
