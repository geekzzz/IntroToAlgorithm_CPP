//��һ��map����¼ÿ��nums[i]��ǰ���������еĳ��ȣ�����keyΪnums[i],key��Ӧ��valueΪ���keyĿǰ���������г��ȡ�
//��ͷ��ʼ��ɨ�����飬��map�в����Ƿ����nums[i] + 1 ��nums[i] - 1,�������ó���
//���д��붼���濴һ��
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