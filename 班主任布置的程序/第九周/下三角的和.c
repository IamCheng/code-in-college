#include<stdio.h>
void main()
{
	int a,b,c=0,i,j,g[20][20];
	printf("���������к���:\n");
	scanf("%d%d",&a,&b);
	printf("����%d������\n",a*b);
    for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			scanf("%d",&g[i][j]);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			printf("%3d",g[i][j]);
		printf("\n");
	}
		printf("��������ǵĺͣ�\n");
		for(i=0;i<a;i++)
			for(j=0;j<=i;j++)
				c=c+g[i][j];
			printf("%d\n",c);
}