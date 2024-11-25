#include"snakesort.h"
void Snakesort(int(*a)[MAX], int n)
{
	int num = 1;
	int row=0;
	int col = n - 1;
	int dir = -1;
	for (num = 1; num <= n * n; ++num)
	{
		a[row][col] = num;
		row += dir;
		col += dir;
		if (row < 0 || row == n || col < 0 || col == n)
		{
			dir = -dir;
		}
		if (col < 0)
		{
			++col;
			row += 2;
		}
		else if (row < 0)
		{
			++row;
		}
		else if (row == n)
		{
			--row;
			col -= 2;
		}
		else if (col == n)
		{
			--col;
		}
	}
}
void print(int (*a)[MAX],int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		int j = 0;
		for (j = 0; j < n; ++j)
		{
			printf("%-4d", (*(a + i))[j]);
		}
		printf("\n");
	}
}