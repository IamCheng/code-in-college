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
	FILE *fp;int i;
	char filename[20]="filetest.dat";
	printf("输入十个学生的姓名和成绩\n");
	for(i=0;i<size;i++)
		scanf("%s%d%d%d",stud[i].name,&stud[i].c,&stud[i].m,&stud[i].e);
	 
		
	if((fp=fopen(filename,"w+"))==NULL)
	{
		printf("cannot open file\n");
	    exit(0);
	}
	for(i=0;i<size;i++)
		if(fwrite(&stud[i],sizeof(struct student),1,fp)!=1)
	       printf("file write error\n");
    fclose(fp);
	
}