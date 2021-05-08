/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1,vector<int>(p.size() + 1,0));
        dp[0][0] = true;
        //"" 和p的匹配关系初始化，a*a*a*a*a*这种能够匹配空串，其他的是都是false。
        //  奇数位不管什么字符都是false，偶数位为* 时则: dp[0][i] = dp[0][i - 2]
        for(int j = 2;j <= p.size();j += 2)
        {
            dp[0][j] = (p[j - 1] == '*' && dp[0][j - 2] );
        }

        // 最后来个归纳：
        //如果 p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]；
        //如果 p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1]；
        // 如果 p.charAt(j) == '*'：
        // 如果 p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
        // 如果 p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.'：
        // dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
        // or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
        // or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
        for(int i = 1;i <= s.size();++i)
        {
            for(int j = 1;j <= p.size();++j)
            {
                if(p[j - 1] != '*')
                {
                    dp[i][j] = dp[i - 1][j - 1] &&( s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                else 
                {
                    if(s[i - 1] != p[j - 2] && p[j - 2] != '.')
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j  -2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end

