/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int res = INT_MAX;
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> v;
        unordered_map<string,int> m;
        for(auto d : deadends)
        { 
            m[d]++;
        }
        q.push(string("0000"));
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string s = q.front();
                q.pop();
                if(m[s] > 0)
                    continue;
                if (s == target)
                    return step;
                for (int p = 0; p < 4; ++p)
                {
                    auto ll = Add(s, p);
                    auto rr = Minus(s, p);
                    if (v.count(ll) == 0 )
                    {
                        q.push(ll);
                        v.insert(ll);
                    }
                        
                    if(v.count(rr) == 0 )
                    {
                        q.push(rr);
                        v.insert(rr);
                    }
                        
                }
            }
            step++;
        }
        return -1;
    }
    string Add(string s, int p)
    {
        int t = s[p] - '0';
        if (t == 9)
            s[p] = '0';
        else
            s[p] = s[p] + 1;
        return s;
    }
    string Minus(string s, int p)
    {
        int t = s[p] - '0';
        if (t == 0)
            s[p] = '9';
        else
            s[p] = s[p] - 1;
        return s;
    }
};
// @lc code=end

