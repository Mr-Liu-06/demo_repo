#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int steps = 0;

void move(char from, char to)
{
	printf("%c -> %c\n", from, to);
	steps++;
}

void Hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		move(from, to);
	}
	else
	{
		Hanoi(n - 1, from, to, by);
		move(from, to);
		Hanoi(n - 1, by, from, to);
	}
}
int main()
{
	int n;
	printf("请输入汉诺塔层数：");
	scanf("%d", &n);

	printf("步骤为：\n");
	Hanoi(n, 'A', 'B', 'C');

	printf("一共有%d个步骤", steps);

	return 0;
}