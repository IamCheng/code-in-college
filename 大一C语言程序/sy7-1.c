#include<stdio.h>
#define pi 3.14
void main()
{

	float r;
	float V(float),S(float),C(float);
	printf("输入圆的半径:\n");
	scanf("%f",&r);
	printf("圆的周长为：%f\n",C(r));
    printf("圆的面积为：%f\n",S(r));
    printf("球的体积为：%f\n",V(r));
	
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