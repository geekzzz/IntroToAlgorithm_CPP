class Solution {
public:
	vector<int> ori;

	Solution(vector<int>& nums) {
		ori.assign(nums.begin(), nums.end());
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return ori;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> news(ori);
		for (int i = 0; i < news.size(); ++i)
		{
			int pos = i + rand() % (news.size() - i);//将第i位于i后面的随机一位的数字交换
			swap(news[i], news[pos]);
		}
		return news;
	}
};