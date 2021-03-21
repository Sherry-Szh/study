#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int FindNum(int arr[3][3], int k, int* px, int *py)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y]<k)//比这一行最大的还要大-不在这一行
		{
			x++;
		}
		else if (arr[x][y]>k)//比这一列最小的还小-不在这一列
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int k = 7;//假设找7
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是：%d %d\n", x, y);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}