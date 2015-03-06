#include<stdio.h>
#include<algorithm>
using namespace std;
#define max(a, b) (a > b ? a : b)
struct Person
{
	int s, p, f;
}p[20100];
int cmp(Person a, Person b)
{
	return a.s == b.s ? ( a.f < b.f) : a.s < b.s;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, h, m, i, tmp;
		scanf("%d", &n);
		for(i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			scanf("%d:%d", &h, &m);
			p[i<<1].s = h * 60 + m;
			p[i<<1].f = 1;
			scanf("%d:%d", &h, &m);
			p[(i<<1)+1].s = h * 60 + m;		
			p[(i<<1)+1].f = -1;
			p[i<<1].p = p[(i<<1)+1].p = tmp;
		}
		sort(p, p+2*n, cmp);
		int sum = 0, ans = -1;
		for(i = 0; i < n << 1; i++)
		{
			if(p[i].f > 0)
			{
				sum += p[i].p;
				ans = max(ans, sum);
			}
			else
				sum -= p[i].p;
		}
		printf("%d\n", ans);
	}
	return 0;
}