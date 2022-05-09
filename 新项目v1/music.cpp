#include"music.h"
#include<Windows.h>
#include<process.h>
void musicFrame()
{
	while (1)
	{
		system("cls");
		system("color 70");
		cout << "==========音乐专区==========" << endl;
		if (Music.name != "void")
			cout << "< 0 > " << Music.name << endl;
		cout << "< 1 > 进入各大音乐网页" << endl;
		if (Music.name == "void")
		{
			cout << "< 2 > 添加我的音乐软件。" << endl;
		}
		cout << "< e > 退出音乐专区" << endl;
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
			cout << "1.网易云音乐官网" << endl;
			cout << "2.QQ音乐官网" << endl;
			cout << "3.酷狗音乐官网" << endl;
			cout << "输入你的选项：" << endl;
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
				cout << "输入有效的选项！" << endl;
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
			cout << "做出合适的选择." << endl;
		}
	}
	
}
void addmusic()
{
	flag:
	cout << "输入音乐软件名：" << endl;
	string sname;
	string spath;
	cin >> sname;
	cout << "输入软件路径： <注意！>软件路径要写成双斜杠形式，如C:\\\\网易云音乐.exe" << endl;
	cin.ignore();
	getline(cin, spath);
	cout << "是否无误不需要修改？Y/N" << endl;
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
		cout << "输入合适选择！" << endl;
	}
}