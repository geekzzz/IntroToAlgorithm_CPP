//我的解法
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> m;
		int half = nums.size() / 2;
		for (int i = 0; i < nums.size(); ++i)
		{
			m[nums[i]]++;
			if (m[nums[i]] > half)
				return nums[i];
		}
		return nums[0];
	}
};

//各种解法：
https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C%2B%2B-with-Explanations