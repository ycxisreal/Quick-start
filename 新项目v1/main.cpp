#include<iostream>
#include<process.h>
#include<Windows.h>
#include <tchar.h>
#include"resource.h"
#include"game.h"
#include"store.h"
#include"web.h"
#include"music.h"
#include"record.h"
using namespace std;
game Game[60];
web Web[60];
music Music;
int n=0;
int n1 = 0;
time_t initialtime=0;
/*
* 开发时间：2022.4.13中午
* 2022.4.13晚，完成游戏与网页专区的大部分功能；
*2022.4.15  完成音乐部分
* 2022.4.15 完成绝大部分程序，已基本结尾。
*/
int main()
{
	//模板C:\\Program Files\\Microsoft Games\\Minesweeper\\Minesweeper.exe
	//ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\86156\\Desktop\\路易唐林only the brave.mp4"), NULL,NULL,SW_SHOWNORMAL);
	//ShellExecute(NULL, TEXT("open"), TEXT("https://www.bilibili.com/"), NULL, NULL, SW_SHOWNORMAL);
	/*cout << "\t\t欢迎~~~" << endl;
	
	for (int i = 1; i <= 5; i++)
	{
		cout << " . ";
		Sleep(300);
	}
	cout << endl;*/
	system("mode con cols=50 lines=25");//设置窗口大小
	system("cls");//清屏
	ini();
	if (initialtime == 0)
	{
		time_t mytime;
		time(&mytime);
		initialtime = mytime;
	}
	while (1)
	{
		system("color 07");
		system("cls");
		char choice;
		cout << "==================================" << endl;
		cout << "[1] 游戏专区" << endl;
		cout << "[2] 网页专区" << endl;
		cout << "[3] 听点音乐？" << endl;
		cout << "[4] 视频专区(未完成)" << endl;
		cout << "[5] 关于程序<<" << endl;
		cout << "[6] >>>>使用前必看-注意事项<<<<" << endl;
		cout << "[7] 统计信息" << endl;
		cout << "[0] 退出程序" << endl<<endl;
		cout << "[p] 嘿嘿。打赏作者" << endl;
		cout << "==================================" << endl;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case'1':
			gFrame();
			break;
		case'2':
			webFrame();
			break;
		case'3':
			musicFrame();
			break;
		case'4':
			system("pause");
			break;
		case '5':
			cout << "===============================" << endl;
			cout << "作者：杨春潇" << endl;
			cout <<"个人qq;1634770529"<<endl;
			cout << "获得灵感时间：2022.4.13中午" << endl;
			cout << "基本完成时间：2022.4.14" << endl;
			cout << "目前版本V.1.05" << endl;
			cout << "最近一次更新完成时间：2022.5.8晚" << endl;//待修改
			cout << "===============================" << endl;
			system("pause");
			break;
		case'6':
			notice();
			system("pause");
			break;
		case '7':
			record();
			break;
		case'p':
			ShellExecute(NULL, TEXT("open"), TEXT("data\\pay.png"), NULL, NULL, SW_SHOWNORMAL);
			cout << "******我爱死你啦******" << endl;
			system("pause");
			break;
		case'0':
			cout << ">>程序关闭啦<<" << endl;
			gamestore();
			webstore();
			return 0;
		default:
			break;
		}
	}
	//tst
	return 0;
}