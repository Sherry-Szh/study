#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//判断一个字符串是否为另一个字符串左旋得到的
//方法二

int is_left_move(char* str1, char* str2)
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)//长度不同一定不是
	{
		return 0;
	}

	strncat(str1, str1, len1);//在str1后面追加一个自己
	char* ret = strstr(str1, str2);//查找是否有子串
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