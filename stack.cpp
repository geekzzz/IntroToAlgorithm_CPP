//根据CLRS中算法编写,简单的数组实现栈
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define stack_max_size 1000

class stack
{
public:
    bool stack_empty();
    bool push(int x);
    int pop();
    int top = 0;  //top为0时表示栈为空
    int stack[stack_max_size];
};

bool stack::stack_empty()
{
    if(top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::push(int x)
{
    top += 1;
    stack[top] = x;
    return true;
}

int stack::pop()
{
    if(top == 0)
    {
        cout << "underflow";
        return 0;
    }
    else
    {
        top -= 1;
        return stack[top + 1];
    }
}

int  main(int argc,const char *argv[])
{
    stack s;
    bool z = s.stack_empty();
    cout << z << endl;
    z = s.push(100);
    cout << z << endl;
    s.push(1000);
    //cout << s.top << endl;
    s.push(10000);
    int m = s.pop();
    //cout << s.top << endl;
    cout << m << endl;
    m = s.pop();
    cout << m << endl;
    m = s.pop();
    cout << m;
}
