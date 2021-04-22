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

struct node
{
    int w;
    vector<int> child;
};

vector<node> tree(110);

void dfs(int nowsum, int s, int rootid, vector<int> way)
{
    if (nowsum > s)
    {
        return;
    }
    else if (nowsum == s)
    {
        if (tree[way.back()].child.size() != 0)
            return;
        for (int i = 0; i < way.size(); ++i)
        {
            if (i == 0)
                cout << tree[way[i]].w ;
            else
                cout << " " << tree[way[i]].w;
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < tree[rootid].child.size(); ++i)
        {
            way.push_back(tree[rootid].child[i]);
            dfs(nowsum + tree[tree[rootid].child[i]].w, s, tree[rootid].child[i], way);
            way.pop_back();
        }
    }
}
bool cmp(const int& a, const int& b)
{
    return tree[a].w > tree[b].w;
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> tree[i].w;
    }
    int id, num;
    for (int i = 0; i < m; ++i)
    {
        cin >> id >> num;
        int c;
        for (int j = 0; j < num; ++j)
        {
            cin >> c;
            tree[id].child.push_back(c);
        }
        sort(tree[id].child.begin(), tree[id].child.end(),cmp);
    }
    vector<int> way;
    way.push_back(0);
    dfs(tree[0].w, s, 0,way);
    system("pause");
    return 0;
}