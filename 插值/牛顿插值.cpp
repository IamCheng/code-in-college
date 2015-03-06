#include<stdio.h>
double an[100], bn[100];
void cal_left(int n, double & l)
{
	if(n == 0)
		l = bn[0];
	else
	{
		l = 0;
		for(int i = 0; i <= n; i++)
		{
			double d = 1;
			for(int j = 0; j <= n; j++)
			{
				if(i != j)
				{
					d *= an[i] - an[j];
				}
			}		
			l += bn[i] / d;	
	//		printf("bn[%d]:%lf %lf\n", i, bn[i], d);
		}
	}
}
int main()
{
	int i, n;
	double num, ans = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%lf%lf", &an[i], &bn[i]);	
	scanf("%lf", &num);
	for(i = 0; i < n; i++)
	{
		double r = 1, l = 1;
		for(int j = 0; j < i; j++)
		{
			r *= (num - an[j]);
		}
		cal_left(i, l);
//		printf("l :%lf\n", l);
		ans += l * r;
	//	printf("ans : %lf\n", ans);
	}
	printf("%lf\n", ans);
	return 0;
}