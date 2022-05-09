#pragma once
#include<iostream>
#include<string>
#include<process.h>
#include<Windows.h>
using namespace std;
class game
{
private:
	string name;
	int num;
	int total_use;
public:
	string path;
	game():
		name("void"),path("void"), num(0),total_use(0) {}
	void setname(string a) { name = a; }
	void setpath(string a) { path = a; }
	void setnum(int a) { num = a; }
	void settotal(int a) { total_use = a; }
	void totalplus() { total_use++; }
	void cnum(int a) { num += a; }

	string getname() { return name; }
	int getnum() { return num; }
	string getpath() { return path; }
	int gettotal() { return total_use; }
	friend ostream& operator<<(ostream& out, game& a);
	void operator=(game a)
	{
		this->name = a.name;
		this->num = a.num;
		this->path = a.path;
		this->total_use = a.total_use;
	}
};
class web
{
private:
	string path;
	string name;
	int num;
public:
	web():
		path("void"),name("void"),num(0){}
	void setpath(string a) { path = a; }
	void setname(string a) { name = a; }
	void setnum(int a) { num = a; }
	void cnum(int a) { num += a; }
	string getpath() { return path; }
	string getname() { return name; }
	int getnum() { return num; }
	friend ostream& operator<<(ostream& out, web& a);
	void operator =(web a)
	{
		this->name = a.name;
		this->num = a.num;
		this->path = a.path;
	}
};
class music
{
public:
	string name;
	string path;
	music():
	name("void"),path("void") {}
};

void notice();
extern game Game[60];
extern web Web[60];
extern music Music;
extern int n;
extern int n1;
extern time_t initialtime;