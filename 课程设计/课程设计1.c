#include<stdio.h>
void main()
{
	int i,j,a[11],max,temp,k;
	printf("����10��ѧ���ĳɼ���	\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	//ѡ�������
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
	printf("�����Ľ��\n");
	for(k=0;k<10;k++)
		printf("%d ",a[k]);
	printf("\n����һ���ɼ�:\n");
	scanf("%d",&temp);
	//���������
	j=0;
	for(i=0;i<10;i++)
		if(a[i]<=temp)
		break;
		if(i==9) a[10]=temp;
		else
		{
			for(k=10;k>i;k--)
				a[k]=a[k-1];
			a[i]=temp;
		}
	//��������
	for(k=0;k<6;k++)
	{
		temp=a[k];
		a[k]=a[10-k];
		a[10-k]=temp;
	}
	printf("���������Ľ��\n");
	for(k=0;k<11;k++)
		printf("%d ",a[k]);
	printf("\n");
	
		
}

