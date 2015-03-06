#include<stdio.h>
int n;
double solve(double (*a)[100], int nn, int r)
{
	if(r == n)
	{
		return a[r-1][nn];
	}
	/*
		��ÿ������ʽ�ӽ�����Ԫ
	*/
	for(int i = r; i < n; i++)
	{
		double ch = a[i][nn];
		for(int j = nn; j <= n; j++)
		{
			a[i][j] /=ch;
		}
	}
	for(i = r+1; i < n; i++)
	{
		for(int j = nn; j <= n; j++)
		{
			a[i][j] -= a[r][j];
		}
	}
	solve(a, nn+1, r+1);//�����ݹ����

//�����������
	for(i = r+1; i < n; i++)
	{
		a[r][n] -= a[r][i] * a[i][n];
	}
	return 0;
}
int main()
{
	double a[100][100];
	printf("���뷽�����X����:\n");
	scanf("%d", &n);
	printf("���뷽����ϵ��:\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= n; j++)
			scanf("%lf", &a[i][j]);
	solve(a, 0, 0);
	printf("������Ľ�Ϊ��\n");
	for(i = 0; i < n; i++)
		printf("x%d = %lf\n", i+1, a[i][n]);
	return 0;
}