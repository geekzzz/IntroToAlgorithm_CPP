class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return nums.size();
		}
		int n = 1;
		for (vector<int>::iterator it = nums.begin(), it2 = nums.begin() + 1; it2 != nums.end();)
		{
			if (*it == *it2)
			{
				it = nums.erase(it);
				it2 = it + 1;
			}
			else
			{
				it++;
				it2++;
				n++;
			}
		}
		return n;
	}
};