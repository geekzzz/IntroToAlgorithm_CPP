
//转换为sum数组，i 至 j 区间和可表示为sum[j] - sum[i - 1]
class NumArray {
public:
	vector<int> n;
	NumArray(vector<int>& nums) {
		n.resize(nums.size() + 1);
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			n[i] = sum;
		}
	}

	int sumRange(int i, int j) {
		return i == 0 ? n[j] : n[j] - n[i - 1];
	}
};
