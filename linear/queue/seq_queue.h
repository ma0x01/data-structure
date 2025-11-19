//
// Created by tube on 2025/11/9.
//

#ifndef DATA_STRUCTURE_SEQ_QUEUE_H
#define DATA_STRUCTURE_SEQ_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

#define MAXSIZE 100

typedef struct //动态顺序循环队列
{
	int front;
	int rear;
	int capacity;
	ElemType *data;
} Queue;

Queue *InitQueue(); //初始化

bool IsEmptyQueue(Queue *q); //判断队列是否为空

bool ExpandQueue(Queue *q); //扩容

bool IsFullQueue(Queue *q); //判断队列是否满

bool Enqueue(Queue *q, ElemType e); //入队

bool Dequeue(Queue *q, ElemType *e); //出队

bool GetQueueHead(Queue *q, ElemType *e); //获取队头数据

bool GetQueueRear(Queue *q, ElemType *e); //获取队尾数据

#endif //DATA_STRUCTURE_SEQ_QUEUE_H
