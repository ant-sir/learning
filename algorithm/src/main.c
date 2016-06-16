/*
 * main.c
 *
 *  Created on: 2015年4月13日
 *      Author: zyl
 */
#include <stdio.h>

extern int test_huawei_audition(void);
extern int test_linklist(void);

int main(int argc, char* argv[])
{
    printf("master");
	test_linklist();
	test_huawei_audition();
	return 0;
}
