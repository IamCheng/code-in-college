#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct P
{
	double x, y;
}p[maxn];
P mid[maxn];
bool cmp(P a, P b)
{
	return a.x < b.x;
}
bool cmp_y(P a, P b)
{
	return a.y < b.y;
}
double dis(P a, P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Min(double a, double b)
{
	return a > b ? b : a;
}
double min_radius(int l, int r)
{
	if(r - l == 1)
		return dis(p[l], p[r]);
	if(r - l == 2)
	{
		return	Min(Min(dis(p[l], p[l+1]), dis(p[r], p[l])), dis(p[r], p[l+1]));; 
	}
	int m = l + ((r - l) >> 1);
	double min = Min(min_radius(l, m), min_radius(m+1, r));
	int tmp = m - 1, t = 0;
	while(tmp >= l && p[m].x - p[tmp].x < min)	mid[t++] = p[tmp--];
	tmp = m;
	while(tmp < r && p[tmp].x - p[m].x < min)	mid[t++] = p[tmp++];
	sort(mid, mid+t, cmp_y);
	for(int i = 0; i < t; i++)
	{
		for(int j = i + 1; mid[j].y - mid[i].y < min && j < t; j++)
		{
			double tmp = dis(mid[i], mid[j]);
			min = Min(min, tmp);
		}
	}
	return min;
	
}
int main()
{
	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		sort(p, p+n, cmp);
		printf("%.2lf\n", min_radius(0, n-1)/2);
	}	
	return 0;
}
