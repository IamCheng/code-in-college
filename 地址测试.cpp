#include<stdio.h>
void main()
{
	int *p,**a,b;
	void swap(int **);
	b=5;
	p=&b;
	a=&p;
	printf("b�ĵ�ַ%d p��ֵ%d\n",&b,b);
	printf("p�ĵ�ַ��%d pָ�����ĵ�ַ��%d �����ֵ��%d\n",&p,p,*p);
	printf("a�ĵ�ַ%d aָ���ָ��ĵ�ַ��%d aָ���ָ���ָ�����ĵ�ַ��%d aָ���ָ���ָ������ֵ��%d\n",&a,a,*a,**a);
	swap(a);
	printf("\n\n%d\n",**a);
}
void swap(int i)
{
	int *b,a=9;
	b=&a;
	&i=a;
}
