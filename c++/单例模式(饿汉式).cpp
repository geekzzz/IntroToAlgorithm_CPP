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

//�ο���վhttps://blog.csdn.net/cjbct/article/details/79266057

/*

//����ʽ����ʵ�֣������ڲ���GC

class singleton
{
private:
singleton()
{
cout << "��������" << endl;
}
singleton(singleton &s) {}
singleton& operator=(const singleton& s) {}
~singleton()
{
cout << "��������" << endl;
}
static singleton *instance;//��������

//�����Զ����ٶ���instance ʵ���ĵ�һ�ַ�ʽ

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

//�����Զ����ٶ���instance ʵ���ĵ�һ�ַ�ʽ


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

//����ʽ����ʵ�֣���������ָ��


class singleton
{
private:
	singleton()
	{
		cout << "��������" << endl;
	}
	singleton(singleton& s) {}
	singleton & operator =(const singleton & s) {}
	~singleton()
	{
		cout << "��������" << endl;
	}
	static void deleter(singleton * s)
	{
		delete s;
		s = nullptr;
		cout << "ͨ��ɾ�������ٵ���" << endl;
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