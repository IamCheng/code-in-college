#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
int Lsrch(int *s,int n)//˳�����
{
	int i,p;
	LARGE_INTEGER start,end,freq;//����ʱ��ı���
	printf("����Ҫ��ѯ��Ԫ��:\n");
	scanf("%d",&p);
	/*��ʼ��ʱ*/
	QueryPerformanceFrequency(&freq);   
	QueryPerformanceCounter(&start); 
	for(i=0;i<n;i++)//�����ؼ��֣��ҵ�Ŀ���ֹͣ
		if(s[i]==p)
		{
			QueryPerformanceCounter(&end); 
			printf("���ҳɹ�!\n���Ϊ��%d\n����ʱ��Ϊ:%.10fs\n",s[i],(double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
			return 1;
		}
        /*û�в���ʧ�ܣ���ִ���������*/
		QueryPerformanceCounter(&end); 
		printf("����ʧ�ܣ�\n������ʱ��Ϊ:%.10fs\n",(double)(end.QuadPart - start.QuadPart) / (double)freq.QuadPart);
	return 0;
}
int Hsrch(int *s,int n)//�۰���ң�nΪԪ�ظ���
{
	int h=n-1,l=0,mid,p;//hΪ��λ�±꣬lΪ��λ�±꣬midΪ�м��±�
	LARGE_INTEGER start,end,freq;
	printf("����Ҫ���ҵ�Ԫ��:\n");
	scanf("%d",&p);
	/*��ʼ��ʱ*/
	QueryPerformanceFrequency(&freq);   
	QueryPerformanceCounter(&start); 
	if(p<=100000000)
	while(h>l)//�۰����
	{
		mid=(h+l)/2;
		if(s[h]==p||s[l]==p||s[mid]==p)
		{
			QueryPerformanceCounter(&end); 
			printf("���ҳɹ���\n%d\n���õ�ʱ��Ϊ��%.10fs\n",p,(double)(end.QuadPart-start.QuadPart)/(double)freq.QuadPart);
			return 1;
		}
		else
		{
			if(s[mid]>p)
			{h=mid;l++;}
			else
			{l=mid;h--;}
			if(s[l]>p||s[h]<p)
				break;
		}
	}
	QueryPerformanceCounter(&end); 
	printf("����ʧ��!\n���õ�ʱ��Ϊ:%.10fs\n",(double)(end.QuadPart - start.QuadPart)/(double)freq.QuadPart);
	return 0;
}
void main()
{
	int *s,n,j;//�ı���ʾ
	printf("\t\t\t\t��ܰ��ʾ!\n    ��������Ϊ�˲���˳����Һ��۰���ҵ�ʱ�临�Ӷȣ������ڴ��Ѿ�����0��1��֮�������ż�����û�����ʾֱ������Ҫ���ҵ����ּ��ɡ�\n");
	getch();system("cls");
	s=(int*)malloc(sizeof(int)*100000000);
	if(s==NULL)/*�����ڴ�ʧ�ܣ���ֱ���˳�����*/
		exit(0);
	for(n=0;n<=50000000;n++)//�洢0��1��֮�������ż��
		s[n]=n*2;	
	/*�˵���ʾ*/
	while(1)
	{
		printf(" **********���ܱ�*********\n");
		printf("1��˳�����  2���۰����\n");
		scanf("%d",&j);
		if(j==1)
			Lsrch(s,n);
		else
		if(j==2)
			Hsrch(s,n);
		else
			printf("������������������!\n");
	}
}

