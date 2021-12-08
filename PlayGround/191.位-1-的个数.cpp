/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n!= 0)
        {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};
// @lc code=end

