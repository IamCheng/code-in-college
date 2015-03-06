#include<stdio.h>
void main()
{
int a,b,c,d,e,f;
printf("输入一个小于1000的数\n");
scanf("%d",&a);
if (a>1000) printf("error\n");
else {b=a/100;
e=a%100;
c=e/10;
f=e%10;
printf("%d %d %d\n",b,c,f);};
}