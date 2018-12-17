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
//重载"="以使得 obj = "hello"能够成立
{
	if (str)
		delete[] str;
	if (s) {  //s不为NULL才会执行拷贝
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
		cout << "相等" << endl;
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
	s = "Good Luck,"; //等价于 s.operator=("Good Luck,");
	cout << s.c_str() << endl;
	// String s2 = "hello!";   //这条语句要是不注释掉就会出错
	s = "Shenzhou 8!"; //等价于 s.operator=("Shenzhou 8!");
	cout << s.c_str() << endl;

	String s2, s3;
	s3 = s2 = s;

	cout << s.c_str() << "  " << s2.c_str() << "  " << s3.c_str() << endl;

	String s4;
	s4 = s = s;//注意相同类检测到后，直接return this
	cout << s.c_str() << s4.c_str() << endl;

	system("pause");
	return 0;
}