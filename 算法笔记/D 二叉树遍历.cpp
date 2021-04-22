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

string s;
int index = 0;

struct node {
    char v;
    node* l;
    node * r;
};



node* build( string s)
{
    if (index >= s.size())
    {
        return nullptr;
    }
    if (s[index] == '#')
    {
        index++;
        return nullptr;
    }
    node* t = new node();
    t->v = s[index];
    index++;
    t->l = build(s);
    t->r = build(s);
    return t;
}


vector<char> inorder;

void in(node* t)
{
    if (!t)
        return;
    
    in(t->l);
    inorder.push_back(t->v);
    in(t->r);
}

int main()
{

    while (cin >> s)
    {
        index = 0;
        auto t = build( s);
        in(t);
        for (int i = 0; i < inorder.size(); ++i)
        {
            if (i == 0)
            {
                cout << inorder[i];
            }
            else
            {
                cout << " " << inorder[i];
            }
        }
        cout << endl;
        inorder.clear();
        s.clear();
    }
}