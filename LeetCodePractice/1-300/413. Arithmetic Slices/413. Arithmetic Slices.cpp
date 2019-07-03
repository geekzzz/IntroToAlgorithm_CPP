class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n + 1,0);
        for(int i = 2;i < n;++i)
        {
            if(a[i]  - a[i - 1] == a[i - 1] - a[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        int res = 0;
        for(auto x : dp)
            res += x;
        return res;
    }
};