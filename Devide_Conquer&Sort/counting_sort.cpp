// 计数排序

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>


using namespace std;

void counting_sort(vector<int> a,int k)
{
    //vector<int> *b = new vector<int>;
    //b->resize(k,0);
    vector<int> b(a.size(),0);          //临时存放排序后数组
    vector<int> c(k,0);                    //c[0,,,k]记录0到k的每个元素的个数
    for(auto i = 0;i<a.size();i++)
    {
        c[a[i]] += 1;
    }
    for(auto i = 1;i<c.size();i++)
    {
        c[i] += c[i-1];
    }
    
    for(auto i = a.size();i >= 1;--i)
    {
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    for(auto j = 0;j<b.size();j++)
    {
        cout << b[j] << ":" ;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {1,53,63,26,62,5,757,85,86,97,12,32,43,45,4553,654,76,75,46,47};
    int k = sizeof(a)/sizeof(int);
    vector<int> z;
    z.push_back(0);
    for(auto i = 0;i < k;++i)               //初始化输入vector z
    {
        z.push_back(a[i]);
    }
    int max = z[0];                         //找出数组中最大值k
    for(auto i = 0;i<z.size();++i)
    {
        if(z[i] > max)
        {
            max = z[i];
        }
    }
    counting_sort(z, max);
    return 0;
}

