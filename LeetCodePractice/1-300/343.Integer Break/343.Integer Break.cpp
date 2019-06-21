class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1,0);
        dp[1] = 1;
        for(int i = 2;i < dp.size();++i)
        {
            for(int j = 1;j <= i - 1;++j)
            {
                dp[i] = max(dp[i],max(dp[i - j] * j,(i - j) * j));//ע��������˱Ƚ�dp[i]��dp[i - j]*j���⣬��Ҫ�Ƚϣ�i-j��*j
            }
        }
        return dp[n];
    }
};