#include<stdio.h>
int a[10];
void print(int a[],int s)
{
	int i;
	for(i=0;i<10;i++)
		printf("%d",a[i]);
	printf("\n");
	
}
int score(int s,int t)
{
	if(t<10)
	{
		a[t]=0;
		score(s-t-1,t+1);
		a[t]=1;
		score(s*2,t+1);
	}
	else
		if(s==100)
			print(a,s);
	return 1;
}
void main()
{
	int s=10,t=0;
	score(s,t);
}