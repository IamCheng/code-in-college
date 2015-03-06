#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int sum=0;
void compress(int code)
{
	int tmp;
	if(code>0)
	{
		sum+=code%10;
		compress(code/10);
	}
	if(sum>=10)
	{
		tmp=sum;
		sum=0;
		compress(tmp);
	}
}
void Dncode(char a[][7],int r,int last,int *code)
{
	int i,j;
	for(i=0;i<6;i++)
	{
		sum=0;
		for(j=0;j<=r;j++)
		{
		    if(last<=0)
				for(j=0;j<r;j++)
					code[i]+=a[j][i];
			else
				code[i]+=a[j][i];
		}
		last--;
		compress(code[i]);
		code[i]=sum;
		printf("%d",code[i]);
	}
	printf("\n");
	
}
void main()
{
	char s[MAX][100],a[MAX][7];
	int k,n,tmp=0;
	scanf("%d",&n);
	for(k=0;k<n;k++)
		scanf("%s",s[k]);
	for(k=0;k<n;k++)
	{
		int i=0,j=0,code[6]={0};
		while(s[k][i]!='\0')
		{
			a[j][i%6]=s[k][i];
			if((++i)%6==0)
			{
				a[j][6]='\0';
				j++;
			}
		}
		a[j][i%6]='\0';
		Dncode(a,j,i%6,code);
	
	}

}