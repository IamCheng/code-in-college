#include<stdio.h>
#include<malloc.h>
void rotate(int* x, int rank)
{
	int i;
	int* y = (int*)malloc(sizeof(int)*rank*rank);  // МоїХ

	for(i=0; i<rank * rank; i++)
	{
		//y[4*(i-(i/4)*4)+(3-i/4)] = x[i];  // МоїХ
		y[4*i-17*(i/4)+3] = x[i];
	}

	for(i=0; i<rank*rank; i++)
	{
		x[i] = y[i];
	}

	free(y);
}
int main(int argc, char* argv[])
{
	int x[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int rank = 4;
	int i,j;

	rotate(&x[0][0], rank);

	for(i=0; i<rank; i++)
	{
		for(j=0; j<rank; j++)
		{
			printf("%4d", x[i][j]);
		}
		printf("\n");
	}

	return 0;
}

