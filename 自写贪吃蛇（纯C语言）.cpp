#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
typedef struct node
{
	int raw;
	int col;
	struct node *next;
}coordinate;
typedef struct Lnode
{
	int lenth;
	coordinate *rear;
	coordinate *front;
}queue;

/*chart为屏幕的一个两维数组,over游戏是否结束，pauseTime挂起的时间*/
char chart[25][40];
int over;
int eated;
unsigned long pauseTime = 200;
queue s;

void gotoxy(int a,int b)
{
	HANDLE hOutput;
	COORD loc;
	loc.X = a; loc.Y=b;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
}
/* 随机出一个豆豆*/
int food()
{
	int i, j;
	i = rand() % 25;
	j = rand() % 40;
	while(1 == chart[i][j])
	{
		i = rand() % 25;
		j = rand() % 40;
	}
	chart[i][j] = 2;
	s.lenth ++;
	if(s.lenth % 3 == 0)//每出现3个豆豆，加速30毫秒
		pauseTime -= 30;
	gotoxy(j*2, i);
	printf("●");
	return i;
}

/*定义一个队列入队函数。raw行，col列*/
int Enqueue(int raw, int col)
{
	coordinate *p;
	p = (coordinate *)malloc(sizeof(coordinate));
	if(p==NULL)
	{
		printf("分配内存失败!\n");
		exit(0);
	}
	else
	{
		p->raw = raw;
		p->col = col;
	}
	p->next=NULL;
	if(s.rear != NULL)
		s.rear->next=p;
	if(s.front == NULL)
		s.front = p;
	s.rear = p;
	return 1;
}
/*刷屏函数*/
void show()
{
	if(0 == eated)
	{
		coordinate *tmp;
		tmp = s.front;
		chart[tmp->raw][tmp->col] = 0;
		s.front = s.front->next;
		gotoxy(tmp->col*2, tmp->raw);
			printf("  ");
		free(tmp);
	}
	gotoxy((s.rear)->col*2, (s.rear)->raw);
	printf("█");
	
}
//初始化函数
int initial( )
{
	memset(chart,0,sizeof(chart));
	s.lenth = 0;
	s.rear = NULL;
	s.front = NULL;
	for(int i = 10; i < 16; i++)
	{
		chart[12][i] = 1;
		Enqueue(12 ,i);
	}
	gotoxy(20, 12);
	for(int j = 20; j < 26; j++)
		printf("█");
	return 1;	
}
int direction_common_action()
{
	if(chart[s.rear->raw][s.rear->col] == 2)
	{
		chart[s.rear->raw][s.rear->col] = 1;
		eated = 1;
		food();
		return 3;
	}
	chart[s.rear->raw][s.rear->col] = 1;

	return 1;
	
}
/*w上操作*/
int up( )
{
	Enqueue( s.rear->raw - 1,s.rear->col);
	if( chart[s.rear->raw][s.rear->col] == 1|| s.rear->raw < 0)
		return over = 1;
	direction_common_action();
	return 1;
	
}
/*s下操作*/
int down( )
{
	Enqueue( s.rear->raw + 1,s.rear->col);
	if( chart[s.rear->raw][s.rear->col] == 1||s.rear->raw > 24)
		return over = 1;
	direction_common_action();
	return 1;
}
/*a左操作*/
int left( )
{
	Enqueue(s.rear->raw, s.rear->col-1);
	if(chart[s.rear->raw][s.rear->col] == 1 || s.rear->col < 0)
		return over = 1;
	direction_common_action();
	return 1;
}
/*d右操作*/
int right( )
{	
	Enqueue(s.rear->raw, s.rear->col+1);
	if(chart[s.rear->raw][s.rear->col] == 1 || s.rear->col >39)
		return over = 1;
	direction_common_action();
	return 1;
}
/*选择方向的操作*/
int operate(char drt )
{
	switch(drt)
	{
	case 'w':up( );break;
	case 's':down( );break;
	case 'a':left( );break;
	case 'd':right( );break;
	}
	return 1;
}
void clrscr(int x,int y) 
{ 
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD coordScreen={x, y};//设置清屏后光标返回的屏幕左上角坐标 
	BOOL bSuccess; 
	DWORD cCharsWritten; 
	CONSOLE_SCREEN_BUFFER_INFO csbi;//保存缓冲区信息 	
	
	DWORD dwConSize;//当前缓冲区可容纳的字符数 
	
	bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息 
	dwConSize=(csbi.dwSize.X-x) * (csbi.dwSize.Y-2);//(缓冲区容纳字符数目)要清空的面积，X是列数减去6列，Y默认是25，减去
	//24等于1，x默认是80减去6等于74，因为光标定位在第0行第6列，所以就是
	//清空第0行的第7列开始到第0行的结尾
	//dwConSize=csbi.dwSize.X * csbi.dwSize.Y;
	//用空格填充缓冲区 	
	bSuccess=FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten); 	
	
	bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息 	
	//填充缓冲区属性 
	bSuccess=FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten); 	
	
	//光标返回屏幕左上角坐标 
	bSuccess=SetConsoleCursorPosition(hConsole,coordScreen); 
	
	return; 
}
void main()
{	
	queue ss = {0,NULL,NULL};
	do
	{
		system("cls");
		char drt = 'd';
		over = 0;
		pauseTime = 200;		
		memset(chart, 0, sizeof(chart));
		initial( );
		srand(time(NULL));
		food( );
		while(1)
		{
			eated = 0;
			if(kbhit() == 0)//键盘无输入时
				operate(drt);
			else
			{
				drt = getch();
				operate(drt );
			}	
			if(over == 1)
				break;
			Sleep(pauseTime);
			show();	
		}
		gotoxy(0, 23);
		printf("game over !\n是否继续玩(y|n)");
		s = ss;	
	}while(getch() == 'y');
}
