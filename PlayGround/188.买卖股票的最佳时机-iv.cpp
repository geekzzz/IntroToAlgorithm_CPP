/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k + 1,vector<int>(2,0)));
        //vector<vector<int>> dp(n,vector<int>(2,0));
        for( int i = 0; i < n ; ++i )
        {
           for(int kk = k; kk >= 1;--kk)
           {
               if(i == 0)
               {
                   dp[i][kk][0] = 0;
                   dp[i][kk][1] = -prices[0];
                   continue;
               }
                dp[i][kk][0] = max(dp[i - 1][kk][0], dp[i - 1][kk][1] + prices[i]);
                dp[i][kk][1] = max(dp[i - 1][kk][1], dp[i - 1][kk - 1][0] - prices[i]);
           }
        }
        return dp[n - 1][k][0];
    }
};
// @lc code=end

