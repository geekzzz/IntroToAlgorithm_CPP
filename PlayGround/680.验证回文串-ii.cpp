/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int l , int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while(l < r)
            {
                if(s[l] == s[r])
                {
                    l++;
                    r--;
                }
                else
                {
                    return isPalindrome(s, l+ 1, r) || isPalindrome(s, l, r - 1);
                }
            }
        }
        return true;
    }
};
// @lc code=end

