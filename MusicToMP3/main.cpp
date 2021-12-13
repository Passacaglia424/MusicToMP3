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
    //cout << "-请保持网易云程序开启，否则缓存文件夹可能会被删除-" << endl;
    user_name = GetCurrentName();
    /*起始绝对路径*/
    string source_dir = C + user_name + cloud_dir;
    /*目的绝对路径*/
    string dst_dir = "C:\\Users\\" + user_name + "\\Desktop\\ReverseToMp3";
    GetUCFiles(source_dir,files);
    cout << source_dir << '\n' << dst_dir << endl;
    /*文件夹创建失败*/
    if (_mkdir(dst_dir.c_str()) == -1) {
        cout << "-存在ReverseToMp3文件夹-" << endl;
    }

    /*主功能循环体*/
    for (auto it = files.begin(); it != files.end(); it++) {
        ifstream temp_file(source_dir+"\\"+* it, ios::in | ios::binary);
        char temp;

        /*文件打开失败*/
        if (!temp_file) {
            cout << "-错误：无法读取文件" + *it + ",尝试下一个-" << endl;
            continue;
        }

        string obj_name = dst_dir + "\\" + *it;
        obj_name = obj_name.substr(0, obj_name.length() - 2) + "mp3";
        ofstream obj_file(obj_name,ios::out | ios::binary);

        /*简单异或转码*/
        while (!temp_file.eof()) {
            temp_file.get(temp);
            temp = temp ^ 0xa3;
            obj_file.put(temp);
        }

        temp_file.close();
        obj_file.close();
        cout << "---已转换完"+*it << endl;
    }
    cout << "-转换完毕，请在桌面的ReverseToMp3文件夹下查看-" << endl;
    Sleep(5000);
    return 0;
}


