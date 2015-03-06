#include<stdio.h>
#include<windows.h>
#include "conio.h"
#include<string>
#include<stack>
#include<time.h>
#include<map>
using namespace std;

char cmd[][20] = {"time", "version", "date", "cls", "dir", "help", "print", "del", "mkdir", "ren"};
char para[][100] = {"E:\\", "E:\\"};

int show_version()
{
	printf("The latest CX version [版本 8.8.88888](C)\n版权所有 2000 - 3000.\n");
	return 0;
}
int show_time()
{
	char tmp[20];
	time_t t = time(NULL);
	strftime(tmp, sizeof(tmp), "%X", localtime(&t));
	printf("当前时间为：\n	%s\n", tmp);
	return 0;
}

int show_date()
{
	char tmp[20];
	time_t t = time(NULL);
	strftime(tmp, sizeof(tmp), "%Y/%m/%d",localtime(&t) ); ;
	printf("当前日期为：\n	%s\n", tmp);
	return 0;
}

int PathIsDirectory(char *path)
{
	WIN32_FIND_DATA find_file;	
	FindFirstFile(path, &find_file);
	if (find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		return 1;
	return 0;
}

int del_files(char * name)
{
	char tmp[100];
	strcpy(tmp, name + strlen(para[1]));
	if(remove(name) == -1 && remove(tmp) == -1)
		printf("文件不存在!\n");
	else
		printf("删除成功!\n");
	return 0;
}

int print_text(char * name)
{
	FILE *fp = fopen(name, "r");
	if(fp == NULL)
		printf("读取信息失败，文件不存在!\n");
	else
	{
		char  ch;
		ch = fgetc(fp);
		if(ch != NULL)
			while(!feof(fp))
				putchar(fgetc(fp));
	}
	printf("\n");
	return 0;
}

int rename_file(char old[], char New[])
{
	if(-1 == rename(old, New))
		printf("重命名失败!请检查文件是否存在或新命名包含特殊字符.\n");
	else
		printf("重命名成功!\n");
	return 0;
}

int show_directory()
{
	HANDLE	obj_handle;
	WIN32_FIND_DATA find_file;			
	SYSTEMTIME st;//定义系统时间
	//获取当前目录
	strcat(para[0], "\\*.*");
	
	obj_handle = FindFirstFile(para[0], &find_file);//obj_handle初始化
	
	if( obj_handle != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(obj_handle, &find_file))
		{
			FILETIME tmp;
			FileTimeToLocalFileTime(&find_file.ftCreationTime,  &tmp); 
			FileTimeToSystemTime(&tmp,  &st);
			printf("%d/%d/%d\t", st.wYear, st.wMonth, st.wDay);//年月日
			printf("%d:%d:%2d\t", st.wHour, st.wMinute, st.wSecond);
			if (find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				printf("<dir> ");
			printf("\t%s\n",find_file.cFileName);//
		}
	}
	FindClose(obj_handle);
	return 0;
}

int creat_dir(char name[])
{
	if(CreateDirectory(name, NULL) == NULL)
		printf("创建目录失败!请检查目录名称\n");
	else
		printf("创建成功！\n");
	return 0;
}

int del_dir(const char name[])
{
	char path1[100],path2[100];
	memset(path1, 0, sizeof(path1));
	strcpy(path1, name);
	memset(path2, 0, sizeof(path2));
	strcpy(path2, name + strlen(para[1]));
	if(!PathIsDirectory(path1) && !PathIsDirectory(path2))
		return 0;
	SHFILEOPSTRUCT FileOp;
	if(PathIsDirectory(path2))
		FileOp.pFrom = path2;
	else
		FileOp.pFrom = path1;
	FileOp.fFlags = FOF_NOCONFIRMATION;
	FileOp.hNameMappings = NULL;
	FileOp.hwnd = NULL;
	FileOp.lpszProgressTitle = NULL;	
	FileOp.pTo = NULL;
	FileOp.wFunc = FO_DELETE;
	return SHFileOperation(&FileOp) == 0;
}

int change_path(char *path)
{
	memset(para, 0, sizeof(para));
	strcpy(para[0], path);
	if(para[0][2] != '\\')
	{
		for(int i = strlen(path); i > 2; i--)
			para[0][i] = para[0][i-1];
		para[0][2] = '\\';
	}
	strcpy(para[1], para[0]);
	return 0;
}

int show_current_tree()
{
	return 0;
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
	dwConSize=(csbi.dwSize.X-x) * (csbi.dwSize.Y-24);//(缓冲区容纳字符数目)要清空的面积，X是列数减去6列，Y默认是25，减去
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
void help()
{
	printf("\t      \t*************命令行大全****************\n");//{"time", "version", "date", "cls", "dir", "help", "print", "del", "mkdir", "ren"};
	printf("time			显示时间\n");
	printf("date			显示日期\n");
	printf("version			显示版本\n");
	printf("help			帮助信息\n");
	printf("dir			显示当前目录的所有文件\n");
	printf("print filename  \t打印文本文件内容\n");
	printf("del file/dir    \t删除指定文件明为filename的文件\n");
	printf("mkdir filename  \t创建一个名为filename的目录\n");
	printf("ren old new     \t重命名一个文件，old为旧文件名，new为新文件名\n");
	printf("string\t\t\t设置当前命令行的路径为string\n");
	return;
}
int explain(char *in)
{
	char tmp[100];
	memset(tmp, 0, sizeof(tmp));
	if(SetCurrentDirectory(in))
		return 10;
	for(int i = 0; i < strlen(in); i++)
		if(in[i] == ' ')
			break;
		int j = i;		
		in[i] = 0;
		for(i = 0; i < 11; i++)
			if(strcmp(in, cmd[i]) == 0)
				break;
			if(i == 8||(i <= 5 && in[j] != 0))
				return -1;
			if(i <= 5 && in[j+1] == 0)
				return i;
			if(in[j+1] == 0)
				return -1;
			strcpy(tmp, in + j + 1);
			
			if(i >= 6 && i <= 8)
				strcat(para[0], tmp);
			else
			{
				for(int i = 0; i < strlen(tmp); i++)
					if(tmp[i] == ' ')
						break;
					tmp[i] = 0;
					if(tmp[i+1] == 0)
						return -1;
					strcat(para[0], tmp);
					strcat(para[1], tmp + i +1);
			}
			return i;	
}
int main(int argn ,char *argv[])
{	
	char in[100];
	while(1)
	{
		int n = strlen(para[0]);
		printf("%s->", para[0]);
		memset(in, 0, sizeof(in));
		gets(in);
		int choice = explain(in);
		switch(choice)
		{
		case -1: printf("' %s '不是内部或外部命令，也不是可运行的程序\n或批处理文件。\n", in);break;
		case 0 : show_time();break; 
		case 1 : show_version();break;
		case 2 : show_date();break;
		case 3 : clrscr(0, 0);break;
		case 4 : show_directory();break;
		case 5 : help();break;
		case 6 : print_text(para[0]);break;	
		case 7 : if(del_dir(para[0]) == 0)	del_files(para[0]);break;
		case 8 : creat_dir(para[0]);break;
		case 9 : rename_file(para[0], para[1]);break;
		case 10 : change_path(in);break;
		}//{"time", "version", "date", "cls", "dir", "help", "print", "del", "mkdir", "ren"};
		if(choice != 10)
		{
			memset(para[0] + n, 0, (100 - n) * sizeof(char));
			memset(para[1] + n, 0, (100 - n) * sizeof(char));
		}
	}
	return 0;
}