/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int cur = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '-')
                continue;
            res.push_back(toupper(s[i]));
            cur++;
            if (cur % k == 0)
                res.push_back('-');
        }
        if (res.size() > 0 && res.back() == '-')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

