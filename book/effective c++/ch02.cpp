/*
define ����û�н���Ǻű�symbol table
�ó����������const double as = 1.63;�����������������
����ָ�룺	
	const char * const aaa  = "dadada";
������ҪΪ����

classר��������
class a
{
	static const int n = 5; //const ���� ���n��class �ڣ�static ��ֻ֤��һ�ݣ�����class��ʵ��ȡֵ��һ��
};
*/

/*
enum ���Դ���ints��ʹ��

class player
{
	enum{ numt = 5 };
	int score[numt];
};

*/


/*
��Ҫ��define����Ҫ���õĺ�����
���� #define CALL_FUN(a, b) f((a)>(b) ? (a):(b))

CALL_FUN(++A,B);//a�ۼ�����
CALL_FUN(++A,B +10);//a�ۼ�һ��
���������template inline

template<typename T>
inline void call_fun(const T & a.const T & b)
{
	f(a>b?a:b);
}

*/