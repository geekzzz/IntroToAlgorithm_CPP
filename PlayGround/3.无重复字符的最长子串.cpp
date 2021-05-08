/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string ss) {
		unordered_map<char,int> m;
		int len = 0;
		int left = 0;
		for(int i = 0;i < ss.size();++i)
		{
			char s = ss[i];
			if(m[s])
			{
				left = max(left,m[s]);
			}
			m[s] = i + 1;
			len = max(len,i + 1 - left);
		}
		return len;
    }
};
// @lc code=end

