#include<stdio.h>
void main()
{
	int a;
	void t(int);
    printf("����һ��ʮ��������\n");
	scanf("%d",&a);
	t(a);
	printf("�˽��ƣ�%o\n",a);
	printf("ʮ�����ƣ�%x\n",a);
	
}
void t(int x)
{
	int a[16],b=0;
	for(;b<16;b++)
	{
        a[b]=x%2;
        x=x/2;

	}
	printf("�����ƣ�");
    for(b=15;b>=0;b--)
		printf("%d",a[b]);
	printf("\n");
}
