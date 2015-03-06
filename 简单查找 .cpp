#include<stdio.h>
int main()
{
	int num[1005], n, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	int m;
	scanf("%d", &m);
	for(i = 1; i <= n; i++)
		if(num[i] == m){
			printf("%d\n", i);
			break;
		}
		if(i == n+1)
			printf("-1\n");
		return 0;
}