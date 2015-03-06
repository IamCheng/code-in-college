#include<stdio.h>
#include<math.h>
const int maxn = 8005;
char ch[maxn];
int main()
{
	int n, az[26] = {0}, i;
	scanf("%d", &n);
	scanf("%s", ch);
	for(i = 0; i < n; i++)
		az[ch[i]-'a']++;
	int t = 0;
	for(i = 0; i < 26; i++)
		if(az[i] % 2 == 1)
			t++;
	if(t > 1)
	{
		printf("Impossible\n");
		return 0;
	}
	int ans = 0, s = n / 2;
	for(i = n - 1, t = n - 1; t >= n / 2; i--)
	{
		if(ch[i] != 0)
		{
			if(az[ch[i]-'a'] == 1)
			{
				s = t;
				t--;
				continue;
			}
			int tt = 0;
			int j;
			for(j = 0; ch[i] != ch[j]; j++)
				if(ch[j] != 0 )	tt++;
			ch[j] = 0;
			ans += tt;
			az[ch[i]-'a'] -= 2;
			t--;
		}
	}
	printf("%d\n", ans+abs(s-n/2));
	return 0;



}
