#include<stdio.h>
#include<algorithm>
int main()
{
	int m,n,A[20005],B[20005];
	while(scanf("%d%d", &n, &m) ==2 && !(n == 0 && m == 0))
	{
		int sum = 0, i, num = 0;
		for(i = 0; i < n; i++)	
			scanf("%d",&A[i]);
		for(i = 0; i < m; i++)	
			scanf("%d",&B[i]);
		std::sort(A, A+n);
		std::sort(B, B+m);

		for(i = 0; i < m; i++)
		{
			if( B[i] >= A[num])
			{
				sum += B[i];
				num++;
			}
			if(num == n)
				break;
		}
		if(num == n)
			printf("%d\n", sum);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}