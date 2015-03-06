#include<stdio.h>
int mutrix[10][10];
int ans;
int cal(int n)
{
	int sum = 0, max = -1, t = 0;
	for(int i = n; i >= 3; i -= 2)
	{
		int r1 = 0, c1 = 0, r2 = 0, c2 = n-1, r3 = n - 1, c3 = n - 1, r4 = n - 1,c4 = 0, ss = 0;
		if(i != n)
		{
			r1 += t;c1 += t;
			r2 -= t;c2 += t;
			r3 -= t;c3 -= t;
			r4 -= t;c4 += t;
		}
		int k = 0;
		for(int j = 0; j < i - 1; j++)
		{	
			int tmp = mutrix[r1][c1] + mutrix[r2][c2] +mutrix[r3][c3] + mutrix[r4][c4];  	
			if(max < tmp)
			{
				ss = j;
				max = tmp;
			}
			if(max == tmp)
			{
			//	ss > j % (i / 2 + 1)
			}
			c1++;r2++;c3--;c4--;
		}
		ss = ss > i - 1 -ss ? (i - 1 - ss) : ss;
		sum += ss;
		ans += max;
		t++;
	}
	return sum;
}
int main()
{
	int i, j, n;
	while(scanf("%d", &n) == 1 && n)
	{
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &mutrix[i][j]);
		printf("%d ", cal(n));
			printf("%d\n", ans);
		//printf("%d %d\n", cal(n), ans);
	}
	return 0;

}
