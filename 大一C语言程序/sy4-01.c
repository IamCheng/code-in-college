#include<stdio.h>
void main()
{
    int max(int x,int y,int z);
	int a,b,c,d;
    printf("������������\n");
	scanf("%d %d %d",&a,&b,&c);
    d=max(a,b,c);
	printf("max=%d\n",d);
}
int max(int x,int y,int z)
{int t;
t=x>y?x:y;
t=t>z?t:z;
return(t);
}