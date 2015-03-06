#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 100010;
typedef struct t
{
	int a;
	int m;
}arrow;
int cmp(int a, int b)
{
	return a > b;
}
int cmp1(const arrow &a, const arrow &b)
{
	return a.a > b.a;
}
bool operator < (const t & a, const t & b)
{
	return a.m > b.m;
};
int R[maxn];
arrow B[maxn];
int main()
{
	int N, M;
	while(scanf("%d%d", &N, &M) == 2)
	{
		int i, j;
		priority_queue <arrow> q; 
		for(i = 0; i < N; i++)
			scanf("%d", &R[i]);
		for(j = 0; j < M; j++)
			scanf("%d", &B[j].a);
		for(i = 0; i < M; i++)
			scanf("%d", &B[i].m);
		sort(R, R+N, cmp);
		sort(B, B+M, cmp1);
		__int64 crt = 0, ans = 0;
		j = 0;
		for(i = 0; i < N; i++)
		{
			while(R[crt] <= B[j].a && j < M)
				q.push(B[j++]);
			if(!q.empty())
			{
				crt++;
				ans += q.top().m;
				q.pop();
			}
			else
				break;
			
		}		
		if(i == N)
			cout<<ans<<endl;
		else
			printf("No\n");
	}
	return 0;
}
