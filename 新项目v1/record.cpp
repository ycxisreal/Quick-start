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
	cout << "���Ѿ�ʹ�ñ���� ";
	if (year != 0)
		cout << year << " �� ";
	if (mouth != 0)
		cout << mouth << " �� ";
	if (day != 0)
		cout << day << " �� ";
	if (hour != 0)
		cout << hour << " Сʱ ";
	cout << "�ˡ�" << endl;
	if (n)
	{
		cout << "������Ϸ�������£�" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << Game[i] <<" �ۻ�ʹ�ô�����" << Game[i].gettotal() << endl;
		}
	}
	system("pause");
}