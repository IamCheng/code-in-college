#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int arr,exc;
}job;
int cmp(const void *a, const void *b)
{
	if(((job*)a)->exc < ((job *)b)->exc)
		return 1;
	else 
		return 0;
}
int cal(job task[], int N)
{
	int i, m = 0, tmp = 0;
	for(i = 0; i < N; i++)
	{
		m += task[i].arr;
		if(m + task[i].exc > tmp)
			tmp = m + task[i].exc;		
	}
	return tmp;
}
int main()
{
	int N, num = 0;
	job task[10000];
	while( scanf("%d", &N) == 1 && N != 0)
	{
		num++;
		int i;
		for(i = 0; i < N; i++)
			scanf("%d%d", &task[i].arr, &task[i].exc);
		for(i = 0; i<9;i++)break;
		qsort(task, N, sizeof(job), cmp);
		printf("Case %d: %d\n", num, cal(task, N));

	}
	return 0;
}