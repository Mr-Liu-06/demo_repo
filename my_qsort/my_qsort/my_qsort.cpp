#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int cmp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

void exchge(char* e1, char* e2, int width)
{
	int i = 0;
	char c;
	for (i = 0; i < width; i++)
	{
		c = *e1;
		*e1 = *e2;
		*e2 = c;
		e1++;
		e2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
				exchge((char*)base + j * width, (char*)base + (j + 1) * width, width);
		}
	}
}

void print_int(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_int(arr,sz);

	return 0;
}