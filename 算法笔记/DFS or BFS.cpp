
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

void bfs(vector<string>)
{
    
}
int main()
{
    int n;
    while(cin >> n)
    {
        vector<vector<string>> v(n,vector<string>(8));
        for(int i = 0;i < n;++i)
        {
            auto vv = v[i];
            for(int j = 0;j <8;++j)
            {
                cin >> vv[j];
            }
        }
        for(int i = 0;i <n;++i)
        {
            //bfs()
        }
    }
    

    return 0;

}