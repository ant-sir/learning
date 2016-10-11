/*
 * select_sort.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */



/**
 * 选择排序
 * 第一次从所有中选出最大（小）的一个，放入第一个位置，
 * 第二次在剩余的中选出最大（小）的一个，放入第二个位置，
 * 依次至到最后一个
 */
void select_sort(int arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		int temp, j;
		for(temp = j = i; j < len; j++)
			if(arr[temp] > arr[j])
				temp = j;
		if(i != temp)
		{
			int tmp = arr[temp];
			arr[temp] = arr[i];
			arr[i] = tmp;
		}
	}
}
