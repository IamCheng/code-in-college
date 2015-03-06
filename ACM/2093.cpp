#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct person
{
	char name[12];
	int num;
	int score;
};
person p[10000];
char str[20][20];
int cmp(const person & a, const person & b)
{
	if(a.num == b.num)
	{
		if(a.score < b.score)
			return true;
	}
	return a.num > b.num;
}
int main()
{
//	char buf[] = "Josephus  72(3)	126	10	-3	0	47	21(2)	-2";
	int n, m, i, j, tot = 0;;
	scanf("%d%d", &n, &m);
	while(scanf("%s", str[0]) != EOF)
	{
		strcpy(p[tot].name, str[0]);
		for(j = 1; j <= n; j++)
			scanf("%s", str[j]);
		for(j = 1; j <= n; j++)
		{
			int a, b;
			int tmp = sscanf(str[j], "%d(%d)", &a, &b);
			if(a > 0)
			{
				p[tot].num++;
				p[tot].score += a;
				if(tmp == 2)
					p[tot].score += b * m;
			}
		}
		tot++;
	}
	sort(p, p + tot, cmp);
	for(i = 0; i < tot; i++)
		printf("%-10s %2d %4d\n", p[i].name, p[i].num, p[i].score);
	return 0;
}
