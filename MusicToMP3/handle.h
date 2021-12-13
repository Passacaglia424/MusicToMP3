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
func: wchar_t�ַ�ת��Ϊchar�ַ���
param: @wchar:��ת�Ŀ��ַ�����
return: ת����ַ�����
*/
char* wchar2char(const wchar_t* wchar);

/*
func: ��ȡ�����ó�����û����ƣ����û����������ʧ�ܡ�
no param
return: �û����ַ�����
*/
string GetCurrentName();

/*
func: ���ָ��Ŀ¼�µ�����.uc��׺���ļ��������ַ���������·����,���ܵݹ������ļ��С�
param: @path:·�� @files:�����ַ�����ɵ�vector����
no return
*/
void GetUCFiles(string path, vector<string>& files);
