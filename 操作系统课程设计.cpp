#include<stdio.h>
#include<windows.h>
#include "conio.h"
#include<string>
#include<time.h>
/*�����еĸ��������window��dos�������ƻ�����ͬ��*/
char cmd[][20] = {"time", "version", "date", "cls", "dir", "help", "tree", "exit", "print", "del", "mkdir", "ren"};

/*Ĭ�ϵ�·��ΪE:\*/
char para[][100] = {"E:\\", "E:\\"};

/*��ʾ�����г���İ汾*/
int show_version()
{
	printf("The latest CX version [�汾 8.8.88888](C)\n��Ȩ��������� 2000 - 3000.\n");
	return 0;
}
/*��ʾϵͳ��ʱ��*/
int show_time()
{
	char tmp[20];
	time_t t = time(NULL);
	strftime(tmp, sizeof(tmp), "%X", localtime(&t));//��time_tת��Ϊ�ַ���
	printf("��ǰʱ��Ϊ��\n	%s\n", tmp);
	return 0;
}
/*��ʾϵͳ����*/
int show_date()
{
	char tmp[20];
	time_t t = time(NULL);
	strftime(tmp, sizeof(tmp), "%Y/%m/%d", localtime(&t));//��time_tת��Ϊ�ַ���
	printf("��ǰ����Ϊ��\n	%s\n", tmp);
	return 0;
}
//�ж�path���ļ�����·��
int PathIsDirectory(char *path)
{
	WIN32_FIND_DATA find_file;	
	FindFirstFile(path, &find_file);
	if (find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//������Ϊ��ʱ����Ϊ·��
		return 1;
	return 0;
}
//ɾ���ļ�������nameΪָ���ľ���·�����ߵ�ǰĿ¼�µ��ļ���
int del_files(char * name)
{
	char tmp[100];
	strcpy(tmp, name + strlen(para[1]));//��ȡname�е��ļ���
	if(remove(name) == -1 && remove(tmp) == -1)//����name����ʱ·��Ҳ�������ļ���������Ҫͬʱɾ��
		printf("�ļ�������!\n");
	else
		printf("ɾ���ɹ�!\n");
	return 0;
}
//��ӡ�ı�������nameΪָ���ľ���·�����ߵ�ǰĿ¼�µ��ļ���
int print_text(char * name)
{
	
	char tmp[100];
	strcpy(tmp, name + strlen(para[1]));//��nameΪ��ǰ����Ŀ¼�µ��ļ���ʱ����ȡ�ļ�����
	FILE *fp = fopen(name, "r");
	FILE *fp2 = fopen(tmp, "r");
	//�ֱ�����ǣ����в����ڵ�һ��Ŀ¼�µ��ļ��򷵻ؿա������һ���ڣ���������fpָ����ļ���
	if(fp == NULL)
	{
		if(fp2 == NULL)
		{
			printf("��ȡ��Ϣʧ�ܣ��ļ�������!\n");
			return 0;
		}
		else
			fp = fp2;
	}
	char  ch;
	ch = fgetc(fp);
	if(ch != NULL)
	{
		putchar(ch);/*����ַ��ش��ļ��ж�ȡ������ʾ����*/
		while(!feof(fp))
			putchar(fgetc(fp));
	}
	printf("\n");
	fclose(fp);//�ر��ļ�ָ��
	return 0;
}
/*
�������ļ���oldΪԭ�ļ����� NewΪ���ļ���
*/
int rename_file(char old[], char New[])
{
	if(-1 == rename(old, New))
		printf("������ʧ��!�����ļ��Ƿ���ڻ����������������ַ�.\n");
	else
		printf("�������ɹ�!\n");
	return 0;
}
//��ʾ��ǰĿ¼�µ������ļ�����ͬ��dir���
int show_directory()
{
	HANDLE	obj_handle;
	WIN32_FIND_DATA find_file;			
	SYSTEMTIME st;//����ϵͳʱ��
	//��ȡ��ǰĿ¼
	strcat(para[0], "\\*.*");
	
	obj_handle = FindFirstFile(para[0], &find_file);//obj_handle��ʼ��
	
	if( obj_handle != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(obj_handle, &find_file))//���ҵ����ļ�����find_file��
		{
			FILETIME tmp;//�ļ�ʱ��ṹ��
			FileTimeToLocalFileTime(&find_file.ftCreationTime,  &tmp); 
			FileTimeToSystemTime(&tmp,  &st);//���ļ�ʱ��ת��Ϊϵͳʱ��
			printf("%d/%d/%d\t", st.wYear, st.wMonth, st.wDay);//������
			printf("%d:%d:%2d\t", st.wHour, st.wMinute, st.wSecond);//ʱ����

			if (find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//�����ǰ�ļ����ļ��У�����ʾʱ����������<dir>��������
				printf("<dir> ");
			printf("\t%s\n",find_file.cFileName);//��ӡ�ļ���
		}
	}
	FindClose(obj_handle);//�ر��ļ����
	return 0;
}
//����һ��Ŀ¼����
int creat_dir(char name[])
{
	if(CreateDirectory(name, NULL) == NULL)
		printf("����Ŀ¼ʧ��!����Ŀ¼����\n");
	else
		printf("�����ɹ���\n");
	return 0;
}
//ɾ���ļ��к���,nameΪָ����·�����ļ��л�ǰĿ¼�µ��ļ���
int del_dir(const char name[])
{
	char path1[100],path2[100];
	memset(path1, 0, sizeof(path1));//��path�ַ������ʣ��Ŀռ���ΪNULL������ɾ��ʧ��
	strcpy(path1, name);
	memset(path2, 0, sizeof(path2));//ͬ��
	strcpy(path2, name + strlen(para[1]));
	if(!PathIsDirectory(path1) && !PathIsDirectory(path2))//����ļ��в����ڣ��򷵻�0;
		return 0;
	SHFILEOPSTRUCT FileOp;//windowsϵͳרΪ�ļ��Ĳ������ṩ��һ��API���������Ϳ��Լ����ǵĳ���
	
	/*
		����Ҫɾ�����ļ���·��
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
	FileOp.wFunc = FO_DELETE;//ɾ��
	return SHFileOperation(&FileOp) == 0;//ִ�в���
}
//�ı乤��·��
int change_path(char *path)
{
	memset(para, 0, sizeof(para));//��para[0]��para[1]�ַ�����Ϊ0
	strcat(path, "\\");
	strcpy(para[0], path);
	if(para[0][2] != '\\')//��·��Ϊ��D:��E:��F����ʱ�������ǵĺ������һ����\��ͳһ��ʾ��ʽ
	{
		for(int i = strlen(path); i > 2; i--)
			para[0][i] = para[0][i-1];
		para[0][2] = '\\';
	}
	strcpy(para[1], para[0]);//para[0]��para[1]������ͬ�Ĺ���Ŀ¼��
	return 0;
}

int show_current_tree(char * path, int n)
{
	HANDLE	obj_handle;
	WIN32_FIND_DATA find_file;			
	//��ȡ��ǰĿ¼
	char ch[100];
	strcpy(ch, path);
	strcat(path, "\\*.*");
	obj_handle = FindFirstFile(path, &find_file);//obj_handle��ʼ��	
	if( obj_handle != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(obj_handle, &find_file))//���ҵ����ļ�����find_file��
		{		
			if(find_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(find_file.cFileName, "..") != 0)
			{
				for(int i = 0; i < n; i++)		
					printf(" ");
				printf("%s\n",find_file.cFileName);//��ӡ�ļ���
				strcpy(path, ch);//��ԭ·��
				strcat(path, "\\");
				strcat(path, find_file.cFileName);
				show_current_tree(path, n+4);//�ݹ���ã��൱���������������
			}
		}
		strcpy(path, ch);//��ԭ·��
	}
	FindClose(obj_handle);//�ر��ļ����
	return 0;
}
//��������
void clrscr(int x,int y) 
{ 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD c = {x, y};//�����������귵�ص���Ļ���Ͻ����� 
	BOOL bSuccess; 
	DWORD cCharsWritten; 
	CONSOLE_SCREEN_BUFFER_INFO csbi;//���滺������Ϣ 	
	
	DWORD dwConSize;//��ǰ�����������ɵ��ַ��� 
	
	bSuccess = GetConsoleScreenBufferInfo(hConsole,&csbi);//��û�������Ϣ 
	dwConSize = (csbi.dwSize.X-x) * (csbi.dwSize.Y-24);//(�����������ַ���Ŀ)Ҫ��յ������X��������ȥ6�У�YĬ����25����ȥ
	//24����1��xĬ����80��ȥ6����74����Ϊ��궨λ�ڵ�0�е�6�У����Ծ���
	//��յ�0�еĵ�7�п�ʼ����0�еĽ�β
	//�ÿո���仺���� 	
	bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, c, &cCharsWritten); 	
	
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);//��û�������Ϣ 	
	//��仺�������� 
	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, c, &cCharsWritten); 	
	
	//��귵����Ļ���Ͻ����� 
	bSuccess = SetConsoleCursorPosition(hConsole, c); 
	
	return; 
}
void help()
{
	printf("\t      \t*************�����д�ȫ****************\n");//{"time", "version", "date", "cls", "dir", "help", "print", "del", "mkdir", "ren"};
	printf("time			��ʾʱ��\n");
	printf("date			��ʾ����\n");
	printf("version			��ʾ�汾\n");
	printf("help			������Ϣ\n");
	printf("dir			��ʾ��ǰĿ¼�������ļ�\n");
	printf("tree			��ʾ���νṹ\n");
	printf("print filename  \t��ӡ�ı��ļ�����\n");
	printf("del file/dir    \tɾ��ָ���ļ���Ϊfilename���ļ�\n");
	printf("mkdir filename  \t����һ����Ϊfilename��Ŀ¼\n");
	printf("ren old new     \t������һ���ļ���oldΪ���ļ�����newΪ���ļ���\n");
	printf("string\t\t\t���õ�ǰ�����е�·��Ϊstring\n");
	printf("exit\t\t\t�˳�\n");
	return;
}
//�����������inΪ������ַ���
int explain(char *in)
{
	char tmp[100];
	memset(tmp, 0, sizeof(tmp));
	strcpy(tmp, para[0]);
	strcat(tmp, "\\");
	strcat(tmp, in);
	if(SetCurrentDirectory(in) || SetCurrentDirectory(tmp))//���������ַ�����·��������Ϊ��ǰ·��
	{
		if(SetCurrentDirectory(tmp))
			strcpy(in, tmp);
		return 12;//12����ı�·��
	}
		
	for(int i = 0; i < strlen(in); i++)
		if(in[i] == ' ')	break;
	int j = i;		
	in[i] = 0;//��in�еĿո��滻Ϊ0
	for(i = 0; i < 12; i++)
		if(strcmp(in, cmd[i]) == 0)
			break;
	if(i == 12||(i <= 7 && in[j+1] != 0))//������ڻ������޲���ָ�������ڲ��������������Ϸ�
		return -1;
	if(i <= 7)
		return i;

	strcpy(tmp, in + j + 1);//��ȡin�е�һԪ������ֻ��һ��������
	
	if(i >= 8 && i <= 10)
	{	
		strcat(para[0], tmp);	
	}//���ֻ��һ��������������tmp��ֵ��para[0]�����������tmp�ֳ���������
	else
	{
		for(int i = 0; i < strlen(tmp); i++)//ԭ��ͬ��һ���滻
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
		//��������������ķ��ؽ��ִ�����Ӧ������
		switch(choice)
		{
		case -1: printf("' %s '�����ڲ����ⲿ���Ҳ���ǿ����еĳ���\n���������ļ���\n", in);break;
		case 0 : show_time();break; 
		case 1 : show_version();break;
		case 2 : show_date();break;
		case 3 : clrscr(0, 0);break;
		case 4 : show_directory();break;
		case 5 : help();break;
		case 6 : show_current_tree(para[0], 0);break;
		case 7 : return 0;
		case 8 : print_text(para[0]);break;	
		case 9 : if(del_dir(para[0]) == 0)	del_files(para[0]);break;//���para[0]���ļ��У���ִ��ɾ���ļ��к���������ִ���ļ�ɾ������
		case 10 : creat_dir(para[0]);break;
		case 11 : rename_file(para[0], para[1]);break;
		case 12 : change_path(in);break;
		}//{"time", "version", "date", "cls", "dir", "help", "tree", "print", "del", "mkdir", "ren"};
		if(choice != 12)//���û�иı�·������ÿ�ζ��ѵ�ǰ����Ŀ¼�µ�����������ַ����
		{
			memset(para[0] + n, 0, (100 - n) * sizeof(char));
			memset(para[1] + n, 0, (100 - n) * sizeof(char));
		}
	}
	return 0;
}