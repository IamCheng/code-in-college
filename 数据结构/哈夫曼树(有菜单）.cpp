#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
typedef struct wnc
{
	char ch;
	int w;
	char *code;
}dat,*datptr;//����ַ���Ȩֵ������Ľṹ�壬w����Ȩֵ��code������룬ch�����ַ�
typedef struct nod
{
	int l,r,p;
	int w;
}HTree;//�����Ľṹ��
int compare(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
int strnum(char *a,int *i,datptr rcd)//ͳ���ַ�����������������ַ�Ȩֵ�ĺ���
{
	int j=1;
	char *p;
	(*i)=0;
	p=(char *)malloc(strlen(a)*sizeof(char)+1);
	strcpy(p,a);
	qsort(p,strlen(p),sizeof(char),compare);//���������������ַ���������
	/*ͳ���ַ����ַ��ĸ�����*/
	while(*p!='\0')
	{
		if(*p!=*(p+1))
		{
			rcd[(*i)].w=j;
			rcd[(*i)].ch=*p;
			(*i)++;
		}
		if(*p==*(p+1))
			j++;
		else
			j=1;
		p++;
	}
	/*���Ȩֵ���ַ�*/
	printf("���ַ�������%d���ַ���\n",*i);
	printf("-------------------\n�ַ�  Ȩֵ\n");
	for(j=0;j<*i;j++)
		printf("%3c  %4d\n",rcd[j].ch,rcd[j].w);
	printf("-------------------\n");
	return 1;
}
int Getmin(HTree *T,int n,int *min)//��ȡ��СȨֵ�Ľ��
{
	int i,m=1000000;
	for(i=0;i<n;i++)
		if(T[i].p==0)
		{
			if(m>(T[i].w))
			{
				*min=i;
				m=T[i].w;
			}
		}
		return 1;
		
}
/*����haffman����������*/
int CreatHTree(HTree **T,datptr rcd,int n)
{
	
	int m=2*(n)-1,i,j,min1,min2,k;//min1 min2Ϊ��С�Ķ���Ȩֵ�����±�
	(*T)=(HTree*)malloc(m*sizeof(HTree));
	//��ʼ���������
	for(i=0;i<n;i++)
	{
		(*T)[i].p=0;
		(*T)[i].l=0;
		(*T)[i].r=0;
		(*T)[i].w=rcd[i].w;
	}
	for(;i<m;i++)
	{
		(*T)[i].p=0;
		(*T)[i].l=0;
		(*T)[i].r=0;
		(*T)[i].w=0;
	}
	//����huffman��
	for(i=n;i<m;i++)
	{
		Getmin(*T,i,&min1);
		(*T)[min1].p=i;
		Getmin(*T,i,&min2);
		(*T)[i].w=(*T)[min1].w+(*T)[min2].w;
		(*T)[i].l=min1;
		(*T)[i].r=min2;
		(*T)[min2].p=i;
	}
	printf("׼����ʼ����\n");
	system("pause");
	if(n==1)//��huffman��ֻ��һ�����ʱ������������
	{
		rcd[0].code=(char *)malloc(2*sizeof(char));
		rcd[0].code="0";
		
	}
	else
		for(i=0;i<n;i++)
		{
			k=i;
			rcd[i].code=(char *)malloc(n*sizeof(char));//�����Ľ��̫��2ʱ��huffman�������<=n
			for(j=0;(*T)[k].p!=0;j++,k=(*T)[k].p)
			{
				if(k==(*T)[(*T)[k].p].l)
					rcd[i].code[j]='0';
				else
					rcd[i].code[j]='1';
			}
			rcd[i].code[j]='\0';
		}
		return 1;
}
int Decode(HTree *T,char *cd,datptr rcd,int m)
{
	HTree *s;int choice,k=0,i,j;
	char ch;
	printf("\t1���Ըղŵĵ��Ľ���  2���������������  3���������˵�\n");
	scanf("%d",&choice);
	while(choice<1||choice>3)
		scanf("%d",&choice);
	if(choice==3) return 0;
	if(choice==2)
	{
		for(i=0;(ch=getch())!=13;i++)
		{
			while(ch<'0'||ch>'1')
				ch=getch();
			if(i==0)cd=(char *)malloc(20*sizeof(char));
			cd[i]=ch;
			putchar(ch);
		}
		cd[i]='\0';
	}
	printf("\n");
	printf("-----------------------\nȨֵ  �ַ�   ���� \n");
	for(i=0;i<m/2+1;i++)
		printf("%4d %4c %7s\n",rcd[i].w,rcd[i].ch,rcd[i].code);
	while(*cd!='\0')
	{
		s=T+m-1;
		for(;s->l!=0||s->r!=0;)
			if(*(cd++)=='0')
			{
				k=s->l;
				s=T+s->l;
			}
			else
			{
				k=s->r;
				s=T+s->r;
			}
			
			if(m==1&&cd[i]=='1') cd++;
			else if(m==1){printf("%c",rcd[k].ch);cd++;}
			else
				printf("%c",rcd[k].ch);
	}
	printf("\n");
	return 1;
}

int main()
{
	char a[100],tmp,**encode,*cd;
	HTree *T;
	int n,i,j,r,k,choice,flag=0;
	dat rcd[100];
	while(1)
	{
		printf("\t\t-------------------------------------\n\t\t1���Ե��Ķ��б���   2������   3���˳�\n\t\t************************************\n");
		printf("�����������\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("�������һ���ַ������԰����ո�����ĸ�����ŵȣ���\n");	
			while(*gets(a)=='\0');//��gets()���룬�ַ������Դ洢�ո�
			strnum(a,&n,rcd);//ͳ�ƺ���
			printf("ԭ��Ϊ��%s\n",a);
			flag=CreatHTree(&T,rcd,n);
			/*����Ķ���ѭ���Ƕ�rcd[].code���ַ�������*/
			for(i=0;i<n;i++)
			{
				r=strlen(rcd[i].code);
				for(j=0,k=r;j<r/2;j++)
				{	
					tmp=rcd[i].code[j];
					rcd[i].code[j]=rcd[i].code[k-1];
					rcd[i].code[k-1]=tmp;
					k--;
				}
			}
			printf("-----------------------\nȨֵ  �ַ�   ���� \n");
			for(i=0;i<n;i++)
				printf("%4d %4c %7s\n",rcd[i].w,rcd[i].ch,rcd[i].code);
			printf("-----------------------\n");
			encode=(char **)malloc(strlen(a)*sizeof(char*));//encode���ԭ�ַ���������
			//����Ķ���ѭ���ǵ�ԭ�ַ���������룬�����encode��
			for(i=0,r=0;i<strlen(a);i++)
			{
				for(j=0;j<n;j++)
					if(a[i]==rcd[j].ch)
						break;
					r=r+strlen(rcd[j].code);
					encode[i]=(char*)malloc(strlen(rcd[j].code+1));
					strcpy(encode[i],rcd[j].code);
			}
			printf("�ַ���������Ϊ:\n");
			cd=(char *)malloc(r*sizeof(char)+1);
			strcpy(cd,encode[0]);
			for(i=1;i<strlen(a);i++)
				strcat(cd,encode[i]);
			free(encode);
			printf("\n%s",cd);
		}
		if(choice==2)
		{
			if(flag!=1)
				printf("���ȶԵ籨����!\n");
			else
				Decode(T,cd,rcd,2*n-1);//����
		}
		if(choice==3) break;
		if(choice>3||choice<1)
			printf("����������������������!\n");
		system("pause");
		system("cls");
		
	}
	return 1;
}
