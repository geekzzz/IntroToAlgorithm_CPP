/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        set<char> excludeChar {'a','e','i','o','u','A','E','I','O','U'};
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while(l < r && excludeChar.find(s[l]) == excludeChar.end())
            {
                l++;
            }
            while(l < r && excludeChar.find(s[r]) == excludeChar.end())
            {
                r--;
            }
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};
// @lc code=end

