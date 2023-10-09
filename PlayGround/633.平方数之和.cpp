/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0;
        long long r = sqrt(c) ;
        while(l <= r)
        {
            long long res = l * l + r * r;
            if(res > c)
            {
                r--;
            }
            else if(res < c)
            {
                l++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

