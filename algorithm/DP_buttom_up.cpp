//动态规划算法,buttom up 方法
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

int buttom_up_cut_rod(int *p,int n)
{
    int *r =(int*)malloc(sizeof(int)*n);
    r[0] = 0;
    for(int j = 1;j<= n;j++)
    {
        int q = INT_MIN;
        for(int i = 1;i <= j; i++)
        {
            q = max(q,p[i]+buttom_up_cut_rod(p, n - i));
        }
        r[j] = q;
    }
    return r[n];
}



int  main(int argc,const char *argv[])
{
    cout << buttom_up_cut_rod(p,4);
}
