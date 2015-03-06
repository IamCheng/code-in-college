#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int pc,h,t=0,s=0,r=0;
	srand((int)time(0));
	printf("1石头，2剪刀，3布：\n");
	
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
          printf("平手\n");
	   }
       if((h==1&&pc==2)||(h==2&&pc==3)||(h==3&&pc==1))             //1=石头，2=剪刀，3=布
	   {
           printf("您赢了\n");
		   t++;
	   }
       if((h==2&&pc==1)||(h==3&&pc==2)||(h==1&&pc==3))  
		{
           printf("您输了\n");
		   s++;
		}
	 }while(t<3&&s<3);
	if(s>t) printf("电脑赢了\n");
	else printf("你真地赢了！\n");
}



