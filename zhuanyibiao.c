#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//ת�Ʊ�

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}int Mul(int x, int y)
{
	return x * y;
}int Div(int x, int y)
{
	return x / y;
}int Xor(int x, int y)
{
	return x ^ y;
}
menu()
{
	printf("**************************************\n");
	printf("******   1.Add         2.Sub   *******\n");
	printf("******   3.Mul         4.Div   *******\n");
	printf("******   5.Xor         0.exit  *******\n");
	printf("**************************************\n");
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int(*pfArr[])(int, int) = { 0, Add, Sub, Mul, Div, Xor };
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 5)
		{
			printf("����������������:>");
			scanf("%d%d", &x, &y);
			printf("%d\n", pfArr[input](x, y));
		}
		else if (input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("��������������룡\n");
		}
	} while (input);
	return 0;
}