#include<stdio.h>
#include<algorithm>
#define max  1000010
using namespace std;
_int64 c[max], tot, m;
int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		_int64 tmp;
		int i;
		m = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%I64d", &tmp);
			m += tmp;
			c[i+1] = c[i] + tmp;
		}
		m = m / n;
		for(i = 1; i < n; i++)
			c[i] -= i * m;
		sort(c, c+n);
		_int64 ans = 0;
		for(i = 0; i < n; i++)
			ans += abs(c[n/2] - c[i]);
		printf("%I64d\n", ans);
	}
	return 0;
}