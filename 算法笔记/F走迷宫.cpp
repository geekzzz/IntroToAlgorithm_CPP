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
    node(int x_, int y_) { x = x_; y = y_; };
    int x;
    int y;
};

vector<int> XX{ 0,-1,0,1 };
vector<int> YY{ -1,0,1,0 };
vector<queue<node>> resways;

bool check(int x, int y, vector<vector<int>>& inq, vector<vector<int>>& v)
{

    if (x <= 0 || x > inq.size() || y <= 0 || y > inq[0].size())
    {
        return false;
    }
    if (inq[x][y] == 1 || v[x][y] == 0)
    {
        return false;
    }
    /*if (v[x][y] == 0)
        return false;*/
    return true;
}


void DFS(int x, int y, queue<node> way, vector<vector<int>>& v, vector<vector<int>> inq, int endx, int endy)
{
    way.push(node(x, y));
    if (x == endx && y == endy)
    {
        resways.push_back(way);
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        auto nextx = x + XX[i];
        auto nexty = y + YY[i];
        if (check(nextx, nexty, inq, v))
        {
            inq[nextx][nexty] = 1;
            DFS(nextx, nexty, way, v, inq, endx, endy);
            inq[nextx][nexty] = 0;
        }
    }
}


int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        resways.clear();
        vector<vector<int>> v(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> inq(m + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> v[i][j];
            }
        }
        int beginx, beginy, endx, endy;
        cin >> beginx >> beginy;
        cin >> endx >> endy;
        queue<node> way;
        inq[beginx][beginy] = 1;
        DFS(beginx, beginy , way, v, inq, endx, endy);
        if (resways.size() > 0)
        {
            for (int i = 0; i < resways.size(); ++i)
            {
                auto q = resways[i];
                cout << "(" << q.front().x << "," << q.front().y  << ")";
                q.pop();
                while (!q.empty())
                {
                    cout << "->(" << q.front().x  << "," << q.front().y  << ")";
                    q.pop();
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}