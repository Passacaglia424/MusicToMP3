#pragma once
#include<string>
using namespace std;

typedef struct _mp3_struct {
	char ID[3];
	char Ver;
	char Revision;
	char Flag;
	char Size[4];
	
}MP3;

/*
func: wchar_t字符转换为char字符。
param: @wchar:待转的宽字符数组
return: 转完的字符数组
*/
char* wchar2char(const wchar_t* wchar);

/*
func: 获取启动该程序的用户名称，非用户启动程序会失败。
no param
return: 用户名字符串。
*/
string GetCurrentName();

/*
func: 获得指定目录下的所有.uc后缀的文件的名称字符串，不含路径名,不能递归获得子文件夹。
param: @path:路径 @files:名称字符串组成的vector容器
no return
*/
void GetUCFiles(string path, vector<string>& files);
