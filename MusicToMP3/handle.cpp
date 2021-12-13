#pragma once
#include<windows.h>
#include<string>
#include<vector>
#include<io.h>
#include<cstring>
using namespace std;

char* wchar2char(const wchar_t* wchar){
    char* m_char;
    int len = WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), NULL, 0, NULL, NULL);
    m_char = new char[len + 1];
    WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), m_char, len, NULL, NULL);
    m_char[len] = '\0';
    return m_char;
}

string GetCurrentName() {
    DWORD M_size = MAX_PATH;
    TCHAR* pszName = new TCHAR[M_size];
    GetUserName(pszName, &M_size);
    return string(wchar2char(pszName));
}

void GetUCFiles(string path, vector<string>& files){
    //�ļ����
    long hFile = 0;
    /*�����ļ���Ϣ��*/
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1){
        do{
            /*ѡȡ����Ŀ¼���ļ�*/
            if (!(fileinfo.attrib & _A_SUBDIR)){
                /*�����*.uc��ʽ*/
                if (!strcmp(fileinfo.name+strlen(fileinfo.name)-3,".uc")) {
                    files.push_back(fileinfo.name);
                } 
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}
