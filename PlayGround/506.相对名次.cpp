/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start

class Solution {
public:
    struct node {
        int idx;
        int val;
    };
    static bool cmp(const node* a, const node* b)
    {
        return a->val > b->val;
    };

    std::string myitoa(int num) {
        std::string result;
        bool isNegative = false;

        // 处理负数的情况
        if (num < 0) {
            isNegative = true;
            num = -num;
        }

        // 处理0的情况
        if (num == 0)
            return "0";

        // 逐位生成数字字符串
        while (num > 0) {
            int digit = num % 10;
            result = static_cast<char>('0' + digit) + result;
            num /= 10;
        }

        // 添加负号
        if (isNegative)
            result = '-' + result;

        return result;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<node*> v;
        for (int i = 0; i < score.size(); ++i)
        {
            node* a = new node();
            a->idx = i;
            a->val = score[i];
            v.push_back(a);
        }
        sort(v.begin(), v.end(), cmp);
        vector<string> res(v.size());
        for (int i = 0; i < v.size(); ++i)
        {
            if (i == 0)
                res[v[i]->idx] = "Gold Medal";
            else if (i == 1)
                res[v[i]->idx] = "Silver Medal";
            else if (i == 2)
                res[v[i]->idx] = "Bronze Medal";
            else
            {
                res[v[i]->idx] = myitoa(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end

