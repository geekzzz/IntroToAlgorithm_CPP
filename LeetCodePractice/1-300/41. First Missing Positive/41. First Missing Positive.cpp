//思想： 把数字换到对应坐标下，如1 换到 nums[0],2 到 nums[1] ...... 6到 nums[5]
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])//注意边界条件
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] != i + 1)//不相等则返回
				return i + 1;
		}
		return n + 1;//返回
	}
};