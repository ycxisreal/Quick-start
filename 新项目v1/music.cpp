#include"music.h"
#include<Windows.h>
#include<process.h>
void musicFrame()
{
	while (1)
	{
		system("cls");
		system("color 70");
		cout << "==========����ר��==========" << endl;
		if (Music.name != "void")
			cout << "< 0 > " << Music.name << endl;
		cout << "< 1 > �������������ҳ" << endl;
		if (Music.name == "void")
		{
			cout << "< 2 > ����ҵ����������" << endl;
		}
		cout << "< e > �˳�����ר��" << endl;
		string choice;
		getline(cin, choice);
		if (choice == "0" && Music.name != "void")
		{
			string b = Music.path;
			LPCSTR a = b.c_str();
			ShellExecute(NULL, TEXT("open"), a, NULL, NULL, SW_SHOWNORMAL);
		}
		else if (choice == "1")
		{
			char n;
			cout << "1.���������ֹ���" << endl;
			cout << "2.QQ���ֹ���" << endl;
			cout << "3.�ṷ���ֹ���" << endl;
			cout << "�������ѡ�" << endl;
			cin >> n;
			switch (n)
			{
			case '1':
				ShellExecute(NULL, TEXT("open"), TEXT("https://music.163.com/"), NULL, NULL, SW_SHOWNORMAL);
				break;
			case '2':
				ShellExecute(NULL, TEXT("open"), TEXT("https://y.qq.com/"), NULL, NULL, SW_SHOWNORMAL);
				break;
			case'3':
				ShellExecute(NULL, TEXT("open"), TEXT("https://www.kugou.com/"), NULL, NULL, SW_SHOWNORMAL);
				break;
			default:
				cout << "������Ч��ѡ�" << endl;
				break;
			}
		}
		else if (choice == "2" && Music.name == "void")
		{
			addmusic();
		}
		else if (choice == "e")
		{
			break;
		}else
		{
			cout << "�������ʵ�ѡ��." << endl;
		}
	}
	
}
void addmusic()
{
	flag:
	cout << "���������������" << endl;
	string sname;
	string spath;
	cin >> sname;
	cout << "�������·���� <ע�⣡>���·��Ҫд��˫б����ʽ����C:\\\\����������.exe" << endl;
	cin.ignore();
	getline(cin, spath);
	cout << "�Ƿ�������Ҫ�޸ģ�Y/N" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		Music.name = sname;
		Music.path = spath;
		//gamestore();
	}
	else if (choice == 'N' || choice == 'n')
	{
		goto flag;
	}
	else
	{
		cout << "�������ѡ��" << endl;
	}
}