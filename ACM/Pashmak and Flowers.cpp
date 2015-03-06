#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 200010;
int num[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	sort(num, num+n);
	__int64 tot = num[n-1]-num[0], ans = 0;
	printf("%d ", tot);	
	int ll = 0, rr = n - 1;
	while(num[ll] == num[0] && ll <= n-1)	ll++;
	while(num[rr] == num[n-1])	rr--;
	if(num[0] == num[n-1])
		ans = (__int64)(n-1) * n / 2;
	else
		ans = (__int64)ll * (n-1 - rr);;
	printf("%I64d\n", ans);
	return 0;
}