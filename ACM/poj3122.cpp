#include<stdio.h>
#include<math.h>
const double pie = acos(-1.0);
int main()
{
	int T, N ,F, r;
	double s[10010];
	scanf("%d", &T);
	while(T--)
	{
		double maxs = -1, m;
		scanf("%d%d", &N, &F);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &r);
			s[i] = pie * r * r;
			maxs = maxs > s[i] ? maxs : s[i];		
		}
		double l = 0;
		while(maxs - l > 0.00001)
		{
			int sum = 0;
			m = (maxs + l) / 2;
			for(int j = 0; j < N; j++)
				sum += s[j] / m;
			if(sum >= F+1)
				l = m;
			else
				maxs = m;
		}
		printf("%.4f\n", m);
	
	}
	return 0;
}