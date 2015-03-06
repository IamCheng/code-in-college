#include<stdio.h>
#include<stdlib.h>
#define size 2
struct student
{
	char name[20];
	int c,m,e;
}stud[size];
void main()
{
	FILE *fp;int i,ave[10],j=0;
	fp=fopen("filetest.dat","r+");

	for(i=0;i<size;i++)
	{
	fread(&stud[i],sizeof(struct student),1,fp);
    ave[i]=(stud[i].c+stud[i].m+stud[i].e)/3;
	if(ave[i]>=80) j++;
	printf("%s  %d  %d  %d\n",stud[i].name,stud[i].c,stud[i].m,stud[i].e);
	}
    printf("平均分大于80的人数为：%d\n",j);
    fclose(fp);
	
}