/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> finres;


    bool canplace(vector<string> cur, int m, int n)
    {
        for (int i = 0; i < cur.size(); ++i)
        {
            if (cur[i][n] == 'Q')
            {
                return false;
            }
        }
        for (int i = m,  j = n; i >= 0 && j >= 0; --i, --j)
        {
            if (cur[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = m,  j = n; i >= 0 && j < cur[0].size(); --i, ++j)
        {
            if (cur[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur;
        string s;
        for (int i = 0; i < n; ++i)
        {
            s.push_back('.');
        }
        for (int i = 0; i < n; ++i)
        {
            cur.push_back(s);
        }
        helper(cur, 0);
        return finres;

    }
    void helper(vector<string> cur, int m )
    {
        if (m >= cur[0].size())
        {
            finres.push_back(cur);
            return;
        }
        for (int i = 0; i < cur[0].size(); ++i)
        {
            if (canplace(cur, m, i))
            {
                cur[m][i] = 'Q';
                helper(cur, m + 1);
                cur[m][i] = '.';
            }
        }
    }
};
// @lc code=end

