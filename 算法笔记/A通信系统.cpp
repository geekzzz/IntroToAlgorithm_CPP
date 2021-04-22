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

vector<int> father;

int getroot(int x)
{
    int f = x;
    while (f != father[f])
    {
        f = father[f];
    }
    return f;
}


int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        father.resize(n + 1);
        for (int i = 0; i < father.size(); ++i)
        {
            father[i] = i;
        }
        int a, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            int faa = getroot(a);
            int fab = getroot(b);
            if (faa != fab)
            {
                father[fab] = faa;
            }
        }
        int root = getroot(1);
        bool flag = true;
        for (int i = 2; i <= n; ++i)
        {
            if (getroot(i) != root)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}