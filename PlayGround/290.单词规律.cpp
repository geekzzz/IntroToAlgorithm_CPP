/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string s, string pattern) {
        int pCount = 0;
        vector<string> ps = split(pattern, ' ',pCount);
        set<char> sss;
        for(int i = 0;i < s.size();++i)
        {
            sss.insert(s[i]);
        }
        unordered_map<char, string> m;
        unordered_map<string, char> m2;
        if(ps.size() != s.size())
            return false;
        if(pCount != sss.size())
            return false;
        for(int i = 0;i < s.size();++i)
        {
            if(m.find(s[i]) != m.end())
            {
                if(m[s[i]] != ps[i])
                    return false;
                if(m2[ps[i]] != s[i])
                    return false;
            }
            else
            {
                m[s[i]] = ps[i];
                m2[ps[i]] = s[i];
            }
        }
        return true;
    }
    vector<string> split(string p, char c, int& pCount) {
        vector<string> res;
        string cur;
        set<string> s;
        for(int i = 0;i < p.size();++i)
        {
            if(p[i] == c)
            {
                res.push_back(cur);
                s.insert(cur);
                cur = "";
            }
            else 
                cur += p[i];
        }
        if(cur.size() > 0)
        {
            res.push_back(cur);
            s.insert(cur);
        }
        pCount = s.size();
        return res;
    }
};
// @lc code=end

