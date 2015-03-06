#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) a*x*x*x+b*x*x+c*x+d
double a, b, c, d;
int solve(double l, double r)
{
    while(fabs(r - l) > 1e-3)
    {
        double m = l + (r - l) / 2;
        if(f(m) >= 0)
            r = m;
        else
            l = m;
    }
    printf("%.2lf ", l);
    return 0;
}
int main()
{
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	double x1 = (-2 * b - sqrt(4 * b * b - 12 * a * c)) / (6 * a);
	double x2 = (-2 * b + sqrt(4 * b * b - 12 * a * c)) / (6 * a);
	double l = -100, r = x1;
	if(f(-100) > 0)
	{
		solve(x1, -100);
		solve(x1, x2);
		solve(100, x2);
	}
	else
	{
		solve(-100, x1);
		solve(x2, x1);
		solve(x2, 100);
	}
	return 0;
}