#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int pc,h,t=0,s=0,r=0;
	srand((int)time(0));
	printf("1ʯͷ��2������3����\n");
	
	do
	{
	   scanf("%d",&h);
	   while(h>3||h<1)
	   {
		  printf("erro,input again(1~3)!\n");
		  scanf("%d",&h);
	   }
	   pc=rand()%3+1;
	   if(h==pc)
	   {
		  r++;
          printf("ƽ��\n");
	   }
       if((h==1&&pc==2)||(h==2&&pc==3)||(h==3&&pc==1))             //1=ʯͷ��2=������3=��
	   {
           printf("��Ӯ��\n");
		   t++;
	   }
       if((h==2&&pc==1)||(h==3&&pc==2)||(h==1&&pc==3))  
		{
           printf("������\n");
		   s++;
		}
	 }while(t<3&&s<3);
	if(s>t) printf("����Ӯ��\n");
	else printf("�����Ӯ�ˣ�\n");
}



