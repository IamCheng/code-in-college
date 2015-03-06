#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;int j=0;
	char str[1000];
	fp=fopen("英语.txt","r+");
	fgets(str,1000,fp);
	printf("修改前：%s \n",str);
    fclose(fp);
	fp=fopen("英语2.txt","w+");
	printf("修改后：\n");
	while(str[j]!='\0')
	{
		if(str[j]==' '&&str[j+1]=='a'&&str[j+2]=='t'&&str[j+3]==' ') j=j+3;
		if(str[j]==' '&&str[j+1]=='i'&&str[j+2]=='n'&&str[j+3]==' ') j=j+3;
		if(str[j]==' '&&str[j+1]=='o'&&str[j+2]=='n'&&str[j+3]==' ') j=j+3;
		if(str[j]==' '&&str[j+1]=='o'&&str[j+2]=='f'&&str[j+3]==' ') j=j+3;
		if(str[j]==' '&&str[j+1]=='b'&&str[j+2]=='y'&&str[j+3]==' ') j=j+3;
		if(str[j]==' '&&str[j+1]=='i'&&str[j+2]=='n'&&str[j+3]=='t'&&str[j+4]=='0'&&str[j+5]==' ') j=j+5;
		if(str[j]==' '&&str[j+1]=='t'&&str[j+2]=='h'&&str[j+3]=='a'&&str[j+4]=='t'&&str[j+5]==' ') j=j+5;
		if(str[j]==' '&&str[j+1]=='w'&&str[j+2]=='h'&&str[j+3]=='i'&&str[j+4]=='c'&&str[j+5]=='h'&&str[j+6]==' ') j=j+6;
		if(str[j]==' '&&str[j+1]=='b'&&str[j+2]=='u'&&str[j+3]=='t'&&str[j+4]==' ') j=j+4;
		if(str[j]==' '&&str[j+1]=='w'&&str[j+2]=='h'&&str[j+3]=='o'&&str[j+4]==' ') j=j+4;
		else 
		{putc(str[j],fp);
		printf("%c",str[j]);}
		j++;
	}
    fclose(fp);

}