/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int curmin = INT_MAX;
//         int res = 0;
//         for(int i = 0; i < prices.size();++i)
//         {
//             res = max(res,prices[i] - curmin);
//             curmin = min(curmin,prices[i]);
//         }
//         return res;
//     }
// };



// DP  state maching solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][1] = -prices[0];
        for(int i = 1;i < dp.size();++i)
        {
            dp[i][0] = max(dp[i - 1][0],dp[i  - 1][1] + prices[i] );
            dp[i][1] = max(-prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

