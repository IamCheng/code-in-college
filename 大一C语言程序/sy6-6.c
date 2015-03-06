#include<stdio.h>
void main()
{
    char string[50];
	int a=0,b=0,f=0,d=0,e=0,i;
    char c;   
	printf("输入一行字符：\n");
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
	printf("大写字母:%d个\n小写字母:%d个\n数字:%d个\n空格:%d个\n其它:%d个\n",a,b,f,d,e);
}