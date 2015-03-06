#include<stdio.h>
int ball[25][25],flag[25];
void main()
{
	int N,i,j;
	while(scanf("%d",&N)!=EOF)
	{
		for(i = 0; i < N; i ++ )
		{
			for(j = 0 ;j <= i; j ++)
			{
				scanf("%d",&ball[i][j]);
			}
		}
		for(i = 0; i < N; i++)
			flag[i] = ball[N-1][i];
		for(i = N - 2;i >= 0 ; i --)
		{
			for(j = 0;j <= i; j++)
			{
				flag[j] = (flag[j] + ball[i][j]) > (flag[j+1] + ball[i][j])?(flag[j] + ball[i][j]):(flag[j+1] + ball[i][j]);
			}
		}
		printf("%d\n",flag[0]);
	}
}