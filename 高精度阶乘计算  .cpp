#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
int tot[10100];
int main()
{
	int n;
	scanf("%d", &n);
	tot[10099] = 1;
	int l = 10099;
	for(int i = 2; i <= n; i++)
	{
		int r = 10099, adc = 0;
		while(l <= r)
		{
			tot[r] = tot[r] * i + adc;
			adc = tot[r] / 10000;
			tot[r] = tot[r] % 10000;
			r--;
		}
		if(adc > 0)
			tot[--l] = adc;
		
	}
	printf("%d", tot[l]);
	for(int j = l + 1; j < 10100; j++)
		cout << setw(4) << setfill('0') << tot[j]; 
	printf("\n");
	return 0;
}