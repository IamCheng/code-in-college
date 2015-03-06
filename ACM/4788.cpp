#include<stdio.h>
int main()
{
	int T, i, j = 1;
	scanf("%d", &T);
	char ch[4], m[] = {'B', 'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y'};
	double ans[9] = {1, 0.9765625, 0.953674, 0.931323, 0.909495, 0.888178, 0.867362, 0.847033, 0.827181};
	while(T--)
	{
		int tmp;
		scanf("%d[%s", &tmp, ch);
		for(i = 0; m[i] != ch[0]; i++);
		printf("Case #%d: %.2lf%%\n", j++, (1-ans[i])*100); 
	}
	return 0;
}