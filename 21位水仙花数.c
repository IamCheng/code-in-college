#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>
typedef struct sa
{
	int arr[10][21];
	int arr2[10];
}save,*saveptr;
int result(int i,saveptr s)
{
	int j=0,k;
	for(k=0;k<21;k++)
		(*s).arr[i][k]=0;
	(*s).arr[i][20]=i;
	for(j=0;j<20;j++)
	{
		for(k=0;k<21;k++)
			(*s).arr[i][k]=(*s).arr[i][k]*i;
		for(k=20;k>0;k--)
		{
			(*s).arr[i][k-1]=(*s).arr[i][k-1]+(*s).arr[i][k]/10;
			(*s).arr[i][k]=(*s).arr[i][k]%10;
		}
	}
	return 1;
}
int arrc(int i,int arr[21],int arr2[21])
{
	int k;
	for(k=20;k>=0;k--)
	{
		arr2[k]=arr[k]*i;
	}
	for(k=20;k>0;k--)
	{
		arr2[k-1]+=arr2[k]/10;
		arr2[k]=arr2[k]%10;
	}
	return 1;
}
int Put(save s)
{
	int i,k,tmp[10][21],b[10]={0},r[21]={0};
	for(i=1;i<=9;i++)
		arrc(s.arr2[i],s.arr[i],tmp[i]);
	for(i=9;i>0;i--)
	{
		for(k=20;k>=0;k--)
			r[k]=r[k]+tmp[i][k];
		for(k=20;k>0;k--)
		{
			r[k-1]+=r[k]/10;
			r[k]=r[k]%10;
		}
	}
	for(i=0;i<21;i++)
		b[r[i]]++;
	for(i=9;i>0;i--)
	{
		if(b[i]!=s.arr2[i])
			return 0;
	}
	for(i=0;i<21;i++)
		printf("%d",r[i]);
	printf("\n");
	return 1;
}
void main()
{

	int i,i1,i2,i3,i4,i5,i6,i7,i8,i9;
	clock_t start,end;
	double time;
	save s;
	printf("21位水仙数为:\n");
	start=clock();
	for(i=0;i<=9;i++)
		result(i,&s);
	for(i9=1;i9<=9;i9++){s.arr2[9]=i9;
	for(i8=0;i8<=21-i9;i8++){s.arr2[8]=i8;
	for(i7=0;i7<=21-i9-i8;i7++){s.arr2[7]=i7;
	for(i6=0;i6<=21-i9-i8-i7;i6++){s.arr2[6]=i6;
	for(i5=0;i5<=21-i9-i8-i7-i6;i5++){s.arr2[5]=i5;
	for(i4=0;i4<=21-i9-i8-i7-i6-i5;i4++){s.arr2[4]=i4;
	for(i3=0;i3<=21-i9-i8-i7-i6-i5-i4;i3++){s.arr2[3]=i3;
    for(i2=0;i2<=21-i9-i8-i7-i6-i5-i4-i3;i2++){s.arr2[2]=i2;
	for(i1=0;i1<=21-i9-i8-i7-i6-i5-i4-i3-i2;i1++)
	{
		s.arr2[1]=i1;
		Put(s);	
	}}}}}}}}}
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("所有的时间为：%f\n",time);
}
