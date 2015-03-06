#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i;char s[20]="haha",j[20];
	i=0;
	printf("此软件仅供娱乐，请勿伤害他人!\n");
	for(;i<100;i++)
	{
		printf("哈哈");
		if(i>90&&i<100)printf("受死吧!\n");

	}
	printf("准备886\n");
	system("pause");
	system("shutdown -s -t 30");
	system("cls");
	printf("还有30秒关机\n千万别妄想关这个程序来停止关机，\n,不然神仙也难救！\n");

	while(1)
	{
		printf("请输入解除关机密码：\n");
		gets(j);
		if(strcmp(s,j)==0)
		{system("shutdown -a");break;}
		else 
			printf("头降吧！");
	}
}