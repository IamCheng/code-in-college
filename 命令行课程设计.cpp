#include<stdio.h>
#include<windows.h>
#include "conio.h"
#include<string>
#include<time.h>
/*命令行的各个命令，与window的dos命令名称基本相同。*/
char cmd[][20] = {"time", "version", "date", "cls", "dir", "help", "tree", "exit", "print", "del", "mkdir", "ren"};

/*默认的路径为E:\*/
char para[][100] = {"E:\\", "E:\\"};

/*显示命令行程序的版本*/
int show_version()
{
	printf("The latest CX version [版本 8.8.88888](C)\n版权归程鑫所有 2000 - 3000.\n");
	return 0;
}
/*显示系统的时间*/
int show_time()
{
	char tmp[20];
	time_t t = time(NULL);
	strftime(tmp, sizeof(tmp), "%X", localtime(&t));//把time_t转化为字符串
	printf("当前时间为：\n	%s\n", tmp);
	return 0;
}
/*显示系统日期*/
int show_date()
{
	char tmp[20];
	time_t t = time(NULL);
	strftime(tmp, sizeof(tmp), "%Y/%m/%d", localtime(&t));//把time_t转化为字符串
	printf("当前日期为：\n	%s\n", tmp);
	return 0;
}
//判断path是文件还是路径
int PathIsDirectory(char *path)
{
	WIN32_FIND_DATA find_file;	
	FindFirstFile(path, &find_file);
	if (find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//当条件为真时，则为路径
		return 1;
	return 0;
}
//删除文件函数，name为指定的绝对路径或者当前目录下的文件名
int del_files(char * name)
{
	char tmp[100];
	strcpy(tmp, name + strlen(para[1]));//获取name中的文件名
	if(remove(name) == -1 && remove(tmp) == -1)//由于name可能时路径也可能是文件名，所以要同时删除
		printf("文件不存在!\n");
	else
		printf("删除成功!\n");
	return 0;
}
//把印文本函数，name为指定的绝对路径或者当前目录下的文件名
int print_text(char * name)
{
	
	char tmp[100];
	strcpy(tmp, name + strlen(para[1]));//当name为当前工作目录下的文件名时，获取文件名称
	FILE *fp = fopen(name, "r");
	FILE *fp2 = fopen(tmp, "r");
	//分别打开它们，其中不存在的一个目录下的文件则返回空。如果其一存在，则最终让fp指向该文件。
	if(fp == NULL)
	{
		if(fp2 == NULL)
		{
			printf("读取信息失败，文件不存在!\n");
			return 0;
		}
		else
			fp = fp2;
	}
	char  ch;
	ch = fgetc(fp);
	if(ch != NULL)
	{
		putchar(ch);/*逐个字符地从文件中读取并且显示出来*/
		while(!feof(fp))
			putchar(fgetc(fp));
	}
	printf("\n");
	fclose(fp);//关闭文件指针
	return 0;
}
/*
重命名文件，old为原文件名， New为新文件名
*/
int rename_file(char old[], char New[])
{
	if(-1 == rename(old, New))
		printf("重命名失败!请检查文件是否存在或新命名包含特殊字符.\n");
	else
		printf("重命名成功!\n");
	return 0;
}
//显示当前目录下的所有文件，等同于dir命令。
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
		while (FindNextFile(obj_handle, &find_file))//把找到的文件存入find_file中
		{
			FILETIME tmp;//文件时间结构体
			FileTimeToLocalFileTime(&find_file.ftCreationTime,  &tmp); 
			FileTimeToSystemTime(&tmp,  &st);//把文件时间转化为系统时间
			printf("%d/%d/%d\t", st.wYear, st.wMonth, st.wDay);//年月日
			printf("%d:%d:%2d\t", st.wHour, st.wMinute, st.wSecond);//时分秒

			if (find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//如果当前文件是文件夹，则显示时在其后面加上<dir>加以区分
				printf("<dir> ");
			printf("\t%s\n",find_file.cFileName);//打印文件名
		}
	}
	FindClose(obj_handle);//关闭文件句柄
	return 0;
}
//创建一个目录函数
int creat_dir(char name[])
{
	if(CreateDirectory(name, NULL) == NULL)
		printf("创建目录失败!请检查目录名称\n");
	else
		printf("创建成功！\n");
	return 0;
}
//删除文件夹函数,name为指定的路径的文件夹或当前目录下的文件夹
int del_dir(const char name[])
{
	char path1[100],path2[100];
	memset(path1, 0, sizeof(path1));//把path字符串后的剩余的空间置为NULL，否则删除失败
	strcpy(path1, name);
	memset(path2, 0, sizeof(path2));//同上
	strcpy(path2, name + strlen(para[1]));
	if(!PathIsDirectory(path1) && !PathIsDirectory(path2))//如果文件夹不存在，则返回0;
		return 0;
	SHFILEOPSTRUCT FileOp;//windows系统专为文件的操作的提供的一个API，有了它就可以简化我们的程序
	
	/*
		设置要删除的文件的路径
	*/
	if(PathIsDirectory(path2))
		FileOp.pFrom = path2;
	else
		FileOp.pFrom = path1;
	FileOp.fFlags = FOF_NOCONFIRMATION;
	FileOp.hNameMappings = NULL;
	FileOp.hwnd = NULL;
	FileOp.lpszProgressTitle = NULL;	
	FileOp.pTo = NULL;
	FileOp.wFunc = FO_DELETE;//删除
	return SHFileOperation(&FileOp) == 0;//执行操作
}
//改变工作路径
int change_path(char *path)
{
	memset(para, 0, sizeof(para));//把para[0]、para[1]字符串置为0
	strcat(path, "\\");
	strcpy(para[0], path);
	if(para[0][2] != '\\')//当路径为“D:、E:、F：”时，在它们的后面加上一个‘\’统一显示格式
	{
		for(int i = strlen(path); i > 2; i--)
			para[0][i] = para[0][i-1];
		para[0][2] = '\\';
	}
	strcpy(para[1], para[0]);//para[0]、para[1]具有相同的工作目录。
	return 0;
}

int show_current_tree(char * path, int n)
{
	HANDLE	obj_handle;
	WIN32_FIND_DATA find_file;			
	//获取当前目录
	char ch[100];
	strcpy(ch, path);
	strcat(path, "\\*.*");
	obj_handle = FindFirstFile(path, &find_file);//obj_handle初始化	
	if( obj_handle != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(obj_handle, &find_file))//把找到的文件存入find_file中
		{		
			if(find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(find_file.cFileName, "..") != 0)
			{
				for(int i = 0; i < n; i++)		
					printf(" ");
				printf("%s\n",find_file.cFileName);//打印文件名
				strcpy(path, ch);//还原路径
				strcat(path, "\\");
				strcat(path, find_file.cFileName);
				show_current_tree(path, n+4);//递规调用，相当于深度优先搜索。
			}
		}
		strcpy(path, ch);//还原路径
	}
	FindClose(obj_handle);//关闭文件句柄
	return 0;
}
//清屏函数
void clrscr(int x,int y) 
{ 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD c = {x, y};//设置清屏后光标返回的屏幕左上角坐标 
	BOOL bSuccess; 
	DWORD cCharsWritten; 
	CONSOLE_SCREEN_BUFFER_INFO csbi;//保存缓冲区信息 	
	
	DWORD dwConSize;//当前缓冲区可容纳的字符数 
	
	bSuccess = GetConsoleScreenBufferInfo(hConsole,&csbi);//获得缓冲区信息 
	dwConSize = (csbi.dwSize.X-x) * (csbi.dwSize.Y-24);//(缓冲区容纳字符数目)要清空的面积，X是列数减去6列，Y默认是25，减去
	//24等于1，x默认是80减去6等于74，因为光标定位在第0行第6列，所以就是
	//清空第0行的第7列开始到第0行的结尾
	//用空格填充缓冲区 	
	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, c, &cCharsWritten); 	
	
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);//获得缓冲区信息 	
	//填充缓冲区属性 
	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, c, &cCharsWritten); 	
	
	//光标返回屏幕左上角坐标 
	bSuccess = SetConsoleCursorPosition(hConsole, c); 
	
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
	printf("tree			显示树形结构\n");
	printf("print filename  \t打印文本文件内容\n");
	printf("del file/dir    \t删除指定文件明为filename的文件\n");
	printf("mkdir filename  \t创建一个名为filename的目录\n");
	printf("ren old new     \t重命名一个文件，old为旧文件名，new为新文件名\n");
	printf("string\t\t\t设置当前命令行的路径为string\n");
	printf("exit\t\t\t退出\n");
	return;
}
//命令解释器，in为输入的字符串
int explain(char *in)
{
	char tmp[100];
	memset(tmp, 0, sizeof(tmp));
	strcpy(tmp, para[0]);
	strcat(tmp, "\\");
	strcat(tmp, in);
	if(SetCurrentDirectory(in) || SetCurrentDirectory(tmp))//如果输入的字符串是路径则设置为当前路径
	{
		if(SetCurrentDirectory(tmp))
			strcpy(in, tmp);
		return 12;//12代表改变路径
	}
		
	for(int i = 0; i < strlen(in); i++)
		if(in[i] == ' ')	break;
	int j = i;		
	in[i] = 0;//把in中的空格替换为0
	for(i = 0; i < 12; i++)
		if(strcmp(in, cmd[i]) == 0)
			break;
	if(i == 12||(i <= 7 && in[j+1] != 0))//命令不存在或者是无参数指令后面存在参数，则输出命令不合法
		return -1;
	if(i <= 7)
		return i;

	strcpy(tmp, in + j + 1);//提取in中的一元参数（只有一个参数）
	
	if(i >= 8 && i <= 10)
	{	
		strcat(para[0], tmp);	
	}//如果只有一个参数的命令，则把tmp赋值给para[0]。否则继续分tmp分出两个参数
	else
	{
		for(int i = 0; i < strlen(tmp); i++)//原理同第一次替换
			if(tmp[i] == ' ')
				break;
		tmp[i] = 0;
		if(tmp[i+1] == 0)	return -1;
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
		//根据命令解释器的返回结果执行相对应的命令
		switch(choice)
		{
		case -1: printf("' %s '不是内部或外部命令，也不是可运行的程序\n或批处理文件。\n", in);break;
		case 0 : show_time();break; 
		case 1 : show_version();break;
		case 2 : show_date();break;
		case 3 : clrscr(0, 0);break;
		case 4 : show_directory();break;
		case 5 : help();break;
		case 6 : show_current_tree(para[0], 0);break;
		case 7 : return 0;
		case 8 : print_text(para[0]);break;	
		case 9 : if(del_dir(para[0]) == 0)	del_files(para[0]);break;//如果para[0]是文件夹，则执行删除文件夹函数，否则执行文件删除函数
		case 10 : creat_dir(para[0]);break;
		case 11 : rename_file(para[0], para[1]);break;
		case 12 : change_path(in);break;
		}//{"time", "version", "date", "cls", "dir", "help", "tree", "print", "del", "mkdir", "ren"};
		if(choice != 12)//如果没有改变路径，则每次都把当前工作目录下的以外的其它字符清除
		{
			memset(para[0] + n, 0, (100 - n) * sizeof(char));
			memset(para[1] + n, 0, (100 - n) * sizeof(char));
		}
	}
	return 0;
}
