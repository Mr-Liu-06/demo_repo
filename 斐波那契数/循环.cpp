#include<stdio.h>

int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n;
	printf("������������ڼ���쳲�������?\n");
	scanf_s("%d", &n);
	printf("��%d��쳲��������� %d\n", n,Fib(n));

	return 0;
}