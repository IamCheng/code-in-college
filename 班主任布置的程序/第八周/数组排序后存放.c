#include<stdio.h>
void main()
{
	int i,j,temp,a[20],n; 
	printf("��������ĸ�����\n");
	scanf("%d",&n);
	printf("�������֣�\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

    for(i=0;i<n-1;i++)
	{
        for(j=0;j<n-i;j++)
			if(a[j+1]>a[j])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
            
	}
    printf("���������飺\n");
	for(i=0;i<n;i++)
		printf("%2d",a[i]);
	printf("\n");


}	