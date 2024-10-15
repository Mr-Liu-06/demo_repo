#include<stdio.h>
int main()
{
	int a;
	int b;
	int c;
	scanf_s("%d%d%d", &a, &b, &c);
	
	int max1 = (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
	int max2 = a > b ? (a > c ? a : c) : (b > c ? b : c);

	printf("max1=%d\nmax2=%d\n", max1, max2);

	return 0;
}