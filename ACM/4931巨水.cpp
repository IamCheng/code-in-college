#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t, num[6];
	scanf("%d", &t);
	while(t--)
	{
		int s = -1;
		for(int i = 0; i <= 5; i++)
			scanf("%d", &num[i]);
		sort(num, num+6);
		if(num[3] + num[1] + num[2] < num[5] + num[4])
			printf("Grandpa Shawn is the Winner!\n");
		else
			printf("What a sad story!\n");
	}
	return 0;
}