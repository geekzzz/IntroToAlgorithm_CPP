// 快排

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>


using namespace std;

ivoid quicksorts(vector<int> &v, int l,int r)
{
    int i  = l,j = r, pivot = v[i];
    if(i < j)
    {
        while(i < j)
        {
            while(i < j && v[j] >= pivot)
                j--;
            if(i < j)
            {
                v[i] = v[j];
                i++;
            }
            
            while(i < j && v[i] < pivot)
                i++;
            if(i < j)
            {
                v[j] = v[i];
                j--;
            }
            
        }
        v[i] = pivot;
        quicksorts(v, l, i - 1);
        quicksorts(v, i + 1, r);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v {34,65,12,43,67,5,78,10,3,70 };
    //QuickSort(v, 0, (int)v.size() - 1);
    quicksorts(v, 0, (int)v.size() - 1);
    for(auto a : v)
        cout << a << " ";
    return 0;
}

