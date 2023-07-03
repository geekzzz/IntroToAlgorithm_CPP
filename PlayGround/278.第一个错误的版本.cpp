/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while(l < r)
        {
            int m = l + (r - l)/2;
            if(isBadVersion(m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }
};
// @lc code=end

