#define pi 3.14
#include<stdio.h>
#include<math.h>
void main()
{
float l,r,h,s,v,p;
printf("�������Բ�İ뾶�͸�:\n");
scanf("%f%f",&r,&h);
l=sqrt(r*r+h*h);
s=p*r*r+p*r*l;
v=p*r*r*h/3;
printf("%f\n%f\n",s,v);
}