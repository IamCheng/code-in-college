#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
int Lsrch(int *s,int n)//顺序查找
{
	int i,p;
	LARGE_INTEGER start,end,freq;//计算时间的变量
	printf("输入要查询的元素:\n");
	scanf("%d",&p);
	/*开始计时*/
	QueryPerformanceFrequency(&freq);   
	QueryPerformanceCounter(&start); 
	for(i=0;i<n;i++)//遍历关键字，找到目标就停止
		if(s[i]==p)
		{
			QueryPerformanceCounter(&end); 
			printf("查找成功!\n结果为：%d\n所有时间为:%.10fs\n",s[i],(double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			return 1;
		}
        /*没有查找失败，才执行下面语句*/
		QueryPerformanceCounter(&end); 
		printf("查找失败！\n所有用时间为:%.10fs\n",(double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
	return 0;
}
int Hsrch(int *s,int n)//折半查找，n为元素个数
{
	int h=n-1,l=0,mid,p;//h为高位下标，l为低位下标，mid为中间下标
	LARGE_INTEGER start,end,freq;
	printf("输入要查找的元素:\n");
	scanf("%d",&p);
	/*开始计时*/
	QueryPerformanceFrequency(&freq);   
	QueryPerformanceCounter(&start); 
	if(p<=100000000)
	while(h>l)//折半查找
	{
		mid=(h+l)/2;
		if(s[h]==p||s[l]==p||s[mid]==p)
		{
			QueryPerformanceCounter(&end); 
			printf("查找成功！\n%d\n所用的时间为：%.10fs\n",p,(double)(end.QuadPart-start.QuadPart)/(double)freq.QuadPart);
			return 1;
		}
		else
		{
			if(s[mid]>p)
			{h=mid;l++;}
			else
			{l=mid;h--;}
			if(s[l]>p||s[h]<p)
				break;
		}
	}
	QueryPerformanceCounter(&end); 
	printf("查找失败!\n所用的时间为:%.10fs\n",(double)(end.QuadPart - start.QuadPart)/(double)freq.QuadPart);
	return 0;
}
void main()
{
	int *s,n,j;//文本提示
	printf("\t\t\t\t温馨提示!\n    本程序是为了测试顺序查找和折半查找的时间复杂度，所以内存已经存在0～1亿之间的所有偶数。用户按提示直接输入要查找的数字即可。\n");
	getch();system("cls");
	s=(int*)malloc(sizeof(int)*100000000);
	if(s==NULL)/*分配内存失败，则直接退出程序*/
		exit(0);
	for(n=0;n<=50000000;n++)//存储0～1亿之间的所有偶数
		s[n]=n*2;	
	/*菜单显示*/
	while(1)
	{
		printf(" **********功能表*********\n");
		printf("1、顺序查找  2、折半查找\n");
		scanf("%d",&j);
		if(j==1)
			Lsrch(s,n);
		else
		if(j==2)
			Hsrch(s,n);
		else
			printf("输入有误，请重新输入!\n");
	}
}

