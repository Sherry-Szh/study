#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//�ж�һ���ַ����Ƿ�Ϊ��һ���ַ��������õ���
//������

int is_left_move(char* str1, char* str2)
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)//���Ȳ�ͬһ������
	{
		return 0;
	}

	strncat(str1, str1, len1);//��str1����׷��һ���Լ�
	char* ret = strstr(str1, str2);//�����Ƿ����Ӵ�
	if (ret == NULL)
		return 0;
	else
		return 1;
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