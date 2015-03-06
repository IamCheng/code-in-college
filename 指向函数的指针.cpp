#include<stdio.h>
#include<algorithm>
using namespace std;
int show(int num[], int n, void (*fun)(int a[], int n))
{
	
	fun(num, n);
	return 0;
}
void qsort_out(int a[], int n)
{
	printf("快排:");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void bubble_sort_out(int a[], int n)
{
	printf("冒泡");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void out(int a[], int n)
{
	printf("直接输出:");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int main()
{
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	show(a, 9, out);

	sort(a, a+9);
	show(a, 9, qsort_out);

	show(a, 9, bubble_sort_out);
	return 0;
}