#include"web.h"
#include<iostream>
#include<process.h>
#include"store.h"
void webFrame()
{
	while (1)
	{
		system("cls");
		system("color 70");
		cout<< "=============��ҳ=============" << endl;
		for (int i = 0; i < n1; i++)
		{
			cout << Web[i];
		}
		cout << "==============================" << endl;
		cout << " q  ����ղ���ҳ" << endl;
		cout << " e  �˳���ҳѡ��" << endl;
		cout << " d  ɾ����ҳ" << endl;

		string choice;
		getline(cin, choice);
		if (choice == "q")
		{
			addweb();
		}
		else if (choice == "e")
		{
			break;
		}
		else if (choice == "d")
		{
			delweb();
		}else
		{
			if (n1 != 0) {

				for (int i = 0; i < n1; i++)
				{

					if (to_string(Web[i].getnum()) == choice)
					{
						string b = Web[i].getpath();
						LPCSTR a = b.c_str();
						ShellExecute(NULL, TEXT("open"), a, NULL, NULL, SW_SHOWNORMAL);
					}

				}
			}
			else
			{
				cout << "�������ʵ�ѡ��." << endl;
			}
		}
	}
}
void addweb()
{
flag:
	cout << "��������վ���ƣ�[����e�˳�]" << endl;
	string webname, webpath;
	cin >> webname;
	if (webname == "e")
	{
		return;
	}
	cout << "��������ַ��" << endl;
	cin.ignore();
	getline(cin, webpath);
	cout << "�Ƿ�������Ҫ�޸ģ�Y/N" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		Web[n1].setname(webname);
		Web[n1].setpath(webpath);
		Web[n1].setnum(n1 + 1);
		n1++;
		webstore();
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
void delweb()
{
	cout << "��ѡ��Ҫɾ������վ��ţ�" << endl;
	string choice;
	cin >> choice;
	for (int i = 0; i < n1; i++)
	{
		//Ѱ����Ϸ���ҵ���ִ��ɾ���������˳�ѭ����
		if (to_string(Web[i].getnum()) == choice)
		{
			for (int j = i; j < n1 - 1; j++)
			{
				Web[j + 1].cnum(-1);
				Web[j] = Web[j + 1];
			}
			Web[n1 - 1].setname("void");
			Web[n1 - 1].setnum(0);
			Web[n1 - 1].setpath("void");
			n1--;
			break;
		}
	}
	webstore();
}