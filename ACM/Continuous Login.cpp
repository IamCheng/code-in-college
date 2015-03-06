#include<stdio.h>
#include<math.h>
int ans[100], cnt;
int srch(int num, int depth)
{
	int div = (int)(sqrt(num*2+0.25)-0.5);
	if(depth == 0)
	{
		if(div*(div+1) == num*2)
		{
			ans[cnt++] = div;
			return 1;
		}
		return 0;
	}
	for(int i = 1; i <= div; i++)
	{
		if(srch(num-(i+1)*i/2, depth-1) == 1)
		{
			ans[cnt++] = i;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		cnt = 0;		
		for(int i = 0; i < 100; i++)
			if(srch(N, i) == 1)	break;
		printf("%d", ans[0]);
		for(i = 1; i < cnt; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}