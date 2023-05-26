/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
         string res;
        vector<char> st;
        for (int i = 0; i < num.size(); ++i)
        {
            while (!st.empty() && k > 0 && st.back() > num[i])
            {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while (k > 0)
        {
            st.pop_back();
            k--;
        }
        for (int i = 0; i < st.size(); ++i)
        {
            if (st[i] == '0' && res.size() == 0)
            {
                continue;
            }
            res += st[i];
        }


        return res.size() == 0 ? "0" : res;
    }
};
// @lc code=end

