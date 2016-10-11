/*
 * palindrome.cpp
 *
 *  Created on: 2016年10月2日
 *      Author: zyl
 */


/**
 * 打印小于 num 的回文数
 */
bool palindrome(int num)
{
	int temp = 0, n = num;
	while(n)
	{
		temp = temp*10 + n%10;
		n /= 10;
	}
	return (num == temp);
}

