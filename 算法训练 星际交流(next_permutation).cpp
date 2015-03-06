#include<stdio.h>
#include<algorithm>
using namespace std;
int num[10010];
int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	int t = 0;
	if(m == 0)
	{
		for(int i = 0; i < n; i++)
				printf("%d ", num[i]);
		return 0;
	}
	while(next_permutation(num, num+n))
	{
		if(++t == m)
		{
			for(int i = 0; i < n; i++)
				printf("%d ", num[i]);
			return 0;
		}

	}

	return 0;

}