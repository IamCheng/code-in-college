#include<stdio.h>
void main()
{
	int a[50][50],i,j,n,p,q,max;
	printf("����һ��������\n");
	scanf("%d",&n);
	printf("����%d������\n",n*n);
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	max=a[0][0];
    printf("%d*%d�ľ���Ϊ:\n",n,n);	
	
    for(i=0;i<n;i++)
	{   
		for(j=0;j<n;j++)
		printf("%3d",a[i][j]);
        printf("\n");
	}
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
		{	
			max=a[i][j]>=max?a[i][j]:max;
	       p=i+1;
		   q=j+1;
		}

    	printf("������Ϊ��%d\n",max);
		printf("λ�ڵ�%d�У���%d��\n",p,q);
}

	

