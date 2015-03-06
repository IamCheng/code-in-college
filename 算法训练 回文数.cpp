#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100;
int plus(vector <int> & a, vector <int> &b, int n)
{
	int adc = 0;
	for(int i = a.size() - 1; i >= 0; i--)
	{
		int tmp = (a[i] + b[i] + adc) % n;
		adc = (a[i] + b[i] + adc) / n;
		a[i] = tmp;
	}
	if(adc > 0)
		a.insert(a.begin(), adc);
	return 1;
}
bool jd(vector <int> a)
{
	int len = a.size() - 1;
	for(int i = 0; i < a.size() / 2; i++)
		if(a[i] != a[len-i])
			return false;
	return true;
}
int main()
{
	int n;
	char in[maxn];
	vector <int> a, b;
	scanf("%d", &n);
	scanf("%s", in);
	for(int i = 0; in[i] != 0; i++)
	{
		int tmp = in[i]-'0' < 10 ? in[i]-'0': in[i]-'A'+10;
		a.push_back(tmp);
	}
	if(jd(a))
	{
		printf("STEP=0\n");
		return 0;
	}
	for(int j = 1; j <= 30; j++)
	{
		b = a;
		reverse(a.begin(), a.end());
		plus(a, b, n);
		if(jd(a))
		{
			printf("STEP=%d\n", j);
			return 0;
		}
	}
	printf("Impossible!\n");
	return 0;
}