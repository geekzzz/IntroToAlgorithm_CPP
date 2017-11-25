// 快排

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>


using namespace std;

int partition(int a[],int p,int r)
{
    int x = a[r];
    int i = p - 1;
    for(auto j = p;j < r;j++)
    {
        if(a[j] < x)
        {
            i = i + 1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i + 1],a[r]);
    return i + 1 ;
}


void quick_sort(int a[],int p,int r)
{
    if(p < r)
    {
        int q = partition(a, p, r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {1,53,63,26,62,5,757,85,86,97,12,32,43,45,4553,654,76,75,46,47};
    int r = sizeof(a)/sizeof(int);
    //cout << a[r - 1];
    quick_sort(a, 0, r -1 );
    for(auto i = 0;i< r;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

