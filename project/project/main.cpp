//动态规划算法,记录信息的方法
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
int s[11];
int r[11];

int extended_buttom_up_cut_rod(int *p,int n)
{
    r[0] = 0;
    for(int j = 1;j<= n;j++)
    {
        int q = INT_MIN;
        for(int i = 1;i <= j; i++)
        {
            if(q < p[i] + r[j-i])
            {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}

void print_cut_rod(int n)
{
    while(n > 0)
    {
        cout << s[n] << endl;
        n = n -s [n];
    }
}

int  main(int argc,const char *argv[])
{
	cout << "1" << endl;
    cout << extended_buttom_up_cut_rod(p,7) << endl;
    print_cut_rod(7);
}
