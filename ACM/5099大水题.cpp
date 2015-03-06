#include<stdio.h>
#include<string.h>
char ans[3][3] = {" <", " =", " >"};
int main()
{
	int T, n;
	scanf("%d", &T);
	for(n = 1; n <= T; n++)
	{
		printf("Case %d:", n);
		char A[10], B[10];
		scanf("%s %s", A, B);
		int o = A[0] == B[0] ? 1 : (A[0] > B[0] ? 2 : 1);
		printf(ans[o]);	
		if(A[1] != B[1]){
			A[4] = B[4] = 0;
		}
		o = strcmp(A+2, B+2);
		o++;
		printf(ans[o]);
		printf("\n");
	}
	return 0;
}