//用一个map来记录每个nums[i]当前的连续序列的长度，其中key为nums[i],key对应的value为这个key目前的连续序列长度。
//从头开始，扫描数组，从map中查找是否存在nums[i] + 1 和nums[i] - 1,并且设置长度
//所有代码都认真看一下
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (m.find(nums[i]) == m.end())
			{
				int left = m.find(nums[i] - 1) != m.end() ? m[nums[i] - 1] : 0;
				int right = m.find(nums[i] + 1) != m.end() ? m[nums[i] + 1] : 0;

				int sum = left + right + 1;
				m[nums[i]] = sum;
				res = max(sum, res);

				m[nums[i] - left] = sum;
				m[nums[i] + right] = sum;
			}
			else
				continue;
		}
		return res;
	}
};