#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 505;
int A[maxn], B[maxn];
int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int T, crt;
	scanf("%d", &T);
	for(crt = 1; crt <= T; crt++)
	{
		int N;
		cin >> N;
		int a = 0, b = 0, tmp;
		bool flag[1010] = {0};
		for(int i = 0; i < N; i++){
			scanf("%d", &tmp);
			if(tmp % 2 == 0){
				B[b++] = tmp;
				flag[i] = true;
			}
			else
				A[a++] = tmp;
		}
		sort(B, B+b, cmp);
		sort(A, A+a);
		a = 0;
		b = 0;
		cout << "Case #" << crt << ":"; 
		for(i = 0; i < N; i++)
			if(flag[i])
				cout <<" "<< B[a++];
			else
				cout <<" "<< A[b++];
		cout << endl;
	}
	return 0;
}