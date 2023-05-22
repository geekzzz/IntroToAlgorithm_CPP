/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 10);
        for(int i = 1;i < dp.size();++i)
        {
            for(int j = 0; j  < coins.size();++j)
            {
                if(coins[j] < i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX - 10 ? - 1 : dp[amount];
    }
};
// @lc code=end

