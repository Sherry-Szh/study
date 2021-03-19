#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//�ж�һ���ַ����Ƿ�Ϊ��һ���ַ��������õ���
//����һ

void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
}

int is_left_move(char* s1, char* s2)
{
	int i = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)//���Ȳ�ͬһ������
	{
		return 0;
	}
	for (i = 0; i < len1; i++)//ÿ����һ�ξͱȽ�һ��
	{
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0)
			return 1;
	}
	return 0;
}

int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}