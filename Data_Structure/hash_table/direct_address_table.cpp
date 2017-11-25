//直接寻址表实现，根据clrs
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define max_table_size 1000

class dirct_hash_table      //基本元素
{
public:
    dirct_hash_table(int a = 0,int b =0) :key(a),element(b) {};
    int key;      //关键字
    int element;  //记录的数据
};

class hash_            //利用此class进行操作
{
public:
    hash_()
    {
        dirct_hash_table *n = new dirct_hash_table();
        n->key = 0;
        n->element = 0;
        for(auto i = 0;i< max_table_size;i++)
        {
            table[i].key = n->key;
            table[i].element = n->element;
        }
    };
    dirct_hash_table table[max_table_size];
    int search(int k);
    void h_insert(dirct_hash_table x);
    void h_delete(dirct_hash_table x);
};

int hash_::search(int k)
{
    return table[k].element;
}

void hash_::h_insert(dirct_hash_table x)
{
    table[x.key] = x;
}

void hash_::h_delete(dirct_hash_table x)
{
    table[x.key] = NULL;
}

int  main(int argc,const char *argv[])
{
    hash_ s;
    dirct_hash_table d(10,1);
    s.h_insert(d);
    d.key = 100;
    d.element = 2;
    s.h_insert(d);
    auto x = s.search(10);
    cout << x << endl;
    x = s.search(100);
    cout << x << endl;
    s.h_delete(d);
    x = s.search(100);
    cout << x << endl;
}
