/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        
        return helper(n);
    }
    int helper(long long n)
    {
        if(n == 1)
        {
            return 0;
        }
        if(n % 2 == 0)
        {
            return 1 + helper(n  / 2);
        }
        return  1 + min(  helper(n + 1), helper(n - 1)   );
    }

};
// @lc code=end

