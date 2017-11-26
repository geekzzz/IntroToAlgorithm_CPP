//直接寻址表实现，根据clrs,有问题暂时不能用
//


#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main() {    //引用的他人的，可以借鉴一下
    
    int num;
    int key;
    while (scanf("%d", &num) && num) {
        vector<int> v[13];
        while (num--) {
            scanf("%d", &key);
            int temp = key % 13;
            v[temp].push_back(key);
        }
        for (int i = 0; i < 13; ++i) {
            printf("%d%s", i, "#");
            if (v[i].empty()) {
                printf("NULL\n");
            } else {
                vector<int>::iterator it = v[i].begin();
                for (; it != v[i].end(); ++it) {
                    printf("%s%d", it == v[i].begin() ? "" : " ", *it);
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}



/*
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define max_table_size 1000
int m = 0;

int h(int k)
{
    return k % m;
}
int h2(int k)
{
    return 1 + k % (m-1);
}
//线性探测
int Linear_Probing(int k, int i)
{
    return (h(k) + i) % m;
}
//二次探测
int Quadratic_Probint(int k, int i)
{
    int c1 = 1, c2 = 3;
    return (h(k) + c1 * i + c2 * i * i) % m;
}
//双重探测
int Double_Probint(int k, int i)
{
    return (h(k) + i * h2(k)) % m;
}


class dirct_hash_table      //基本元素
{
public:
    dirct_hash_table(int a = 0,int b = 0) :key(a),element(b){};
    int key;      //关键字
    int element;  //记录的数据,没有使用链表实现，而直接使用了vector数据结构，简化实现
};

class hash_            //利用此class进行操作
{
public:
    hash_()
    {
        
    };
    vector<dirct_hash_table> table[max_table_size];
    dirct_hash_table search(dirct_hash_table k);
    void h_insert(dirct_hash_table x);
    void h_delete(dirct_hash_table x);
};

dirct_hash_table hash_::search(dirct_hash_table k)
{
    vector<dirct_hash_table> t = table[k.key];
    for(auto z = 0;z < t.size();z++)
    {
        if(t[z].element == k.element)
        {
            return t[z];
        }
    }
    return t[0];
}

void hash_::h_insert(dirct_hash_table x)
{
    //table[x.key] = x;
    table[x.key].push_back(x);
}

void hash_::h_delete(dirct_hash_table x)
{
    //table[x.key].
    vector<dirct_hash_table> t = table[x.key];
    for(auto z = 0;z < t.size();z++)
    {
        if(t[z].element == x.element)
        {
            t[z] = NULL;
        }
    }
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
    cout << x.key << endl;
    cout << x.element << endl;
    x = s.search(100);
    cout << x.key << endl;
    cout << x.element << endl;
    s.h_delete(d);
    x = s.search(100);
    cout << x.key << endl;
    cout << x.element << endl;
}
 */
