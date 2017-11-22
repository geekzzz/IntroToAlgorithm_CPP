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
    bool enqueues(int x);
    int dequeue();
    int head = 0;  //head指向队列头
    int tail = 0;  //tail指向队尾
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

bool queue::enqueues(int x)
{
    if(head == tail +1)
    {
        cout << "overflow  上溢出" << endl;
        return false;
    }
    else
    {
        queue[tail] = x;
        if(tail == queue_max_size - 1)
        {
            tail = 0;
        }
        else
        {
            tail += 1;
        }
        return true;
    }
}

int queue::dequeue()
{
    if(queue_empty())
    {
        cout << "overflow 下溢出" << endl;
        return 0;
    }
    else
    {
        int x = queue[head];
        if(head == queue_max_size - 1)
        {
            head = 0;
        }
        else
        {
            head += 1;
        }
        return x;
    }
    
}

int  main(int argc,const char *argv[])
{
    queue q;
    bool e = q.queue_empty();
    cout << e << endl;
    q.enqueues(100);
    e= q.queue_empty();
    q.enqueues(1000);
    int x = q.dequeue();
    cout << q.queue_empty() << endl;
    cout << x << endl;
    x = q.dequeue();
    cout << x << endl;
    cout <<q.queue_empty() << endl;
}
