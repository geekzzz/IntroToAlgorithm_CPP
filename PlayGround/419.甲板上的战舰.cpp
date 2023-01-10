/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0;i < board.size();++i)
        {
            for(int j = 0;j < board[i].size();++j)
            {
                if(board[i][j] == 'X')
                {
                    count++;
                    board[i][j] = '.';
                    for(int mi = i + 1;mi < board.size() && board[mi][j] =='X';++mi)
                    {
                        board[mi][j] = '.';
                    }
                    for(int mj = j + 1;mj < board[i].size() && board[i][mj] =='X';++mj)
                    {
                        board[i][mj] = '.';
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

