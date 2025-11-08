//
// Created by tube on 2025/11/8.
//

#include "sequence_list.h"

void InitSeqList(SeqList *p) //初始化顺序表
{
	p->length = 0;
}

void AppendSeqList(SeqList *p, ElementType e) //尾插顺序表
{
	if (p->length >= MAX_SIZE)
	{
		printf("顺序表空间不足\n");
		return;
	}
	else
	{
		p->data[p->length] = e;
		p->length++;
		return;
	}
}


void DisplaySeqList(SeqList *p) //遍历顺序表
{
	for (int i = 0; i < p->length; i++)
	{
		printf("%d ", p->data[i]);
	}
	printf("\n");
}

void InsertSeqList(SeqList *p, int pos, ElementType e) //插入顺序表
{
	if (pos < p->length)
	{
		for (int i = p->length; i > pos; i--)
		{
			p->data[i] = p->data[i - 1];
		}
		p->data[pos] = e;
		p->length++;
	}
}

int DeleteSeqListELem(SeqList *p, int pos, ElementType *e) //删除顺序表中的某个元素
{
	*e = p->data[pos];
	for (int i = pos; i < p->length; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->length--;

	return 0;
}

int FindSeqListIndex(SeqList *p, ElementType e) //查找顺序表中的元素位置
{
	for (int i = 0; i < p->length; i++)
	{
		if (e == p->data[i])
		{
			return i;
		}
	}

	return -1;
}
