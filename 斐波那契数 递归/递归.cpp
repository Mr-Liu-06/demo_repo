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
	printf("请输入你想求第几个斐波那契数?\n");
	scanf_s("%d", &n);
	printf("第%d个斐波那契数是 %d\n", n, Fib(n));


	return 0;
}