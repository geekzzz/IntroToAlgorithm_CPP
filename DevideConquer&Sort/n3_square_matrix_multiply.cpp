// n^3 效率的 nxn 矩阵乘法

#include <iostream>
#include <vector>
#include <limits.h>



using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> a,vector<vector<int>> b)
{
    vector<vector<int>> c(3,vector<int>(3));
    cout<<a.size() << endl;
    cout << a[0].size() << endl;
    for(auto i = 0;i < a.size();i++)
    {
        for(auto j = 0; j < a[0].size();j++)
        {
            c[i][j] = 0;
            for(auto k = 0; k < a[0].size();k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return c;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> b = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> c = matrix_multiply(a, b);
    for(auto i = 0;i<c.size();i++)
    {
        for(auto j = 0;j<c[0].size();j++)
        {
            cout << c[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}

