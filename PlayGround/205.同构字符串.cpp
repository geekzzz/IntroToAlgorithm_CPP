/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256, -1);
        vector<int> m2(256, -1);

        for (int i = 0; i < s.size(); ++i)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        
        return true;
    }
};
// @lc code=end

