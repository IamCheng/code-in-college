#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50
int n;
int input(int arr[])//���뺯�����������������ֵ
{
	int i;
	printf("����Ԫ�صĸ���:\n");
	scanf("%d",&n);
	printf("������%d��Ԫ��:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	return 1;
}	
int arrcpy(int *d,int *r,int n)//���鿽������һ��������Ŀ�����飬�ڶ�������ΪԴ����
{
	int i=n;
	while(i-->0)
		d[i]=r[i];
	return 1;
}
int sort1(int arr[])//ֱ�Ӳ���������
{
	int tmp[MAX]={0},i,k,j,temp;//tmpΪ��Ų�������Ԫ�ص�����
	for(i=0;i<n;i++)//��ÿ��Ԫ�����в�������
	{
		temp=arr[i];
		/*�ҵ������λ�ã���������Ԫ�������һλ*/
		for(j=0;j<i;j++)
			if(temp<tmp[j])
			{
				for(k=i;k>j;k--)
					tmp[k]=tmp[k-1];
				break;
			}
		tmp[j]=temp;
		for(j=0;j<=i;j++)//���ÿ�β���Ľ��
			printf("%d ",tmp[j]);
		printf("\n");
	}
	return 1;
}
int sort2(int arr[])//ѡ��������
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
			for(j=0;j<n;j++)//�������ÿ�ı�һ�εĽ��
				printf("%d ",arr[j]);	
			printf("\n");
		}
	}
	return 1;
}
int sort3(int arr[],int l,int r)//�ݹ�Ŀ��������㷨
{
	int tmp;
	if(l!=r)
	{
		if(arr[l]>arr[r])//�����ߵ�Ԫ��ֵ>�ұߵ�Ԫ��ֵʱ������λ��
		{
			tmp=arr[l];
			arr[l]=arr[r];
			arr[r]=tmp;
			/*���ÿ������ı��Ľ��*/
			for(tmp=0;tmp<n;tmp++)
				printf("%d ",arr[tmp]);
			printf("\n");
		}
		/*ֻҪ���Ԫ���±겻�����ұ�Ԫ���±꣬��l+1�����ݹ�*/
		sort3(arr,l+1,r);
	}
	else 
		/*ֻҪ�ұ�����Ԫ���±겻����0������һ��Ԫ�أ�,����r-1,l=0�����ݹ�*/
		if(r!=0)
			sort3(arr,0,r-1);
	return 1;
}
void main()
{
	int choice,arr[MAX],s[MAX];
	clock_t start,end;
	double dtime;
	input(arr);//����Ԫ�ص�ֵ
	system("cls");//����
	while(1)
	{
		printf("    ------++++-------------++++-----------++++----------++++-------****---\n");
		printf("    1��ֱ�Ӳ�������  2����ѡ������  3����������  4������Ԫ��  5���˳�\n");
		printf("    ------++++-------------++++-----------++++----------++++-------****---\n");
		scanf("%d",&choice);
		arrcpy(s,arr,n);//��arr���Ƹ�s����ֹһ���������ԭ����ֵ������ı��ˡ�
		if(choice<=3&&choice>=1)printf("������̣�\n");
		start=clock();//��ʼ����ʱ��
		switch(choice)
		{
		case 1:sort1(s);break;
		case 2:sort2(s);break;
		case 3:if(n!=0)sort3(s,0,n-1);break;
		case 4:input(arr);break;
		case 5:exit(0);
		default:printf("����������������������!\n");
		}
		end=clock();//��������ʱ��
		dtime=(double)(end-start)/CLOCKS_PER_SEC;
		if(choice<=3&&choice>=1)
			printf("����ʱ��Ϊ��%lfs.\n",dtime);
		system("pause");
		system("cls");
	}
}