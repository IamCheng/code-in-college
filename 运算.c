#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	int i,k=0,t,j=0,s[20],n;char pre[100],save[100];//pre是输入的字符串，save把字符串的每一个字符保存在字符数组，s用来记录数字
	gets(pre);
	n=strlen(pre);//统计输入的长度
	for(i=0;i<=n;i++)
	{
		save[i]=pre[i];
		if(save[i]=='+'||save[i]=='-'||save[i]=='*'||save[i]=='/') {s[j]=i;j++;}//记录符号所在的位置
		if(i==n) s[j]=n;//在记录完符号后，记录字符串总长度
	}
	t=j;
	for(i=0;i<t+1;i++)
	{
		j++;
		for(s[j]=0;k<s[i];k++)
		   s[j]=s[j]*10+(int)(save[k]-48);//把字符转换为数字
		k++;
	}
	for(i=0;i<j+1;i++)
	      printf("%d\n",s[i]);//输出所有数字
		


}
