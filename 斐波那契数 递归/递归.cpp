#include<stdio.h>

int Fib(int n)
{
	if (n < 3)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}


int main()
{
	int n;
	printf("������������ڼ���쳲�������?\n");
	scanf_s("%d", &n);
	printf("��%d��쳲��������� %d\n", n, Fib(n));


	return 0;
}