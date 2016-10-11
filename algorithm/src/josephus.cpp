/*
 * josephus.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */

#include<iostream>
#include<cstring>
#include<cstdlib>

/**
 * 约斯夫环，数学算法
 */
void josephus2(int n, int m)
{
	int f = 0;
	for(int i = 1; i <= n; i++)
		f = (f + m)%i;
	std::cout << f+1 << std::endl;
}
/**
 * 约斯夫环
 */
void josephus(int n, int m, int live)
{
	int *que = (int*)malloc(sizeof(int)*n);
	memset(que, 0, sizeof(int)*n);
	int dead = 0;
	int count = 0, j = 0;
	while( dead != n-live )
	{
		if(j == n)
			j = 0;
		if(!que[j])
			count++;
		if(count == m)
		{
			que[j] = 1;
			std::cout << j+1 << " was killed." << std::endl;
			count = 0;
			dead++;
		}
		j++;
	}
	for(int i = 0; i < n; i++)
		if(!que[i])
			std::cout << i+1 << " win." << std::endl;
}


