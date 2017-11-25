#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void find_max_crossing_subarray(int a[],int re[],int low,int mid,int high)
{
    int leftsum ,rightsum = INT_MIN;
    int left = mid;
    int right = mid + 1;
    int sum = 0;
    for(int i = mid;i>=low;--i)
    {
        sum += a[i];
        if(sum > leftsum)
        {
            leftsum = sum;
        }
        left = i;
    }
    sum = 0;
    for(int i = mid + 1;i<=high;++i)
    {
        sum += a[i];
        if(sum > rightsum)
        {
            rightsum = sum;
        }
        right = i;
    }
    re[0] = left;
    re[1] = right;
    re[2] = leftsum + rightsum;
}

void find_max_subarray(int a[],int r1[],int low,int high)
{
    //int return1[3];//返回值
    //int r1[3] 保存返回的 low high sum（最大值）
    int l[3];//保存返回的 llow lhigh lsum（最大值） 分治左边最大
    int r[3];//保存返回的 llow lhigh lsum（最大值） 分治右边最大
    int c[3];//保存返回的 clow chigh csum（最大值） 分治交叉最大
    if(high == low)
    {
        r1[0] = low;
        r1[1] = high;
        r1[2] = a[low];
    }
    else
    {
        int mid = (low + high)/2;
        find_max_subarray(a, l, low, mid);
        find_max_subarray(a, r, mid+1, high);
        find_max_crossing_subarray(a, c, low, mid, high);
        if(l[2]>=r[2] && l[2]>=c[2])
        {
            r1[0] = l[0];
            r1[1] = l[1];
            r1[2] = l[2];
        }
        else if(r[2]>=l[2] && r[2]>=c[2])
        {
            r1[0] = r[0];
            r1[1] = r[1];
            r1[2] = r[2];
        }
        else
        {
            r1[0] = c[0];
            r1[1] = c[1];
            r1[2] = c[2];
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //    vector<int> zz ={5,2,4,6,1,3};
    //    insertSort(zz);
    //    int a[10] = {5,6,10,2,1,4,7,2,6,11};
    //    Merge_sort(a, 0, 9);
    //    for(auto i = 0;i<10;i++)
    //    {
    //        cout << a[i];
    //    }
    int a[20] = {5,-6,10,2,1,-4,7,2,-6,11,-23,16,5,7,2,14,6,-3,4,2};
    for(auto i = 0;i<20;i++)
    {
        cout << a[i] << ":" ;
    }
    cout<< "zzzzz"<< endl;
    int r1[3] = {0};
    find_max_subarray(a, r1, 0, 19);
    cout << r1[0] <<":"<< r1[1]<<":" << r1[2];//测试，输出10，19，53，代表最大子数组为a[10]至a[19],和为53
    return 0;
}

