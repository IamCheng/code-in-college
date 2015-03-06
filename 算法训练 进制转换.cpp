#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
int tran(vector <int> &a, int n)
{
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] >= 0)	continue;
		int adc = 1;
		a[i] = abs(n) - abs(a[i]);
		for(int j = i + 1; j < a.size(); j++)
		{
			int tmp = (a[j] + adc) % n;
			adc = (a[j] + adc) / n;
			a[j] = tmp;		
		}
		if(adc != 0)
			a.insert(a.end(), adc);
	}
	return 0;
}
int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	printf("%d=", n);
	vector <int> a;
	while(abs(n/r) > 0)
	{
		a.push_back(n % r);
		n = n / r;
	}
	a.push_back(n%r);
	tran(a, r);
	for(int i = a.size() - 1; i >= 0; i--)
	{
		if(a[i] >= 10)
			printf("%c", 'A'+a[i]-10);
		else
			printf("%d", a[i]);
	}
	printf("(base%d)", r);
	return 0;
}