#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//���������Ķ������ж��ٸ�1�������������
//����һ��
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

//������  
int count_bit_one(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n & (n - 1);//ÿ��n&(n-1)���������ұߵ�1
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