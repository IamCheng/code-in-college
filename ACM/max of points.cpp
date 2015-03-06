#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define lenth(a, b) ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
const int maxn = 100;
struct P
{
	double x, y;
};
P p[maxn], crd[maxn*2];
double N, r, sqrR;

int intsctn(double x1, double y1, double x2, double y2, double r, P & C, P & D)
{
	double X0 = (x1 + x2) / 2;
	double Y0 = (y1 + y2) / 2;
	double L = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	if(y1 == y2)
	{
		C.x = D.x = X0;
		D.y = y1 + sqrt(r * r - L / 4);	
		C.y = y1 - sqrt(r * r - L / 4);	
		return 0;
	}
	double k1 = (y1 - y2) / (x1 - x2);
	double K2 = - (x1 - x2) / (y1 - y2);
	double dx = sqrt((r * r - L / 4) / (1 + K2 * K2));
	C.x = X0 - dx;
	C.y = Y0 + K2 * (C.x - X0);
	D.x = X0 + dx; 
	D.y = Y0 + K2 * (D.x - X0);
	return 0;
}

int cmp(P a, P b)
{
	if(fabs(a.x-b.x) < 0.000001)
		return (b.y != 1);
	return (a.x < b.x);		
}

double tran(P C, P t)
{
	if(C.x > t.x)
	{
		if(C.y > t.y)
			return (r - fabs(C.x - t.x) + r);
		else
			return fabs(C.x - t.x);
	}
	else
	{
		if(C.y > t.y)
			return  fabs(C.x - t.x) + 2 * r;
		else
			return 	r - fabs(C.x - t.x) +3 * r;			
	}
}
int work(int n)
{
	int i, cc = 0;
	P t = p[n];
	for(i=0; i < N; i++)
	{
		if(i == n ||t.x - p[i].x > 2 * r || t.y - p[i].y > 2 * r || lenth(t, p[i]) > sqrR)
			continue;
		else
		{
			P C, D;
			intsctn(t.x, t.y, p[i].x, p[i].y, r, C, D);
			crd[cc++].x = tran(C, t);		
			crd[cc++].x = tran(D, t);
			double tmp = crd[cc-2].x - crd[cc-1].x;
			if (fabs(tmp) > 2 * r)
			{
				if(tmp > 0)
					crd[cc-2].x = C.x - t.x;
				else
					crd[cc-1].x = D.x - t.x;
			}
			if(crd[cc-1].x < crd[cc-2].x )
			{				
				crd[cc-1].y = 1;
				crd[cc-2].y = -1;
			}
			else
			{
				crd[cc-1].y = -1;
				crd[cc-2].y = 1;
			}
		}		
	}
	sort(crd, crd+cc, cmp);
	int	max = -1;
	bool flag = false;
	for(int j=0; j < cc; j++)
	{
		int num = 0;
		if(crd[j].y == -1 || (flag && crd[j-1].y == 1))
			continue;
		flag = true;
		for(i=j;i < cc+j; i++)
			if(crd[i%cc].y == 1)
			{
				num++;
				if(num > max)
					max = num;
			}
			else
				num--;		
	}
	return max;
}	
int main()
{
	int i, T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf%lf", &r, &N);
		sqrR = r * r * 4;
		for(i=0; i < N; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		int ans = 0;
		for(i=0; i < N; i++)
		{
			int tot = work(i);
			if(ans < tot)
				ans = tot;
		}
		if(N == 0)
			printf("0\n");
		else
			printf("%d\n", ans+1);
	}
	return 0;
}