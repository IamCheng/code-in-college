#include<stdio.h>
#include<algorithm>
using namespace std;
int num[1010], ds[1010];
int copy(int l, int r)
{
	int t = 0;
	for(int i = l; i <= r; i++)
		ds[t++] = num[i];
	return 0;
}
int main()
{
	int n, m, l, r, k, i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &m);
	for(j = 1; j <= m; j++)
	{
		scanf("%d%d%d", &l, &r, &k);
		copy(l, r);
		sort(ds, ds+(r-l+1));
		printf("%d\n", ds[r-l-k+1]);

	}
	return 0;

}