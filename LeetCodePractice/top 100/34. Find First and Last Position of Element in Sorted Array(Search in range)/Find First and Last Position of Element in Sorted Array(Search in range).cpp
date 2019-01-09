class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1,-1 };
		int n = nums.size();
		if (n == 0)
			return result;
		int low = 0, high = n - 1;
		int mid;
		while (low < high)
		{
			mid = (low + high) / 2;
			if (nums[mid] < target)
				low = mid + 1;
			else if (nums[mid] > target)
				high = mid - 1;
			else
			{
				low = mid;
				high = mid;
				while (low - 1 >= 0 && nums[low - 1] == target) low--;//��������
				while (high + 1 < n && nums[high + 1] == target) high++;//��������
				break;
			}
		}
		if (nums[low] == target)//�����ȣ������ҵ��˶�Ӧ��target�������ʾû���ҵ���Ӧ��target
		{
			result[0] = low;
			result[1] = high;
		}
		return result;
	}
};