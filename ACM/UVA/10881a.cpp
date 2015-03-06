#include<stdio.h>
#include<stdlib.h>
#define max 10000
typedef struct
{
	int num;
	int id;
	char dr;
	int flag;
}ant;
ant a[max], b[max];
const char p[][12] = {"%d %c\n", "%d Turning\n", "Fell off\n"};
int L,t,n;
int cmp(const void * a, const void * b)
{
	if(((ant *)a)->num > ((ant *)b)->num)
		return 1;
	else
		return 0;
}
int cmpid(const void * a, const void * b)
{
	if(((ant *)a)->id > ((ant *)b)->id)
		return 1;
	else
		return 0;
}
int main()
{
	int T,i;
	scanf("%d", &T);
	int m = T;
	while(T--)
	{
		scanf("%d%d%d", &L, &t, &n);
		for(i = 0; i < n; i++)
		{
			scanf("%d %c", &a[i].num, &a[i].dr);
			a[i].id = i;
			b[i].num = a[i].num;
			a[i].dr == 'R'?	b[i].num += t:b[i].num -= t;
			b[i].dr = a[i].dr;
		}
		qsort(b, n, sizeof(ant), cmp);
		qsort(a, n, sizeof(ant), cmp);
		for(i = 0; i < n; i++)
			b[i].flag = (b[i].num == b[i+1].num) ? (b[i++].flag = 1):(b[i].num < 0 || b[i].num > L) ? 2 : 0;
		for(i = 0; i < n; i++)
			b[i].id = a[i].id;
		qsort(b, n, sizeof(ant), cmpid);
		printf("Case #%d:\n", m-T);
		for(i = 0; i < n; i++)
			printf(p[b[i].flag], b[b[i].id].num, b[i].dr);
		printf("\n");
	}

	return 0;
}