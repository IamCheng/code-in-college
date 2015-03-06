#include<stdio.h>
#include<math.h>
int main()
{
	double a,b;
	double k;
	while(scanf("%lf%lf",&a,&b)!=EOF)
	{
		k = pow(b,1/a);
		printf("%.0lf\n",k);
	}

	return 0;
}