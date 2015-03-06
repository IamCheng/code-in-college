#include<stdio.h>
#include<math.h>
int main()
{
	int n, m;
	double pos, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		ans = 0.0;
		for(int i = 1; i < n; i++)
		{
			pos = (double)i / n * (n+m);
			ans += fabs(pos - floor(pos + 0.5)) / (n + m);
		}
		printf("%.4lf\n", ans*10000);
	}
	return 0;
}