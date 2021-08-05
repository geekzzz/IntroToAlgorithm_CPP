/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
		unordered_map<int,int> m;
        for(int i = 0;i < nums.size();++i)
        {
			int num = nums[i];
            if(m.find(target - num) != m.end())
			{
				result.push_back(m[target - num]);
				result.push_back(i);
				return result;
			}
			else 
			{
				m[num] = i;
			}
        }
        return result;
    }
};
// @lc code=end

