//借鉴网上方法写的最坏时间为O（n）的选择算法,直接复制的网上版本，有详细注释
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

int Partition(int a[],int low,int high, int x)
{  //这里数组a是[low,high)的，注意右边界最多到a[high-1]，
    /*利用x将数组划分为2部分*/
    int i = low;
    high--;
    while (a[i]!= x) i++;
    swap(a[low], a[i]);  //将基准移到首位置
    while (low < high)
    {
        while (low < high&&a[high] >= x)
        {
            high--;
        }
        a[low] = a[high];
        while (low < high&&a[low] <= x)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = x;
    return low;
}
int randomized_select(int a[],int low,int high, int k){
    int i, j,x,q,n;
    n = high - low;                                //n为数组a[low...high]元素个数,注意右边最多取到a[high-1]
    if (n < 5)
    {      //元素小于5时候单独处理
        sort(a + low, a + high);
        return a[low +k-1];
    }
    for (i = 0; i <n/ 5; i++)
    {
        sort(a + low+i * 5, a + low+i * 5 + 5);   //对每组数据排序
        swap(a[low+i], a[low+i * 5 + 2]);        //中位数移到前面
    }
    x = randomized_select(a, low,low+n/5, n/10+1);          //寻找中位数的中位数、n/10+1非常重要，避免n<10时n/10==0此时会出现问题
    j = Partition(a, low, high, x);             //根据x将数组a划分为2部分，j为x所在数组下标
    q = j - low + 1;                           // q为小于或者等于x元素的个数
    if (q == k)
        return x;
    else if (q>k)
        return randomized_select(a, low, j + 1, k);
    else
        return randomized_select(a, j + 1, high, k - q);
}


int  main(int argc,const char *argv[])
{
    int  br[10] = {78,17,39,26,72,94,21,12,23,68};
    vector<float> aa;
    for(auto i = 0;i < 10;i++)
    {
        aa.push_back(br[i]);
    }
    int a = randomized_select(br, 1, 9, 4);
    cout << a<< endl;
}
