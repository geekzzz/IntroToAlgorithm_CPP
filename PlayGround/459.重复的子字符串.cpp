/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int l = 1; l <= n / 2; ++l)
        {
            if (n % l != 0)
                continue;
            string cur = s.substr(0, l);
            int start = 0;
            bool valid = true;
            for (; start <= n - l; start += l)
            {
                if (cur != s.substr(start, l))
                    valid = false;
            }
            if (valid)
                return true;
        }
        return false;
    }
};
// @lc code=end

