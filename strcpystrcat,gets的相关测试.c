#include<stdio.h>
#include<string.h>
void sum(char *c)
{
printf("%d %d\n",strlen(c),sizeof(*c));
}
void main()
{
	int i;
char a[10],b[34]="d";
	//scanf("%s ",a);
//gets(a);
printf("%c \n",*gets(a));
/*strcat(b,a);
printf("%s",b);
printf("%d\n",strlen(a));
strcpy(b,a);
printf("%c",b[5]);
for(i=0;i<8;i++)
printf("%c",b[i]);
puts("\n");
printf("%s",b);
*/
}
