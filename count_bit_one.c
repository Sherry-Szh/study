#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//计算整数的二进制有多少个1（不考虑溢出）
//方法一：
//int count_bit_one(int n)
//{
//	int i = 0;
//	int count = 0;
//
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == (n >> i & 1))
//			count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	int count = 0;
//	scanf("%d", &n);
//	count = count_bit_one(n);
//	printf("%d\n", count);
//	return 0;
//}

//方法二  
int count_bit_one(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n & (n - 1);//每次n&(n-1)会消除最右边的1
		count++;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int count = count_bit_one(n);
	printf("%d\n", count);
	return 0;
}