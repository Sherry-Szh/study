#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[10][10] = { 0 };//假设打印10行
	int i = 0;
	int j = 0;
	for (i = 0; i<10; i++)//将杨辉三角数存进二维数组
	{
		for (j = 0; j<10; j++)
		{
			if (j == 0)
			{
				a[i][j] = 1;//第一列赋值1
			}
			if (i == j)
			{
				a[i][j] = 1;//对角线赋值1
			}
			if (i >= 2 && j >= 1)
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; //计算中间部分数据
			}
		}
	}
	for (i = 0; i<10; i++)
	{
		int col = 0;
		for (col = 0; col<=9 - i; col++)
		{
			if (col<9 - i)
			{
				printf(" ");
			}
			else
			{
				for (j = 0; j <= i; j++)
				{
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
			
		}
	}
	return 0;
}