/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0;i < grid.size();++i)
        {
            for(int j = 0; j < grid[i].size();++j)
            {
                if(grid[i][j])
                {
                    if(i - 1 < 0)
                        res++;
                    else
                        res += grid[i-1][j] == 0 ? 1 : 0;
                    if( i + 1 >= grid.size())
                        res++;
                    else
                        res += grid[i+1][j] == 0 ? 1 : 0;
                    if(j - 1 < 0)
                        res++;
                    else
                        res += grid[i][j-1] == 0 ? 1 : 0;
                    if(j + 1 >= grid[i].size())
                        res++;
                    else
                        res += grid[i][j+1] == 0 ? 1 : 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end

