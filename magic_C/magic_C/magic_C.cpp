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
	//һֱ��ӡ    Hello          ��������
	//���Է��֣�&i==&arr[12]     ��������
	//Խ������ڴ� i����arr���� i�ڸߵ�ַ arr�ڵ͵�ַ �������±�������ַ�ɵ͵��߱仯 �ʵ�Խ�����ʵ�i�ĵ�ַ
	return 0;
}