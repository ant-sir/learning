/*
 * quick_sort.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */


/**
 * 快速排序
 * 通过一趟排序将要排序的数据分为两个部分，
 * 其中一部分的所有数据都比另外一部分的所有数据要小，
 * 然后再按此法对这两部分进行排序
 */
void quick_sort(int arr[], int left, int right)
{
	if( left >= right)
		return;
	int i = left, j = right, key = arr[left];
	while( i < j)
	{
		for(; j > left && arr[j] > key; --j);
		arr[i] = arr[j];
		for(; i < right && arr[i] < key; i++);
		arr[j] = arr[i];
	}
	arr[i] = key;
	quick_sort(arr, left, i - 1);
	quick_sort(arr, i + 1, right);
}

