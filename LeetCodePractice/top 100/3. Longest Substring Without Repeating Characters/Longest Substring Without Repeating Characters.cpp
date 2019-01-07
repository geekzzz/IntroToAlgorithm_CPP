class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int max = 0, start = -1;
		int nums[256];
		memset(nums, -1, sizeof(nums));
		for (int i = 0; i < s.size(); ++i)
		{
			if (start < nums[s[i]])
			{
				start = nums[s[i]];
			}
			nums[s[i]] = i;
			max = i - start > max ? i - start : max;
		}
		return max;
	}

};