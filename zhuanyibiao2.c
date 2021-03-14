#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//转移表
//如果用switch语句如何避免冗余

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

Calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数:>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 5:
			Calc(Xor);
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}
