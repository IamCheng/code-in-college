#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int num[60], n;
bool deal(double M)
{
	double crt = -1e12;
	for(int i = 1; i < n - 1; i++)
	{
		if(fabs(num[i]-num[i-1]-M) < 1e-4)
		{
			continue;
		}
		if(num[i] - num[i-1] > M)
		{					
			if(crt < num[i] - M || (fabs(crt-num[i]+M) < 1e-4))
			{
				crt = num[i] - M;
				continue;
			}						
		}
		if(num[i+1] - num[i] > M || (fabs(num[i+1]-num[i]-M) < 1e-4))
		{
			crt = num[i] + M;
			continue;
		}
		return false;
		break;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int i;
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d", &num[i]);
		sort(num, num+n);
		double L = 0, R = 2e9;
		while(L < R && fabs(L-R) > 1e-4)
		{
			double M = L + (R - L) / 2;			
			if(deal(M)) L = M;	else R = M;
		}
		for(i = 1; i < n; i++)
		{
			if(L < num[i] - num[i-1])
			{
				if(deal(num[i]-num[i-1]))
					L = num[i]-num[i-1];
			}
		}
		printf("%.3lf\n", L);
	}
	return 0;
}
