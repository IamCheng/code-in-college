#include<stdio.h>
const int maxn = 10000; 
int num[maxn], de[maxn];
int main()
{
    int n = 0, in_max = 0, de_max = 0;
    while(scanf("%d", &num[n++]) == 1);
    for(int j = 1; j < n - 1; j++)
    {
        for(int i = 0; i < j; i++)
        {
            if(num[j] <= num[i])
            {
                if(de[i] + 1 > de[j])
                    de[j] = de[i] + 1;
            }
        }
        if(de[j] > de_max)
            de_max = de[j];
    }
	int cnt = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(num[i] == -1)	continue;
		int tmp = num[i];
		cnt++;
		for(int j = i + 1; j < n - 1; j++)
		{
			if(num[j] != -1 && tmp >= num[j])
			{	
				tmp = num[j];
				num[j] = -1;				
			}
		}
	}
    printf("%d\n%d\n", de_max+1, cnt); 
    return 0;
}