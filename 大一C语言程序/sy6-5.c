#include<stdio.h>
int main()
{
  char ch;
  int k=0;
  printf("输入一行字符：\n");
  while((ch=getchar())!='\n')
  k++;
  
  printf("字符个符：%d\n",k+1);
  
  }

