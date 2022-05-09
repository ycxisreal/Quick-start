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
		cout<< "=============网页=============" << endl;
		for (int i = 0; i < n1; i++)
		{
			cout << Web[i];
		}
		cout << "==============================" << endl;
		cout << " q  添加收藏网页" << endl;
		cout << " e  退出网页选项" << endl;
		cout << " d  删除网页" << endl;

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
				cout << "做出合适的选择." << endl;
			}
		}
	}
}
void addweb()
{
flag:
	cout << "请输入网站名称：[输入e退出]" << endl;
	string webname, webpath;
	cin >> webname;
	if (webname == "e")
	{
		return;
	}
	cout << "请输入网址：" << endl;
	cin.ignore();
	getline(cin, webpath);
	cout << "是否无误不需要修改？Y/N" << endl;
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
		cout << "输入合适选择！" << endl;
	}
}
void delweb()
{
	cout << "请选择要删除的网站序号：" << endl;
	string choice;
	cin >> choice;
	for (int i = 0; i < n1; i++)
	{
		//寻找游戏，找到后执行删除操作并退出循环。
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