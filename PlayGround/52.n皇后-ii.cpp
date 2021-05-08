/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int result = 0;
    bool check(int row ,int col,const vector<vector<int>> &board){
        for(int i = 0;i < row;++i)
        {
            if(board[i][col] == 1)
                return false;
        }
        for(int i = row - 1,j = col - 1;i >= 0 &&  j >= 0;--i,--j)
        {
            if(board[i][j] == 1)
                return false;
        }
        for(int i = row - 1,j = col + 1;i >= 0 && j < board.size();--i,++j)
        {
            if(board[i][j] == 1)
                return false;
        }
        return true;
    }
    void backtrack(int row,int n,vector<vector<int>> &board )
    {
        if(row == n)
        {
            result++;
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            board[row][i] = 1;
            if(check(row,i,board))
            {
                backtrack(row + 1,n,board);
            }
            board[row][i] = 0;
        }
            
    }
    int totalNQueens(int n) {
        vector<vector<int>> board;
        board.resize(n,vector<int>(n,0));
        backtrack(0,n,board);
        return result;
    }
};
// @lc code=end

