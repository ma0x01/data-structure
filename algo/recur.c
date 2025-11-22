//
// Created by tube on 2025/11/19.
//

#include "recur.h"

int SumRecur(int n) //普通递归
{
	if (n == 1)
	{
		return 1;
	}
	int res = SumRecur(n - 1);

	return n + res;
}

int SumRecurTail(int n, int res) //尾递归
{
	if (n == 0)
	{
		return res;
	}

	return SumRecurTail(n - 1, res + n);
}
