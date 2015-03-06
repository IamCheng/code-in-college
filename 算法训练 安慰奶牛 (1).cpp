#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
int vex_w[maxn], u[maxn], v[maxn], w[maxn], fa[maxn], ans;
int min_v = 1000000000;

int unionsearch(int x)
{
	return x == fa[x] ? x : fa[x] = unionsearch(fa[x]);
}
int cmp(const int & a, const int & b)
{
	return w[a] < w[b];
}
int kruskal(int n, int p)
{
	int i, r[maxn];
	for(i = 1; i <= n; i++)
		fa[i] = i;
	for(i = 0; i < p; i++)
		r[i] = i;
	sort(r, r+p, cmp);
	int tot = 0;
	for(i = 0; i < p; i++)
	{
		if(tot == n-1)
			break;
		int & j = r[i];
		int a = unionsearch(u[j]), b = unionsearch(v[j]);
		if(a != b)
		{
			fa[a] = b;
			ans += w[j];
			tot++;
		}
	}
	ans += min_v;
	printf("%d\n", ans);
	return 0;

}
int main()
{
	int N, P, i;
	scanf("%d%d", &N, &P);
	for(i = 1; i <= N; i++)
	{
		scanf("%d", &vex_w[i]);
		if(min_v > vex_w[i])
			min_v = vex_w[i];
	}
	for(i = 0; i < P; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		w[i] += w[i] + vex_w[u[i]] + vex_w[v[i]];
	}
	kruskal(N, P);
	return 0;

}
