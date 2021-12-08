/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window,need;
        for(int i = 0;i < t.size();++i)
            need[t[i]]++;
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        int valid = 0;
        while(right < s.size())
        {
            auto c = s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            while(valid == need.size())
            {
                if(right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                auto d = s[left];
                left++;
                if(need.count(d))
                {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
// @lc code=end

