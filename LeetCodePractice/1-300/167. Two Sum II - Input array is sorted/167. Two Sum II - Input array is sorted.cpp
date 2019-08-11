class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0;
		int j = numbers.size() - 1;
		int sum;
		vector<int> res;
		while (i <j)
		{
			sum = numbers[i] + numbers[j];
			if (sum > target)
				j--;
			else if (sum < target)
				i++;
			else
			{
				res.push_back(i + 1);
				res.push_back(j + 1);
				break;
			}
		}
		return res;
	}

};