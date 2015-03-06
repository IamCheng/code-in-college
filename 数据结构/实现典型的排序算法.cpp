#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50
int n;
int input(int arr[])//输入函数，用来输入数组的值
{
	int i;
	printf("输入元素的个数:\n");
	scanf("%d",&n);
	printf("请输入%d个元素:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	return 1;
}	
int arrcpy(int *d,int *r,int n)//数组拷备，第一个参数有目的数组，第二个参数为源数组
{
	int i=n;
	while(i-->0)
		d[i]=r[i];
	return 1;
}
int sort1(int arr[])//直接插入排序函数
{
	int tmp[MAX]={0},i,k,j,temp;//tmp为存放插入排序元素的数组
	for(i=0;i<n;i++)//对每个元素排行插入排序
	{
		temp=arr[i];
		/*找到插入的位置，并把所有元素向后移一位*/
		for(j=0;j<i;j++)
			if(temp<tmp[j])
			{
				for(k=i;k>j;k--)
					tmp[k]=tmp[k-1];
				break;
			}
		tmp[j]=temp;
		for(j=0;j<=i;j++)//输出每次插入的结果
			printf("%d ",tmp[j]);
		printf("\n");
	}
	return 1;
}
int sort2(int arr[])//选择排序函数
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(arr[min]>arr[j])
				min=j;
		if(i!=min)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
			for(j=0;j<n;j++)//输出数组每改变一次的结果
				printf("%d ",arr[j]);	
			printf("\n");
		}
	}
	return 1;
}
int sort3(int arr[],int l,int r)//递规的快速排序算法
{
	int tmp;
	if(l!=r)
	{
		if(arr[l]>arr[r])//如果左边的元素值>右边的元素值时，交换位置
		{
			tmp=arr[l];
			arr[l]=arr[r];
			arr[r]=tmp;
			/*输出每次数组改变后的结果*/
			for(tmp=0;tmp<n;tmp++)
				printf("%d ",arr[tmp]);
			printf("\n");
		}
		/*只要左边元素下标不等于右边元素下标，让l+1继续递规*/
		sort3(arr,l+1,r);
	}
	else 
		/*只要右边数组元素下标不等于0（即第一个元素）,则让r-1,l=0继续递规*/
		if(r!=0)
			sort3(arr,0,r-1);
	return 1;
}
void main()
{
	int choice,arr[MAX],s[MAX];
	clock_t start,end;
	double dtime;
	input(arr);//输入元素的值
	system("cls");//清屏
	while(1)
	{
		printf("    ------++++-------------++++-----------++++----------++++-------****---\n");
		printf("    1、直接插入排序  2、简单选择排序  3、快速排序  4、重输元素  5、退出\n");
		printf("    ------++++-------------++++-----------++++----------++++-------****---\n");
		scanf("%d",&choice);
		arrcpy(s,arr,n);//把arr复制给s，防止一次排序过后，原数组值的排序改变了。
		if(choice<=3&&choice>=1)printf("排序过程：\n");
		start=clock();//开始计算时间
		switch(choice)
		{
		case 1:sort1(s);break;
		case 2:sort2(s);break;
		case 3:if(n!=0)sort3(s,0,n-1);break;
		case 4:input(arr);break;
		case 5:exit(0);
		default:printf("您的输入有误，请重新输入!\n");
		}
		end=clock();//结束计算时间
		dtime=(double)(end-start)/CLOCKS_PER_SEC;
		if(choice<=3&&choice>=1)
			printf("所用时间为：%lfs.\n",dtime);
		system("pause");
		system("cls");
	}
}