class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		for (int i = 0; i < k; i++)
		{
			int t = *(nums.end() - 1);
			nums.erase(nums.end() - 1);
			nums.insert(nums.begin(), t);
		}
	}
};