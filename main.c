/*
 ============================================================================
 Name        : prime_number.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

/**
 * 把非负整数0,1,2,...,n-1随机放入大小为n的数组中，
 * 要求时间杂度为O(n)，辅助空间为O(1)，
 * 只允许用交换操作，一次只能交换两个元素
 */
void sort_int()
{
	int data[] = {9, 4, 3, 8, 7, 5, 2, 0, 1, 6};
	int len = sizeof(data)/sizeof(data[0]);
	int temp = 0;
	for(int i = 0; i< len; )
	{
		if(data[i] == i)
		{
			i++;
			continue;
		}
		temp = data[data[i]];
		data[data[i]] = data[i];
		data[i] = temp;
	}
	for(int i = 0; i < len; i++)
		printf("%d ", data[i]);
	printf("\n");
}

/**
 * 最大支持一个40位整数的阶乘
 * 用数组操作整数
 * 输入 : 要求的整数
 */
void factorial( int num )
{
	int data[40] = {0};
	int digit = 0;//数据位数变量
	for(int i = 0; i <= 40; i++)
		data[i] = 0;
	data[0] = 1;
	digit = 1;
	for(int i = 1; i <= num; i++)
	{
		for(int j = 0; j < digit; j++)
			data[j] *= i;
		for(int j = 0; j < digit; j++)
		{
			if(data[j] > 9)
			{
				if(j == digit - 1)
					digit++;
				data[j+1] += data[j]/10;
				data[j] = data[j]%10;
			}
		}
		printf("%d! = ", i);
		for(int k = digit - 1; k >= 0; k--)
			printf("%d", data[k]);
		printf("\n");
	}
}

/**
 * 求2~2000的所有素数.有足够的内存,要求尽量快
 */
int findvalue[2000] = {2};
static int find = 1;

bool adjust(int value)
{
	assert(value >= 2);
	if(value == 2)
		return true;
	for(int i = 0; i < find; i++)
	{
		if(value%findvalue[i] == 0)
			return false;
	}
	findvalue[find++] = value;
	return true;
}

/**
 * 打印1～n的所有素数
 */
void print_prime_number(int n)
{
	int flag = 0;
	for(int i = 2; i <= n; i++)
	{
		flag = 0;
		for(int j = 2; j < i/2+1; j++)
		{
			if(i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			printf("%d ", i);
	}
	printf("\n");
}

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

/**
 * 约斯夫环，数学算法
 */
void josephus2(int n, int m)
{
	int f = 0;
	for(int i = 1; i <= n; i++)
		f = (f + m)%i;
	printf("%d win.\n", f+1);
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
			printf("%d was killed.\n", j+1);
			count = 0;
			dead++;
		}
		j++;
	}
	for(int i = 0; i < n; i++)
		if(!que[i])
			printf("%d win.\n", i+1);
}
/**
 * 实现字符串比较函数
 * int strcmp(char  *source, char *dest)
 */
int strcmp_self(char  *source, char *dest)
{
	char* s = source, *d = dest;
	for(; *s != '\0' && *d != '\0' && *s == *d; s++, d++);
	if(*s == '\0' && *d == '\0')
		return 0;
	return -1;
}
/**
 * 打印出输入时间的下一秒
 * 输入：年／月／日／时／分／秒
 */
void time_print(
		int *year,
		int *mouth,
		int *day,
		int *hour,
		int *minute,
		int *second )
{
	if(++(*second) >= 60)
	{
		*second %= 60;
		if(++*minute >=60)
		{
			*minute %= 60;
			if(++*hour >= 24)
			{
				*hour %= 24;
				++*day;
				switch(*mouth)
				{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					if(*day > 31)
					{
						++*mouth;
						*day %= 31;
					}
					break;
				case 2:
					if((*year % 4 == 0 && *year % 100 != 0) || (*year % 400 == 0))
					{
						if(*day > 29)
						{
							++*mouth;
							*day %= 29;
						}
					}
					else
					{
						if(*day > 28)
						{
							++*mouth;
							*day %= 28;
						}
					}
					break;
				default:
					if(*day > 30)
					{
						++*mouth;
						*day %= 30;
					}
				}
				if(*mouth > 12)
				{
					++*year;
					*mouth %= 12;
				}
			}
		}
	}
	printf("%d/%d/%d %d:%d:%d\n", *year, *mouth, *day, *hour, *minute, * second);
}

/**
 * 直接插入排序
 * 将一个记录插入到已排序好的有序表中，从而得到一个新的，记录数增加1的有序表
 * 时间复杂度O(n^2)
 * 稳定排序方法
 */
void intsert_srot(int arr[], int len)
{
	for(int i = 1; i < len; i++)
	{
		int temp = arr[i];
		int j = 0;
		for(j = i - 1; j >= 0 && temp < arr[j]; arr[j + 1] = arr[j], --j);
		arr[j + 1] = temp;
	}
}
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
/**
 * 冒泡排序
 */
void bubble_sort(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

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

int main(void) {
//	print_prime_number(100);
//	josephus(10, 3, 2);
//	josephus2(10, 3);
//	factorial(20);
//	sort_int();
//	char* a = "hello world";
//	char* b = "hello world	";
//	printf("%d\n", strcmp_self(a, b));
//	int **a[3][4];
//	printf("%lu\n", sizeof(a));
//	for(int y = 1956; y <= 2015;)
//		for(int m = 1; m <=12; )
//			for(int d = 1; d <= 31; )
//				for(int h = 0; h <= 23; )
//					for(int m2 = 0; m2 <=59;)
//						for(int s = 0; s <= 59;)
//						{
//							time_print(&y, &m, &d, &h, &m2, &s);
//							usleep(50000);
//						}
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//intsert_srot(arr, sizeof(arr)/sizeof(arr[0]));
	quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		printf("%d ", arr[i]);
	printf("\n");

	return EXIT_SUCCESS;
}
