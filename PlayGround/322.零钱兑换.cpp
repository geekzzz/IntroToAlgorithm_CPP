/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i <= amount;++i)
        {
            for(int j = 0;j < coins.size();++j)
            {
                if(coins[j] <= i && dp[i - coins[j]] < INT_MAX )
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

