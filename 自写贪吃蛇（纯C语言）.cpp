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

/*chartΪ��Ļ��һ����ά����,over��Ϸ�Ƿ������pauseTime�����ʱ��*/
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
/* �����һ������*/
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
	if(s.lenth % 3 == 0)//ÿ����3������������30����
		pauseTime -= 30;
	gotoxy(j*2, i);
	printf("��");
	return i;
}

/*����һ��������Ӻ�����raw�У�col��*/
int Enqueue(int raw, int col)
{
	coordinate *p;
	p = (coordinate *)malloc(sizeof(coordinate));
	if(p==NULL)
	{
		printf("�����ڴ�ʧ��!\n");
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
/*ˢ������*/
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
	printf("��");
	
}
//��ʼ������
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
		printf("��");
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
/*w�ϲ���*/
int up( )
{
	Enqueue( s.rear->raw - 1,s.rear->col);
	if( chart[s.rear->raw][s.rear->col] == 1|| s.rear->raw < 0)
		return over = 1;
	direction_common_action();
	return 1;
	
}
/*s�²���*/
int down( )
{
	Enqueue( s.rear->raw + 1,s.rear->col);
	if( chart[s.rear->raw][s.rear->col] == 1||s.rear->raw > 24)
		return over = 1;
	direction_common_action();
	return 1;
}
/*a�����*/
int left( )
{
	Enqueue(s.rear->raw, s.rear->col-1);
	if(chart[s.rear->raw][s.rear->col] == 1 || s.rear->col < 0)
		return over = 1;
	direction_common_action();
	return 1;
}
/*d�Ҳ���*/
int right( )
{	
	Enqueue(s.rear->raw, s.rear->col+1);
	if(chart[s.rear->raw][s.rear->col] == 1 || s.rear->col >39)
		return over = 1;
	direction_common_action();
	return 1;
}
/*ѡ����Ĳ���*/
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
	COORD coordScreen={x, y};//�����������귵�ص���Ļ���Ͻ����� 
	BOOL bSuccess; 
	DWORD cCharsWritten; 
	CONSOLE_SCREEN_BUFFER_INFO csbi;//���滺������Ϣ 	
	
	DWORD dwConSize;//��ǰ�����������ɵ��ַ��� 
	
	bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ 
	dwConSize=(csbi.dwSize.X-x) * (csbi.dwSize.Y-2);//(�����������ַ���Ŀ)Ҫ��յ������X��������ȥ6�У�YĬ����25����ȥ
	//24����1��xĬ����80��ȥ6����74����Ϊ��궨λ�ڵ�0�е�6�У����Ծ���
	//��յ�0�еĵ�7�п�ʼ����0�еĽ�β
	//dwConSize=csbi.dwSize.X * csbi.dwSize.Y;
	//�ÿո���仺���� 	
	bSuccess=FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten); 	
	
	bSuccess=GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ 	
	//��仺�������� 
	bSuccess=FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten); 	
	
	//��귵����Ļ���Ͻ����� 
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
			if(kbhit() == 0)//����������ʱ
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
		printf("game over !\n�Ƿ������(y|n)");
		s = ss;	
	}while(getch() == 'y');
}
