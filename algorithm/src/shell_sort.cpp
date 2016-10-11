/*
 * shell_sort.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */


/**
 * 希尔排序（缩小增量的插入排序）
 */
void shell_sort(int arr[], int len)
{
	for(int gas = len >> 1; gas > 0; gas >>= 1)
	{
		for(int i = gas; i < len; i++)
		{
			int temp = arr[i];
			int j = 0;
			for(j = i - gas; j >= 0 && temp < arr[j]; arr[j + gas] = arr[j], j -= gas);
			arr[j + gas] = temp;
		}
	}
}

