/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& board,int i ,int j)
    {
        if(i < 0 || i >= board.size())
            return;
        if(j < 0 || j >= board[0].size())
            return;
        if(board[i][j] == 'O')
        {
            board[i][j] = '.';
            dfs(board,i - 1,j);
            dfs(board,i ,j - 1);
            dfs(board,i + 1,j);
            dfs(board,i ,j + 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        //vector<vector<char>> v = board;
        for(int i = 0;i < board.size();++i)
        {
            dfs(board,i,0);
            dfs(board,i,board[0].size() -1);
        }
        for(int  j = 0;j < board[0].size();++j)
        {
            dfs(board,0,j);
            dfs(board,board.size() - 1,j);
        }
        for(int i = 0;i < board.size();++i){
            for(int j = 0;j < board[0].size();++j)
            {
                
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '.') 
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end

