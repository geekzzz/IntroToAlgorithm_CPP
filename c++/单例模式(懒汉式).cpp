#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
#include <memory>
#include <Windows.h>
#include <mutex>
using namespace std;

//�ο���վhttps://www.cnblogs.com/Forever-Kenlen-Ja/p/7050300.html


//����ʽ����ʵ��,�̰߳�ȫ

/*
//��һ��ʵ�ַ�ʽ
class singleton
{
public:
singleton()
{
std::cout << "construct begin" << std::endl;
Sleep(500);
std::cout << "construct end" << std::endl;
}
void print()
{
std::lock_guard<std::mutex> lgd(s_mt);
std::cout << "print" << std::endl;
std::cout << s_num++ << std::endl;
}
static int s_num;
static std::mutex s_mt;
};

int singleton::s_num = 0;
std::mutex singleton::s_mt;

void thread_func()
{
static singleton st;
st.print();
}

int main()
{
std::vector<std::thread> vecThread;
for (auto i = 0; i < 8; i++)
{
vecThread.push_back(std::thread(thread_func));
}
for (auto i = 0; i < 8; i++)
{
vecThread[i].join();
}
//
system("pause");
return 0;
}
*/


//�ڶ���ʵ�ַ�ʽ

class Singleton {
public:
	static Singleton *instance()
	{
		return &m_instance;
	}
private:
	Singleton() { cout << "��������" << endl; }
	~Singleton() { cout << "��������" << endl; }
	Singleton(const Singleton&) {}
	Singleton& operator=(const Singleton&) {}
private:
	static Singleton m_instance;
};

Singleton Singleton::m_instance;

//Singleton.cpp  


void main()
{

}