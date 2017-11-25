// 找最大值（n次比较）、找最小值（n次比较）、同时找出最大最小值（3 * floor（n/2）次比较）
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;


int find_max(vector<int> a)
{
    int max = a[0];
    for(auto i = 1;i<a.size();i++ )
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int find_min(vector<int> a)
{
    int min = a[0];
    for(auto i = 1;i<a.size();i++ )
    {
        if(min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}


vector<int> find_min_and_max(vector<int> a)    //3*floor(n/2) 时间同时找出最大最小值
{
    vector<int> tmp(2,0);//tmp[0]存储min，tmp[1]存储max
    int i = 0;
    if(a.size()%2 == 0)
    {
        i = 2;//遍历数组循环偏移设为2
        if(a[0] > a[1])
        {
            tmp[0] = a[1];
            tmp[1] = a[0];
        }
        else
        {
            tmp[0] = a[0];
            tmp[1] = a[1];
        }
        
    }
    else
    {
        i = 1;//遍历数组循环偏移设为1
        tmp[0] = tmp[1] = a[0];
    }
    int max = a[0],min = a[0];
    for(auto j = i;j < a.size();j += 2)
    {
        int tmax,tmin;
        if(a[j] > a[j+1])
        {
            tmax = a[j];
            tmin = a[j+1];
        }
        else
        {
            tmax = a[j+1];
            tmin = a[j];
        }
        tmp[0] = tmp[0] < tmin ? tmp[0] : tmin;
        tmp[1] = tmp[1] > tmax ? tmp[1] : tmax;
    }
    return tmp;
}

int  main(int argc ,const char *argv[])
{
    vector<int> a {1,2,3,4,5,6,7,100,10,24,45,18,56,53,13,2424,454,-1,-100};
    vector<int> b = find_min_and_max(a);
    cout << b[0] << ":" << b[1] <<endl;
}

