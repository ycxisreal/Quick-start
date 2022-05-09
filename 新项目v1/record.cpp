#include<iostream>
#include"record.h"
#include"resource.h"
using namespace std;
void record()
{
	//calculate time
	time_t ti;
	time(&ti);
	time_t year=0, mouth=0, day=0, hour=0;
	time_t cha = ti - initialtime;
	year = cha / 31536000;
	cha -= year * 31536000;
	mouth = cha / 2592000;
	cha -= mouth * 2592000;
	day = cha / 86400;
	cha -= day * 86400;
	hour = cha / 3600;
	cout << "你已经使用本软件 ";
	if (year != 0)
		cout << year << " 年 ";
	if (mouth != 0)
		cout << mouth << " 月 ";
	if (day != 0)
		cout << day << " 天 ";
	if (hour != 0)
		cout << hour << " 小时 ";
	cout << "了。" << endl;
	if (n)
	{
		cout << "您的游戏数据如下：" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << Game[i] <<" 累积使用次数：" << Game[i].gettotal() << endl;
		}
	}
	system("pause");
}