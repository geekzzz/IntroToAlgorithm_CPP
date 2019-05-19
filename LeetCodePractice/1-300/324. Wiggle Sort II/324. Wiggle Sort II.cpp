//three-way partition + virtual index
//²Î¿¼https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
//https://leetcode.com/problems/wiggle-sort-ii/discuss/77682/Step-by-step-explanation-of-index-mapping-in-Java

class Solution {
public:
	int n = 0;
	void wiggleSort(vector<int>& nums) {
		int i = 0;
		int j = 0;
		n = nums.size();
		int k = n - 1;
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;

		while (j <= k)
		{
			if (nums[A(j)] > mid)
				swap(nums[A(i++)], nums[A(j++)]);
			else if (nums[A(j)] < mid)
				swap(nums[A(j)], nums[A(k--)]);
			else
				j++;
		}



	}
	int A(int i)
	{
		return (1 + 2 * (i)) % (n | 1);
	}

};