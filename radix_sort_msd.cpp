// msd(最高位优先)方法实现基数排序

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>


using namespace std;


int getdigit(int x,int d)
{
    int a[] = {1, 1, 10};     //因为待排数据最大数据也只是两位数，所以在此只需要到十位就满足
    return ((x / a[d]) % 10);    //确定桶号
}

void  PrintArr(int ar[],int n)
{
    for(int i = 0; i < n; ++i)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void radix_sort_msd(int arr[],int begin,int end,int d)
{
    const int radix = 10;
    int count[radix], i, j;
    for(i = 0; i < radix; ++i)
    {
        count[i] = 0;
    }
    int *bucket = (int *) malloc((end-begin+1) * sizeof(int));
    for(i = begin;i <= end; ++i)
    {
        count[getdigit(arr[i], d)]++;
    }
    for(i = 1; i < radix; ++i)
    {
        count[i] = count[i] + count[i-1];
    }
    for(i = end;i >= begin; --i)
    {
        j = getdigit(arr[i], d);      //求出关键码的第d位的数字， 例如：576的第3位是5
        bucket[count[j]-1] = arr[i];   //放入对应的桶中，count[j]-1是第j个桶的右边界索引
        --count[j];                    //第j个桶放下一个元素的位置(右边界索引+1)
    }
    for(i = begin, j = 0;i <= end; ++i, ++j)
    {
        arr[i] = bucket[j];
    }
    free(bucket);
    //对各桶中数据进行再排序
    for(i = 0;i < radix; i++)
    {
        int p1 = begin + count[i];         //第i个桶的左边界
        int p2 = begin + count[i+1]-1;     //第i个桶的右边界
        if(p1 < p2 && d > 1)
        {
            radix_sort_msd(arr, p1, p2, d-1);  //对第i个桶递归调用，进行基数排序，数位降 1
        }
    }
}

int  main()
{
    int  ar[] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89};
    int len = sizeof(ar)/sizeof(int);
    PrintArr(ar, len);
    radix_sort_msd(ar, 0, len-1, 2);
    PrintArr(ar, len);
    return 0;
}


