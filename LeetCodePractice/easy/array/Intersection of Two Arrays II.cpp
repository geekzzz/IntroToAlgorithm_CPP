class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> m;
		vector<int> ans;
		for (auto it = nums1.begin(); it != nums1.end(); ++it)
		{
			m[*it]++;
		}
		for (auto it = nums2.begin(); it != nums2.end(); ++it)
		{
			if (m[*it] > 0)
			{
				m[*it]--;
				ans.push_back(*it);
			}
		}
		return ans;
	}
};