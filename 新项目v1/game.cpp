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
		cout << "=============游戏=============" << endl;
		if (n != 0) {
			for (int i = 0; i < n; i++)
			{
				cout << Game[i] << endl;
			}
		}
		cout << "==============================" << endl;
		cout << " q  添加游戏" << endl;
		cout << " e  退出游戏选择界面" << endl;
		cout << " d  删除已添加的游戏" << endl;
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
				cout << "做出合适的选择." << endl;
			}
			
		}

	}
	
}
void addgame()
{
	flag:
	cout << "输入游戏名：[输入e退出]" << endl;
	string gamename;
	string gamepath;
	cin >> gamename;
	if (gamename == "e") 
	{
		return;
	}
	cout << "输入游戏路径： <注意！>游戏路径要写成双斜杠形式，如C:\\\\game.exe" << endl;
	cin.ignore();
	getline(cin, gamepath);
	cout << "是否无误不需要修改？Y/N" << endl;
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
		cout << "输入合适选择！" << endl;
	}

}
void delgame()
{
	cout << "请选择要删除的游戏序号：" << endl;
	string choice;
	cin >> choice;
	for (int i = 0; i < n; i++)
	{
		//寻找游戏，找到后执行删除操作并退出循环。
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
