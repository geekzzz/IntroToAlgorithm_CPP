class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2;i < n;++i)//注意这里从2开始，否则会出错
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n - 1];
    }
};
