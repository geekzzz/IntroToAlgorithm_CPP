/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    struct node
    {
        int key = -1;
        int freq = 0;
    };
    static bool cmp(node a, node b)
    {
        return a.freq > b.freq;
    };
    string frequencySort(string s) {
        vector<node> freq(200);
        for (int i = 0; i < s.size(); ++i)
        {
            auto t = (int)s[i];
            freq[t].key = t;
            freq[t].freq++;
        }
        sort(freq.begin(), freq.end(), cmp);
        string res;
        for (int i = 0; i < freq.size(); ++i)
        {
            if (freq[i].key != -1)
            {
                for (int j = 0; j < freq[i].freq; ++j)
                {
                    res += (char)freq[i].key;
                }
            }
        }
        return res;
    }
};
// @lc code=end

