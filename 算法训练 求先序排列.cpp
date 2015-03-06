#include<stdio.h>
#include<string.h>
int order_first(char A[], char B[], int n)
{
	if(n <= 0)
		return 0;
	printf("%c", B[n-1]);
	int len = strchr(A, B[n-1]) - A;
	order_first(A, B, len);
	order_first(A+len+1, B+len, n-len-1);
	return 0;

}
int main()
{
	char A[10], B[10];
	scanf("%s%s", A, B);
	order_first(A, B, strlen(B));
	return 0;
}
