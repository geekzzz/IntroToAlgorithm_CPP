/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<int> v;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        v = vector<int>(nums.size(), 0);
        vector<int> cur;
        helper(nums, cur);
        return res;
    }
    void helper(vector<int>& nums, vector<int> cur)
    {
        if (cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (v[i] == 1)
            {
                continue;
            }
            v[i] = 1;
            cur.push_back(nums[i]);
            helper(nums, cur);
            cur.pop_back();
            v[i] = 0;
        }
    }
};
// @lc code=end

