#include<stdio.h>
#define pi 3.14
void main()
{

	float r;
	float V(float),S(float),C(float);
	printf("����Բ�İ뾶:\n");
	scanf("%f",&r);
	printf("Բ���ܳ�Ϊ��%f\n",C(r));
    printf("Բ�����Ϊ��%f\n",S(r));
    printf("������Ϊ��%f\n",V(r));
	
}
float C(float x)
{
	return(2*pi*x);
}
float S(float y)
{
	return(pi*y*y);
}
float V(float z)
{
	return(4*pi*z*z*z/3);
}