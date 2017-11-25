//  期望为线性时间的选择算法  从数组中选择第i小的元素
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <list>
#include <ctime>
#include <stdlib.h>
using namespace std;

//#define random(x) (rand()%x)
int partition(int a[],int p,int r);

int Random(int low ,int high)     //产生[low,high] 区间的随机数
{
    /*
     (rand()%(up-low+1)) + low - 1    (low,up)
     (rand()%(up-low)) + low       [low,up)
     (rand()%(up-low))+ low + 1      (low,up]
     (rand()%(up-low+1)) + low      [low,up]
     */
    srand((unsigned)time(NULL));
    int r = rand()%(high - low) + low;
    return r;
}
int randomized_partition(int a[],int p, int r)
{
    int i = Random(p, r);
    swap(a[r],a[i]);
    return partition(a, p, r);
}

int partition(int a[],int p,int r) //运用快排思想，返回的整数q将数组分割为两部分，前半部分都小于a[q],后面的都大于a[q]
{
    int x = a[r];
    int i = p - 1;
    for(auto j = p;j < r;++j)
    {
        if(a[j] <= x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

int randomized_select(int a[],int p,int r,int i)//a 数组，p，r  数组中的区间[p,r],i 随机选择的第i小的元素
{
    if(p == r)
    {
        return a[p];
    }
    //int q = Random(p,r);
    //swap(a[r],a[q]);
    int q = partition(a, p, r);
    int k = q - p +1;
    if(i == k)
    {
        return a[q];
    }
    else if(i < k)
    {
        return randomized_select(a, p, q-1, i);
    }
    else
    {
        return randomized_select(a, q+1, r, k);
    }
}


int  main(int argc,const char *argv[])
{
    int  br[10] = {78,17,39,26,72,94,21,12,23,68};
    vector<float> aa;
    for(auto i = 0;i < 10;i++)
    {
        aa.push_back(br[i]);
    }
    int a = randomized_select(br, 1, 9, 1);
    cout << a<< endl;
}
