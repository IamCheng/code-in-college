#include<stdio.h>
#define pi 3.14
void main()
{
	int n;
	float r;
	float V(float),S(float),C(float);
	printf("   圆周长，圆面积，球体积的计算\n");
	printf("1,计算圆的周长      2，计算圆的面积\n3,计算球的体积     4，退出\n");
	printf("输入序号使用对应功能：\n");
	n=getchar();
    while(n<='3')
{  
	printf("输入圆的半径:\n");
	scanf("%f",&r);
	if(n=='1') printf("圆的周长为：%f\n",C(r));
	if(n=='2') printf("圆的面积为：%f\n",S(r));
	if(n=='3') printf("球的体积为：%f\n",V(r));
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