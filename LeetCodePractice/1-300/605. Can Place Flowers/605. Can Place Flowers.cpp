class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int cnt = 0;
		for (int i = 0; i < flowerbed.size(); ++i)
		{
			int before = i == 0 ? 0 : flowerbed[i - 1];
			int forward = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
			if (before == 0 && forward == 0 && flowerbed[i] != 1)
			{
				flowerbed[i] = 1;
				cnt++;
			}
		}
		return cnt >= n;
	}
};