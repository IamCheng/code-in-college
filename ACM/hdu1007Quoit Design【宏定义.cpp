#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
const double inf = 100000000000000000;
const int maxn = 100010;
#define dis(a, b) sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
#define Min(a, b) (a > b ? b : a)
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
double min_radius(int l, int r)
{
	if(r - l == 1)
		return inf;	
	int m = l + (r - l) / 2;
	double ll = min_radius(l, m);//±ØÐë·Ö¿ªÐ´
	double rr = min_radius(m, r);
	double min = Min(rr, ll);
	int tmp = m - 1, t = 0;
	while(tmp >= l && p[m].x - p[tmp].x < min)	mid[t++] = p[tmp--];
	tmp = m;
	while(tmp < r && p[tmp].x - p[m].x < min)	mid[t++] = p[tmp++];
	sort(mid, mid+t, cmp_y);
	for(int i = 0; i < t; i++)
	{
		for(int j = i + 1; j < t && mid[j].y - mid[i].y < min; j++)
		{
			double tmp = dis(mid[i], mid[j]);
			min = Min(tmp, min);
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
		printf("%.2lf\n", min_radius(0, n)/2);
	}
	return 0;
}
