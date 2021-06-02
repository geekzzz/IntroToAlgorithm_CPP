/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        for(int i = 1;i < n;++i)
        {
            if(i == 0)
            {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
            }
            if(i == 1)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] );
                dp[i][1] = max(-prices[0],-prices[1]);
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] );
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i] );
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

