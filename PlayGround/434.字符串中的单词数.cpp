/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        string cur = "";
        int res = 0;
        for(int i = 0;i < s.size();++i)
        {
            if(s[i] == ' ')
            {
                if(cur.size() > 0)
                {
                    res++;
                }
                cur = "";
            }
            else
            {
                cur += s[i];
            }
        }
        if(cur.size() > 0)
            res++;
        return res;
    }
};
// @lc code=end

