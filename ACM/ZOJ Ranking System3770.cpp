#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct node
{
	int num, qq, y, m, d, score, lv;
}p[2010];
int order[2010];
int cmp(node a, node b)
{
	return a.score == b.score ? (a.y == b.y ? (a.m == b.m ? (a.d == b.d ? a.qq < b.qq : a.d < b.d) : a.m < b.m) : a.y < b.y) : a.score > b.score;
}
int main()
{
	int T, N;
	double q[] = {0.03, 0.07, 0.2, 0.3};
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int cnt = 0, i, j;
		memset(p, 0, sizeof(p));
		for(i = 0; i < N; i++)
		{
			scanf("%d%d/%d/%d%d", &p[i].qq, &p[i].y, &p[i].m, &p[i].d, &p[i].score);
			if(p[i].score > 0)	cnt++;
			p[i].num = i;
		}
		sort(p, p+N, cmp);
		i = 0;
		for(j = 0; j < 4; j++)
		{
			int tmp = i + cnt * q[j];
			for( ;i < tmp; i++)
				p[i].lv = 6 - j;
		}
		for(i = 0; i < N; i++)
			order[p[i].num] = i;
		for(i = 0; i < N; i++)
		{
			printf("LV%d\n", p[order[i]].lv > 0 ? p[order[i]].lv : (p[order[i]].score != 0 ? 2 : 1));
		}
	}
	return 0;
}