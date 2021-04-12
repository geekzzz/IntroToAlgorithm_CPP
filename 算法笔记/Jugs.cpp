
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

///////////////////////////////////////传统迭代////////////////////////////////////
//void solve(int ca, int cb, int n)
//{
//    int nowa = 0;
//    int nowb = 0;
//    while (nowb != n)
//    {
//        nowa = ca;
//        cout << "fill A" << endl;
//        nowb += nowa;
//        if (nowb > cb)
//        {
//            nowa = nowb - cb;
//            nowb = cb;
//        }
//        else
//        {
//            nowa = 0;
//        }
//        cout << "pour A B" << endl;
//        if (nowb == cb)
//        {
//            nowb = 0;
//            cout << "empty B" << endl;
//            nowb = nowa;
//            nowa = 0;
//            cout << "pour A B" << endl;
//        }
//    }
//    cout << "success" << endl;
//}
//
//
//int main()
//{
//    int ca, cb, n;
//    while (cin >> ca >> cb >> n)
//    {
//        solve(ca, cb, n);
//    }
//}
///////////////////////////////////////传统迭代////////////////////////////////////
/////////////////////////////////BFS///////////////////////////////////


map<int, string> m;
struct node
{
    int nowa = 0;
    int nowb = 0;
    int step = 0;
    vector<int> ops;
};

void bfs(int ca, int cb, int n)
{
    queue<node> q;
    node nd1;
    nd1.nowa = ca;
    nd1.step = 0;
    nd1.ops.push_back(1);
    node nd2;
    nd2.nowb = cb;
    nd2.step = 0;
    nd2.ops.push_back(2);
    q.push_back(nd1);
    q.push_back(nd2);
    while(!q.empty())
    {
        node nd = q.front();
        q.pop();
        
        if(nd.nowb == n)
        {
            for(int i = 0;i < nd.ops.size() ;++i)
            {
                cout << m[nd.ops[i]] << endl;
            }
            cout << "success" << endl;
        }
        
        if(nd.nowa < ca)
        {
            node newnd;
            newnd.nowa = ca;
            newnd.step = nd.step + 1;
            newnd.ops.push_back(1);
        }
        if(nd.nowb < cb)
        {
            node newnd;
            newnd.nowb = cb;
            newnd.step = nd.step + 1;
            newnd.ops.push_back(2);
        }
        if(nd.nowa > 0)
        {
            node newnd;
            newnd.nowb = nd.nowa + nd.nowb;
            if(newnd.nowb > cb)
            {
                newnd.nowa = newnd.nowb - cb;
                newnd.nowb = cb;
            }
            else 
            {
                nowa = 0;
            }
            newnd.step = nd.step + 1;
            newnd.ops.push_back(3);
        }
        if(nd.nowb > 0)
        {
            node newnd;
            newnd.nowa = nd.nowa + nd.nowb;
            if(newnd.nowa > ca)
            {
                newnd.nowb = newnd.nowa - ca;
                newnd.nowa = ca;
            }
            else 
            {
                nowb = 0;
            }
            newnd.step = nd.step + 1;
            newnd.ops.push_back(4);
        }
        if(nd.nowa > 0)
        {
            node newnd;
            newnd.nowa = 0;
            newnd.step = nd.step +1;
            newnd.ops.push_back(5);
        }
        if(nd.nowb > 0)
        {
            node newnd;
            newnd.nowb = 0;
            newnd.step = nd.step +1;
            newnd.ops.push_back(6);
        }
    }
}


int main()
{
    int ca, cb, n;
    m[1] = "fill A";
    m[2] = "fill B";
    m[3] = "pour A B";
    m[4] = "pour B A";
    m[5] = "empty A";
    m[5] = "empty B";
    while (cin >> ca >> cb >> n)
    {
        bfs(ca, cb, n);
    }
}