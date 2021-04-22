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
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> m;
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
        unordered_set<int> s;
        for (int i = 1; i <= n; ++i)
        {
            s.insert(getroot(i));
        }
        cout << s.size() - 1 << endl;
    }
    return 0;
}