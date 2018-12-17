#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


class String {
private:
	char * str;
public:
	String() :str(NULL) { }
	const char * c_str() const { return str; };
	String & operator = (const char* s);
	String & operator = (const String & s);
	~String();
};
String & String::operator = (const char * s)
//����"="��ʹ�� obj = "hello"�ܹ�����
{
	if (str)
		delete[] str;
	if (s) {  //s��ΪNULL�Ż�ִ�п���
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
		str = NULL;
	return *this;
}
String & String::operator = (const String & s)
{
	if (this == &s)
	{
		cout << "���" << endl;
		return *this;
	}
	delete[]str;
	str = nullptr;

	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
	return *this;
}
String::~String()
{
	if (str)
		delete[] str;
};
int main()
{
	String s;
	s = "Good Luck,"; //�ȼ��� s.operator=("Good Luck,");
	cout << s.c_str() << endl;
	// String s2 = "hello!";   //�������Ҫ�ǲ�ע�͵��ͻ����
	s = "Shenzhou 8!"; //�ȼ��� s.operator=("Shenzhou 8!");
	cout << s.c_str() << endl;

	String s2, s3;
	s3 = s2 = s;

	cout << s.c_str() << "  " << s2.c_str() << "  " << s3.c_str() << endl;

	String s4;
	s4 = s = s;//ע����ͬ���⵽��ֱ��return this
	cout << s.c_str() << s4.c_str() << endl;

	system("pause");
	return 0;
}