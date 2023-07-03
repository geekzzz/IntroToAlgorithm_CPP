/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counter;
        for (char c : s)
            counter[c]++;
        // 统计构造回文串的最大长度
        int res = 0, odd = 0;
        for (auto kv : counter) {
            // 将当前字符出现次数向下取偶数，并计入 res
            int count = kv.second;
            int rem = count % 2;
            res += count - rem;
            // 若当前字符出现次数为奇数，则将 odd 置 1
            if (rem == 1) odd = 1;
        }
        return res + odd;
    }
};
// @lc code=end

