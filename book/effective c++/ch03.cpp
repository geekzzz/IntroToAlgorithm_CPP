/*
1.const ���γ�Ա����
#include<iostream>
using namespace std;
int main(){
int a1=3;   ///non-const data
const int a2=a1;    ///const data

int * a3 = &a1;   ///non-const data,non-const pointer
const int * a4 = &a1;   ///const data,non-const pointer
int * const a5 = &a1;   ///non-const data,const pointer
int const * const a6 = &a1;   ///const data,const pointer
const int * const a7 = &a1;   ///const data,const pointer

return 0;
}
const����ָ�����ʱ��

����(1)ֻ��һ��const�����constλ��*��࣬��ʾָ����ָ�����ǳ���������ͨ���������޸ĸ����ݣ�ָ�뱾���Ǳ���������ָ���������ڴ浥Ԫ��

  ����(2)ֻ��һ��const�����constλ��*�Ҳ࣬��ʾָ�뱾���ǳ���������ָ�������ڴ��ַ��ָ����ָ�����ݿ���ͨ���������޸ġ�

	����(3)����const��*���Ҹ�һ������ʾָ���ָ����ָ���ݶ������޸ġ�

*/

/*

2.const���κ�������

�������ݹ����Ĳ����ں����ڲ����Ըı䣬���������α���ʱ������һ����
  void testModifyConst(const int _x) {
  _x=5;������///�������
  }

*/


/*
3.const���γ�Ա����

(1)const���εĳ�Ա���������޸��κεĳ�Ա����(mutable���εı�������)

(2)const��Ա�������ܵ��÷�onst��Ա��������Ϊ��const��Ա�������Ի��޸ĳ�Ա����

#include <iostream>
using namespace std;
class Point{
public :
Point(int _x):x(_x){}

void testConstFunction(int _x) const{

///������const��Ա�����У������޸��κ����Ա����
x=_x;

///����const��Ա�������ܵ��÷�onst��Ա��������Ϊ��const��Ա�������Ի��޸ĳ�Ա����
modify_x(_x);
}

void modify_x(int _x){
x=_x;
}

int x;
};
*/

/*
4.const���κ�������ֵ

(1)ָ�봫��

�������const data,non-const pointer������ֵҲ���븳��const data,non-const pointer����Ϊָ��ָ��������ǳ��������޸ġ�

const int * mallocA(){  ///const data,non-const pointer
int *a=new int(2);
return a;
}

int main()
{
const int *a = mallocA();
///int *b = mallocA();  ///�������
return 0;
}

(2)ֵ����

�����������ֵ���á�ֵ���ݷ�ʽ�������ں�����ѷ���ֵ���Ƶ��ⲿ��ʱ�Ĵ洢��Ԫ�У���const ����û���κμ�ֵ�����ԣ�����ֵ������˵����constû��̫�����塣

���ԣ�

������Ҫ�Ѻ���int GetInt(void) д��const int GetInt(void)��
  ������Ҫ�Ѻ���A GetA(void) д��const A GetA(void)������A Ϊ�û��Զ�����������͡�

*/