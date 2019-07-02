//dp解法，N^2复杂度
//dp[i]代表以dp[i]为结束的前面的递增串的长度
//解释视频  https://www.youtube.com/watch?v=fV-TF4OvZpk
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int maxL = 1;//maxL在i指针每次移动比较记录一下
		vector<int> dp(n + 1, 1);//初始化为1，代表以DP[I]为结尾的
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
			maxL = max(maxL, dp[i]);

		}
		return maxL;
	}
};



//二分法，nlogn复杂度，推荐
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        vector<int> tails(n,0);
        int size = 0;
        for(auto x : nums)
        {
            
            int i = bisearch(tails,0,size,x);
            tails[i] = x;
            if(size == i)
                size++;
        }
        return size;
    }
    int bisearch(vector<int> v,int low ,int high,int val)
    {
        while(low < high)
        {
            int mid = (high + low)/2;
            if(v[mid] == val)
                return mid;
            else if(v[mid] > val)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

