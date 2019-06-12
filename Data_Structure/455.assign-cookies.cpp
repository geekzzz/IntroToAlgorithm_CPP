/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), less<int>());
		sort(s.begin(), s.end(), less<int>());
		int i = 0;
		int j = 0;
		int res = 0;
		while (i < g.size() && j < s.size())
		{
			if (s[j] >= g[i])
			{
				res++;
				j++;
				i++;
			}
			else
			{
				j++;
			}
		}
		return res;
    }
};

