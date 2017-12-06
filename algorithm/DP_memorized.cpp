//动态规划算法,使用memorized记录的方法
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>

using namespace std;

int p[11] = {0,1,5,8,9,10,17,17,20,24,30};

int memorized_cut_rod_aux(int *p,int n,int *r)
{
    if(r[n] >= 0)
    {
        return r[n];
    }
    int q;
    if(n == 0)
    {
        q = 0;
    }
    else
    {
        q = INT_MIN;
    }
    for(auto i = 1;i<= n;i++)
    {
        q = max(q,p[i] + memorized_cut_rod_aux(p, n - i, r));
    }
    r[n] = q;
    return q;
}


int memorized_cut_rod(int p[],int n)
{
    int *r = (int*)malloc(sizeof(int)*n);
    for(auto i = 0;i<=n;i++)
    {
        r[i] = INT_MIN;
    }
    return memorized_cut_rod_aux(p, n, r);
}



int  main(int argc,const char *argv[])
{
    cout << memorized_cut_rod(p,4);
}
