/////////////////////////////////////////dfs解法//////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <climits>
#include <unordered_set>

using namespace std;

int res = 0;
void dfs( int n,int stacksize,int outsize,int insize )
{
    if (outsize == n)
    {
        res++;
        return;
    }
    if (stacksize > 0)
    {
        dfs(n, stacksize - 1, outsize + 1,insize);//出栈
    }
    if (insize > 0)
    {
        dfs(n, stacksize + 1, outsize,insize - 1);//进栈
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        res = 0;
        stack<int> s;
        vector<int> vin(n);
        vector<int> vout(0);
        dfs( n,0,0,n);
        cout << res << endl;
    }
}
///////////////////////////////dfs解法//////////////////////////////////////


//////////////////////////////dp解法/////////////////////////////////
https://blog.csdn.net/tham_/article/details/49471871