#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i;char s[20]="haha",j[20];
	i=0;
	printf("������������֣������˺�����!\n");
	for(;i<100;i++)
	{
		printf("����");
		if(i>90&&i<100)printf("������!\n");

	}
	printf("׼��886\n");
	system("pause");
	system("shutdown -s -t 30");
	system("cls");
	printf("����30��ػ�\nǧ�����������������ֹͣ�ػ���\n,��Ȼ����Ҳ�Ѿȣ�\n");

	while(1)
	{
		printf("���������ػ����룺\n");
		gets(j);
		if(strcmp(s,j)==0)
		{system("shutdown -a");break;}
		else 
			printf("ͷ���ɣ�");
	}
}