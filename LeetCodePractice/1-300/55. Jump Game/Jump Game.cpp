class Solution {
public:
	bool canJump(vector<int>& nums) {
		int i = 0;
		int reach = 0;
		while (i < nums.size() && i <= reach)
		{
			reach = max(i + nums[i], reach);
			i++;
		}
		return i == nums.size();
	}
};