#include<stdio.h>
#include<algorithm>
using namespace std;
int ans = 0, n, num_n, num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int srch()
{
	int  i, j, k;
	for(i = 0; i < num_n; i++)
	{
		int L = 0, nn = n;
		for(j = 0; j <= i; j++)
			L = L * 10 + num[j];
		nn -= L;
		if(nn <= 0)	continue;
		for(j =  (i + 8) / 2; j < 8; j++)
		{
			int up = 0, down = 0;
			for(k = i + 1; k <= 8; k++)
			{
				if(k <= j)
					up = up * 10 + num[k];
				else
					down = down * 10 + num[k];				
			}
			if(up % down == 0 && up / down == nn)
				ans++;
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	int tmp = n;
	while(tmp != 0)
	{
		tmp /= 10;
		num_n++;
	}
	do
	{
		srch();
	}while(next_permutation(num, num+9));
	printf("%d\n", ans);
	return 0; 
}