/*
 * test.cpp
 *
 *  Created on: 2016年10月3日
 *      Author: zyl
 */

#include <gtest/gtest.h>

extern void bubble_sort(int arr[], int len);

TEST(bubble_sort_test, bubble_sort_case)
{
	int arr[10] = {3, 6, 9, 1, 2, 7, 5, 4, 8, 10};

	bubble_sort(arr, sizeof(arr));

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

