/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> c(26,0);
        for(int i = 0;i < t.size(); ++i)
        {
            c[t[i] - 'a']++;
        }
        for(int i = 0;i < s.size(); ++i)
        {
            c[s[i] - 'a']--;
        }
        for(int i = 0;i < c.size(); ++i)
        {
            if(c[i] > 0)
            {
                return 'a' + i;
            }
        }
        return 'a';
    }
};
// @lc code=end

