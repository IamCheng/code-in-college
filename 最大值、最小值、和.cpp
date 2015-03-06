#include<stdio.h>
int main()
{
	int num[10005], n, i, max, min, sum;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	max = min = sum = num[1];
	for(i = 2; i <= n; i++)
	{
		if(num[i] > max)
			max = num[i];
		if(num[i] < min)
			min = num[i];
		sum += num[i];
	}	
	printf("%d\n%d\n%d\n", max, min, sum);
		return 0;
}