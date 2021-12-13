#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<windows.h>
#include<direct.h>
#include"handle.h"

using namespace std;
string C = "C:\\Users\\";
string user_name;
string cloud_dir="\\AppData\\Local\\Netease\\CloudMusic\\Cache\\Cache";
vector<string>files;

int main() {
    //cout << "-�뱣�������Ƴ����������򻺴��ļ��п��ܻᱻɾ��-" << endl;
    user_name = GetCurrentName();
    /*��ʼ����·��*/
    string source_dir = C + user_name + cloud_dir;
    /*Ŀ�ľ���·��*/
    string dst_dir = "C:\\Users\\" + user_name + "\\Desktop\\ReverseToMp3";
    GetUCFiles(source_dir,files);
    cout << source_dir << '\n' << dst_dir << endl;
    /*�ļ��д���ʧ��*/
    if (_mkdir(dst_dir.c_str()) == -1) {
        cout << "-����ReverseToMp3�ļ���-" << endl;
    }

    /*������ѭ����*/
    for (auto it = files.begin(); it != files.end(); it++) {
        ifstream temp_file(source_dir+"\\"+* it, ios::in | ios::binary);
        char temp;

        /*�ļ���ʧ��*/
        if (!temp_file) {
            cout << "-�����޷���ȡ�ļ�" + *it + ",������һ��-" << endl;
            continue;
        }

        string obj_name = dst_dir + "\\" + *it;
        obj_name = obj_name.substr(0, obj_name.length() - 2) + "mp3";
        ofstream obj_file(obj_name,ios::out | ios::binary);

        /*�����ת��*/
        while (!temp_file.eof()) {
            temp_file.get(temp);
            temp = temp ^ 0xa3;
            obj_file.put(temp);
        }

        temp_file.close();
        obj_file.close();
        cout << "---��ת����"+*it << endl;
    }
    cout << "-ת����ϣ����������ReverseToMp3�ļ����²鿴-" << endl;
    Sleep(5000);
    return 0;
}


