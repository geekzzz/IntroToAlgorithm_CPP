//��wiggle sort II��ȣ����ÿ��ǵ��ڵ����

class Solution {
public:
	/*
	* @param nums: A list of integers
	* @return: nothing
	*/
	void wiggleSort(vector<int> &nums) {
		// write your code here
		for (int i = 1; i < nums.size(); ++i)
		{
			if ((nums[i] > nums[i - 1] && i % 2 == 0) || (nums[i] < nums[i - 1] && i % 2 == 1))
				swap(nums[i], nums[i - 1]);
		}
	}
};