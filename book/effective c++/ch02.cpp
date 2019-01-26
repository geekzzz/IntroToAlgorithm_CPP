/*
define 可能没有进入记号表symbol table
用常量替代，如const double as = 1.63;包括两种特殊情况：
常量指针：	
	const char * const aaa  = "dadada";
两个都要为常量

class专属常量：
class a
{
	static const int n = 5; //const 限制 这个n在class 内，static 保证只有一份，所有class的实例取值都一样
};
*/

/*
enum 可以代替ints被使用

class player
{
	enum{ numt = 5 };
	int score[numt];
};

*/


/*
不要用define定义要调用的函数：
例如 #define CALL_FUN(a, b) f((a)>(b) ? (a):(b))

CALL_FUN(++A,B);//a累加两次
CALL_FUN(++A,B +10);//a累加一次
解决方法用template inline

template<typename T>
inline void call_fun(const T & a.const T & b)
{
	f(a>b?a:b);
}

*/