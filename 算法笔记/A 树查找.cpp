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

vector<int> pre;

vector<int> res;

struct node{
    int v;
    node* l;
    node* r;
    int h;
};

node* build(int index,int height)
{
    if(index >= pre.size())
        return nullptr;
    node* t = new node();
    t->v = pre[index];
    t->h = height;
    t->l = build(index * 2 +1,height + 1);
    t->r = build(index * 2 + 2,height + 1);
    return t;
}


void trav(node* t,int h)
{
    queue<node*> q;
    q.push(t);
    while(!q.empty())
    {
        auto n = q.front();
        q.pop();
        if(n.h == h)
        {
            res.push(n.h);
        }
        if(n->l)
        {
            q.push(n->l);
        }
        if(n->r)
        {
            q.push(n->r);
        }
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        res.clear();
        vector<int> v(n);
        for(int i  = 0;i < n;++i)
        {
            cin >> v[i];
        }
        int d;
        cin >> d;
        auto t = build(0,1);
        trav(t,d);
        for(int i = 0;i < res.size();++i)
        {
            if(i  == 0)
            {
                cout << res[i];
            }
            else 
            {
                cout << " " << res[i];
            }
        }
        cout << endl;
    }
}