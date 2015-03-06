#include<stdio.h>
struct node
{
	__int64 p,q;
};
unsigned __int64 num[] = {0, 1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,
268435455,536870911,1073741823,2147483647,4294967295,8589934591,17179869183,34359738367,68719476735,137438953471,274877906943,549755813887,1099511627775,
2199023255551,4398046511103,8796093022207,17592186044415,35184372088831,70368744177663,140737488355327,281474976710655,562949953421311,1125899906842623,2251799813685247,
4503599627370495,9007199254740991,18014398509481983,36028797018963967,72057594037927935,144115188075855871,288230376151711743,576460752303423487,1152921504606846975,
2305843009213693951,4611686018427387903,9223372036854775807,18446744073709551615};
bool flag = false;
int crt = 0;
node cal(unsigned __int64 row, unsigned __int64 r)
{
	node t;
	if(row == 1)
	{
		t.p = 1;
		t.q = 1;
		return t;
	}
	if(r % 2 == 0)
	{
		node h = cal(row - 1, r / 2);
		t.p = h.p + h.q;
		t.q = h.q;
	}
	if(r % 2 == 1)
	{
		node h = cal(row - 1, (r + 1) / 2);
		t.p = h.p;
		t.q = h.p + h.q;
	}
	return t;
}
node srch(node t)
{
	node tmp;
	node rd;
	if(t.p <= 0 || t.q <= 0)
		return rd;
	if(t.p == 1 && t.q == 1)
	{
		flag = true;
		rd.p = 1;
		rd.q = 1;
		return rd;
	}
	if(!flag)
	{
		tmp.q = t.q - t.p;
		tmp.p = t.p;
		node rr = srch(tmp);
		rd.p = rr.p;
		rd.q = rr.q * 2 - 1;
	}
	if(!flag)
	{
		tmp.p = t.p - t.q;
		tmp.q = t.q;
		node rr = srch(tmp);
		rd.p = rr.p;
		rd.q = rr.q * 2;
	}
	if(flag)
	{
		rd.p++;
		return rd;
	}
	return rd;

}
int op1()
{
	unsigned __int64 n;
	scanf("%I64d", &n);
	for(int i = 1; i <= 66; i++)
		if(n <= num[i])
			break;
	unsigned __int64 rest = n - num[i-1];
	node tmp = cal(i, rest);
	printf("%I64u %I64u\n", tmp.p, tmp.q);
	return 0;
}
int op2()
{
	node in;
	flag = false;
	scanf("%I64d%I64d", &in.p, &in.q);
	in = srch(in);
	printf("%I64u\n", num[in.p-1] + in.q);
	return 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int crt = 1; crt <= T; crt++)
	{
		int ch;
		scanf("%d", &ch);
		printf("Case #%d: ", crt);
		if(ch == 1)
			op1();
		else
			op2();

	}
	return 0;
}