#include<stdio.h>
#include<string.h>
int C[130];
int main()
{
	int T, t;
	char march[1005];
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		int N;
		memset(C, 0, sizeof(C));
		scanf("%d", &N);
	    scanf("%s", march);	
		for(int i = 0; i < N; i++)
			C[march[i]]++;
        if(C['A'] == N){
			printf("Case %d: ABANDONED\n", t);
			continue;
		}
		if(C['B'] + C['A'] == N){
			printf("Case %d: BANGLAWASH\n", t);
			continue;
		}
		if(C['W'] + C['A'] == N){
			printf("Case %d: WHITEWASH\n", t);
			continue;
		}
	
		if(C['B'] > C['W']){
			printf("Case %d: BANGLADESH %d - %d\n", t, C['B'], C['W']);
			continue;			
		}
		else
			if(C['B'] < C['W']){
				printf("Case %d: WWW %d - %d\n", t, C['W'], C['B']);
				continue;
			}
			else
				printf("Case %d: DRAW %d %d\n", t, C['W'], C['B']);
	}
	return 0;
}
