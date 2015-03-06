#include<stdio.h>
struct point
{
	double x, y;
};
int deal(point & a, point & b)
{
	if(a.x < b.x && a.y < b.y)
		return 0;
	if(a.x > b.x && a.y > b.y)
	{
		point t = a;
		a = b;
		b = t;
		return 0;
	}
	if(a.x > b.x)
	{
			double t = a.x;
		a.x = b.x;
		b.x = t;
	}
	else
	{
		double t = a.y;
		a.y = b.y;
		b.y = t;
	}
	return 0;
}
int main()
{
	point r1, r2, r3, r4;
	scanf("%lf%lf%lf%lf", &r1.x, &r1.y, &r2.x, &r2.y);
	scanf("%lf%lf%lf%lf", &r3.x, &r3.y, &r4.x, &r4.y);
	deal(r1, r2);
	deal(r3, r4);
	point a, b;
	a.x = r1.x > r3.x ? r1.x : r3.x;
	b.x = r2.x < r4.x ? r2.x : r4.x;
	a.y = r1.y > r3.y ? r1.y : r3.y;
	b.y = r2.y < r4.y ? r2.y : r4.y;
	if(a.x > b.x || a.y > b.y)
		printf("0.00\n");
	else
		printf("%.2lf\n", (a.x-b.x)*(a.y-b.y));
	return 0;

}