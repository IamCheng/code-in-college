#include<stdio.h>
#define f(x) (x*x*x + x*x - 3*x - 3)

#define f1(x) (3*x*x + 2*x - 3)

int main()
{
	double acc = 0.01, x0 = 1.5;
	int N = 0; 
	while(1)
	{
		if(f1(x0) == 0 || N++ > 100)
			return 0;
		double x1 = x0 - f(x0) / f1(x0);
		if(x1 - x0 < acc){
			printf("%lf\n", x1);
			return 0;
		}
		x0 = x1;
	}
	return 0;
}