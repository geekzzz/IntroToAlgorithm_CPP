/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.size())
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
                continue;
            }
            j++;
            if(j >= t.size())
            return false;
        }
        return true;
    }
};
// @lc code=end

