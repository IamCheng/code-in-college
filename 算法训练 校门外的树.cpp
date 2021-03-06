#include<stdio.h>
#include<algorithm>
using namespace std;
struct Area
{
	int l, r;
};
Area a[101];
bool cmp(Area a, Area b)
{
	return a.l < b.l;
}
int main()
{
	int L, m, i;
	scanf("%d%d", &L, &m);
	for(i = 0; i < m; i++)
		scanf("%d%d", &a[i].l, &a[i].r);
	sort(a, a+m, cmp);
	int tot = 0, crt = -1;
	for(i = 0; i < m; i++)
	{
		if(a[i].l > crt)
		{
			crt = a[i].l;
			tot++;
		}
		if(crt < a[i].r)
		{
			tot += a[i].r - crt;
			crt = a[i].r;
		}
	}
	printf("%d\n", L-tot+1);
	return 0;
}