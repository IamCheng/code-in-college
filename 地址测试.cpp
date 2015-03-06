#include<stdio.h>
void main()
{
	int *p,**a,b;
	void swap(int **);
	b=5;
	p=&b;
	a=&p;
	printf("b的地址%d p的值%d\n",&b,b);
	printf("p的地址：%d p指向对象的地址：%d 对象的值：%d\n",&p,p,*p);
	printf("a的地址%d a指向的指针的地址：%d a指向的指针的指向对象的地址：%d a指向的指针的指向对象的值：%d\n",&a,a,*a,**a);
	swap(a);
	printf("\n\n%d\n",**a);
}
void swap(int i)
{
	int *b,a=9;
	b=&a;
	&i=a;
}
