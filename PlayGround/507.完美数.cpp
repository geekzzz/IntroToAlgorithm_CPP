/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        set<int> n;
        for(int i = 1;i <= num / 2;++i)
        {
            if(num % i == 0)
            {
                n.insert(i);
            }
        }
        int total = 0;
        for(auto it = n.begin(); it != n.end();++it)
        {
            total += *it;
        }
        return total == num;
    }
};
// @lc code=end

