#include<stdio.h>
#define pi 3.14
void main()
{
	int n;
	float r;
	float V(float),S(float),C(float);
	printf("   Բ�ܳ���Բ�����������ļ���\n");
	printf("1,����Բ���ܳ�      2������Բ�����\n3,����������     4���˳�\n");
	printf("�������ʹ�ö�Ӧ���ܣ�\n");
	n=getchar();
    while(n<='3')
{  
	printf("����Բ�İ뾶:\n");
	scanf("%f",&r);
	if(n=='1') printf("Բ���ܳ�Ϊ��%f\n",C(r));
	if(n=='2') printf("Բ�����Ϊ��%f\n",S(r));
	if(n=='3') printf("������Ϊ��%f\n",V(r));
}
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