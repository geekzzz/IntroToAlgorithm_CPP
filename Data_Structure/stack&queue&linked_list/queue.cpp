//根据CLRS中算法编写,简单的数组实现队列
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define queue_max_size 1000

class queue
{
public:
    bool queue_empty();
    bool enqueue(int x);
    int dequeue();
    int head = 0;//top为0时表示栈为空
    int tail = 0;
    int queue[queue_max_size];
};

bool queue::queue_empty()
{
    if(head == tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue::enqueue(int x)
{
    queue[tail] = x;
    //尾索引加1，并自动折转
    if(tail == queue_max_size - 1)
    {
        tail = 0;
    }
    else
    {
        tail++;
    }
    return true;
}

int queue::dequeue()
{
    int x = queue[head];
    if(head == queue_max_size -1)
    {
        head = 0;
    }
    else
    {
        head++;
    }
    return x;
}

int  main(int argc,const char *argv[])
{
    queue s;
    bool z = s.queue_empty();
    cout << z << endl;
    z = s.enqueue(100);
    cout << z << endl;
    s.enqueue(1000);
    //cout << s.top << endl;
    s.enqueue(10000);
    int m = s.dequeue();
    //cout << s.top << endl;
    cout << m << endl;
    m = s.dequeue();
    cout << m << endl;
    m = s.dequeue();
    cout << m;
}


