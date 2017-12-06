//动态规划算法
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
/*
 int max(int a ,int b)
 {
 int t = a>=b ? a:b;
 return t;
 }
 */
int cut_rod(int n)
{
    if(n == 0)
    {
        return 0;
    }
    int q = INT_MIN;
    for(int i = 1;i <= n;i++)  //注意！！！！！！！！！！！！！：一定要从1开始至<=n，否则函数中递归会出错
    {
        q = max(q,p[i] + cut_rod(n-i));
    }
    return q;
}

int  main(int argc,const char *argv[])
{
    cout << cut_rod(4);
}
