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
* ����ʱ�䣺2022.4.13����
* 2022.4.13�������Ϸ����ҳר���Ĵ󲿷ֹ��ܣ�
*2022.4.15  ������ֲ���
* 2022.4.15 ��ɾ��󲿷ֳ����ѻ�����β��
*/
int main()
{
	//ģ��C:\\Program Files\\Microsoft Games\\Minesweeper\\Minesweeper.exe
	//ShellExecute(NULL, TEXT("open"), TEXT("C:\\Users\\86156\\Desktop\\·������only the brave.mp4"), NULL,NULL,SW_SHOWNORMAL);
	//ShellExecute(NULL, TEXT("open"), TEXT("https://www.bilibili.com/"), NULL, NULL, SW_SHOWNORMAL);
	/*cout << "\t\t��ӭ~~~" << endl;
	
	for (int i = 1; i <= 5; i++)
	{
		cout << " . ";
		Sleep(300);
	}
	cout << endl;*/
	system("mode con cols=50 lines=25");//���ô��ڴ�С
	system("cls");//����
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
		cout << "[1] ��Ϸר��" << endl;
		cout << "[2] ��ҳר��" << endl;
		cout << "[3] �������֣�" << endl;
		cout << "[4] ��Ƶר��(δ���)" << endl;
		cout << "[5] ���ڳ���<<" << endl;
		cout << "[6] >>>>ʹ��ǰ�ؿ�-ע������<<<<" << endl;
		cout << "[7] ͳ����Ϣ" << endl;
		cout << "[0] �˳�����" << endl<<endl;
		cout << "[p] �ٺ١���������" << endl;
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
			cout << "���ߣ����" << endl;
			cout <<"����qq;1634770529"<<endl;
			cout << "������ʱ�䣺2022.4.13����" << endl;
			cout << "�������ʱ�䣺2022.4.14" << endl;
			cout << "Ŀǰ�汾V.1.05" << endl;
			cout << "���һ�θ������ʱ�䣺2022.5.8��" << endl;//���޸�
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
			cout << "******�Ұ�������******" << endl;
			system("pause");
			break;
		case'0':
			cout << ">>����ر���<<" << endl;
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