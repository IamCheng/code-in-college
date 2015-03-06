#include<stdio.h>
#define f(x) (x*x*x-x-1)
int main()
{
	double x1 = 1.0, x2 = 1.5; 
	double y1 = f(x1), y2 = f(x2);
	double acc = 0.01;
	if(y1 * y2 > 0)
	{
		printf("нч╫Б\n");
		return 0;
	}
	while(x2 - x1 > acc)
	{
		double m = (x1 + x2) / 2;
		double f = f(m);
		if(y1 * f < 0)
		{
			x2 = m;
			y2 = f;
		}
		else
		{
			x1 = m;
			y1 = f;
		}
	}
	printf("%.2lf\n", x1);
	return 0;
}