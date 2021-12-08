/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> window,need;
        int valid = 0;
        int left = 0,right = 0;
        for(auto c : p)
            need[c]++;
        while(right < s.size())
        {
            char c = s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            while(valid == need.size())
            {
                if(right - left == p.size())
                {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if(need.count(d))
                {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

