#include"game.h"
#include"resource.h"
#include"store.h"
#include<string>
#include<Windows.h>
#include<process.h>
#include<atlstr.h>
#include<iostream>
#include <algorithm>
void gFrame()
{
	while (1)
	{
		sort(Game, Game + n,cmp);
		for (int i = 0; i < n; i++)
		{
			Game[i].setnum(i + 1);
		}
		system("cls");
		system("color 70");
		cout << "=============��Ϸ=============" << endl;
		if (n != 0) {
			for (int i = 0; i < n; i++)
			{
				cout << Game[i] << endl;
			}
		}
		cout << "==============================" << endl;
		cout << " q  �����Ϸ" << endl;
		cout << " e  �˳���Ϸѡ�����" << endl;
		cout << " d  ɾ������ӵ���Ϸ" << endl;
		string choice;
		getline(cin, choice);
		if (choice == "q"||choice=="Q")
		{
			addgame();
		}
		else if (choice == "e"||choice=="E")
		{
			break;
		}
		else if (choice == "d"||choice=="D")
		{
			delgame();
		}else
		{
			if (n != 0) {

				for (int i = 0; i < n; i++)
				{
					
					if (to_string(Game[i].getnum()) == choice)
					{
						string b = Game[i].getpath();
						LPCSTR a = b.c_str();
						ShellExecute(NULL, TEXT("open"), a, NULL, NULL, SW_SHOWNORMAL);
						Game[i].totalplus();
						gamestore();
						break;
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
void addgame()
{
	flag:
	cout << "������Ϸ����[����e�˳�]" << endl;
	string gamename;
	string gamepath;
	cin >> gamename;
	if (gamename == "e") 
	{
		return;
	}
	cout << "������Ϸ·���� <ע�⣡>��Ϸ·��Ҫд��˫б����ʽ����C:\\\\game.exe" << endl;
	cin.ignore();
	getline(cin, gamepath);
	cout << "�Ƿ�������Ҫ�޸ģ�Y/N" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		Game[n].setname(gamename);
		Game[n].setpath(gamepath);
		Game[n].setnum(n + 1);
		n++;
		gamestore();
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
void delgame()
{
	cout << "��ѡ��Ҫɾ������Ϸ��ţ�" << endl;
	string choice;
	cin >> choice;
	for (int i = 0; i < n; i++)
	{
		//Ѱ����Ϸ���ҵ���ִ��ɾ���������˳�ѭ����
		if (to_string(Game[i].getnum()) == choice)
		{
			for (int j = i; j < n-1; j++)
			{
				Game[j + 1].cnum(-1);
				Game[j] = Game[j + 1];
			}

			Game[n - 1].setname("void");
			Game[n - 1].setnum(0);
			Game[n - 1].setpath("void");
			Game[n - 1].settotal(0);
			n--;
			break;
		}
	}
	gamestore();
}
bool cmp(game a, game b)
{
	return a.gettotal() > b.gettotal();
}
