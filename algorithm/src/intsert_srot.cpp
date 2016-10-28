/*
 * intsert_srot.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */


/**
 * 直接插入排序
 * 将一个记录插入到已排序好的有序表中，从而得到一个新的，记录数增加1的有序表
 * 时间复杂度O(n^2)
 * 稳定排序方法
 */
void insert_sort(int arr[], int len)
{
	for(int i = 1; i < len; i++)
	{
		int temp = arr[i];
		int j = 0;
		for(j = i - 1; j >= 0 && temp < arr[j]; arr[j + 1] = arr[j], --j);
		arr[j + 1] = temp;
	}
}

