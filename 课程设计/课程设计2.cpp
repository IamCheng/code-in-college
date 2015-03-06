#include<stdio.h>
//10个数选择法降序
void sort(int a[10])
{
	int i,j,max,temp;
	for(i=0;i<9;i++)
	{
		max=i;
		for(j=i+1;j<10;j++)
			if(a[j]>a[max])
				max=j;
		if(i!=max)
		{
			temp=a[i];
			a[i]=a[max];
			a[max]=temp;
		}
	}

}
//n个数的选择降序
void sort(int a[],int n)
{
	int i,j,max,temp;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
			if(a[j]>a[max])
				max=j;
		if(i!=max)
		{
			temp=a[i];
			a[i]=a[max];
			a[max]=temp;
		}
	}
}
//可以选择升降序的函数
void sort(int a[],int n,char b)
{
	int i,j,max,temp;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(b=='d')
			{
				if(a[j]>a[max])
						max=j;
			}
			if(b=='a')
			{
				if(a[j]<a[max])
				max=j;
			}
			if(i!=max)
			{
				temp=a[i];
				a[i]=a[max];
				a[max]=temp;
			}
		}
	}
}
int *Sort1(int a[],int n)
{
	int i,j,temp;
	for(j=0;j<n;j++)  
		for(i=0;i<n-1-j;i++)
			if(a[i]<a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
	return(a);

}

int *Sort2(int a[],int n)
{
	int i,j,temp;
	for(j=0;j<n;j++)  
		for(i=0;i<n-1-j;i++)
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
	return(a);

}
int *Sort3(int a[],int n)
{
	int i,j,max,temp;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
			if(a[j]>a[max])
				max=j;
		if(i!=max)
		{
			temp=a[i];
			a[i]=a[max];
			a[max]=temp;
		}
	}
	return a;

}
int *Sort4(int a[],int n)
{
	int i,j,max,temp;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[max])
				max=j;
		if(i!=max)
		{
			temp=a[i];
			a[i]=a[max];
			a[max]=temp;
		}
	}
	return a;


}

void show(int* (*fun)(int a[], int n ), int* a, int n)
{
	int* b=fun(a, n);
	int i;
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n");
}

void main()
{
	int a[10],i,n;char c;
	//10个数排序
	printf("输入10整数:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("调用sort(a)\n");
	sort(a);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n改进sort()\n输入一个你想要的数:\n");
	scanf("%d",&n);
	printf("请输入%d个数：\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("调用sort()改进后的sort(a,n)函数:\n");
	sort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n改进sort(a,n)函数为sort(a,n,c)\n输入排序方式\na为升序，d为降序\n");
	c=getchar();
	c=getchar();
	sort(a,n,c);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n选择排序方法（直接调用输出函数）：\n1、冒泡降序  2、冒泡升序\n3、选择降序  4、选择升序\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:show(Sort1,a,n);break;
	case 2:show(Sort2,a,n);break;
	case 3:show(Sort3,a,n);break;
	case 4:show(Sort4,a,n);break;
	}


}