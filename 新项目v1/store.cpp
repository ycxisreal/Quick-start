#include <locale>
#include<iostream>
#include<fstream>
#include"resource.h"
#include"store.h"
void gamestore() 
{
    ofstream shan;
    shan.open("data/game.txt", ios::trunc);
    shan.close();
    for (int a = 0; a < n; a++)
    {
        ofstream cun;
        cun.open("data/game.txt", ios::app);
        cun << Game[a].getname() << " " << Game[a].getnum() <<" "<<Game[a].gettotal() << endl;
        cun.close();
    }
    ofstream sh;
    sh.open("data/gamepath.txt", ios::trunc);
    sh.close();
    for (int a = 0; a < n; a++)
    {
        ofstream cun;
        cun.open("data/gamepath.txt", ios::app);
        cun << Game[a].getpath() << endl;
        cun.close();
    }
    ofstream sha;
    sha.open("data/usingTime.txt", ios::trunc);
    sha.close();
    ofstream timewrite;
    timewrite.open("data/usingTime.txt", ios::app);
    timewrite << initialtime << endl;
    timewrite.close();

}
void ini()
{
    setlocale(LC_ALL, "chs");	// 设置字符编码环境
    ifstream cun;
    cun.open("data/game.txt", ios::in);
    string na;
    string pa;
    int num,tot;
    while (cun >> na && cun >> num && cun >> tot)
    {
        Game[n].setname(na);
        Game[n].setnum(num);
        Game[n].settotal(tot);
        n++;
    }
    cun.close();
    setlocale(LC_ALL, "chs");
    ifstream cun2;
    cun2.open("data/gamepath.txt", ios::in);
    int i = 0;
    string s;
    while (getline(cun2, s))
    {
        //Game[i].path= UTF8ToGB(s.c_str()).c_str();
        Game[i].path = s;
        i++;
    }
    cun2.close();
    ifstream cun1;
    cun1.open("data/web.txt", ios::in);
    string N;
    string P;
    int Num;
    while (cun1 >> N && cun1 >> Num && cun1 >> P)
    {
        Web[n1].setname(N);
        Web[n1].setnum(Num);
        Web[n1].setpath(P);
        n1++;
    }
    cun1.close();
    setlocale(LC_ALL, "chs");
    ifstream mcun;
    mcun.open("data/music.txt", ios::in);
    string mname, mpath;
    while (mcun >> mname && mcun >> mpath)
    {
        Music.name = mname;
        Music.path = mpath;
    }
    mcun.close();

    ifstream timestore;
    timestore.open("data/usingTime.txt", ios::in);
    time_t ti;
    while (timestore >> ti)
    {
        initialtime = ti;
    }
    timestore.close();
}
string UTF8ToGB(const char* str)
{
    string result;
    WCHAR* strSrc;
    LPSTR szRes;

    //获得临时变量的大小
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //获得临时变量的大小
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}
void webstore() {
    ofstream shan;
    shan.open("data/web.txt", ios::trunc);
    for (int a = 0; a < n1; a++)
    {
        ofstream cun;
        cun.open("data/web.txt", ios::app);
        cun << Web[a].getname() << " " << Web[a].getnum() <<" "<<Web[a].getpath()<< endl;
        cun.close();
    }
}
void mstore()
{
    ofstream shan;
    shan.open("data/music.txt", ios::trunc);
    ofstream cun;
    cun.open("data/music.txt", ios::app);
    cun << Music.name << " " << Music.path << endl;
    cun.close();
}