#include"resource.h"
ostream& operator<<(ostream& out, game& a)
{
	out << " < "<< a.num << " >  " << a.name;
	return out;
}
ostream& operator<<(ostream& out, web& a)
{
	out << " < " << a.num << " >  网站名：" << a.name << endl;
	return out;
}
void notice()
{
	/*cout << "===========注意事项===========" << endl;
	cout << "1.游戏选项中添加 Steam中的游戏快捷方式时，其路径中游戏名后要加.url" << endl;
	cout << " 如：C:\\桌面\\游戏.url   否则可能出现没有反应的现象（只是steam游戏需要这样）" << endl << endl;
	cout << "2.关闭程序最好不要直接点右上角的×，建议输入0让程序退出。" << endl;
	cout << " 原因是可能添加游戏或网页并没有保存下来(目前已经稍微解决了此问题，但还是不建议直接点×关闭程序)" << endl << endl;
	cout << "3.如果之前用过程序的旧版本，并想将旧程序中保存的网页与软件转移到新程序上，" << endl;
	cout << " 那么可以将旧程序目录中的data文件夹粘贴替换掉新程序的data文件夹。" << endl << endl;
	cout << "==============================" << endl;*/
	cout << "===================注意事项===================" << endl;
	cout << "1.游戏选项中添加 Steam中的游戏快捷方式时" << endl;
	cout << "  其路径中游戏名后要加.url，如：C:\\\\桌面\\\\游戏.url" << endl;
	cout << "  否则可能出现无反应的现象（仅steam游戏需要这样）" << endl << endl;
	cout << "2.关闭程序最好不要直接点×，建议输入0让程序退出。" << endl;
	cout << "  原因是可能添加游戏或网页并没有保存下来" << endl;
	cout << "  目前已经稍微解决了此问题，但仍不建议点×关闭程序" << endl << endl;
	cout << "3.如果之前用过程序的旧版本" << endl;
	cout << "  并想将旧程序中保存的网页与软件转移到新程序上" << endl;
	cout << "  那么可以将旧程序目录中的data文件夹" << endl;
	cout << "  粘贴替换掉新程序的data文件夹。" << endl << endl;
	cout << "4.如果认为本程序挺好的话可以在桌面创建快捷方式" << endl;
	cout << "  开机自启方法：" << endl;
	cout << "  win+r并输入shell:startup,然后将快捷方式拖入即可" << endl;
	cout << "==============================================" << endl;
}