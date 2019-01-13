只能向下或者向右，所以dp的方程为：//一个简单的dp思路：只能往左走或者往下走，所以dp的方程即为： dp[i][j]  = dp[i - 1][j] + dp[i][j - 1]

参考：https://leetcode.com/problems/unique-paths/discuss/22954/0ms-5-lines-DP-Solution-in-C%2B%2B-with-Explanations