#include<stdio.h>
#include<iostream>
#include<cctype>
using namespace std;
const int maxn = 100010;
int score[maxn];
inline int readint()
{
	char c=getchar();
	bool flag=1;
	while(!isdigit(c)) {if(c=='-') flag=0;c=getchar();}
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	if(!flag) x*=-1;
	return x;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			score[i] = readint();
		int ans = -999999999, m = score[0];		
		for(int j = 1; j < n; j++)
		{
			ans = max(ans, m - score[j]);
			m = max(m, score[j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
