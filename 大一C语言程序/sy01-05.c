#include<stdio.h>
void main()
{
int max(int x,int y,int z);
int a,b,c,d;
printf("input a b c\n");
scanf("%d,%d,%d",&a,&b,&c);
d=max(a,b,c);
printf("max=%d\n",d);
}
int max(int x,int y,int z)
{int T;
T=x>y?x:y;
T=z>T?z:T;
return(T);
}
