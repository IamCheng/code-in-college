#include<stdio.h>
#include<stdlib.h>
#define N 10
struct stu
{
	long num;
	char name[20];
	int grade[3];
}a[10];
//�ҳ�ƽ������ߵ�ѧ�����������Ϣ
void cal()
{
	int i,j,ave[10]={0},t,max;
	for(i=0;i<N;i++)
	{
		for(j=0;j<3;j++)
			ave[i]+=a[i].grade[j];
		ave[i]=ave[i]/3;
	}
    max=ave[0];
	for(i=1;i<N;i++)
		if(max<ave[i])
		{
			t=i;
			max=ave[i];
		}
printf("ƽ�������ͬѧ����Ϣ:%d %s %d\n",a[t].num,a[t].name,max);

}
//��ѧ����Ϣ����stud.dat��
void file()
{
	int i;
	FILE *fp;
	if((fp=fopen("stud.dat","w"))==0)
		printf("error!");
	else
	{
		for(i=0;i<N;i++)
			fprintf(fp,"%d %s %d %d %d\n",a[i].num,a[i].name,a[i].grade[0],a[i].grade[1],a[i].grade[2]);
		printf("��Ϣ����stud.dat�ɹ���\n");
	}
	fclose(fp);
}

//��ȡ ���� ���
void readnsort()
{
	FILE *fp,*p;int i,j,ave[10],Max,t;//Max��ѡ��������м������ave���ѧ����ƽ����
	struct stu s;
	if((fp=fopen("stud.dat","r"))==0)
	{printf("��ȡʧ�ܣ�\n");return;}
	if((p=fopen("studsort.dat","w"))==0)
		{printf("����ʧ�ܣ�\n");return;}
    
	for(i=0;i<N;i++)
		fscanf(fp,"%d %s %d %d %d\n",&a[i].num,a[i].name,&a[i].grade[0],&a[i].grade[1],&a[i].grade[2]);
	fclose(fp);
	printf("��stud.dat�ж�ȡ�ɹ���\n");
	for(i=0;i<N;i++)
		{
			for(j=0;j<3;j++)
				ave[i]+=a[i].grade[j];
			ave[i]=ave[i]/3;
		}
	for(i=0;i<N-1;i++)
	{
		Max=i;
		for(j=i+1;j<N;j++)
			if(ave[Max]<ave[j])
				Max=j;
		if(i!=Max)
		{
			t=ave[i];
			ave[i]=ave[Max];
			ave[Max]=t;
			s=a[i];
			a[i]=a[Max];
			a[Max]=s;
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d %s %d %d %d\n",a[i].num,a[i].name,a[i].grade[0],a[i].grade[1],a[i].grade[2]);
		fprintf(p,"%d %s %d %d %d\n",a[i].num,a[i].name,a[i].grade[0],a[i].grade[1],a[i].grade[2]);
	}
	fclose(p);
	system("pause");
	system("cls");


}
//�����13579��ѧ����Ϣ
void read13579()
{
	FILE *p;int i,j=0;
	struct stu m;
	if((p=fopen("studsort.dat","r"))==0)
		{printf("��ʧ�ܣ�\n");return;}
	printf("�����1��3��5��7��9��ѧ��������\n");
	for(i=0;i<N;i++)
	{
		fscanf(p,"%d %s %d %d %d\n",&m.num,m.name,&m.grade[0],&m.grade[1],&m.grade[2]);
		if(i==j)
		{
			printf("%d %s %d %d %d\n",m.num,m.name,m.grade[0],m.grade[1],m.grade[2]);
			j+=2;
		}
	}
	fclose(p);
}	


void main()
{
	int i,j,max[10],num[10];
	for (i=0;i<N;i++)
	{
		num[i]=0;
		max[i]=0;
	}
	//����������ֵ
	for(i=0;i<N;i++)
	{
		printf("�����%d���˵�ѧ�ź�����:\n",i+1);
		scanf("%d%s",&a[i].num,a[i].name);
		for(j=0;j<3;j++)
		{
			printf("�����%d�Ƴɼ�:\n",j+1);
			scanf("%d",&a[i].grade[j]);
		}
	}
	system("cls");
	for(j=0;j<3;j++)
	{
		for(i=0;i<N;i++)
		{
			if(i==0) max[j]=a[i].grade[j];
			else  
				if(max[j]<a[i].grade[j])
				{
					max[j]=a[i].grade[j];
					num[j]=i;
				}
		}
	}
	for(i=0;i<3;i++)
		printf("��%d�Ƴɼ���߷��˵���Ϣ:%d %s %d\n\n",i+1,a[num[i]].num,a[num[i]].name,max[i]);

//���ø�������
	cal();
	system("pause");
	file();
	readnsort();
	read13579();


}
