#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
#include <memory>
using namespace std;

//参考网站https://blog.csdn.net/cjbct/article/details/79266057

/*

//饿汉式单例实现，采用内部类GC

class singleton
{
private:
singleton()
{
cout << "单例创建" << endl;
}
singleton(singleton &s) {}
singleton& operator=(const singleton& s) {}
~singleton()
{
cout << "单例销毁" << endl;
}
static singleton *instance;//单例对象

//单例自动销毁堆区instance 实例的第一种方式

public:
class GC
{
public:
GC() {};
~GC()
{
if (instance != nullptr)
{
delete instance;
instance = nullptr;
}
}
};
static GC gc;

//单例自动销毁堆区instance 实例的第一种方式


static singleton* getInstance()
{
if (instance == NULL)
instance = new singleton();
return instance;
}
};

singleton *singleton::instance = new singleton();
singleton::GC singleton::gc;
int  main()
{
singleton *s = singleton::getInstance();
singleton *ss = singleton::getInstance();
cout << s << endl << ss << endl;

system("pause");
return 0;
}
*/

//饿汉式单例实现，采用智能指针


class singleton
{
private:
	singleton()
	{
		cout << "单例创建" << endl;
	}
	singleton(singleton& s) {}
	singleton & operator =(const singleton & s) {}
	~singleton()
	{
		cout << "单例销毁" << endl;
	}
	static void deleter(singleton * s)
	{
		delete s;
		s = nullptr;
		cout << "通过删除器销毁单例" << endl;
	}
	static shared_ptr<singleton> instance;
public:
	static shared_ptr<singleton> getInstance()
	{
		return instance;
	}
};


shared_ptr<singleton> singleton::instance(new singleton, singleton::deleter);
int main()
{
	shared_ptr<singleton> s = singleton::getInstance();
	shared_ptr<singleton> ss = singleton::getInstance();
	shared_ptr<singleton> sss = singleton::getInstance();
	cout << s << endl << ss << endl << sss << endl;


	system("pause");
	return 0;
}