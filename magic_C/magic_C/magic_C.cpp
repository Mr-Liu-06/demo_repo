#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("Hello\n");
	}
	//一直打印    Hello          ！！？？
	//调试发现：&i==&arr[12]     ！！？？
	//越界访问内存 i先于arr创建 i在高地址 arr在低地址 数组随下标增长地址由低到高变化 适当越界会访问到i的地址
	return 0;
}