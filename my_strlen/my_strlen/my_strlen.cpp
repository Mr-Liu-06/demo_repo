#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int my_strlen1(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(char* str)
{
	int count = 0;
	if (*str == '\0')
		return count;
	else
		return 1 + my_strlen2(str + 1);
}

int my_strlen3(char* str)
{
	char* start = str;
	while (*str != '\0')
		str++;
	return str - start;
}

int main()
{
	char arr[] = "HelloWorld";
	char* p = arr;
	printf("arr中共有%d个字符\n", my_strlen1(p));
	printf("arr中共有%d个字符\n", my_strlen2(p));
	printf("arr中共有%d个字符\n", my_strlen3(p));
	return 0;
}