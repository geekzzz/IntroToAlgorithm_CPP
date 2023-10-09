/*
 * @lc app=leetcode.cn id=1881 lang=cpp
 *
 * [1881] 插入后的最大值
 */

// @lc code=start
class Solution {
public:
    string maxValue(string n, int x) {
        bool neg = false;
        if (n[0] == '-')
        {
            neg = true;
        }
        if (!neg)
        {
            for (int i = 1; i < n.size(); ++i)
            {
                if (n[i] - '0' < x)
                {
                    //return n.insert(i, x);
                    string toinsert;
                    toinsert.push_back((char)('0' + x));
                    n.insert(i, toinsert);
                    return n;
                }
            }
        }
        else
        {
            for (int i = 1; i < n.size(); ++i)
            {
                if (n[i] - '0' > x)
                {
                    string toinsert;
                    toinsert.push_back((char)('0' + x));
                    n.insert(i, toinsert);
                    return n;
                }
            }
        }
        n.push_back(x);
        return n;
    }
};// @lc code=end

