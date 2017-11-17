// 桶排序
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>

using namespace std;

void bucket_sort(vector<float> a) //算法导论中，桶排序数据都为[0,1)区间上的小数
{
    list<float> b[10];
    vector<float> tt;
    for(auto i = 0;i< a.size();i++)
    {
        int t = floor(a[i] * 10);
        //cout << t;
        b[t].push_back(a[i]);
    }
    for(auto i = 0;i < 10;i++)
    {
        b[i].sort();
        list<float> tl = b[i];
        auto x = tl.size();
        for(auto j = 0;j<x;j++)
        {
            tt.push_back(tl.front());
            tl.pop_front();
        }
    }
    /*
    a.clear();
    for(auto i = 0;i < tt.size();i++)
    {
        a.push_back(tt[i]);
    }
     */
    for(auto i = 0;i < tt.size();i++)
    {
        cout << tt[i] << ":" ;
    }
}



int  main(int argc,const char *argv[])
{
    float  br[10] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    vector<float> aa;
    for(auto i = 0;i < 10;i++)
    {
        aa.push_back(br[i]);
    }
    bucket_sort(aa);
}
