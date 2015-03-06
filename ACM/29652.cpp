#include<stdio.h>
#include<string.h>


int c, flag[16], flag1[16], max = 10000000;
int map[] = {0x111f,0x222f,0x444f,0x888f,  0x11f1, 0x22f2,  0x44f4, 0x88f8,   0x1f11,0x2f22,0x4f44, 0x8F88, 0xf111 , 0xf222 ,0xf444,0xF888 };
int ans = max;


int check(int n)
{
	int tmp = c, i, l =0;
	memset(flag1, 0, sizeof(flag1));

	for(i = 0; i < 16; i++)	if( n & (1<<i) ) {l++;flag1[i] = 1;
		}

	if(l > ans && ans < max)
		return max;

	for(i = 0; i < 16; i++)
		if(flag1[i])
			tmp ^= map[i];
	if(0 == tmp)
	{memcpy(flag,flag1 , sizeof(int)*16);return l;}	
	else
		return max;
}
int output()
{
	printf("%d\n", ans);
	for(int i = 0; i < 16; i++)
		if(flag[i] == 1)
			printf("%d %d\n", i/4+1, i%4 +1);
	return 0;
}
int main()
{
	int i, j = 0, k;

	char t[5];


	for(i = 0; i < 4; i++)
	{
		scanf("%s", t);
		for(k = 0; k < 4; k++,j++)
			if(t[k] == '+')
				c += 1<<j;
	}
	for(i = 1; i < (1<<16); i++)
	{
		j = check(i);
		ans = ans > j ? j : ans;
	}
	output();
	
	return 0;
}
