#include<stdio.h>
int main()
{
	int a;
	int b;
	int c = 0;
	printf("����ǰ��a bֵ�ֱ�Ϊ��");
	scanf_s("%d %d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("������a=%d,b=%d\n", a, b);

	return 0;
}


