class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxnum = nums[0];
		int n = nums.size();
		vector<int> dpmax(n, 0);
		vector<int> dpmin(n, 0);
		dpmax[0] = nums[0];
		dpmin[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dpmax[i] = max(max(dpmax[i - 1] * nums[i], dpmin[i - 1] * nums[i]), nums[i]);
			dpmin[i] = min(min(dpmax[i - 1] * nums[i], dpmin[i - 1] * nums[i]), nums[i]);
			maxnum = max(maxnum, dpmax[i]);
		}
		return maxnum;
	}
};