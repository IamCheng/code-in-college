#include<stdio.h>
#include<C:\Users\Chengxin\Desktop\新建文件夹 (2)\13.cpp>
void main()
{
	int i;
	printf("      欢迎进入通讯录系统\n");
	printf("1：添加     2：查找       3：修改     4：删除     5：统计     6：退出   7：打印\n");
    check();
	scanf("%d",&i);
	while(i)
	{
		if(i==1) creat();
		if(i==2) search();
	    if(i==3) correct();
	    if(i==4) del();
	    if(i==5) printf("通讯录共有%d人！\n",n);
		if(i==6) {esc();break;};
		if(i==7) print();
		printf("1：添加     2：查找       3：修改     4：删除     5：统计     6：退出   7：打印\n");
		scanf("%d",&i);
	}
	



}