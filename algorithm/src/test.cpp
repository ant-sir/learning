/*
 * test.cpp
 *
 *  Created on: 2016年10月3日
 *      Author: zyl
 */

#include <gtest/gtest.h>

extern void bubble_sort(int arr[], int len);
extern void factorial(int num, int output[], unsigned int len);
extern void insert_sort(int arr[], int len);
extern void quick_sort(int arr[], int left, int right);
extern void select_sort(int arr[], int len);
extern void shell_sort(int arr[], int len);
extern void sort_int(int data[], int len);

TEST(bubble_sort_case, bubble_sort_test)
{
	int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

    bubble_sort(arr, sizeof(arr)/sizeof(int));

	EXPECT_EQ(1, arr[0]);
	EXPECT_EQ(2, arr[1]);
	EXPECT_EQ(3, arr[2]);
	EXPECT_EQ(4, arr[3]);
	EXPECT_EQ(5, arr[4]);
	EXPECT_EQ(6, arr[5]);
	EXPECT_EQ(7, arr[6]);
	EXPECT_EQ(8, arr[7]);
	EXPECT_EQ(9, arr[8]);
	EXPECT_EQ(10, arr[9]);
}

TEST(factorial_case, factorial_test)
{
    int arr[40] = {0};

    factorial(0, arr, sizeof(arr)/sizeof(int));
    EXPECT_EQ(0, arr[0]);

    factorial(1, arr, sizeof(arr)/sizeof(int));
    EXPECT_EQ(1, arr[0]);

    factorial(2, arr, sizeof(arr)/sizeof(int));
    EXPECT_EQ(2, arr[0]);

    factorial(3, arr, sizeof(arr)/sizeof(int));
    EXPECT_EQ(6, arr[0]);

    //2432902008176640000
    factorial(20, arr, sizeof(arr)/sizeof(int));
    EXPECT_EQ(0, arr[0]);
    EXPECT_EQ(0, arr[1]);
    EXPECT_EQ(0, arr[2]);
    EXPECT_EQ(0, arr[3]);
    EXPECT_EQ(4, arr[4]);
    EXPECT_EQ(6, arr[5]);
    EXPECT_EQ(6, arr[6]);
    EXPECT_EQ(7, arr[7]);
    EXPECT_EQ(1, arr[8]);
    EXPECT_EQ(8, arr[9]);
    EXPECT_EQ(0, arr[10]);
    EXPECT_EQ(0, arr[11]);
    EXPECT_EQ(2, arr[12]);
    EXPECT_EQ(0, arr[13]);
    EXPECT_EQ(9, arr[14]);
    EXPECT_EQ(2, arr[15]);
    EXPECT_EQ(3, arr[16]);
    EXPECT_EQ(4, arr[17]);
    EXPECT_EQ(2, arr[18]);
    EXPECT_EQ(0, arr[19]);
}

TEST(insert_sort_case, insert_sort_test)
{
    int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

    insert_sort(arr, sizeof(arr)/sizeof(int));

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    EXPECT_EQ(6, arr[5]);
    EXPECT_EQ(7, arr[6]);
    EXPECT_EQ(8, arr[7]);
    EXPECT_EQ(9, arr[8]);
    EXPECT_EQ(10, arr[9]);
}

TEST(quick_sort_case, quick_sort_test)
{
    int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

    quick_sort(arr, 0, sizeof(arr)/sizeof(int)-1);

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    EXPECT_EQ(6, arr[5]);
    EXPECT_EQ(7, arr[6]);
    EXPECT_EQ(8, arr[7]);
    EXPECT_EQ(9, arr[8]);
    EXPECT_EQ(10, arr[9]);
}

TEST(select_sort_case, select_sort_test)
{
    int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

    select_sort(arr, sizeof(arr)/sizeof(int));

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    EXPECT_EQ(6, arr[5]);
    EXPECT_EQ(7, arr[6]);
    EXPECT_EQ(8, arr[7]);
    EXPECT_EQ(9, arr[8]);
    EXPECT_EQ(10, arr[9]);
}

TEST(shell_sort_case, shell_sort_test)
{
    int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

    shell_sort(arr, sizeof(arr)/sizeof(int));

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    EXPECT_EQ(6, arr[5]);
    EXPECT_EQ(7, arr[6]);
    EXPECT_EQ(8, arr[7]);
    EXPECT_EQ(9, arr[8]);
    EXPECT_EQ(10, arr[9]);
}

TEST(sort_int_case, sort_int_test)
{
    int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

    sort_int(arr, sizeof(arr)/sizeof(int));

    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(2, arr[1]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    EXPECT_EQ(6, arr[5]);
    EXPECT_EQ(7, arr[6]);
    EXPECT_EQ(8, arr[7]);
    EXPECT_EQ(9, arr[8]);
    EXPECT_EQ(10, arr[9]);
}
