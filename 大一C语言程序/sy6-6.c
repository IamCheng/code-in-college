#include<stdio.h>
void main()
{
    char string[50];
	int a=0,b=0,f=0,d=0,e=0,i;
    char c;   
	printf("����һ���ַ���\n");
    gets(string);
	for(i=0;(c=string[i])!='\0';i++)
	{ if (c>='A'&&c<='Z')
		a++;
	  else if (c>='a'&&c<='z')
		b++;
	  else if (c>='0'&&c<='9')
		f++;
	  else if (c==' ')
		d++;
	  else 
		 e++;
	}
	printf("��д��ĸ:%d��\nСд��ĸ:%d��\n����:%d��\n�ո�:%d��\n����:%d��\n",a,b,f,d,e);
}