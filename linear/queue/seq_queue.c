//
// Created by tube on 2025/11/9.
//

#include "seq_queue.h"

Queue *InitQueue() //初始化
{
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->data = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
	q->front = 0;
	q->rear = 0;
	q->capacity = MAXSIZE;
	return q;
}

bool IsEmptyQueue(Queue *q) //判断队列是否为空
{
	if (q->rear == q->front)
	{
		return true;
	}

	return false;
}

bool ExpandQueue(Queue *q) //扩容
{
	int oldCap = q->capacity;
	int newCap = oldCap * 2;

	// 分配新空间
	ElemType *newData = (ElemType *) malloc(sizeof(ElemType) * newCap);
	if (!newData)
	{
		return false;
	}

	// 计算原队列长度
	int size = (q->rear - q->front + oldCap) % oldCap;

	// 将队列元素拷贝到新数组
	for (int i = 0; i < size; i++)
	{
		newData[i] = q->data[(q->front + i) % oldCap];
	}

	// 更新队列结构
	free(q->data);
	q->data = newData;
	q->capacity = newCap;
	q->front = 0;
	q->rear = size;

	return true;
}

bool IsFullQueue(Queue *q) //判断队列是否满
{
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		return true;
	}

	return false;
}

bool Enqueue(Queue *q, ElemType e) //入队
{
	if (IsFullQueue(q))
	{
		printf("队列已满！\n");
		return false;
	}

	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	return true;
}

bool Dequeue(Queue *q, ElemType *e) //出队
{
	if (IsEmptyQueue(q))
	{
		printf("队列为空！\n");
		return false;
	}

	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return true;
}

bool GetQueueHead(Queue *q, ElemType *e) //获取队头数据
{
	if (IsEmptyQueue(q))
	{
		printf("队列为空！\n");
		return false;
	}

	*e = q->data[q->front];
	return true;
}

bool GetQueueRear(Queue *q, ElemType *e) //获取队尾数据
{
	if (IsEmptyQueue(q))
	{
		printf("队列为空！\n");
		return false;
	}

	int index = (q->rear - 1 + MAXSIZE) % MAXSIZE;
	*e = q->data[index];
	return true;
}
