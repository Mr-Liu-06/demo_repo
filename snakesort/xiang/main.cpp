#include"snakesort.h"
int main()
{
	int a[MAX][MAX];
	int n;
	scanf("%d", &n);
	Snakesort(a,n);
	print(a,n);
	return 0;
}