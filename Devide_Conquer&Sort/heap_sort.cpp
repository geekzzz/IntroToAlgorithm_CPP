// 堆算法

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>


using namespace std;


void max_heap(int a[],int i,int heap_size)
{
    int l = 2 * i;
    int r = (2 * i) + 1;
    int largest;
    if(l <= heap_size && a[l] > a[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(r <= heap_size && a[r] > a[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(a[i],a[largest]);
        max_heap(a, largest, heap_size);
    }
}

void build_max_heap(int a[],int heap_size)
{
    for(auto i = floor(heap_size/2);i >= 1;--i)
    {
        max_heap(a, i, heap_size);
    }
}

void heap(int a[],int heap_size)
{
    build_max_heap(a, heap_size);
    for(auto i = heap_size;i >= 1;i--)
    {
        swap(a[1],a[i]);
        max_heap(a, 1, i-1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int heap_size = 10;        //堆元素存储在数组中的个数
    int a[] {0,12,42,52,11,3,5,6,98,100,11};
    /*
     for(auto i = 1;i <= heap_size;++i)
     {
     a[i] = heap_size-i;
     }
     */
    
    cout << "zzz"<< endl;
    for(auto j = 1;j<=heap_size;++j)
    {
        cout << a[j] << ":";
    }
    cout << endl;
    build_max_heap(a, heap_size);
    //heap(a,heap_size);
    
    cout << "堆内数据顺序"<< endl;
    for(auto j = 1;j<=heap_size;++j)
    {
        cout << a[j] << ":";
    }
    cout << endl;
    heap(a, heap_size);
    cout << "排序完成"<< endl;
    for(auto j = 1;j<=heap_size;++j)
    {
        cout << a[j] << ":";
    }
    return 0;
}

