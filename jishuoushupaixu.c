#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//整形数组中的奇数在前偶数在后

void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)//以防都是偶数或奇数造成死循环
	{
		while ((left<right) && arr[left] % 2 == 1)//找到偶数
		{
			left++;
		}
		while ((left<right) && arr[right] % 2 == 0)//找到奇数
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}

void print(int arr[], int sz)//打印
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	print(arr, sz);
	return 0;
}