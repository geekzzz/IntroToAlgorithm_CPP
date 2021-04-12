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

bool isprime(int n)
{
    if (n <= 1)
        return false;
    float sq = sqrt(1.0f * n);
    for (int i = 2; i <= sq; ++i)
    {
        if (n %i == 0)
        {
            return false;
        }
    }
    return true;
}


void dfs(int n, int k, vector<int> v, vector<int> num, int pos)
{
    if (num.size() == k)
    {
        int sum = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            sum += num[i];
        }
        if (isprime(sum))
        {
            res++;
        }
        return;
    }
    if (pos >= v.size())
    {
        return;
    }
    dfs(n, k, v, num, pos + 1);
    num.push_back(v[pos]);
    dfs(n, k, v, num, pos + 1);
    //dfs()
}




int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        vector<int> num;
        dfs(n, k, v, num, 0);
        cout << res << endl;
    }
}
