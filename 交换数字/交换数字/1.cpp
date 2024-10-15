#include<stdio.h>
int main()
{
	int a;
	int b;
	int c = 0;
	printf("交换前：a b值分别为：");
	scanf_s("%d %d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("交换后：a=%d,b=%d\n", a, b);

	return 0;
}


