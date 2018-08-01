class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = nums.size() - 1, j = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] == 0)
			{
				for (int k = i; k < j; ++k)
				{
					nums[k] = nums[k + 1];
				}
				nums[j] = 0;
				j--;
			}
		}
	}
};