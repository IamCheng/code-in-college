#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	int i,k=0,t,j=0,s[20],n;char pre[100],save[100];//pre��������ַ�����save���ַ�����ÿһ���ַ��������ַ����飬s������¼����
	gets(pre);
	n=strlen(pre);//ͳ������ĳ���
	for(i=0;i<=n;i++)
	{
		save[i]=pre[i];
		if(save[i]=='+'||save[i]=='-'||save[i]=='*'||save[i]=='/') {s[j]=i;j++;}//��¼�������ڵ�λ��
		if(i==n) s[j]=n;//�ڼ�¼����ź󣬼�¼�ַ����ܳ���
	}
	t=j;
	for(i=0;i<t+1;i++)
	{
		j++;
		for(s[j]=0;k<s[i];k++)
		   s[j]=s[j]*10+(int)(save[k]-48);//���ַ�ת��Ϊ����
		k++;
	}
	for(i=0;i<j+1;i++)
	      printf("%d\n",s[i]);//�����������
		


}
