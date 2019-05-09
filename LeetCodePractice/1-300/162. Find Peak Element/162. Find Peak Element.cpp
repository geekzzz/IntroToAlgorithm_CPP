//解法1暴力 O(n)
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		nums.insert(nums.begin(), INT_MIN);
		int i = 0, j = 1, k = 2;
		nums.push_back(INT_MIN);
		while (k <= nums.size())
		{
			if (nums[i] < nums[j] && nums[k] < nums[j])
				return j - 1;
			i++;
			j++;
			k++;
		}
		return 0;
	}
};
//解法2 用二分查找，找到局部最大的值,主旨是为了保证循环不变式
//invarient指的是循环不变式。在邓俊辉的数据结构中的二分查找中提到过这个概念。其思路就是
//
//保证初始条件满足循环不变式
//在循环过程中满足循环不变式。
//最终在循环结束时，自然也会满足循环不变式。
//特别像归纳法证明。初始条件满足，第n项满足，只要第n + 1项满足条件，则证明成功。
//
//根据循环不变式，我们来看一下。初始条件。我们将nums[-1]和nums[infi] 看做 - infi，（负无穷）。因此nums[start - 1] < nums[start] && nums[back] > nums[back + 1]满足。
//再考虑循环内。 if (nums[mid] < nums[mid + 1]) start = mid + 1; 保证了循环不变式。
//在if(nums[mid] > nums[mid + 1]) back = mid；保证了循环不变式。 nums[mid] == nums[mid + 1]的情况题目不允许。
//因此，在循环结束后依然保持。当循环结束时，start == back。且nums[start - 1] < nums[start] && nums[back] > nums[back + 1]。
//因此peak就是start的位置。

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		int mid;
		while (low <= high)
		{
			if (low == high)
				return low;
			mid = low + (high - low) / 2;

			if (nums[mid] < nums[mid + 1])
				low = mid + 1;
			else
				high = mid;
		}
		return (low == nums.size() - 1 || nums[low] > nums[low + 1]) ? low : high;//返回条件注意理解
	}

};