#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void merge(int s[] ,int p, int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int *L=new int[n1+1];
    int *R=new int[n2+1];
    for(i=0;i<n1;i++)
        L[i]=s[i+p];
    for(j=0;j<n2;j++)
        R[j]=s[j+q+1];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
            s[k]=L[i++];
        else
            s[k]=R[j++];
    }
}

void Merge_sort(int s[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        Merge_sort(s,p,q);
        Merge_sort(s,q+1,r);
        merge(s,p,q,r);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //    vector<int> zz ={5,2,4,6,1,3};
    //    insertSort(zz);
    int a[10] = {5,6,10,2,1,4,7,2,6,11};
    Merge_sort(a, 0, 9);
    for(auto i = 0;i<10;i++)
    {
        cout << a[i];
    }
    return 0;
}

