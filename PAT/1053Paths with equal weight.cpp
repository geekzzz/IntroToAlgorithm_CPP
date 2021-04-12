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

void dfs()
{

}


int main()
{
    int n,m,s;
    cin >> n >> m >> s;
    for(int i = 0;i <n;++i)
    {
        cin >> tree[i].w;
    }
    int id, num;
    for(int i = 0;i < m;++i)
    {
        cin >> id >> num;
        int c;
        for(int j = 0;j <num;++j)
        {
            cin >> c;
            tree[id].child.push_back(c);
        }
        sort(tree[id].child.begin(),tree[id].child.end());
    }
}