/*
 * sort_int.cpp
 *
 *  Created on: 2016年10月1日
 *      Author: zyl
 */

/**
 * 该算法只排序连续的非负整数，从零开始。
 * 如0,1,2,3,...,n-1。
 * 要求：
 * 时间复杂度为O(n)，空间复杂度为O(1)。
 * 只允许用交换操作，一次只能交换两个元素。
 * 不能用辅助函数。
 */

/**
 * 算法原理：
 * 第i个位置的数应该在以data[i]为下标的位置。
 * 所以我们交换data[data[i]]与data[i]的值。
 */
void sort_int(int data[], int len)
{
	for(int i = 0, tmp =0; i < len;)
	{
		if(data[i] == i)
		{
			++i;
			continue;
		}
		tmp = data[data[i]];
		data[data[i]] = data[i];
		data[i] = tmp;
	}
}

