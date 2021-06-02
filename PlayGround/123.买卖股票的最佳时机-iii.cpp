/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,0)));
        //dp[0][0][1] = -prices[0];
        for(int i = 0;i < dp.size();++i)
        {
            for(int j = 2;j >= 1;--j)
            {
                if(i == 0)//处理第一天的case
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][1] + prices[i] , dp[i - 1][j][0]);
                dp[i][j][1] = max(dp[i - 1][j][1] , dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][2][0];
    }
};
// @lc code=end

