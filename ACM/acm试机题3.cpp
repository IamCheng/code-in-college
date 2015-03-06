#include<stdio.h>
int main()
{
	int n,i,j,num[21];
	_int64 jc[21] = {1},k ;
	for(i = 1; i <= 20 ;i++)
		jc[i] = jc[i-1]*i; 
	while(1)
	{
		int count[21] = {0};
		_int64 temp = 0;
		scanf("%d%I64d", &n, &k);
		if(0 == n && 0 == k)
			break;
		for(i = 0;i < n; i++)
		{
			scanf("%d",&num[i]);
			for(j = 0;j < i;j++)
			{
				if(num[i] > num[j])
					count[i]++;
			}
			temp += (num[i] - count[i] - 1) * jc[n -i-1];//计算这个序列是第几个数列（从0开始）
		}		
		temp = temp - k;
		if(temp < 0)
			printf("-1\n");
		else
		{
			//通个数列的位数求得该数列
			for(i = 0;i < n;i ++)
			{
				int flag[21] = {0};//标记数组
				num[i] = temp / jc[n-i-1] + 1 ;
				temp = temp % jc[n - i -1];
				for( j = 0;j < i;j++)
				{
					for( int k = 0; k < i;k++)
					{
						if(flag[k]==0 && num[i] >= num[k])
						{
							num[i]++;
							flag[k] = 1;
							break;
						}
					}
					
				}
			}
			for(i = 0;i < n;i++)
				printf("%d ",num[i]);
			printf("\n");
			
		}
		
	}
	return 0;	
}