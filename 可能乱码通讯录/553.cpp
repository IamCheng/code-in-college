#include<stdio.h>
#include<C:\Users\Chengxin\Desktop\�½��ļ��� (2)\13.cpp>
void main()
{
	int i;
	printf("      ��ӭ����ͨѶ¼ϵͳ\n");
	printf("1�����     2������       3���޸�     4��ɾ��     5��ͳ��     6���˳�   7����ӡ\n");
    check();
	scanf("%d",&i);
	while(i)
	{
		if(i==1) creat();
		if(i==2) search();
	    if(i==3) correct();
	    if(i==4) del();
	    if(i==5) printf("ͨѶ¼����%d�ˣ�\n",n);
		if(i==6) {esc();break;};
		if(i==7) print();
		printf("1�����     2������       3���޸�     4��ɾ��     5��ͳ��     6���˳�   7����ӡ\n");
		scanf("%d",&i);
	}
	



}