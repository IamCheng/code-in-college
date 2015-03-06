#include<stdio.h>
#include<string.h>
int change(char b[],int flag[], int num)
{
	int i;
	for(i = 0; i < num; i++)
		if(b[i] >= 1 && b[i] <= 5)
			b[i] = flag[b[i]];
	return 1;
}
int main()
{
	char ch[101];
	while(1)
	{
		int i,j=0,k=0,n=0,fr = 0,flag[6],m,f = 0,tmp,tmp1,num;
		//s1是只存放运算符，s存入所有为字符，location_lv存放逻辑变量的位置，location_ysf存入运算符的位置
		char s1[101] = {0},s[101]={0},location_ysf[101]={0},location_lv[101]={0},s2[100],a,b;
		scanf("%s",ch);
		num = strlen(ch);
		if('0' == ch[0])
			break;
		/*把输入的逻辑表达式字符串中的pqrst变成12345*/
		for(i = 0 ; i<num; i++)
		{
			if(ch[i] >= 'p')
			{
				ch[i] = ch[i] - 'p' + 1;
				location_lv[j++] = i;
			}
			else
			{
				s1[k] = ch[i];
				location_ysf[k++] = i;
			}
		}
		strcpy(s2,location_lv);
		//先把位置保存起来
		for(i = 0;i < 32; i++)
		{
			flag[1] = i & 1;
			flag[2] = (i & 2) >> 1;
			flag[3] = (i & 4) >> 2;
			flag[4] = (i & 8) >> 3;
			flag[5] = (i & 16) >> 4;
			strcpy(s,ch);
			tmp = j;
			tmp1 = k;
			change(s, flag, num);//把字符串中的12345转换为01
			while(k > 0)
			{
				k--;
				for( m = 0; m < strlen(location_lv);m++)
					if( location_lv[m] > location_ysf[k])
					{
						n = m;
						break;
					}
				a = s[location_lv[n]];
				while(m < strlen(location_lv) - 1 && location_lv[++m] < 0 );
				b = s[location_lv[m]];
				fr = m ;
				//逐个实现s1[k]中的运算符
				switch(s1[k])
				{
				case 'K':
					s[location_lv[n]] = a & b;
					location_lv[fr] = -1;
					break;
				case 'A':
					s[location_lv[n]] = a | b;
					location_lv[fr] = -1;
					break;
				case 'N':
					if( a > 0)
						s[location_lv[n]] = 0;
					else
						s[location_lv[n]] = 1;
					break;
				case 'C':
					if(1 == a && 0 == b)
						s[location_lv[n]] = 0;
					else
						s[location_lv[n]] = 1;
					location_lv[fr] = -1;
					break;
				case 'E':
					if(a == b)
						s[location_lv[n]] = 1;
					else
						s[location_lv[n]] = 0;
					location_lv[fr] = -1;
					break;
				}
				if(s1[k] != 'N')
					j--;
			}
			if(s[location_lv[n]] == 0)
			{
				f = 1;
				break;
			}
			j = tmp;
			k = tmp1;
			strcpy(location_lv,s2);
		}
		if(1 == f)
			printf("not\n");
		else
			printf("tautology\n");
	}	
	return 0;
}