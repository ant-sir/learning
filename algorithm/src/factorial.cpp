/*
 * factorial.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */

#include<cstring>

/**
 * 计算一个大数的阶乘
 * 要求：
 * 用数组操作整数
 */

void factorial(int num, int output[], unsigned int len)
{
    memset(output, 0, len);
	output[0] = num;
	/**
	 * num! = num*(num-1)*(num-2)...*2*1
	 * 0!等于0
	 * 1!等于1
	 * digit表示有效数位数
	 */
	for(int i = num - 1, digit = 1; i >= 1; i--)
	{
		for(int j = 0; j < digit; j++)
			output[j] *= i;
		for(int j = 0; j < digit; j++)
		{
			if(output[j] > 9)
			{
				if(j == digit - 1)
					++digit;
				output[j+1]	+= output[j]/10;
				output[j] = output[j]%10;
			}
		}
	}
}
