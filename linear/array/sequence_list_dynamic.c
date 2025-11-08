//
// Created by tube on 2025/11/8.
//

#include "sequence_list_dynamic.h"

SeqList *InitDynamicSeqList() //初始化顺序表
{
	SeqList *pSeqList = (SeqList *) malloc(sizeof(SeqList));
	pSeqList->data = (ElementType *) malloc(MAX_SIZE * sizeof(ElementType));
	pSeqList->length = 0;

	return pSeqList;
}
