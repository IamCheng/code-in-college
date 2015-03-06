#include<stdio.h>
int main()
{
	int T, i = 1;
	scanf("%d", &T);
	while(T--)
	{
		int n, tmp, s, flag = 0;
		scanf("%d", &n);
		scanf("%d", &s);
		for(int j = 1; j < n; j++)
		{
			scanf("%d", &tmp);
			if(tmp != s +1 && !flag)
				flag = j;
			s = tmp;
		}
		if(flag == 0)
			tmp = 1;
		else
			tmp = flag + 1;
		printf("Case #%d: %d\n", i++, tmp);;

	}
	return 0;
}