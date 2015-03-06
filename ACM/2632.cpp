#include<stdio.h>
#include<string.h>
typedef struct
{
	int x,y;
}crd;
char ch[101][101];
int k,n,m,a,b,flag;
crd num[101],key;
int order_l(int n1, int n2)
{
	int j;
	j = n2 % 4;
	ch[num[n1].x][num[n1].y] += j;
	if(ch[num[n1].x][num[n1].y] > 4)
		ch[num[n1].x][num[n1].y] -= 4;
	return 1;
}
int order_r(int n1, int n2)
{
	int j = n2 % 4;
	ch[num[n1].x][num[n1].y] -= j;
	if(0 >= ch[num[n1].x][num[n1].y])
		ch[num[n1].x][num[n1].y] += 4;
	return 1;
}
int order_f(int n1,int n2)
{
	int j;
	for(j = 0; j <n2; j++)
	{
		switch(ch[num[n1].x][num[n1].y])
		{
			case 1:
				if(num[n1].x -1 <= 0)
				{flag = 1;break;}
				if(ch[num[n1].x - 1][num[n1].y] != 0 )
				{
					flag = 2;
					key = num[n1];
					key.x--;
				}
				else
				{				 
					ch[num[n1].x - 1][num[n1].y] = ch[num[n1].x][num[n1].y];
					ch[num[n1].x][num[n1].y] = 0;
					num[n1].x --;
				}
				break;
			case 2:
				if(num[n1].y - 1 <= 0)
				{flag = 1;break;}
				if(ch[num[n1].x][num[n1].y - 1] != 0 )
				{
					flag = 2;
					key = num[n1];
					key.y--;
				}
				else
				{				 
					ch[num[n1].x ][num[n1].y - 1] = ch[num[n1].x][num[n1].y];
					ch[num[n1].x][num[n1].y] = 0;
					num[n1].y--;
				}
				break;
			case 3:
				if(num[n1].x + 1 > b)
				{flag = 1;break;}
				if(ch[num[n1].x+1][num[n1].y] != 0 )
				{
					flag = 2;
					key = num[n1];
					key.x++;
				}
				else
				{				 
					ch[num[n1].x +1][num[n1].y] = ch[num[n1].x][num[n1].y];
					ch[num[n1].x][num[n1].y] = 0;
					num[n1].x++;
				}
				break;
			case 4:
				if(num[n1].y + 1 > a)
				{flag = 1;break;}
				if(ch[num[n1].x][num[n1].y + 1] != 0 )
				{				
					flag = 2;
					key = num[n1];
					key.y++;
				}
				else
				{				 
					ch[num[n1].x ][num[n1].y + 1] = ch[num[n1].x][num[n1].y];
					ch[num[n1].x][num[n1].y] = 0;
					num[n1].y++;
				}
				break;
		}
		if(flag>0)
			return flag;
	}
	return 0;
}
int main()
{
	int row,col,i,tmp;
	char dr,order;
	int n1,n2;
	memset(ch,0,sizeof(ch));
	scanf("%d",&k);
	while(k--)
	{	
		flag = 0;
		tmp = 0;
		scanf("%d%d",&a,&b);
		scanf("%d%d",&n,&m);
		for(i = 0;i < n;i++)
		{
		
			scanf("%d %d %c",&row,&col,&dr);
			switch(dr)
			{
			case 'E':tmp = 4;break;
			case 'S':tmp = 1;break;
			case 'W':tmp = 2;break;
			case 'N':tmp = 3;break;
			}
			ch[col][row] = tmp;
			num[i+1].x = col;
			num[i+1].y = row;
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d %c %d",&n1, &order, &n2);
			if(flag == 0)
				switch(order)
				{
				case 'L':order_r(n1, n2);break;
				case 'R':order_l(n1, n2);break;
				case 'F':order_f(n1, n2);tmp=n1;break;
				}
		}
		switch(flag)
		{
		case 0:printf("OK\n");break;	
		case 1:printf("Robot %d crashes into the wall\n",tmp);break;
		case 2:
			for(i = 1;i<100;i++)
				if(key.x == num[i].x&&key.y==num[i].y)
					break;
				printf("Robot %d crashes into robot %d\n",tmp,i);
				break;
		}
	memset(ch,0,sizeof(ch));
	memset(num,0,sizeof(num));

	}
	return 0;
}