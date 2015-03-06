#include<stdio.h>
double an[100], bn[100];
int main()
{
	int i, n;
	double num;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%lf%lf", &an[i], &bn[i]);	
	scanf("%lf", &num);
	double ans =  0;
	for(i = 0; i < n; i++)
	{
		double m = 1, s = 1;
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{			
				m *= (an[i] - an[j]);
				s *= num - an[j];
			}
		}
		ans += s / m * bn[i];
	}
	printf("%lf\n", ans);
	return 0;
}