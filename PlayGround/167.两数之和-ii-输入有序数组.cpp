/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                return vector<int>{l + 1, r + 1};
            }
            else if(numbers[l] + numbers[r] < target)
            {
                l++;
            }
            else if(numbers[l] + numbers[r] > target)
            {
                r--;
            }
        }
        return vector<int>{l, r};
    }
};
// @lc code=end

