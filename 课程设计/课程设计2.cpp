#include<stdio.h>
//10����ѡ�񷨽���
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
//n������ѡ����
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
//����ѡ��������ĺ���
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
	//10��������
	printf("����10����:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("����sort(a)\n");
	sort(a);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n�Ľ�sort()\n����һ������Ҫ����:\n");
	scanf("%d",&n);
	printf("������%d������\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("����sort()�Ľ����sort(a,n)����:\n");
	sort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n�Ľ�sort(a,n)����Ϊsort(a,n,c)\n��������ʽ\naΪ����dΪ����\n");
	c=getchar();
	c=getchar();
	sort(a,n,c);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nѡ�����򷽷���ֱ�ӵ��������������\n1��ð�ݽ���  2��ð������\n3��ѡ����  4��ѡ������\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:show(Sort1,a,n);break;
	case 2:show(Sort2,a,n);break;
	case 3:show(Sort3,a,n);break;
	case 4:show(Sort4,a,n);break;
	}


}